class Pixel{

  const uint8_t SpritealienData[96] = {
    B8_2BIT(33333111),B8_2BIT(11133333),
    B8_2BIT(33311111),B8_2BIT(11111333),
    B8_2BIT(33111111),B8_2BIT(11111133),
    B8_2BIT(31111111),B8_2BIT(11111113),
    B8_2BIT(31111111),B8_2BIT(11111113),
    B8_2BIT(10000111),B8_2BIT(11100001),
    B8_2BIT(10000011),B8_2BIT(11000001),
    B8_2BIT(10000001),B8_2BIT(10000001),
    B8_2BIT(10000001),B8_2BIT(10000001),
    B8_2BIT(31000001),B8_2BIT(10000013),
    B8_2BIT(31100001),B8_2BIT(10000113),
    B8_2BIT(33111111),B8_2BIT(11111133),
    B8_2BIT(33111111),B8_2BIT(11111133),
    B8_2BIT(33311111),B8_2BIT(11111333),
    B8_2BIT(33331111),B8_2BIT(11113333),
    B8_2BIT(33333311),B8_2BIT(11333333) };
  const uint8_t SpritealienMask[32] = {
    B8_1BIT(00000111),B8_1BIT(11100000),
    B8_1BIT(00011111),B8_1BIT(11111000),
    B8_1BIT(00111111),B8_1BIT(11111100),
    B8_1BIT(01111111),B8_1BIT(11111110),
    B8_1BIT(01111111),B8_1BIT(11111110),
    B8_1BIT(10000111),B8_1BIT(11100001),
    B8_1BIT(10110011),B8_1BIT(11001101),
    B8_1BIT(10100001),B8_1BIT(10000101),
    B8_1BIT(10000101),B8_1BIT(10100001),
    B8_1BIT(01000001),B8_1BIT(10000010),
    B8_1BIT(01100001),B8_1BIT(10000110),
    B8_1BIT(00111111),B8_1BIT(11111100),
    B8_1BIT(00111111),B8_1BIT(11111100),
    B8_1BIT(00011111),B8_1BIT(11111000),
    B8_1BIT(00001111),B8_1BIT(11110000),
    B8_1BIT(00000011),B8_1BIT(11000000) };
  
  const struct CRGB SpritealienCols[4] = { CRGB(2,103,2), CRGB(200,200,200),  CRGB(0,0,0)};
  
