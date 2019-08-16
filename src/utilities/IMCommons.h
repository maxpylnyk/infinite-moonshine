#ifndef IM_COMMONS_H
#define IM_COMMONS_H

#include <stdint.h>

#define FLOAT_PRECISION  3

#define NANO_RST_PIN   A7
#define ALC_HEAT_PIN   A10
#define ALC_DATA_PIN   A11
#define HLVL_OUT_PIN   A12
#define HLVL_LO_PIN    A13
#define HLVL_HI_PIN    A14
#define HLVL_OVR_PIN   A15
const int SD_CS_PIN     = 10;
const int MTR1_1_PIN    = 22;
const int MTR1_2_PIN    = 23;
const int MTR1_3_PIN    = 24;
const int MTR1_4_PIN    = 25;
const int MTR2_1_PIN    = 26;
const int MTR2_2_PIN    = 27;
const int MTR2_3_PIN    = 28;
const int MTR2_4_PIN    = 29;
const int MTR3_1_PIN    = 30;
const int MTR3_2_PIN    = 31;
const int MTR3_3_PIN    = 32;
const int MTR3_4_PIN    = 33;
const int MTR4_1_PIN    = 34;
const int MTR4_2_PIN    = 35;
const int MTR4_3_PIN    = 36;
const int MTR4_4_PIN    = 37;
const int MEGA_RST_PIN  = 43;
const int SSR_PIN       = 45;
const int TRM_PIN       = 47;

const int HEIGHT_MULT = 7;
const int WIDTH_MULT = 6;
const int TEXT1_HEIGHT = HEIGHT_MULT;
const int TEXT2_HEIGHT = HEIGHT_MULT * 2;
const int PLAIN_FONT_SIZE = 2;
const int NUM_FONT_SIZE = 6;
const int LBL_FONT_SIZE = 1;
const int DATA_FONT_SIZE = 3;
const int ERR_FONT_SIZE = 1;
const int HDR_FONT_SIZE = 3;
const int SCR_HEIGHT = 240;
const int SCR_WIDTH = 320;
const int BAR_HEIGHT = 42;
const int DASH_SLOT_HEIGHT = (SCR_HEIGHT - 2 * BAR_HEIGHT) / 2;
const int DASH_SLOT_WIDTH = SCR_WIDTH / 3;
const int DASH_LBL_HEIGHT = TEXT2_HEIGHT;
const int DASH_DATA_HEIGHT = DASH_SLOT_HEIGHT - DASH_LBL_HEIGHT;

const uint16_t MAIN_COLOR        = 0x97fc;
const uint16_t MAIN_COLOR_FLAT   = 0x3b4c;
const uint16_t HEAT_COLOR        = 0xffa0;
const uint16_t STAB_COLOR        = 0xfba0;
const uint16_t HEAD_COLOR        = 0xf800;
const uint16_t AROMA_COLOR       = 0xf81f;
const uint16_t BODY_COLOR        = 0xffff;
const uint16_t TAIL_COLOR        = 0x045f;
const uint16_t BACKGROUND_COLOR  = 0x0000;

const uint16_t TEXT_COLOR        = MAIN_COLOR;
const uint16_t ERROR_COLOR       = STAB_COLOR;

typedef enum Panes : uint8_t {
  INIT = 0,
  ERROR,
  FRONT,
  DASH1,
  DASH2,
  DASH3,
  LOG,
  PREF,
  PLOT
};

typedef enum LogIndex : uint8_t {
  SESSION_NAME = 1,
  STATE,
  PAUSE,
  HYDRO_LEVEL,
  ALC_LEVEL,
  STEAM_TEMP,
  TABLE_TEMP,
  COND_TEMP,
  PIPE_TEMP,
  ENV_TEMP,
  PRESSURE,
  COND_MTR,
  COND_MTR_ADJ,
  SW,
  HEAT,
  HEAT_ADJ,
  RF,
  OUT_MTR,
  RET_MTR,
  EXT_ADJ,
  ERROR_CODES
};

typedef enum SrcType : uint8_t {
  SUGAR = 0,
  GRAIN,
  GRAPE,
  APPLE,
  APRICOT,
  PEACH,
  PLUM,
  CHERRY
};

typedef enum Pause : uint8_t {
  RESUME = 0,
  CONTROL,
  MANUAL
};

typedef enum Board : uint8_t {
  MEGA = 0,
  NANO
};

typedef enum Language : uint8_t {
  ENGLISH = 0,
  RUSSIAN
};

#endif
