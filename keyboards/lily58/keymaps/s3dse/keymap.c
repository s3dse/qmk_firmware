#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

enum custom_keycodes {
  ST_MACRO_0 = SAFE_RANGE,
  ST_MACRO_1,
};

enum layer_number {
  _WORKMAN = 0,
  _SYMLEFT,
  _SYMRIGHT,
  _NUMRIGHT,
  _NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_WORKMAN] = LAYOUT( \
  KC_ESC,   KC_1,           KC_2,           KC_3,    KC_4,    KC_5,                                   KC_6,    KC_7,          KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,   KC_Q,           KC_D,           KC_R,    KC_W,    KC_B,                                   KC_J,    KC_F,          KC_U,    KC_P,    KC_SCOLON,    KC_MINS, \
  KC_LCTRL, LGUI_T(KC_A),   KC_S,           KC_H,    LT(2,KC_T),    LT(3,KC_G),                                   KC_Y,    LT(1,KC_N),    KC_E,    KC_O,    RGUI_T(KC_I), KC_QUOT, \
  KC_LSFT,  LCTL_T(KC_Z),   LALT_T(KC_X),   KC_M,    KC_C,    KC_V,       KC_BSPACE,          KC_TAB,  KC_K,    KC_L,         KC_COMMA, RALT_T(KC_DOT),  RCTL_T(KC_SLASH),  KC_RSFT, \
                                            MO(4), KC_DELETE, LSFT_T(KC_SPACE), KC_BSPACE, KC_TAB, RSFT_T(KC_ENTER), KC_ESCAPE, KC_BSPC \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMLEFT] = LAYOUT( \
  _______, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                       _______, _______, _______,_______, _______, RESET,\
  _______, KC_EXLM,        KC_AT,          KC_LPRN,        KC_RPRN,        KC_PIPE,                     _______, _______, _______,_______, _______, _______,\
  _______, KC_HASH,        KC_DLR,         KC_LBRACKET,    KC_RBRACKET,    KC_GRAVE,                    _______, XXXXXXX, _______,_______, _______, _______,\
  _______, KC_PERC,        KC_CIRC,        KC_SCOLON,      KC_COLN,        KC_TILD,   _______, _______, _______, _______, _______,_______, _______, _______,\
                             _______, _______, _______, _______, _______,  _______, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_SYMRIGHT] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  _______, _______, _______, _______, _______, _______,                        KC_MINUS,    KC_EQUAL,    KC_LABK,    KC_RABK,    KC_ASTR,    _______, \
  _______, _______, _______, _______, XXXXXXX, _______,                     KC_UNDS, KC_LCBR, KC_RCBR, ST_MACRO_0,   KC_PLUS, _______, \
  _______, _______, _______, _______, _______, _______,  _______, _______,  KC_AMPR, KC_QUOTE, KC_DQUO,  ST_MACRO_1, KC_BSLASH, _______, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_NUMRIGHT] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, KC_7, KC_8, KC_9, KC_COMMA, _______, \
  _______, _______, _______, _______, _______, XXXXXXX,                   _______, KC_4, KC_5, KC_6, KC_0, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_DOT, _______,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  ),

  [_NAV] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                   _______, KC_7, KC_8, KC_9, KC_COMMA, _______, \
  _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_DOT, _______,\
                             XXXXXXX, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

static bool shifted = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode)
  {
  case LSFT_T(KC_SPACE):
      shifted = record->event.pressed;
      return true;
      break;
    case RSFT_T(KC_ENTER):
      shifted = record->event.pressed;
      return true;
      break;
    case ST_MACRO_0:
      
      if (record->event.pressed) {
        if (shifted) {

          unregister_code16(LSFT_T(KC_SPACE));
          unregister_code16(RSFT_T(KC_ENTER));
          SEND_STRING("<-");
        } else {
          SEND_STRING("->");
        }

      }
    break;
    case ST_MACRO_1:
      if (record->event.pressed) {
        if (shifted) {
          unregister_code16(LSFT_T(KC_SPACE));
          unregister_code16(RSFT_T(KC_ENTER));
          SEND_STRING("<=");
          
        } else {
          SEND_STRING("=>");
        }
      }
    break;
  
  default:
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
