// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
// #include RGBLIGHT_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _LOWER 1
#define _GAME 2
#define _MEDIA 3
#define _RESET 4
#define _NAV 5
#define _NUMPAD 6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT( /* qwerty */
    KC_EQUAL ,  KC_1    ,  KC_2  ,  KC_3               ,  KC_4           ,  KC_5    ,                       KC_6   ,  KC_7    ,  KC_8        ,  KC_9        ,  KC_0    ,  KC_MINS             ,
    KC_TAB   ,  KC_Q    ,  KC_W  ,  KC_E               ,  KC_R           ,  KC_T    ,                       KC_Y   ,  KC_U    ,  KC_I        ,  KC_O        ,  KC_P    ,  KC_BSLS             ,
    KC_LCTL  ,  KC_A    ,  KC_S  ,  LT(_NUMPAD, KC_D)  ,  LT(_NAV, KC_F) ,  KC_G    ,                       KC_H   ,  KC_J    ,  KC_K        ,  KC_L        ,  KC_SCLN ,  LT(_MEDIA, KC_QUOT) ,
    KC_LSFT  ,  KC_Z    ,  KC_X  ,  KC_C               ,  KC_V           ,  KC_B    ,                       KC_N   ,  KC_M    ,  KC_COMM     ,  KC_DOT      ,  KC_SLSH ,  KC_RSHIFT           ,
    KC_ESC   ,  KC_LGUI ,  KC_NO ,  KC_NO              ,  MO(_LOWER)     ,  KC_BSPC ,  KC_LALT ,  KC_ENT ,  KC_SPC ,  KC_RCTL ,  KC_LBRACKET ,  KC_RBRACKET ,  KC_NO   ,  TO(_GAME)
  ),

  [_LOWER] = LAYOUT(
    KC_TRNS        ,  KC_F1      ,  KC_F2      ,  KC_F3      ,  KC_F4      ,  KC_F5      ,                        KC_F6   ,  KC_F7          ,  KC_F8   ,  KC_F9   ,  KC_F10  ,  KC_F11  ,
    LCTL(KC_TAB)   ,  LCTL(KC_Q) ,  LCTL(KC_W) ,  LCTL(KC_E) ,  LCTL(KC_R) ,  LCTL(KC_T) ,                        KC_TRNS ,  KC_EQL         ,  KC_MINS ,  S(KC_9) ,  S(KC_0) ,  KC_F12  ,
    KC_TRNS        ,  LCTL(KC_A) ,  LCTL(KC_S) ,  LCTL(KC_D) ,  LCTL(KC_F) ,  LCTL(KC_G) ,                        KC_TRNS ,  LSFT(KC_GRAVE) ,  KC_GRV  ,  KC_LBRC ,  KC_RBRC ,  KC_TRNS ,
    KC_TRNS        ,  LCTL(KC_Z) ,  LCTL(KC_X) ,  LCTL(KC_C) ,  LCTL(KC_V) ,  LCTL(KC_B) ,                        KC_TRNS ,  KC_TRNS        ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,
    KC_TRNS        ,  KC_TRNS    ,  KC_TRNS    ,  KC_TRNS    ,  KC_TRNS    ,  KC_TRNS    ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_RGUI        ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS
  ),

  [_GAME] = LAYOUT(
    KC_ESC  ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5   ,                       KC_NO  ,  KC_NO               ,  KC_NO               ,  KC_NO         ,  LGUI(LALT(KC_PSCR)) ,  LGUI(LALT(KC_G)) ,
    KC_TAB  ,  KC_T  ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R   ,                       KC_NO  ,  KC_NO               ,  KC_UP               ,  KC_NO         ,  KC_NO               ,  KC_NO            ,
    KC_LCTL ,  KC_G  ,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F   ,                       KC_NO  ,  KC_LEFT             ,  KC_DOWN             ,  KC_RIGHT      ,  KC_NO               ,  MO(_MEDIA)       ,
    KC_LSFT ,  KC_B  ,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V   ,                       KC_NO  ,  KC_NO               ,  KC_NO               ,  KC_NO         ,  KC_NO               ,  KC_NO            ,
    KC_I    ,  KC_U  ,  KC_O  ,  KC_P  ,  KC_N  ,  KC_SPC ,  KC_LALT ,  KC_ENT ,  KC_SPC ,  KC_NO               ,  KC_NO               ,  KC_NO         ,  KC_NO               ,  TO(_DEFAULT)
  ),

  [_MEDIA] = LAYOUT(
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                        KC_TRNS ,  KC_TRNS             ,  KC_TRNS             ,  KC_TRNS       ,  KC_TRNS,  TO(_RESET) ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                        KC_TRNS ,  KC_MEDIA_PREV_TRACK ,  KC_MEDIA_NEXT_TRACK ,  KC_TRNS       ,  KC_TRNS,  KC_TRNS    ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                        KC_TRNS ,  KC_AUDIO_VOL_DOWN   ,  KC_AUDIO_VOL_UP     ,  KC_AUDIO_MUTE ,  KC_TRNS,  KC_TRNS    ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                        KC_TRNS ,  KC_TRNS             ,  KC_MEDIA_PLAY_PAUSE ,  KC_TRNS       ,  KC_TRNS,  KC_TRNS    ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS             ,  KC_TRNS             ,  KC_TRNS       ,  KC_TRNS,  KC_TRNS
  ),

  [_RESET] = LAYOUT(
    KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  RESET ,                      KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO        ,
    KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,                      KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO        ,
    KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,                      KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO        ,
    KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,                      KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO        ,
    KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,   KC_NO ,   KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  TO(_DEFAULT)
  ),

  [_NAV] = LAYOUT(
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                       KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                       KC_TRNS ,  KC_HOME ,  KC_END  ,  KC_TRNS ,  KC_TRNS ,  KC_F12  ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_DEL  ,  KC_TRNS ,  KC_TRNS ,                       KC_LEFT ,  KC_DOWN ,  KC_UP   ,  KC_RGHT ,  KC_TRNS ,  KC_TRNS ,
    KC_LSFT ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                       KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_BSPC ,  KC_LCTL , KC_ENT  ,  KC_SPC  ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS
  ),

  [_NUMPAD] = LAYOUT(
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                      KC_TRNS ,  KC_PSLS ,  KC_PSLS ,  KC_PAST ,  KC_PMNS ,  KC_TRNS ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                      KC_TRNS ,  KC_7    ,  KC_8    ,  KC_9    ,  KC_PPLS ,  KC_TRNS ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                      KC_TRNS ,  KC_4    ,  KC_5    ,  KC_6    ,  KC_PPLS ,  KC_TRNS ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                      KC_TRNS ,  KC_1    ,  KC_2    ,  KC_3    ,  KC_PENT ,  KC_TRNS ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS,  KC_TRNS,  KC_TRNS ,  KC_0    ,  KC_0    ,  KC_DOT  ,  KC_PENT ,  KC_TRNS
  )

  /*
  [_TRNS] = LAYOUT(
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                       KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                       KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                       KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,                       KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,
    KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS , KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS ,  KC_TRNS
  ),
  */
};

