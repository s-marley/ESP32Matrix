class Breakout {

  int8_t sliderPosition;
  uint8_t ballRate;
  uint8_t level;
  uint8_t blocksRemaining;
  cLEDText ScrollingMsg;
  unsigned char txtBreakout[20];

  const uint8_t paddleData[1] = { B8_1BIT(01111000) };
  const uint8_t paddleMask[1] = { B8_1BIT(11111100) };
  const struct CRGB paddleColorTable[1] = {CRGB(200,200,200)};
  uint8_t paddleWidth = 6;
  uint8_t paddleHeight = 1;

  const uint8_t ballData[1] = { B8_1BIT(10000000) };
  const uint8_t ballMask[1] = { B8_1BIT(10000000) };
  const struct CRGB ballColorTable[1] = {CRGB(255,255,0)};

  uint8_t plasmaLowHue = 100;
  uint8_t plasmaHighHue = 150;

  #define NUM_BLOCKS 11
  const uint8_t blockData[30] = {
    // Frame 1
    B8_3BIT(11110000),
    B8_3BIT(11110000),
    // Frame 2
    B8_3BIT(22220000),
    B8_3BIT(22220000),
    // Frame 3
    B8_3BIT(33330000),
    B8_3BIT(33330000),
    // Frame 4
    B8_3BIT(44440000),
    B8_3BIT(44440000),
    // Frame 5
    B8_3BIT(55550000),
    B8_3BIT(55550000),
  };
  const uint8_t blockMask[10] = {
    // Frame 1
    B8_1BIT(11110000),
    B8_1BIT(11110000),
    // Frame 2
    B8_1BIT(11110000),
    B8_1BIT(11110000),
    // Frame 3
    B8_1BIT(11110000),
    B8_1BIT(11110000),
    // Frame 4
    B8_1BIT(11110000),
    B8_1BIT(11110000),
    // Frame 5
    B8_1BIT(11110000),
    B8_1BIT(11110000),
  };
  const struct CRGB blockColors1[5] = { CRGB(13, 150, 255), CRGB(12, 227, 232), CRGB(0, 255, 149), CRGB(12, 232, 43), CRGB(93, 255, 2) };
  const struct CRGB blockColors2[5] = { CRGB(255, 229, 3), CRGB(232, 172, 2), CRGB(255, 154, 11), CRGB(232, 84, 2), CRGB(255, 44, 13) };
  const struct CRGB blockColors3[5] = { CRGB(255, 48, 13), CRGB(232, 12, 74), CRGB(247, 0, 255), CRGB(131, 12, 232), CRGB(32, 3, 255) };
  const uint8_t blockWidth = 4;
  const uint8_t blockHeight = 2;
  
  cLEDSprites Sprites;
  cSprite sprPaddle;
  cSprite sprBall;
  cSprite Blocks[NUM_BLOCKS];

  boolean startUp;

  uint16_t PlasmaTime, PlasmaShift;
  
  public:
  Breakout():Sprites(&leds){};

  void setup(){
    // Create paddle
    sprPaddle.Setup(paddleWidth, paddleHeight, paddleData, 1, _1BIT, paddleColorTable, paddleMask);
    sprPaddle.SetPosition(sliderPosition,0);
    sprPaddle.SetFrame(0);
    sprPaddle.SetMotion(0,0,0,0);
    sprPaddle.SetOptions(SPRITE_DETECT_COLLISION);
    Sprites.AddSprite(&sprPaddle);

    // Create ball
    sprBall.Setup(1, 1, ballData, 1, _1BIT, ballColorTable, ballMask);
    sprBall.SetPosition(0,7);
    sprBall.SetFrame(0);
    sprBall.SetMotion(0,0,0,0);
    sprBall.SetOptions(SPRITE_DETECT_EDGE | SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN | SPRITE_DETECT_COLLISION);
    Sprites.AddSprite(&sprBall);

    level = 1;
    setupLevel(level);

    PlasmaShift = (random8(0, 5) * 32) + 64;
    PlasmaTime = 0;
  }

  boolean loop(){
    
    // Fill background with dim plasma
    #define PLASMA_X_FACTOR  24
    #define PLASMA_Y_FACTOR  24
    for (int16_t x=0; x<leds.Width(); x++)
    {
      for (int16_t y=0; y<leds.Height(); y++)
      {
        int16_t r = sin16(PlasmaTime) / 256;
        int16_t h = sin16(x * r * PLASMA_X_FACTOR + PlasmaTime) + cos16(y * (-r) * PLASMA_Y_FACTOR + PlasmaTime) + sin16(y * x * (cos16(-PlasmaTime) / 256) / 2);
        int16_t hue = ((h / 256) + 128);
        if(hue < 128) hue = map(hue, 0, 127, plasmaLowHue, plasmaHighHue);
        else hue = map(hue, 128, 255, plasmaHighHue, plasmaLowHue);
        leds(x, y) = CHSV((uint8_t)hue, 255, 64);
      }
    }
    uint16_t OldPlasmaTime = PlasmaTime;
    PlasmaTime += PlasmaShift;
    if (OldPlasmaTime > PlasmaTime)
      PlasmaShift = (random8(0, 5) * 32) + 64;
    
    if(startUp) {
      sprBall.SetPosition(sliderPosition+1,1);
    }
    
    if (SerialBT.available()) {
      byte keyPress = SerialBT.read();
      // If it's greater than 20 we sent a character instead
      if(keyPress > 20) {
        if(startUp) {
          sprBall.SetMotion(1, ballRate, 1, ballRate);
          startUp = false;
        }
        switch((char)keyPress) {
          case 'm':
            currentApp = -1;
            return false;
        }
      } else {
        sliderPosition = (int8_t)keyPress - 1;
      }
    }
    
    //FastLED.clear();
    
    sprPaddle.SetPosition(sliderPosition,0);
    
    Sprites.UpdateSprites();
    Sprites.DetectCollisions();

    if(sprBall.GetFlags() & SPRITE_COLLISION) {
      
      if(sprBall.m_Y > 1) {       // If y < 1, ball is hitting paddle instead of a block

        for (uint8_t i = 0; i < NUM_BLOCKS; i++) {
          if(isSpriteAtXY(sprBall.m_X, sprBall.m_Y, blockWidth, blockHeight, &Blocks[i])) {
            
            if(Sprites.IsSprite(&Blocks[i])) {
              Sprites.RemoveSprite(&Blocks[i]);
              blocksRemaining--;

              if(blocksRemaining) {
  
                int8_t ballYChange = sprBall.GetYChange();
                int8_t ballXChange = sprBall.GetXChange();
  
                // Hits top row of pixels on a block and downwards, or bottom row and upwards
                if ((sprBall.m_Y % 2 != 0 && ballYChange == -1) || (sprBall.m_Y % 2 == 0 && ballYChange == 1)){
                  sprBall.SetMotion(ballXChange, ballRate, ballYChange * -1, ballRate);
                  // If hitting straight on need to jump down two pixels instead of one
                  if(ballXChange == 0) sprBall.m_Y += ballYChange * -2;
                  else sprBall.m_Y += ballYChange * -1;
                }
                
                // Hits top row of pixels on a block and upwards, or bottom row and downwards
                else {
                  sprBall.SetMotion(ballXChange * -1, ballRate, ballYChange, ballRate);
                  sprBall.m_X += ballXChange * -1;
                }
              }
              
              else {
                level = ++level % 3;
                setupLevel(level);
              }
            }
          }
        }
      }
    }

    if(sprPaddle.GetFlags() & SPRITE_COLLISION) {
      // Check which pixel of the paddle it has hit
      uint16_t paddleHitPixel = sprBall.m_X - sprPaddle.m_X;     
      
      // Remember current XChange for later
      int8_t lastXChange = sprBall.GetXChange();
      
      // Adjust bounce up according to which pixel is hit on the paddle
      switch(paddleHitPixel) {
        case 0:
        case 1:
          sprBall.SetMotion(-1, ballRate, 1, ballRate);
          break;
        case 2:
        case 3:
          sprBall.SetMotion(0, ballRate, 1, ballRate);
          break;
        case 4:
        case 5:
          sprBall.SetMotion(1, ballRate, 1, ballRate);
          break;
      }
      
      // Pop ball up from paddle
      sprBall.m_Y += 2;
      if (lastXChange > 0) sprBall.m_X--;
      if (lastXChange < 0) sprBall.m_X++;
      sprBall.m_X += sprBall.GetXChange();
    
    }
    else {
      // If hit bottom of screen and NOT collided with paddle, reset game
      if(sprBall.GetFlags() & SPRITE_EDGE_Y_MIN) {
        return false;
      }
    }

    Sprites.RenderSprites();
    FastLED.show();
    
    return true;
  }

  private:

  void setupLevel(uint8_t levelNo) {
    sliderPosition = 6;
    startUp = true;
    blocksRemaining = NUM_BLOCKS;
    sprBall.SetMotion(0,0,0,0);
    
    for (uint8_t i = 0; i < NUM_BLOCKS; i++){
      
      uint8_t xPos, yPos;
      if(i < 4 ) xPos = i*4;
      else if (i > 6) xPos = (i-7)*4;
      else xPos = ((i-4)*4)+2;
      
      if(i < 4) yPos = 14;
      else if (i > 6) yPos = 10;
      else yPos = 12;
      
      switch (levelNo){
        case 1:
          Blocks[i].Setup(blockWidth, blockHeight, blockData, 5, _3BIT, blockColors1, blockMask);
          ballRate = 15;    // Lower is faster
          plasmaLowHue = 100;
          plasmaHighHue = 150;
          break;
        case 2:
          Blocks[i].Setup(blockWidth, blockHeight, blockData, 5, _3BIT, blockColors2, blockMask);
          ballRate = 12;
          plasmaLowHue = 10;
          plasmaHighHue = 64;
          break;
        case 3:
          Blocks[i].Setup(blockWidth, blockHeight, blockData, 5, _3BIT, blockColors3, blockMask);
          ballRate = 9;
          plasmaLowHue = 205;
          plasmaHighHue = 255;
          break;
      }
      
      Blocks[i].SetPosition(xPos, yPos);
      Blocks[i].SetFrame(i % 5);    // Loop colours back around after 5
      Blocks[i].SetMotion(0,0,0,0);
      Blocks[i].SetOptions(SPRITE_DETECT_COLLISION);
      Sprites.AddSprite(&Blocks[i]);
    }
  }
  
  boolean isSpriteAtXY (uint8_t x, uint8_t y, uint8_t w, uint8_t h, cSprite *sprite) {
    if ( x >= sprite->m_X && x <= sprite->m_X + w - 1) {
      if (y >= sprite->m_Y && y <= sprite->m_Y + h - 1) {
        return true;
      }
      return false;
    }
    return false;
  }
};
