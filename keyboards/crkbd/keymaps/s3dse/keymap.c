#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
// #define _QWERTY 0
// #define _LOWER 1
// #define _RAISE 2
// #define _ADJUST 3

enum layer_number {
  _WORKMAN = 0,
  _SYMLEFT,
  _SYMRIGHT,
  _NUMRIGHT,
  _NAV,
  _UMLAUT,
  _EDIT,
  _MEDIA,
  //_GAME,
  _QWERTY,
};

enum custom_keycodes {
  ST_MACRO_0 = SAFE_RANGE,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  MC_SEL_ALL,
  ST_MACRO_16,
  MC_EXP_SEL,
  ST_MACRO_18,
  ST_MACRO_19,
  MC_SHR_SEL,
  ST_MACRO_21,
  ST_MACRO_22,
  ST_MACRO_23,
  ST_MACRO_24,
  ST_MACRO_25,
  ST_MACRO_26,
  MCR_UML_A_UP,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_WORKMAN] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  MO(5), KC_Q, KC_D, KC_R, KC_W, LT(4, KC_B),                                       KC_J,    KC_F,        KC_U,      KC_P, KC_SCOLON,     MO(5), \
  KC_LGUI, LGUI_T(KC_A), KC_S, KC_H, LT(2,KC_T), LT(3,KC_G),                     LT(7,KC_Y), LT(1,KC_N),    KC_E,      KC_O, RGUI_T(KC_I),  TG(8), \
  MO(6),   LCTL_T(KC_Z),   LALT_T(KC_X),   KC_M,    KC_C, KC_V,         KC_K,    KC_L,       KC_COMMA,  RALT_T(KC_DOT),  RCTL_T(KC_SLASH),   MO(6), \
                        KC_DELETE, LSFT_T(KC_SPACE), KC_BSPACE,              KC_TAB,   RSFT_T(KC_ENTER), KC_ESCAPE \
                                      //`--------------------------'  `--------------------------'
  ),
  [_SYMLEFT] = LAYOUT( \
  _______, KC_EXLM,        KC_AT,          KC_LPRN,        KC_RPRN,        KC_PIPE,                     _______, _______, _______,_______, _______, _______,\
  _______, KC_HASH,        KC_DLR,         KC_LBRACKET,    KC_RBRACKET,    KC_GRAVE,                    _______, XXXXXXX, _______,_______, _______, _______,\
  _______, KC_PERC,        KC_CIRC,        KC_SCOLON,      KC_COLN,        KC_TILD,                     _______, _______, _______,_______, _______, _______,\
                            _______, _______, _______, _______,  _______, _______ \
),
[_SYMRIGHT] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   KC_MINUS,    KC_EQUAL,    KC_LABK,    KC_RABK,    KC_ASTR,    _______, \
  _______, _______, _______, _______, XXXXXXX, _______,                   KC_UNDS, KC_LCBR, KC_RCBR, ST_MACRO_25,   KC_PLUS, _______, \
  _______, _______, _______, _______, _______, _______,                   KC_AMPR, KC_QUOTE, KC_DQUO,  ST_MACRO_26, KC_BSLASH, _______, \
                             _______, _______,  _______,                  _______,  _______, _______ \
),
[_NUMRIGHT] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, KC_7, KC_8, KC_9, KC_COMMA, _______, \
  _______, _______, _______, _______, _______, XXXXXXX,                   _______, KC_4, KC_5, KC_6, KC_0, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, KC_1, KC_2, KC_3, KC_DOT, _______,\
                            _______, _______, _______,                    _______,  _______, _______ \
),
[_NAV] = LAYOUT( \
  _______, _______, _______, _______, _______, XXXXXXX,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   KC_HOME, ST_MACRO_2, ST_MACRO_3, KC_END, _______, _______,\
                             _______, _______, _______,                   _______, _______, _______ \
  ),
