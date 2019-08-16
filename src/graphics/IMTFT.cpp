#include "IMTFT.h"

IMTFT::IMTFT(Language locale) : locale(locale) {}

bool IMTFT::init() {
  tft.InitLCD();
  tft.setFont(NULL);
  tft.setTextSize(2);
  return true;
}

void IMTFT::setColor(uint32_t color) {
  byte r, g, b;

  r = (color & 0xFF0000) >> 16;
  g = (color & 0xFF00) >> 8;
  b = color & 0xFF;

  tft.setColor(r, g, b);
}

void IMTFT::setColor(uint16_t color) {
  tft.setColor(color);
}

void IMTFT::paintBackground(uint16_t color) {
  tft.fillScreen(color);
}

void IMTFT::paintBackground() {
  paintBackground(BACKGROUND_COLOR);
}

void IMTFT::drawLine(int x1, int y1, int x2, int y2) {
  tft.drawLine(x1, SCR_HEIGHT - y1, x2, SCR_HEIGHT - y2);
}

void IMTFT::drawCircle(int x0, int y0, int r) {
  tft.drawCircle(x0, SCR_HEIGHT - y0, r);
}

void IMTFT::fillRect(IMRect r) {
  fillRect(r.getXLo(), r.getYLo(), r.getXHi(), r.getYHi());
}

void IMTFT::fillRect(int x1, int y1, int x2, int y2) {
  tft.fillRect(x1, SCR_HEIGHT - y1, x2, SCR_HEIGHT - y2);
}

void IMTFT::fillCircle(int x0, int y0, int r) {
  tft.fillCircle(x0, SCR_HEIGHT - y0, r);
}

void IMTFT::print(String text, int textSize, uint16_t color, int x, int y) {
  tft.setTextColor(color);
  tft.setTextSize(textSize);
  tft.print(text, x, SCR_HEIGHT - y);
}

int getNonLetterCount(String text) {
  int count = 0;
  int len = text.length();

  for (uint8_t i = 0; i < len; i++) {
    switch(text.charAt(i)) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case ' ':
      case '%':
      case ':':
      case '˚':
      case '/':
        count += 1;
        break;
    }
  }
  return count;
}

void IMTFT::print(String text, int textSize, uint16_t color, IMRect r) {
  uint16_t textWidth = text.length();
  uint16_t textHeight = HEIGHT_MULT * textSize;
  int x = r.getXLo();
  int y = r.getYLo();
  
  if (locale == Language::RUSSIAN) {
    int symCount = getNonLetterCount(text);

    textWidth -= symCount;
    textWidth /= 2;
    textWidth += symCount;
  }
  textWidth *= WIDTH_MULT * textSize;
  x += (r.getWidth() - textWidth) / 2;
  y += (r.getHeight() + textHeight) / 2;
  
  tft.setFont(NULL);
  print(text, textSize, color, x, y);
}

void IMTFT::printNum(String num, IMRect r) {
  print(num, NUM_FONT_SIZE, MAIN_COLOR, r);
}
