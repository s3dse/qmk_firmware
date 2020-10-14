
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_WORKMAN 0
#define L_SYMLEFT (1 << 1)
#define L_SYMRIGHT (1 << 2)
#define L_NUMRIGHT (1 << 3)
#define L_NAV (1 << 4)
#define L_UMLAUT (1 << 5)
#define L_EDIT (1 << 6)
#define L_MEDIA (1 << 7)
#define L_GAME (1 << 8)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_WORKMAN:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Workman");
    break;
  case L_SYMLEFT:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: SymLeft");
    break;
  case L_SYMRIGHT:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: SymRight");
    break;
  case L_NUMRIGHT:
    snprintf(layer_state_str, sizeof(layer_state_str), "layer: NumRight");
    break;
  case L_NAV:
    snprintf(layer_state_str, sizeof(layer_state_str), "layer: Nav");
    break;
  case L_UMLAUT:
    snprintf(layer_state_str, sizeof(layer_state_str), "layer: Umlaut");
    break;
  case L_EDIT:
    snprintf(layer_state_str, sizeof(layer_state_str), "layer: Edit");
    break;
  case L_MEDIA:
    snprintf(layer_state_str, sizeof(layer_state_str), "layer: Media");
    break;
  case L_GAME:
    snprintf(layer_state_str, sizeof(layer_state_str), "layer: Game");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
