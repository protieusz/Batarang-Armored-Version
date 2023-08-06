 // Copyright 2023 %YOUR_FULL_NAME% (@%YOUR_GITHUB_USERNAME%)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum combo_events {
  COMBO_DEL,
  COMBO_ESC,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_del[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_T, KC_G, COMBO_END};

combo_t key_combos[] = {
  [COMBO_DEL] = COMBO(combo_del, KC_DEL),
  [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 2, 3);
} 

enum layer_names {
  _BASE,
  _FN1,
  _FN2,
  _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
[_BASE] = LAYOUT(
         
KC_Q, KC_W, KC_E, KC_R, KC_T,                                            KC_Y, KC_U, KC_I, KC_O, KC_P,
KC_A, KC_S, KC_D, KC_F, KC_G,                                            KC_H, KC_J, KC_K, KC_L, KC_SCLN,
LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_MS_BTN1,             KC_MS_BTN2,KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH),
                    KC_LCTL, KC_LGUI, LT(1,KC_BSPC), KC_MUTE, LT(2,KC_SPC), KC_ENT, KC_RALT

),

[_FN1] = LAYOUT(

KC_1, KC_2, KC_3, KC_4, KC_5,                                           KC_6, KC_7, KC_8, KC_9, KC_0,
KC_TAB, _______, _______, _______, _______,                             KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT,
_______, _______, _______, KC_VOLD, KC_VOLU, _______,          _______, KC_TILD,  KC_GRV,  _______, _______, KC_BSLS,
                  _______, _______, _______, _______, _______, _______, _______ 

),

[_FN2] = LAYOUT(

KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                               KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
_______, _______, _______, _______, _______,                            _______, _______, _______, _______,_______,
_______, _______, _______, _______, _______, _______,         _______,  RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
                  _______, _______, _______, _______, _______, _______, _______

),

[_FN3] = LAYOUT(

_______, KC_UP, _______, _______, _______,                              KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PSCR,
KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,                           KC_F5, KC_F6, KC_F7, KC_F8,_______,
_______, _______, _______, _______, _______, _______,          _______, KC_F9, KC_F10, _______, _______, _______,
                           _______, _______, _______, _______, _______, _______, _______

    )
};

//bool encoder_update_user(uint8_t index, bool clockwise) {
    //if (index == 0) {
        //if (clockwise) {
            //tap_code(KC_VOLD);
            //tap_code(KC_MS_WH_UP);
        //} else {
            //tap_code(KC_VOLU);
            //tap_code(KC_MS_WH_DOWN);
        //}
    //}
    //return true;
//}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =  { ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)  },
    [1] =  { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  },
    [2] =  { ENCODER_CCW_CW(XXXXXXX, XXXXXXX)  },
    [3] =  { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) }
};
#endif