  const uint8_t SpriteSmileyData[480] = {
    // Frame 1 done
    B8_2BIT(00000111),B8_2BIT(11000000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00111111),B8_2BIT(11111000),
    B8_2BIT(01111211),B8_2BIT(12111100),
    B8_2BIT(01111211),B8_2BIT(12111100),
    B8_2BIT(11111211),B8_2BIT(12111110),
    B8_2BIT(11111111),B8_2BIT(11111110),
    B8_2BIT(11111111),B8_2BIT(11111110),
    B8_2BIT(11211111),B8_2BIT(11112110),
    B8_2BIT(11211111),B8_2BIT(11112110),
    B8_2BIT(01121111),B8_2BIT(11121100),
    B8_2BIT(01112111),B8_2BIT(11211100),
    B8_2BIT(00111222),B8_2BIT(22111000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00000111),B8_2BIT(11000000),
    // Frame 2 done
    B8_2BIT(00000111),B8_2BIT(11000000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00111111),B8_2BIT(12111000),
    B8_2BIT(01111111),B8_2BIT(21111100),
    B8_2BIT(01121112),B8_2BIT(11111100),
    B8_2BIT(11211111),B8_2BIT(11112110),
    B8_2BIT(11211111),B8_2BIT(11121110),
    B8_2BIT(11211111),B8_2BIT(11211110),
    B8_2BIT(11211111),B8_2BIT(11111110),
    B8_2BIT(11121111),B8_2BIT(11111110),
    B8_2BIT(01121111),B8_2BIT(11111100),
    B8_2BIT(01112211),B8_2BIT(11211100),
    B8_2BIT(00111122),B8_2BIT(22111000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00000111),B8_2BIT(11000000),
    // Frame 3 done
    B8_2BIT(00000111),B8_2BIT(11000000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00111221),B8_2BIT(11111000),
    B8_2BIT(01112111),B8_2BIT(11111100),
    B8_2BIT(01121111),B8_2BIT(11111100),
    B8_2BIT(11211111),B8_2BIT(12221110),
    B8_2BIT(11211111),B8_2BIT(11111110),
    B8_2BIT(11211111),B8_2BIT(11111110),
    B8_2BIT(11211111),B8_2BIT(11111110),
    B8_2BIT(11211111),B8_2BIT(12221110),
    B8_2BIT(01121111),B8_2BIT(11111100),
    B8_2BIT(01112111),B8_2BIT(11111100),
    B8_2BIT(00111221),B8_2BIT(11111000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00000111),B8_2BIT(11000000),
    // Frame 4 done
    B8_2BIT(00000111),B8_2BIT(11000000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00111122),B8_2BIT(22111000),
    B8_2BIT(01112211),B8_2BIT(11211100),
    B8_2BIT(01121111),B8_2BIT(11111100),
    B8_2BIT(11121111),B8_2BIT(11111110),
    B8_2BIT(11211111),B8_2BIT(11111110),
    B8_2BIT(11211111),B8_2BIT(11211110),
    B8_2BIT(11211111),B8_2BIT(11121110),
    B8_2BIT(11211111),B8_2BIT(11112110),
    B8_2BIT(01121112),B8_2BIT(11111100),
    B8_2BIT(01111111),B8_2BIT(21111100),
    B8_2BIT(00111111),B8_2BIT(12111000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00000111),B8_2BIT(11000000),
    // Frame 5 done
    B8_2BIT(00000111),B8_2BIT(11000000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00111222),B8_2BIT(22111000),
    B8_2BIT(01112111),B8_2BIT(11211100),
    B8_2BIT(01121111),B8_2BIT(11121100),
    B8_2BIT(11211111),B8_2BIT(11112110),
    B8_2BIT(11211111),B8_2BIT(11112110),
    B8_2BIT(11111111),B8_2BIT(11111110),
    B8_2BIT(11111111),B8_2BIT(11111110),
    B8_2BIT(11111211),B8_2BIT(12111110),
    B8_2BIT(01111211),B8_2BIT(12111100),
    B8_2BIT(01111211),B8_2BIT(12111100),
    B8_2BIT(00111111),B8_2BIT(11111000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00000111),B8_2BIT(11000000),
    // Frame 6 done
    B8_2BIT(00000111),B8_2BIT(11000000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00111222),B8_2BIT(21111000),
    B8_2BIT(01112111),B8_2BIT(12211100),
    B8_2BIT(01111111),B8_2BIT(11121100),
    B8_2BIT(11111111),B8_2BIT(11121110),
    B8_2BIT(11111111),B8_2BIT(11112110),
    B8_2BIT(11112111),B8_2BIT(11112110),
    B8_2BIT(11121111),B8_2BIT(11112110),
    B8_2BIT(11211111),B8_2BIT(11112110),
    B8_2BIT(01111112),B8_2BIT(11121100),
    B8_2BIT(01111121),B8_2BIT(11111100),
    B8_2BIT(00111211),B8_2BIT(11111000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00000111),B8_2BIT(11000000),
    // Frame 7 done
    B8_2BIT(00000111),B8_2BIT(11000000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00111111),B8_2BIT(22111000),
    B8_2BIT(01111111),B8_2BIT(11211100),
    B8_2BIT(01111111),B8_2BIT(11121100),
    B8_2BIT(11122211),B8_2BIT(11112110),
    B8_2BIT(11111111),B8_2BIT(11112110),
    B8_2BIT(11111111),B8_2BIT(11112110),
    B8_2BIT(11111111),B8_2BIT(11112110),
    B8_2BIT(11122211),B8_2BIT(11112110),
    B8_2BIT(01111111),B8_2BIT(11121100),
    B8_2BIT(01111111),B8_2BIT(11211100),
    B8_2BIT(00111111),B8_2BIT(22111000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00000111),B8_2BIT(11000000),
    // Frame 8 done
    B8_2BIT(00000111),B8_2BIT(11000000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00111211),B8_2BIT(11111000),
    B8_2BIT(01111121),B8_2BIT(11111100),
    B8_2BIT(01111112),B8_2BIT(11121100),
    B8_2BIT(11211111),B8_2BIT(11112110),
    B8_2BIT(11121111),B8_2BIT(11112110),
    B8_2BIT(11112111),B8_2BIT(11112110),
    B8_2BIT(11111111),B8_2BIT(11112110),
    B8_2BIT(11111111),B8_2BIT(11121110),
    B8_2BIT(01111111),B8_2BIT(11121100),
    B8_2BIT(01112111),B8_2BIT(12211100),
    B8_2BIT(00111222),B8_2BIT(21111000),
    B8_2BIT(00011111),B8_2BIT(11110000),
    B8_2BIT(00000111),B8_2BIT(11000000)};
    
