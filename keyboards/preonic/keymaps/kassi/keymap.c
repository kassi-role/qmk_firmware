/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _NAV
};

// enum preonic_keycodes {
//   MY_KEYCODE = SAFE_RANGE
// };

/* Template
 * .-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * '-----------------------------------------------------------------------------------'
 */
// [_NAV] = LAYOUT_preonic_grid(
//   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,
//   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,
//   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,
//   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,
//   KC_NO,   KC_NO,    KC_NO,    KC_NO,      KC_NO,_______,         KC_NO,_______,   KC_NO,   KC_NO,   KC_NO,   KC_NO
// )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * .-----------------------------------------------------------------------------------.
 * |  =   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |"(MED)|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |ENT(SHFT)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  | GUI  |      |Lower |  Bksp(ALT)  |    Space    |  [   |  ]   |      | GAME |
 * '-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_EQUAL, KC_1,    KC_2,    KC_3,    KC_4,           KC_5,         KC_6,    KC_7,    KC_8,        KC_9,        KC_0,    KC_MINS,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,           KC_T,         KC_Y,    KC_U,    KC_I,        KC_O,        KC_P,    KC_BSLS,
  KC_LCTL,  KC_A,    KC_S,    KC_D,    LT(_NAV, KC_F), KC_G,         KC_H,    KC_J,    KC_K,        KC_L,        KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,           KC_B,         KC_N,    KC_M,    KC_COMM,     KC_DOT,      KC_SLSH, MT(MOD_RSFT, KC_ENT),
  KC_ESC,   KC_LGUI, KC_NO,   KC_NO,   KC_NO,MT(MOD_LALT,KC_BSPC),   KC_NO,KC_SPC,    KC_LBRACKET, KC_RBRACKET, KC_NO,   KC_NO
),

/* Navigation Layer
 * .-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | TRNS |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * '-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_preonic_grid(
  KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,              KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,              KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,              KC_LEFT,     KC_DOWN,     KC_UP,      KC_RIGHT,   KC_TRNS,    KC_TRNS,
  KC_LSFT,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,              KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     _______,MT(MOD_LCTL, KC_BSPC),     _______,KC_TRNS,          KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
)


};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//         case QWERTY:
//           if (record->event.pressed) {
//             set_single_persistent_default_layer(_QWERTY);
//           }
//           return false;
//           break;
//     return true;
// };

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    // case RAISE:
    // case LOWER:
    //   return false;
    default:
      return true;
  }
}