// #define _DEFAULT 0 -> purple
// #define _LOWER   1 -> 0xE3
// #define _MEDIA   2 -> green
// #define _GAME    3 -> blue
// #define _RESET   4 -> red
// #define _NAV     5 -> 0xAA
// #define _NUMPAD  6 -> 0x6A

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_sethsv (0xE3, 0xFF, 0x80);
        break;
    case _GAME:
        rgblight_sethsv (0xC6, 0xFF, 0x80);
        break;
    case _MEDIA:
        rgblight_sethsv (0x55, 0xFF, 0x80);
        break;
    case _NAV:
        rgblight_sethsv (0xAA, 0xFF, 0x80);
        break;
    case _NUMPAD:
        rgblight_sethsv (0x61, 0xFF, 0x80);
        break;
    case _RESET:
        rgblight_sethsv (0x00, 0xFF, 0x80);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv (0x80,  0xFF, 0x80);
        // rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}

// void keyboard_post_init_user(void) {
//     rgblight_setrgb (0x00,  0xFF, 0xFF);
// }

// void keyboard_post_init_user(void) { // Runs boot tasks for keyboard
//   debug_enable=true;
//   // debug_matrix=true;
//   // sethsv(HSV_RED, (LED_TYPE *)&led[0]); // led 0
//   // sethsv(HSV_BLUE,   (LED_TYPE *)&led[1]); // led 1
//   // sethsv(HSV_GREEN, (LED_TYPE *)&led[2]); // led 2
//   // rgblight_set(); // Utility functions do not call rgblight_set() automatically, so they need to be called explicitly.

//   // rgblight_enable();
//   rgblight_setrgb(RGB_BLUE);
//   // rgblight_setrgb_at(255, 0, 0, 0);
//   // rgblight_setrgb_at(0, 255, 0, 1);
//   // rgblight_setrgb_at(0, 0, 255, 2);

//   print("WE FUGGEN DID IT");
// };