  const uint8_t SpriteSmileyMask[30] = {
    B8_1BIT(00000111),B8_1BIT(11000000),
    B8_1BIT(00011111),B8_1BIT(11110000),
    B8_1BIT(00111111),B8_1BIT(11111000),
    B8_1BIT(11111111),B8_1BIT(11111110),
    B8_1BIT(11111111),B8_1BIT(11111110),
    B8_1BIT(11111111),B8_1BIT(11111110),
    B8_1BIT(11111111),B8_1BIT(11111110),
    B8_1BIT(11111111),B8_1BIT(11111110),
    B8_1BIT(11111111),B8_1BIT(11111110),
    B8_1BIT(11111111),B8_1BIT(11111110),
    B8_1BIT(11111111),B8_1BIT(11111110),
    B8_1BIT(11111111),B8_1BIT(11111110),
    B8_1BIT(11111111),B8_1BIT(11111110),
    B8_1BIT(00011111),B8_1BIT(11110000),
    B8_1BIT(00000111),B8_1BIT(11000000) };
  
  const struct CRGB SpriteSmileyCols[2] = { CRGB(255,255,0), CRGB(0,0,0) };

  const uint8_t SpriteInvaderData[32] = {
    // Frame 1
    B8_1BIT(00100000),B8_1BIT(10000000),
    B8_1BIT(00010001),B8_1BIT(00000000),
    B8_1BIT(00111111),B8_1BIT(10000000),
    B8_1BIT(01101110),B8_1BIT(11000000),
    B8_1BIT(11111111),B8_1BIT(11100000),
    B8_1BIT(10111111),B8_1BIT(10100000),
    B8_1BIT(10100000),B8_1BIT(10100000),
    B8_1BIT(00011011),B8_1BIT(00000000),
    // Frame 2
    B8_1BIT(00100000),B8_1BIT(10000000),
    B8_1BIT(00010001),B8_1BIT(00000000),
    B8_1BIT(10111111),B8_1BIT(10100000),
    B8_1BIT(11101110),B8_1BIT(11100000),
    B8_1BIT(11111111),B8_1BIT(11100000),
    B8_1BIT(01111111),B8_1BIT(11000000),
    B8_1BIT(00100000),B8_1BIT(10000000),
    B8_1BIT(01000000),B8_1BIT(01000000) };
  const uint8_t SpriteInvaderMask[32] = {
    B8_1BIT(00100000),B8_1BIT(10000000),
    B8_1BIT(00010001),B8_1BIT(00000000),
    B8_1BIT(00111111),B8_1BIT(10000000),
    B8_1BIT(01101110),B8_1BIT(11000000),
    B8_1BIT(11111111),B8_1BIT(11100000),
    B8_1BIT(10111111),B8_1BIT(10100000),
    B8_1BIT(10100000),B8_1BIT(10100000),
    B8_1BIT(00011011),B8_1BIT(00000000),
    // Frame 2
    B8_1BIT(00100000),B8_1BIT(10000000),
    B8_1BIT(00010001),B8_1BIT(00000000),
    B8_1BIT(10111111),B8_1BIT(10100000),
    B8_1BIT(11101110),B8_1BIT(11100000),
    B8_1BIT(11111111),B8_1BIT(11100000),
    B8_1BIT(01111111),B8_1BIT(11000000),
    B8_1BIT(00100000),B8_1BIT(10000000),
    B8_1BIT(01000000),B8_1BIT(01000000) };

  struct CRGB SpriteInvaderCols[1] = { CRGB(0,0,0) };

