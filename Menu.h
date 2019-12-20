class Menu {
  cLEDText ScrollingMsg;
  unsigned char txtMenu[12];
  int menuItem;
  
  public:
  Menu(){
    menuItem = 0;  
  };

  void setup() {
    sprintf((char *)txtMenu, "           ");
    ScrollingMsg.SetFont(MatriseFontData);
    ScrollingMsg.Init(&leds, leds.Width(), ScrollingMsg.FontHeight() + 1, 0, 5);
    ScrollingMsg.SetBackgroundMode(BACKGND_ERASE);
    ScrollingMsg.SetScrollDirection(SCROLL_LEFT);
    ScrollingMsg.SetFrameRate(5);
    ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0xff, 0x00, 0xff);
    FastLED.clear();
    
    menuChanged(0);
  }

  boolean loop() {
    // Rainbow background
    uint32_t ms = millis();
    int32_t yHueDelta32 = ((int32_t)cos16( ms * 27 ) * (350 / leds.Width()));
    int32_t xHueDelta32 = ((int32_t)cos16( ms * 39 ) * (310 / leds.Height()));
    DrawOneFrame( ms / 65536, yHueDelta32 / 32768, xHueDelta32 / 32768);

    //Black bar behind text
    for (int i = 48; i<191; i++) {
      leds(i) = CRGB::Black;
    }
    
    displayMenu();
        
    if(SerialBT.available()){
        char keyPress = (char)SerialBT.read();
        switch(keyPress) {
          case 'a':
            if(--menuItem < 0 ) menuItem = 2;
            menuChanged(menuItem);
            break;
          case 'd':
            menuItem = ++menuItem % 4;
            menuChanged(menuItem);
            break;
          case 'r':
          case 'y':
          case 'g':
          case 'b':
            currentApp = menuItem;
            return false;
        }
    }
    return true;
  }

  void DrawOneFrame( byte startHue8, int8_t yHueDelta8, int8_t xHueDelta8)
  {
    byte lineStartHue = startHue8;
    for( byte y = 0; y < leds.Height(); y++) {
      lineStartHue += yHueDelta8;
      byte pixelHue = lineStartHue;      
      for( byte x = 0; x < leds.Width(); x++) {
        pixelHue += xHueDelta8;
        leds(x, y)  = CHSV( pixelHue, 255, 255);
      }
    }
  }

  private:
  void menuChanged(int menuItem) {
    switch (menuItem) {
      case 0:
        //Tetris highlighted
        sprintf((char *)txtMenu, "    TETRIS ");
        break;
      case 1:
        //Snake highlighted
        sprintf((char *)txtMenu, "     SNAKE ");
        break;
      case 2:
        //Breakout highlighted
        sprintf((char *)txtMenu, "  BREAKOUT ");
        break;
      case 3:
        //Animation highlighted
        sprintf((char *)txtMenu, " PIXEL ART ");
        break;
    }
    ScrollingMsg.SetText((unsigned char *)txtMenu, sizeof(txtMenu)-1);
  }
  
  void displayMenu() {
    if(ScrollingMsg.UpdateText() == -1)
      ScrollingMsg.SetText((unsigned char *)txtMenu, sizeof(txtMenu)-1);
    else
      FastLED.show();
  }
  
};
