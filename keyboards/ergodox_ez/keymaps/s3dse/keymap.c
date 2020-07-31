#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_172_255_255,
  HSV_86_255_128,
  HSV_27_255_255,
  HSV_215_255_128,
  HSV_0_255_255,
};

enum {
    TD_BR_L,
    TD_BR_R,
};

void tap_dance_parens_left(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
      tap_code16(KC_LPRN);
  } else if (state->count == 2) {
      tap_code(KC_LBRACKET);
  } else if (state->count == 3) {
      tap_code16(KC_LCBR);
  } else {
      reset_tap_dance(state);
  }
}

void tap_dance_parens_right(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
      tap_code16(KC_RPRN);
  } else if (state->count == 2) {
      tap_code(KC_RBRACKET);
  } else if (state->count == 3) {
      tap_code16(KC_RCBR);
  } else {
      reset_tap_dance(state);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for parenthesis, twice for bracket, three times for curly brace
    [TD_BR_L] = ACTION_TAP_DANCE_FN(tap_dance_parens_left),
    [TD_BR_R] = ACTION_TAP_DANCE_FN(tap_dance_parens_right),

};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 TG(1),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_DELETE,      KC_Q,           KC_D,           KC_R,           KC_W,           KC_B,           TD(TD_BR_L),                                    TD(TD_BR_R),    KC_J,           KC_F,           KC_U,           KC_P,           KC_SCOLON,      KC_BSLASH,
    LGUI_T(KC_CAPSLOCK),KC_A,           KC_S,           KC_H,           KC_T,           KC_G,                                                                           KC_Y,           KC_N,           KC_E,           KC_O,           LT(1,KC_I),     LGUI_T(KC_QUOTE),
    KC_LSPO,        LCTL_T(KC_Z),   KC_X,           KC_M,           KC_C,           KC_V,           KC_HYPR,                                        KC_MEH,         KC_K,           KC_L,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH),KC_RSPC,
    LT(3,KC_GRAVE), LT(4,KC_QUOTE), LALT(KC_LSHIFT),KC_LEFT,        KC_RIGHT,                                                                                                       KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    MO(3),
                                                                                                    LALT_T(KC_APPLICATION),KC_LGUI,        KC_LALT,        LCTL_T(KC_ESCAPE),
                                                                                                                    KC_HOME,        KC_PGUP,
                                                                                    KC_SPACE,       KC_BSPACE,      LT(3,KC_END),   LT(3,KC_PGDOWN),KC_TAB,         KC_ENTER
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_W,           KC_MS_UP,       RESET,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    TG(2),                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,                                                                                                     KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    RGB_MOD,        HSV_172_255_255,RGB_TOG,        RGB_SLD,
                                                                                                                    HSV_86_255_128, HSV_215_255_128,
                                                                                    RGB_VAI,        RGB_VAD,        HSV_27_255_255, HSV_0_255_255,  RGB_HUI,        RGB_HUD
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LSHIFT,      KC_A,           KC_S,           KC_D,           KC_F,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LCTRL,       KC_Y,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_I,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LALT,                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MINUS,       KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LBRACKET,    KC_RBRACKET,    KC_GRAVE,                                                                       KC_UNDS,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_SCOLON,      KC_COLN,        KC_TILD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLASH,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_DQUO,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213}, {187,104,213} },

    [2] = { {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {31,255,255}, {0,239,228}, {0,239,228}, {0,239,228}, {31,255,255}, {31,255,255}, {31,255,255}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228}, {0,239,228} },

    [3] = { {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255}, {22,255,255} },

    [4] = { {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145}, {86,218,145} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_27_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(27,255,255);
      }
      return false;
    case HSV_215_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(215,255,128);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
  }
  return true;
}

bool led_update_user(led_t led_state) {
    static uint8_t caps_state = 0;
    if (caps_state != led_state.caps_lock) {
        if (led_state.caps_lock) {
          ergodox_right_led_1_set(LED_BRIGHTNESS_LO);
          ergodox_right_led_1_on();
        } else {
          ergodox_right_led_1_off();
        }
        caps_state = led_state.caps_lock;
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_2_set(LED_BRIGHTNESS_LO);
      ergodox_right_led_2_on();
      break;
    case 2:
      ergodox_right_led_2_set(LED_BRIGHTNESS_HI);
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_set(LED_BRIGHTNESS_LO);
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_3_set(LED_BRIGHTNESS_HI);
      ergodox_right_led_3_on();
      break;
    case 5:
      ergodox_right_led_2_set(LED_BRIGHTNESS_LO);
      ergodox_right_led_2_on();
      ergodox_right_led_3_set(LED_BRIGHTNESS_LO);
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_set(LED_BRIGHTNESS_HI);
      ergodox_right_led_2_on();
      ergodox_right_led_3_set(LED_BRIGHTNESS_LO);
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_2_set(LED_BRIGHTNESS_HI);
      ergodox_right_led_2_on();
      ergodox_right_led_3_set(LED_BRIGHTNESS_HI);
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
