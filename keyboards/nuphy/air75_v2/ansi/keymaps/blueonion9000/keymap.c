/*
Copyright 2023 @ Nuphy <https://nuphy.com/>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

bool is_shift_held(void);
void shift_macro(char m, char s);

enum layers {
    QWERTY,
    GRAPHITE,
    FN,
    FN2,
    SYMB,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// layer 'MAC'
[QWERTY] = LAYOUT_75_ansi(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  RGB_TOG,  KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
    KC_BSPC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_END,
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(FN),   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

// layer 'WIN'
[GRAPHITE] = LAYOUT_75_ansi(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  RGB_TOG,  KC_DEL,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LBRC,  KC_RBRC,  KC_BSPC,            KC_PGUP,
    KC_TAB,   KC_B,     KC_L,     KC_D,     KC_W,     KC_Z,     G_QUOT,   KC_F,     KC_O,     KC_U,     KC_J,     KC_SCLN,  KC_EQL,   KC_BSLS,            KC_PGDN,
    KC_BSPC,  KC_N,     KC_R,     KC_T,     KC_S,     KC_G,     KC_Y,     KC_H,     KC_A,     KC_E,     KC_I,     G_COMM,             KC_ENT,             KC_HOME,
    KC_LSFT,            KC_X,     KC_M,     KC_V,     KC_C,     KC_Q,     KC_P,     KC_K,     G_DOT,    G_MINS,   G_SLSH,             KC_RSFT,  KC_UP,    KC_END,
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(FN),   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[FN] = LAYOUT_75_ansi(
    C_DEFL,   KC_BRID,  KC_BRIU,  _______,  _______,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  _______,  _______,
    _______,  LNK_BLE1, LNK_BLE2, LNK_BLE3, LNK_RF,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  DEV_RESET,_______,  BAT_SHOW,           _______,
    KC_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,            C_DEFL,   TO(SYMB), _______,  _______,  BAT_NUM,  _______,  MO(FN2),  RGB_SPD,  RGB_SPI,  _______,            _______,  KC_VOLU,  _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  RM_NEXT,  KC_VOLD,  RM_HUEU),

// Fn + M
[FN2] = LAYOUT_75_ansi(
    _______,  RM_VALD,  RM_VALU,  _______, _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  SLEEP_MODE,         _______,  _______, 
    _______,  _______,  KB_SLP,   DB_TOGG, _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,                      _______,  _______,
    _______,            LINK_TO,  _______, RGB_TEST, _______,  _______,  _______,  _______,   SIDE_SPD, SIDE_SPI, _______,            _______,  SIDE_VAI, _______,
    _______,  _______,  _______,                               _______,                       _______,  MO(FN2),  _______,            SIDE_MOD, SIDE_VAD, SIDE_HUI),

[SYMB] = LAYOUT_75_ansi(
     C_DEFL,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
     _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,  _______,  _______,            _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  C_LPRTS,  C_RPRTS,  C_LBRC,   C_RBRC,   _______,            _______,            _______,
     _______,            _______,  _______,  _______,  _______,  _______,  _______,  C_LFBRC,  C_RFBRC,  _______,  _______,            _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______)
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case C_LPRTS:
        if (record->event.pressed)
            send_char('(');
        return false;
    case C_RPRTS:
        if (record->event.pressed)
            send_char(')');
        return false;
    case C_LFBRC:
        if (record->event.pressed)
            send_char('{');
        return false;
    case C_RFBRC:
        if (record->event.pressed)
            send_char('}');
        return false;
    case C_LBRC:
        if (record->event.pressed)
            send_char('[');
        return false;
    case C_RBRC:
        if (record->event.pressed)
            send_char(']');
        return false;

    case C_DEFL:
        if (record->event.pressed)
            layer_clear();
        return false;

    // graphite
    case G_QUOT:
        if (record->event.pressed)
            shift_macro('\'', '_');
        return false;
    case G_COMM:
        if (record->event.pressed)
            shift_macro(',', '?');
        return false;
    case G_DOT:
        if (record->event.pressed)
            shift_macro('.', '>');
        return false;
    case G_MINS:
        if (record->event.pressed)
            shift_macro('-', '\"');
        return false;
    case G_SLSH:
        if (record->event.pressed)
            shift_macro('/', '<');
        return false;

    // trnv
    case C_CDOT:
        if (record->event.pressed)
            shift_macro('?', '/');
        return false;
    }

    return true;
}

bool is_shift_held(void) {
    if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) return true;
    
    return false;
}

void shift_macro(char m, char s) {
    const uint8_t mods = get_mods();

    if (is_shift_held()) {
        del_oneshot_mods(MOD_MASK_SHIFT);
        unregister_mods(MOD_MASK_SHIFT);

        send_char(s);

        register_mods(mods);

        return;
    }

    send_char(m);
}