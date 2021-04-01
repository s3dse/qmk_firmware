/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

//successive tap and hold tapping_term will register as mod
#define TAPPING_FORCE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#define FIRMWARE_VERSION u8"4OmNQ/xDXGW"
#define RGB_MATRIX_STARTUP_SPD 60


#define LEADER_TIMEOUT 500
#define LEADER_PER_KEY_TIMING