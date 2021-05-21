#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

#ifdef OLED_DRIVER_ENABLE
static uint32_t oled_timer = 0;
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
  _FN,
  _RGB,
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
  KC_LGUI, LGUI_T(KC_A), KC_S, KC_H, LT(2,KC_T), LT(3,KC_G),                     LT(7,KC_Y), LT(1,KC_N),    KC_E,      KC_O, RGUI_T(KC_I),  TG(_QWERTY), \
  MO(6),   LCTL_T(KC_Z),   LALT_T(KC_X),   KC_M,    KC_C, KC_V,         KC_K,    KC_L,       KC_COMMA,  LALT_T(KC_DOT),  RCTL_T(KC_SLASH),   MO(6), \
                        KC_DELETE, LSFT_T(KC_SPACE), KC_BSPACE,              LT(_FN, KC_TAB),   RSFT_T(KC_ENTER), LT(_RGB, KC_ESCAPE) \
                                      //`--------------------------'  `--------------------------'
  ),
  [_SYMLEFT] = LAYOUT( \
  _______, KC_EXLM,        KC_AT,          KC_LPRN,        KC_RPRN,        KC_PIPE,                     _______, _______, _______,_______, _______, RESET,\
  _______, KC_HASH,        KC_DLR,         KC_LBRACKET,    KC_RBRACKET,    KC_GRAVE,                    _______, XXXXXXX, _______,_______, _______, _______,\
  _______, KC_PERC,        KC_CIRC,        KC_SCOLON,      KC_COLN,        KC_TILD,                     _______, _______, _______,_______, _______, _______,\
                            _______, _______, _______, _______,  _______, _______ \
),
[_SYMRIGHT] = LAYOUT( \
  RESET, _______, _______, _______, _______, _______,                   KC_MINUS,    KC_EQUAL,    KC_LABK,    KC_RABK,    KC_ASTR,    _______, \
  _______, _______, _______, _______, XXXXXXX, _______,                   KC_UNDS, KC_LCBR, KC_RCBR, ST_MACRO_25,   KC_PLUS, _______, \
  _______, _______, _______, _______, _______, _______,                   KC_AMPR, KC_QUOTE, KC_DQUO,  ST_MACRO_26, KC_BSLASH, _______, \
                             _______, _______,  _______,                  _______,  _______, _______ \
),
[_NUMRIGHT] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, KC_7, KC_8, KC_9, KC_COMMA, _______, \
  _______, _______, _______, _______, MO(_FN), XXXXXXX,                   _______, KC_4, KC_5, KC_6, KC_0, _______, \
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

  [_FN] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                      _______, KC_F7, KC_F8, KC_F9, KC_COMMA, _______, \
  _______, _______, _______, _______, _______, _______,                      _______, KC_F4, KC_F5, KC_F6, KC_F10, _______, \
  _______, _______, _______, _______, _______, _______,                      _______, KC_F1, KC_F2, KC_F3, KC_DOT, _______,\
                            _______, _______, _______,                       _______,  _______, _______ \
  ),

  [_RGB] = LAYOUT( \
  RGB_M_P, RGB_M_SW, RGB_M_R, RGB_M_B, RGB_MOD, RGB_TOG,                      _______, _______, _______, _______, _______, _______, \
  _______, _______, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,                      _______, _______, _______, _______, _______, _______, \
  _______, _______, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,                      _______, _______, _______, _______, _______, _______,\
                            _______, _______, _______,                       _______,  _______, _______ \
  ),

  [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LSFT, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, \
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                        KC_LGUI, KC_SPC, KC_BSPC,                       KC_TAB, KC_ENTER, KC_LALT \
),

};

int RGB_current_mode;

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
}


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(PSTR("corne"), false);
}

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_SYMLEFT)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_SYMRIGHT)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_NUMRIGHT)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

void render_status_main(void) {
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void render_status_secondary(void) {
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > 30000) {
        oled_off();
        return;
    }
#ifndef SPLIT_KEYBOARD
    else { oled_on(); }
#endif

    if (is_master) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}

#endif

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
        oled_timer = timer_read32();
#endif
    // set_timelog();
  }
  // static uint16_t my_colon_timer;
  
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return TAPPING_TERM + 500;
        case RGUI_T(KC_I):
            return TAPPING_TERM + 500;
        case LT(_NUMRIGHT, KC_G):
            return TAPPING_TERM + 500;
        case LT(4, KC_T):
            return TAPPING_TERM - 200;
        case LT(3, KC_N):
            return TAPPING_TERM - 100;
        default:
            return TAPPING_TERM;
    }
}


#ifdef RGB_MATRIX_ENABLE

void suspend_power_down_keymap(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_keymap(void) {
    rgb_matrix_set_suspend_state(false);
}

#endif
