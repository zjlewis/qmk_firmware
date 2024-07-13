// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum zjl_sofle_layers {
    _ALPHA,
    _SYMB,
    _SEL,
    _ADJ,
    _NUMPAD
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_ALPHA]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),      ENCODER_CCW_CW(KC_PGDN, KC_PGUP)},
    [_SYMB]    = { ENCODER_CCW_CW(_______, _______),      ENCODER_CCW_CW(_______, _______)},
    [_SEL]     = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),      ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [_ADJ]     = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),      ENCODER_CCW_CW(RGB_RMOD,RGB_MOD)},
    [_NUMPAD]  = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),      ENCODER_CCW_CW(XXXXXXX, XXXXXXX)}
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * ALPHA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   =  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *            | LGUI | Left | Right| MO   | / Space /      \ Enter \  | MO   | Down |  Up  | RGUI |
 *            |      | LAlt | LCTR | NAV  |/       /        \       \ | SYMB | RCTR | RAlt |      |
 *            `-----------------------------------'          '-------''---------------------------'
 */
[_ALPHA] = LAYOUT(
              KC_EQL,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
              KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
   LT(_NUMPAD,KC_ESC),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
              KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    KC_MPLY,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
              KC_LGUI,LALT_T(KC_LEFT),LCTL_T(KC_RGHT), MO(_SEL), KC_SPC,      KC_ENT,  MO(_SYMB), RCTL_T(KC_DOWN), RALT_T(KC_UP), KC_RGUI
),
/* SYMBOLS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   =  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    | Pause |------+------+------+------+------+------|
 * | Shift|   `  |   -  |   =  |   {  |   }  |-------|    |-------|   [  |   ]  |   <  |   >  |   \  | Shift|
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *            | LGUI | LAlt | LCTR | MO   | / Space /      \ Enter \  | MO   | RCTR | RAlt | RGUI |
 *            |      |      |      | ADJ  |/       /        \       \ | SYMB |      |      |      |
 *            `-----------------------------------'           '-----------------------------------'
 */
[_SYMB] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, KC_GRV,  KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, _______,     _______, KC_LBRC, KC_RBRC, KC_LABK, KC_RABK, KC_BSLS, _______,
                    _______, _______, _______, MO(_ADJ),_______,     _______, _______, _______, _______, _______
),
 /* NAV
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |      | Pscr | Menu |      |      |                    | Home | PgDn | PgUp | End  | Ins  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | CtlA | CtlS | CtlD | CtlF |      |-------.    ,-------| Left | Down |  Up  | Right| Del  | Bspc |
 * |------+------+------+------+------+------|  MUTE |    | Pause |------+------+------+------+------+------|
 * |Shift | CtlZ | CtlX | CtlC | CtlV |      |-------|    |-------|      |      |      |      |      | Shift|
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *            | LGUI | Left | Right| MO   | / Space /      \ Enter \  | MO   |  Up  | Down | RGUI |
 *            |      | LAlt | LCTR | NAV  |/       /        \       \ | ADJ  | RCTR | RAlt |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_SEL] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, XXXXXXX, KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                         KC_HOME,  KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_F12,
  _______, C(KC_A), C(KC_S), C(KC_D), C(KC_F), XXXXXXX,                         KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_BSPC,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______,       _______, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                    _______, _______, _______, _______, _______,       _______, MO(_ADJ), _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBTog|      | Mode+| Val+ | Spd+ |      |                    |      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Mode-| Val- | Spd- |      |-------.    ,-------|      | PREV | PLAY | NEXT |      |      |
 * |------+------+------+------+------+------|  MUTE |    | Pause |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *            | LGUI | Left | Right|      | / Space /      \ Enter \  |      |  Up  | Down | RGUI |
 *            |      | LAlt | LCTR |      |/       /        \       \ |      | RCTR | RAlt |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
  [_ADJ] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RGB_TOG, XXXXXXX, RGB_MOD, RGB_VAI, RGB_SPI, XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, RGB_RMOD,RGB_VAD, RGB_SPD, XXXXXXX,                     XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
  ),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |NumLck|   /  |   *  |   -  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   +  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |   =  |   \  |
 * |------+------+------+------+------+------|  MUTE |    | Pause |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  | ENT  | Shift|
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *            | LGUI | Left | Right|      | / Space /      \ Enter \  |      |   0  |   .  | RGUI |
 *            |      | LAlt | LCTR |      |/       /        \       \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
  [_NUMPAD] = LAYOUT(
  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,
  TO(_ALPHA), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_PPLS, KC_BSPC,
  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_PEQL, KC_BSLS,
  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_PENT, KC_RSFT,
                       _______, _______, _______, _______,_______,   _______,_______, KC_P0,  KC_PDOT, _______
)
};

// some example numlock code

// track numlock state and if numpad layer changes it
bool bnumlock = false;
bool numlock_changed = false;

bool led_update_user(led_t led_state) {
  bnumlock = led_state.num_lock;
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  // set numlock if activating numpad layer
  if (IS_LAYER_ON_STATE(state, _NUMPAD)) {
    if(!bnumlock) {
      numlock_changed = true;
      register_code(KC_NUM);
      unregister_code(KC_NUM);
    }
  }
  // else return numlock to previous state
  else {
    if(bnumlock && numlock_changed) {
      numlock_changed = false;
      register_code(KC_NUM);
      unregister_code(KC_NUM);
    }
  }

  // set layer specific colors, works with animations
  // TODO(TBD): set layer-specific per-key colors if program memory allows
  HSV curr_hsv = rgb_matrix_get_hsv();
  uint8_t h = curr_hsv.h;
  uint8_t s = curr_hsv.s;
  uint8_t v = curr_hsv.v;

  switch (get_highest_layer(state)) {
    case _ALPHA:
      h = 170;  //blue
      break;
    case _SYMB:
      h = 106;  //springgreen
      break;
    case _SEL:
      h = 191;  //purple
      break;
    case _ADJ:
      h = 36;   //gold
      break;
    case _NUMPAD:
      h = 128;  //cyan
      break;
    default:
      h = 0;    //red
      break;
  }

  rgb_matrix_sethsv_noeeprom(h, s, v);

  return state;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_RIVERFLOW);
    rgb_matrix_sethsv_noeeprom(RGB_MATRIX_DEFAULT_HUE, 255, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
}