[_UMLAUT] = LAYOUT( \
  XXXXXXX, MCR_UML_A_UP, _______, _______, _______, _______,              _______, _______, ST_MACRO_6, ST_MACRO_7, _______, XXXXXXX, \
  _______, ST_MACRO_4, ST_MACRO_5, _______, _______, _______,             _______, _______, ST_MACRO_8, ST_MACRO_9, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
                             _______, _______, _______,                   _______, _______, _______ \
  ),
  [_EDIT] = LAYOUT( \
  _______, _______, _______, ST_MACRO_10, _______, _______,               MC_SEL_ALL, ST_MACRO_16, _______, _______, _______, _______, \
  _______, _______, ST_MACRO_11, ST_MACRO_12, ST_MACRO_13, ST_MACRO_14,   MC_EXP_SEL, ST_MACRO_18, ST_MACRO_19, _______, _______, _______, \
  XXXXXXX, _______, _______, _______, _______, _______,                   MC_SHR_SEL, ST_MACRO_21, ST_MACRO_22, _______, _______, XXXXXXX,\
                             _______, _______, _______,                   _______,  _______, _______ \
  ),

  [_MEDIA] = LAYOUT( \
  _______, KC_MS_ACCEL2, _______,    KC_MS_UP,   _______,     _______,                                _______, _______, _______, _______, _______, _______, \
  _______, KC_MS_ACCEL1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,                                XXXXXXX, KC_BRIU, KC_BRID, _______, KC_HYPR, KC_MEDIA_PLAY_PAUSE, \
  _______, KC_MS_ACCEL0, _______,    _______,    _______,     _______,                                _______, _______, _______, _______, _______, _______,\
                                 KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_BTN1,                              KC_MS_BTN2, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN \
  ),
  [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LSFT, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, \
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                        KC_LGUI, KC_SPC, KC_BSPC,                       KC_TAB, KC_ENTER, KC_LALT \
),

};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

static bool shifted = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_SPACE)));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_SPACE))));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_DELAY(100) SS_TAP(X_A));

    }
    break;
    case MCR_UML_A_UP:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_LSFT(SS_TAP(X_A)));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_S)));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_DELAY(100) SS_LSFT(SS_TAP(X_U)));

    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_DELAY(100) SS_LSFT(SS_TAP(X_O)));

    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_DELAY(100) SS_TAP(X_U));

    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_DELAY(100) SS_TAP(X_O));

    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_T))));

    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LGUI(SS_LSFT(SS_TAP(X_LEFT)))));

    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LGUI(SS_LSFT(SS_TAP(X_DOWN)))));

    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LGUI(SS_LSFT(SS_TAP(X_UP)))));

    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LGUI(SS_LSFT(SS_TAP(X_RIGHT)))));

    }
    break;
    case MC_SEL_ALL:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_F2)));

    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_F))));

    }
    break;
    case MC_EXP_SEL:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_RIGHT))));

    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_UP)));

    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_UP))));

    }
    break;
    case MC_SHR_SEL:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))));

    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_DOWN)));

    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_DOWN))));

    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING("ment");
    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING("ion");
    }
    break;
    case LSFT_T(KC_SPACE):
      shifted = record->event.pressed;
      return true;
      break;
    case RSFT_T(KC_SPACE):
      shifted = record->event.pressed;
      return true;
      break;
    case ST_MACRO_25:
      
      if (record->event.pressed) {
        if (shifted) {

          unregister_code16(LSFT_T(KC_SPACE));
          unregister_code16(RSFT_T(KC_SPACE));
          SEND_STRING("<-");
        } else {
          SEND_STRING("->");
        }

      }
    break;
    case ST_MACRO_26:
      if (record->event.pressed) {
        if (shifted) {
          unregister_code16(LSFT_T(KC_SPACE));
          unregister_code16(RSFT_T(KC_SPACE));
          SEND_STRING("<=");
        } else {
          SEND_STRING("=>");
        }
      }
    break;
  }


  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return TAPPING_TERM + 500;
        case RGUI_T(KC_I):
            return TAPPING_TERM + 500;
        case LT(4, KC_T):
            return TAPPING_TERM - 50;
        case LT(3, KC_N):
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}