  const uint8_t Spriteinvader3Data[32] = {
    // Frame 2
    B8_1BIT(00001111),B8_1BIT(00000000),
    B8_1BIT(01111111),B8_1BIT(11100000),
    B8_1BIT(11111111),B8_1BIT(11110000),
    B8_1BIT(11100110),B8_1BIT(01110000),
    B8_1BIT(11111111),B8_1BIT(11110000),
    B8_1BIT(00011001),B8_1BIT(10000000),
    B8_1BIT(00110110),B8_1BIT(11000000),
    B8_1BIT(11000000),B8_1BIT(00110000),
    // Frame 2
    B8_1BIT(00001111),B8_1BIT(00000000),
    B8_1BIT(01111111),B8_1BIT(11100000),
    B8_1BIT(11111111),B8_1BIT(11110000),
    B8_1BIT(11100110),B8_1BIT(01110000),
    B8_1BIT(11111111),B8_1BIT(11110000),
    B8_1BIT(00111001),B8_1BIT(11000000),
    B8_1BIT(01100110),B8_1BIT(01100000),
    B8_1BIT(00110000),B8_1BIT(11000000) };
  const uint8_t Spriteinvader3Mask[32] = {
    B8_1BIT(00100000),B8_1BIT(10000000),
    B8_1BIT(00010001),B8_1BIT(00000000),
    B8_1BIT(00111111),B8_1BIT(10000000),
    B8_1BIT(01101110),B8_1BIT(11000000),
    B8_1BIT(11111111),B8_1BIT(11100000),
    B8_1BIT(10111111),B8_1BIT(10100000),
    B8_1BIT(10100000),B8_1BIT(10100000),
    B8_1BIT(00011011),B8_1BIT(00000000),
    // Frame 2
    B8_1BIT(00100000),B8_1BIT(10000000),
    B8_1BIT(00010001),B8_1BIT(00000000),
    B8_1BIT(10111111),B8_1BIT(10100000),
    B8_1BIT(11101110),B8_1BIT(11100000),
    B8_1BIT(11111111),B8_1BIT(11100000),
    B8_1BIT(01111111),B8_1BIT(11000000),
    B8_1BIT(00100000),B8_1BIT(10000000),
    B8_1BIT(01000000),B8_1BIT(01000000) };
  
  struct CRGB Spriteinvader3Cols[1] = { CRGB(255,255,255) };

  uint8_t rectHue = 0;
  uint8_t seconds = 0;
  uint8_t secondsTrigger = 0;
  
  cLEDSprites Sprites;
  cSprite sprSmiley;
  cSprite sprInvader;
  cSprite sprInvader3;
  cSprite sprAlien;

  uint16_t steper = random8(2, 8);
  uint8_t h = random(64);
  uint8_t sprite = 4;
  uint8_t background = 0;

  uint16_t PlasmaTime, PlasmaShift;
  uint8_t plasmaLowHue, plasmaHighHue, plasmaBrightness;

  public:
  Pixel():Sprites(&leds){};

  void setup(){
    PlasmaShift = (random8(0, 5) * 32) + 64;
    PlasmaTime = 0;
    plasmaLowHue = 100;
    plasmaHighHue = 150;
    plasmaBrightness = 200;
    //setupSmiley();
    setupAlien();
    FastLED.clear();
  }

  boolean loop(){
    
    
    EVERY_N_MILLISECONDS(100) {
      // Cycle plasma colour
      plasmaLowHue++;
      plasmaHighHue++;
    }

    EVERY_N_SECONDS(1) {
      seconds++;
    }

    if(seconds % 13 == 0 && secondsTrigger != seconds) {
      secondsTrigger = seconds;
      background = ++background % 4;
    }

    switch (background) {
      case 0:
        corner();
        break;
      case 1:
        square();
        break;
      case 2:
        squares();
        break;
      case 3:
        plasma();
        break;
    }
    
    if(seconds % 5 == 0 && secondsTrigger != seconds) {
      secondsTrigger = seconds;
      Sprites.RemoveAllSprites();
      sprite = ++sprite % 6;
      switch (sprite){
        case 0:
          setupSmiley();
          break;
        case 1:
          // Do nothing
          break;
        case 2:
          setupInvader();
          setupInvader3();
          break;
        case 3:
          // Do nothing
          break;
        case 4:
          setupAlien();
          break;
        case 5:
          // Do nothing
          break;
      }
    }

    if (SerialBT.available()) {
      char keyPress = (char)SerialBT.read();
      switch(keyPress) {
        case 'm':
          currentApp = -1;
          return false;
      }
    }

    plasmaBrightness = 200;

    switch (sprite) {
      case 0:   // Rolling acid smiley
        if(sprSmiley.m_X > leds.Width()) {
          sprSmiley.m_X = -15;
        }
        break;
      case 2:   //Invaders
        background = 3;
        plasmaBrightness = 60;
        break;
      case 4:   // Alien face
        background = 2;
        break;
    }

    Sprites.UpdateSprites();
    Sprites.RenderSprites();

    FastLED.show();

    return true;
  }

  private:

  void setupAlien() {
    sprAlien.Setup(16, 16, SpritealienData, 1, _2BIT, SpritealienCols, SpritealienMask);
    sprAlien.SetPosition(0,0);
    sprAlien.SetFrame(0,0);
    sprAlien.SetMotion(0,15,0,0);
    Sprites.AddSprite(&sprAlien);
  }

  void setupSmiley() {
    sprSmiley.Setup(15, 15, SpriteSmileyData, 8, _2BIT, SpriteSmileyCols, SpriteSmileyMask);
    sprSmiley.SetPosition(-15,0);
    sprSmiley.SetFrame(0,30); 
    sprSmiley.SetMotion(1,15,0,0);
    Sprites.AddSprite(&sprSmiley);
  }

