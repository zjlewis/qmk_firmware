// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum zjl_sofle_layers {
    _ALPHA,
    _SYMB,
    _NAV,
    _ADJ,
    _NUMPAD
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_ALPHA]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),      ENCODER_CCW_CW(KC_PGDN, KC_PGUP)},
    [_SYMB]    = { ENCODER_CCW_CW(_______, _______),      ENCODER_CCW_CW(_______, _______)},
    [_NAV]     = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),      ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [_ADJ]     = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),      ENCODER_CCW_CW(RGB_RMOD,RGB_MOD)},
    [_NUMPAD]  = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),      ENCODER_CCW_CW(XXXXXXX, XXXXXXX)}
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * ALPHA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | Left | Right| MO   | / Space /       \Enter \  | MO   |  Up  | Down | RGUI |
 *            |      | LAlt | LCTR | NAV  |/       /         \      \ | SYMB | RCTR | RAlt |      |
 *            `-----------------------------------'           '------''---------------------------'
 */

[_ALPHA] = LAYOUT(
              KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_GRV,
  LT(_NUMPAD,KC_ESC),   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
              KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
              KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    KC_MPLY,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
               KC_LGUI,LALT_T(KC_LEFT),LCTL_T(KC_RGHT), MO(_NAV), KC_SPC,      KC_ENT,  MO(_SYMB), RCTL_T(KC_UP), RALT_T(KC_DOWN), KC_RGUI
),
/* SYMBOLS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    | Pause |------+------+------+------+------+------|
 * | Shift|   =  |   -  |   +  |   {  |   }  |-------|    |-------|   [  |   ]  |   <  |   >  |   \  | Shift|
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *            | LGUI | LAlt | LCTR | MO   | / UndScr/      \ Enter \  | MO   | RCTR | RAlt | RGUI |
 *            |      |      |      | ADJ  |/       /        \       \ | SYMB |      |      |      |
 *            `-----------------------------------'           '-----------------------------------'
 */
[_SYMB] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,     _______, KC_LBRC, KC_RBRC, KC_LABK, KC_RABK, KC_BSLS, _______,
                    _______, _______, _______, MO(_ADJ),KC_UNDS,     _______, _______, _______, _______, _______
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
[_NAV] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, XXXXXXX, KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                         KC_HOME,  KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_F12,
  _______, C(KC_A), C(KC_S), C(KC_D), C(KC_F), XXXXXXX,                         KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_BSPC,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______,       _______, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                    _______, _______, _______, _______, _______,       _______, MO(_ADJ), _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | BOOT |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBTog| Hue+ | Sat+ | Val+ |      |      |                    |      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Mode | Hue- | Sat- | Val- |      |      |-------.    ,-------|      | PREV | PLAY | NEXT |      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *            | LGUI | Left | Right|      | / Space /      \ Enter \  |      |  Up  | Down | RGUI |
 *            |      | LAlt | LCTR |      |/       /        \       \ |      | RCTR | RAlt |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
  [_ADJ] = LAYOUT(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
  ),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |NumLck|   /  |   *  |   -  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   +  |   \  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |   =  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  | ENT  | Shift|
 * `-----------------------------------------/       /    \       \-----------------------------------------'
 *            | LGUI | Left | Right|      | / Space /      \ Enter \  |      |   0  |   .  | RGUI |
 *            |      | LAlt | LCTR |      |/       /        \       \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
  [_NUMPAD] = LAYOUT(
  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,
  TO(_ALPHA), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_PPLS, KC_BSLS,
  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_PEQL, KC_PIPE,
  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_PENT, KC_RSFT,
                       _______, _______, _______, _______,_______,   _______,_______, KC_P0,  KC_PDOT, _______
),
};

