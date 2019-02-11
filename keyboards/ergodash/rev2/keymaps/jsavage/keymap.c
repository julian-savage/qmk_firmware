#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,----------------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC   |    1   |   2    |   3    |   4    |   5    |        |                 |        |   6    |   7    |   8    |   9    |   0    |  -     |
 * |----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Tab   |    Q   |   W    |   E    |   R    |   T    |        |                 |        |   Y    |   U    |   I    |   O    |   P    |  \     |
 * |----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Ctrl  |    A   |   S    |   D    |   F    |   G    |   `    |                 |  =     |   H    |   J    |   K    |   L    |   ;    |  "     |
 * |----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Shift |    Z   |   X    |   C    |   V    |   B    |        |                 |        |   N    |   M    |   ,    |   .    |   /    | Shift  |
 * |----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |       |        |  GUI   | ALT    |||||||||| Lower  | Space  |        |        | Enter  | Raise  |||||||||| MEH    |        |        |        |
 * ,----------------------------------------------------------------------------------------------------------------------------------------------.
 */
  [_QWERTY] = LAYOUT( \
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,                   _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, \
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , _______,                   _______, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS, \
    KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_GRV ,                   KC_EQL , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______,                   _______, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, \
    _______, _______, KC_LGUI, KC_LALT,          LOWER  , KC_SPC , _______, _______, KC_ENT , RAISE           , KC_MEH , _______, _______, _______  \
  ),
  [_COLEMAK] = LAYOUT( \
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,                   _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, \
    KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , _______,                   _______, KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSLS, \
    KC_LCTL, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_GRV ,                   KC_EQL , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT, \
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______,                   _______, KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, \
    _______, _______, KC_LGUI, KC_LALT,          LOWER  , KC_SPC , _______, _______, KC_ENT , RAISE           , KC_MEH , _______, _______, _______  \
  ),
  [_DVORAK] = LAYOUT( \
    KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,                   _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, \
    KC_TAB , KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   , _______,                   _______, KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_BSLS, \
    KC_LCTL, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   , KC_GRV ,                   KC_EQL , KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_SLSH, \
    KC_LSFT, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , _______,                   _______, KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , KC_RSFT, \
    _______, _______, KC_LGUI, KC_LALT,          LOWER  , KC_SPC , _______, _______, KC_ENT , RAISE           , KC_MEH , _______, _______, _______  \
  ),
  [_LOWER] = LAYOUT(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,                   _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,                   _______, KC_INS , KC_HOME, KC_UP  , KC_PGUP, KC_LBRC, _______, \
    _______, KC_F11 , KC_F12 , KC_F13 , KC_F14 , KC_F15 , KC_ESC ,                   _______, KC_DEL , KC_LEFT, KC_DOWN, KC_RGHT, KC_RBRC, _______, \
    _______, KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , _______,                   _______, _______, KC_END , _______, KC_PGDN, _______, _______, \
    _______, _______, _______, _______,          LOWER  , KC_TAB , _______, _______, KC_BSPC, RAISE  ,          _______, _______, _______, _______  \
  ),
  [_RAISE] = LAYOUT(
    _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, _______,                   _______, KC_NLCK, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, KC_PENT, \
    _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,                   _______, KC_INS , KC_KP_4, KC_KP_5, KC_KP_6, KC_PSLS, KC_PSCR, \
    _______, _______, _______, _______, _______, _______, _______,                   _______, KC_DEL , KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, KC_SLCK, \
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, KC_KP_0, KC_PDOT, KC_PEQL, KC_PMNS, KC_PAUS, \
    _______, _______, _______, _______,          LOWER  , KC_TAB , _______, _______, KC_BSPC, RAISE  ,          _______, _______, _______, _______  \
  ),
  [_ADJUST] = LAYOUT(
    _______, QWERTY , COLEMAK, DVORAK , AG_SWAP, AG_NORM, _______,                   _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          LOWER  , _______, _______, _______, _______, RAISE  ,          _______, _______, _______, _______  \
  )
};

/* switch without storing */
static void switch_default_layer(uint8_t layer)
{
    /* xprintf("L%d\n", layer); */
    default_layer_set(1UL<<layer);
    clear_keyboard();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        switch_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        switch_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        switch_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