  void setupInvader() {
    SpriteInvaderCols[0] = CRGB(random8(),random8(),random8());
    sprInvader.Setup(11, 8, SpriteInvaderData, 2, _1BIT, SpriteInvaderCols, SpriteInvaderMask);
    sprInvader.SetPosition(random8(0,5),random8(0,8));
    sprInvader.SetFrame(0,20); 
    sprInvader.SetMotion(1,15,1,15);
    sprInvader.SetOptions(SPRITE_DETECT_EDGE | SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN );
    Sprites.AddSprite(&sprInvader);
  }

  void setupInvader3() {
    Spriteinvader3Cols[0] = CRGB(random8(),random8(),random8());
    sprInvader3.Setup(12, 8, Spriteinvader3Data, 1, _1BIT, Spriteinvader3Cols, Spriteinvader3Mask);
    sprInvader3.SetPosition(random8(0,5),random8(0,8));
    sprInvader3.SetFrame(0,15); 
    sprInvader3.SetMotion(-1,15,-1,15);
    sprInvader3.SetOptions(SPRITE_DETECT_EDGE | SPRITE_X_KEEPIN | SPRITE_Y_KEEPIN );
    Sprites.AddSprite(&sprInvader3);
  }

  void corner() {
    leds.DrawFilledRectangle(0 , 0,  leds.Width(), leds.Height(), CHSV(h, 255, 255));
    h += steper;
  
    for (uint16_t y = 0; y <= leds.Width() / 2 - 1 ; y++)
    {
      leds.DrawFilledCircle(leds.Width() / 2, leds.Height() / 2, (leds.Width() / 2 + 1 - y) / 3, CHSV(h  + y * steper, 255, 255));
      leds.DrawFilledCircle(0, 0, leds.Width() / 2 - y, CHSV(64 + h + y * steper, 255, 255));
      leds.DrawFilledCircle(0, leds.Height() - 1, leds.Width() / 2 - y, CHSV(h - 64 + y * steper, 255, 255));
      leds.DrawFilledCircle(leds.Width()  - 1, 0, leds.Width() / 2 - y, CHSV(h - 64 + y * steper, 255, 255));
      leds.DrawFilledCircle(leds.Width()  - 1, leds.Height() - 1, leds.Width() / 2 - y, CHSV(h + 64 + y * steper, 255, 255));
    }
  }

  void square() {
    for (uint8_t i = 0; i <= leds.Width(); i++) {
      leds.DrawRectangle(i,i,leds.Width() - 1 - i, leds.Height() - 1 - i, CHSV(rectHue + (i*30),255,255));
    }
    rectHue++;
  }

  void squares() {
    //Bottom left
    for (uint8_t i = 0; i <= 7; i++) {
      leds.DrawRectangle(i,i, 6 - i, 6 - i, CHSV(rectHue + (i*15),255,255));
    }
    //Bottom right
    for (uint8_t i = 0; i <= 7; i++) {
      leds.DrawRectangle(i+9,i, 15 - i, 6 - i, CHSV(rectHue + (i*15),255,255));
    }
    // Top left
    for (uint8_t i = 0; i <= 7; i++) {
      leds.DrawRectangle(i,i+9, 6 - i, 15 - i, CHSV(rectHue + (i*15),255,255));
    }
    // Top right
    for (uint8_t i = 0; i <= 7; i++) {
      leds.DrawRectangle(i+9,i+9, 15 - i, 15 - i, CHSV(rectHue + (i*15),255,255));
    }
    rectHue++;
  }

  void plasma() {
    // Fill background with dim plasma
    #define PLASMA_X_FACTOR  24
    #define PLASMA_Y_FACTOR  24
    for (int16_t x=0; x<leds.Width(); x++)
    {
      for (int16_t y=0; y<leds.Height(); y++)
      {
        int16_t r = sin16(PlasmaTime) / 256;
        int16_t h = sin16(x * r * PLASMA_X_FACTOR + PlasmaTime) + cos16(y * (-r) * PLASMA_Y_FACTOR + PlasmaTime) + sin16(y * x * (cos16(-PlasmaTime) / 256) / 2);
        leds(x, y) = CHSV((uint8_t)((h / 256) + 128), 255, plasmaBrightness);
      }
    }
    uint16_t OldPlasmaTime = PlasmaTime;
    PlasmaTime += PlasmaShift;
    if (OldPlasmaTime > PlasmaTime)
      PlasmaShift = (random8(0, 5) * 32) + 64;
  }
  
};
