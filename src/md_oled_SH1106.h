#ifndef _MD_OLED_SH1106_H_
  #define _MD_OLED_SH1106_H_

  #include <Arduino.h>
  #include <md_defines.h>
  #include <md_util.h>

  //#ifdef USE_OLED
    #include <Wire.h>               // Only needed for Arduino 1.6.5 and earlier
    #include "SH1106Wire.h"        // legacy: #include "SSD1306.h"
//    #include <SSD1306Wire.h>        // legacy: #include "SSD1306.h"

                       //#include <U8g2lib.h>
    //#include <Draht.h>

    // --- declarations
      const char COPYRIGHT_SYMBOL[] = {0xa9, '\0'};

    // --- test bitmap
      #ifdef RUN_OLED_TEST
        #define image_width 128
        #define image_height 21
        static const unsigned char image_bits[] U8X8_PROGMEM =
          {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x1f, 0x00, 0x00,
            0xfc, 0x1f, 0x00, 0x00, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0xfe, 0x1f, 0x00, 0x00, 0xfc, 0x7f, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x07, 0x18, 0x00, 0x00, 0x0c, 0x60, 0x00, 0x00,
            0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x18, 0x00, 0x00,
            0x0c, 0xc0, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x03, 0x18, 0x00, 0x00, 0x0c, 0xc0, 0xf0, 0x1f, 0x06, 0x63, 0x80, 0xf1,
            0x1f, 0xfc, 0x33, 0xc0, 0x03, 0x18, 0x00, 0x00, 0x0c, 0xc0, 0xf8, 0x3f,
            0x06, 0x63, 0xc0, 0xf9, 0x3f, 0xfe, 0x33, 0xc0, 0x03, 0x18, 0x00, 0x00,
            0x0c, 0xc0, 0x18, 0x30, 0x06, 0x63, 0xc0, 0x18, 0x30, 0x06, 0x30, 0xc0,
            0xff, 0xff, 0xdf, 0xff, 0x0c, 0xc0, 0x18, 0x30, 0x06, 0x63, 0xe0, 0x18,
            0x30, 0x06, 0x30, 0xc0, 0xff, 0xff, 0xdf, 0xff, 0x0c, 0xc0, 0x98, 0x3f,
            0x06, 0x63, 0x60, 0x98, 0x3f, 0x06, 0x30, 0xc0, 0x03, 0x18, 0x0c, 0x00,
            0x0c, 0xc0, 0x98, 0x1f, 0x06, 0x63, 0x70, 0x98, 0x1f, 0x06, 0x30, 0xc0,
            0x03, 0x18, 0x06, 0x00, 0x0c, 0xc0, 0x18, 0x00, 0x06, 0x63, 0x38, 0x18,
            0x00, 0x06, 0x30, 0xc0, 0x03, 0x18, 0x03, 0x00, 0x0c, 0xe0, 0x18, 0x00,
            0x06, 0x63, 0x1c, 0x18, 0x00, 0x06, 0x30, 0xc0, 0x00, 0x80, 0x01, 0x00,
            0xfc, 0x7f, 0xf8, 0x07, 0x1e, 0xe3, 0x0f, 0xf8, 0x07, 0x06, 0xf0, 0xcf,
            0x00, 0xc0, 0x00, 0x00, 0xfc, 0x3f, 0xf0, 0x07, 0x1c, 0xe3, 0x07, 0xf0,
            0x07, 0x06, 0xe0, 0xcf, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x30, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
            0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0xe0, 0x00, 0xfc, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0xfc, 0x1f, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f
          };
      #endif // RUN_OLED_TEST

    #define _MD_OLED_MAX_ROWS 6
    #define _MD_OLED_MAX_COLS 30
    class md_oled_1106: public SH1106Wire
    {
      private:
        msTimer  _clrT      = msTimer();
        bool     _isStatus  = false; // status text visible
        //char     _outTxt[_MD_OLED_MAX_ROWS][_MD_OLED_MAX_COLS];
        String   _outStr[_MD_OLED_MAX_ROWS];
        //char     _statTxt[_MD_OLED_MAX_COLS];
        String   _statStr;
        uint8_t  _wfont     = 8;
        uint8_t  _hfont     = 10;
        void*    _oled      = NULL;
        uint8_t  _rows      = 1;
        uint8_t  _cols      = 1;
        uint8_t  _statRow   = 1;
        uint8_t  _len       = 0;

      public:
        md_oled_1106(uint8_t address, uint8_t sda, uint8_t scl, OLEDDISPLAY_GEOMETRY g)
            : SH1106Wire(address, sda, scl, g) {}

        bool begin(uint8_t cols, uint8_t rows);
        void clear();
        void drawCircle(void);
          /*
              void drawStr    (u8g2_uint_t x, u8g2_uint_t y, const char *s);
              void drawFrame  (u8g2_uint_t x, u8g2_uint_t w,u8g2_uint_t h, u8g2_uint_t y);
              void drawRFrame (u8g2_uint_t x, u8g2_uint_t w,u8g2_uint_t h, u8g2_uint_t y, u8g2_uint_t r);
              void drawBox    (u8g2_uint_t x, u8g2_uint_t w,u8g2_uint_t h, u8g2_uint_t y);
              void drawRBox   (u8g2_uint_t x, u8g2_uint_t w,u8g2_uint_t h, u8g2_uint_t y, u8g2_uint_t r);
              void drawDisc   (u8g2_uint_t x0, u8g2_uint_t y0, u8g2_uint_t rad);
              void drawArcDisc(u8g2_uint_t x0, u8g2_uint_t y0, u8g2_uint_t rad, u8g2_uint_t part); // quarter Disc z.B. U8G2_DRAW_UPPER_RIGHT
              void drawCircle (u8g2_uint_t x0, u8g2_uint_t y0, u8g2_uint_t rad);
              void drawArcCirc(u8g2_uint_t x0, u8g2_uint_t y0, u8g2_uint_t rad, u8g2_uint_t part); // quarter Disc z.B. U8G2_DRAW_UPPER_RIGHT
              void drawLine   (u8g2_uint_t x1, u8g2_uint_t y1, u8g2_uint_t x2, u8g2_uint_t y2);
              void drawTriang (u8g2_uint_t x1, u8g2_uint_t y1, u8g2_uint_t x2, u8g2_uint_t y2, u8g2_uint_t x3, u8g2_uint_t y3);
              void drawBitmap (u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t w, u8g2_uint_t h, const uint8_t *bitmap);
            */
        bool wrText     (String msg, uint8_t spalte, uint8_t zeile, uint8_t len); // write to text area
        void wrStatus   (const char* msg);
        void wrStatus   (String msg);
        #ifdef RUN_OLED_TEST
          void box_frame();
          void r_frame_box();
          void disc_circle();
          void string_orientation();
          void line();
          void triangle();
          void bitmap();
        #endif

      protected:
        /*
        void sendBuffer ();
        void prepare    ();
        */

    };

    //extern md_oled oled;

  //#endif // USE_OLED
#endif // _MD_OLED_H_