/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include <stdio.h>
#include "keymap_swedish_pro_mac_iso.h"




// magnet
#define MAGNET(kc) LALT(LCTL(kc))

#define M_LH MAGNET(KC_LEFT)
#define M_RH MAGNET(KC_RIGHT)
#define M_TH MAGNET(KC_UP)
#define M_BH MAGNET(KC_DOWN)
#define M_TR MAGNET(SE_I)
#define M_TL MAGNET(SE_U)
#define M_BR MAGNET(SE_K)
#define M_BL MAGNET(SE_J)
#define M_FULL MAGNET(KC_ENTER)

#define C_A LCTL_T(SE_A)
#define A_S LALT_T(SE_S)
#define S_D LSFT_T(SE_D)
#define G_F LGUI_T(SE_F)
#define S_V LT(SYM,SE_V)
#define H_G HYPR_T(SE_G)

#define G_J  RGUI_T(SE_J)
#define S_K  RSFT_T(SE_K)
#define A_L  RALT_T(SE_L)
#define C_OE RCTL_T(SE_ODIA)
#define H_H HYPR_T(SE_H)

#define S_ENT LT(SYM_R,KC_ENT)
#define S_SPC LT(SYM_L,KC_SPC)
#define M_TAB LT(MAG,KC_TAB)
#define N_ESC LT(NUM,KC_ESC)
#define ___X___ KC_NO

#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)

enum layers {
    QWERTY,
    GAME,
    G_N,
    SYM_L,
    SYM_R,
    NUM,
    NAV,
    MAG,
};

enum custom_keycodes {
    SLSH = SAFE_RANGE,
    COM,
    DOT,
    QUOT,
    ANSIBSLS,
    M_ARROW,
    CMD_TAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        N_ESC , SE_Q   , SE_W   , SE_E   , SE_R   , SE_T ,                      SE_Y   , SE_U   , SE_I   , SE_O   , SE_P   , SE_ARNG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TG(GAME), C_A    , A_S    , S_D    , G_F    , H_G ,                      H_H    , G_J    , S_K    , A_L    , C_OE   , SE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ___X___, SE_Z   , SE_X   , SE_C   , SE_V    , SE_B,                         SE_N   , SE_M    , COM    , DOT    , SLSH   , QUOT   ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       MO(NAV),M_TAB   ,S_ENT,       S_SPC, KC_BSPC,  MO(G_N)
                                      //`--------------------------'  `-------------------------
  ),

  [G_N] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------
            ___X___,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            ___X___,    SE_1,    SE_2,    SE_3,    SE_4,    SE_5,                         SE_6,    SE_7,    SE_8,    SE_9,    SE_0,  KC_F12,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LSFT, ___X___, ___X___, ___X___, ___X___, ___X___,                      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------
                                                _______, _______, _______,    _______, _______, _______
                                            //`--------------------------'  `--------------------------'
  ),

    [SYM_R] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                      SE_PIPE, SE_LABK, SE_RABK,   SE_AT, SE_PERC, ___X___,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                      SE_AMPR, SE_EXLM, SE_COLN,  SE_EQL, SE_QUES, ___X___,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            ___X___, ___X___, ___X___, ___X___, ___X___, _______,                      SE_MINS, SE_PLUS, SE_SLSH, SE_ASTR, SE_BSLS, ___X___,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------
            _______, _______, _______,       _______, _______, _______
        ),
    [SYM_L] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            ___X___, SE_CIRC, SE_QUOT, SE_LBRC, SE_RBRC, SE_DQUO,                     ___X___, ___X___, ___X___, ___X___, ___X___,___X___,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            ___X___, SE_GRV,   SE_DLR, SE_LCBR, SE_RCBR, SE_UNDS,                     ___X___, ___X___, ___X___, ___X___, ___X___,___X___,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            ___X___, SE_TILD, SE_HASH, SE_LPRN, SE_RPRN, SE_SCLN,                     ___X___, ___X___, ___X___, ___X___, ___X___,___X___,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------
                                                _______, _______, _______,    _______, _______, _______
                                            //`--------------------------'  `--------------------------'
        ),
    [NUM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                     ___X___, SE_7   , SE_8   , SE_9   , SE_MINS, SE_PLUS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                     KC_TAB , SE_4   , SE_5   , SE_6   , SE_SLSH, SE_ASTR,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            QK_BOOT, ___X___, ___X___, ___X___, ___X___, ___X___,                     SE_0   , SE_1   , SE_2   , SE_3   , SE_DOT , SE_COMM,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------
                                                _______, _______, _______,    _______, _______, _______
                                            //`--------------------------'  `--------------------------'
        ),
    [NAV] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                      ___X___,  KC_HOME , KC_UP  , KC_END   , ___X___ ,___X___ ,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ___X___, _______, _______, _______, _______, ___X___,                      ___X___,  KC_LEFT , KC_DOWN, KC_RIGHT , ___X___ ,___X___ ,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                      ___X___, ___X___ , ___X___ , ___X___, ___X___  , ___X___ ,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------
                                            _______, _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
        ),
    [MAG] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            ___X___, ___X___, M_TL   , M_TH   , M_TR   , ___X___,                     ___X___, ___X___, ___X___, ___X___, ___X___,___X___,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            ___X___, ___X___, M_LH   , M_FULL , M_RH   , ___X___,                      ___X___, ___X___, ___X___, ___X___, ___X___,___X___,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            ___X___, ___X___, M_BL   , M_BH   , M_BR   , ___X___,                      ___X___, ___X___, ___X___, ___X___, ___X___,___X___,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------
                                                _______, _______, _______,    _______, _______, _______
                                            //`--------------------------'  `--------------------------'
        ),
    [GAME] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LT(NUM, KC_ESC),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LSFT_T(KC_TAB),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, SE_ACUT, RSFT_T(KC_ENTER),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            SE_PLUS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  SE_QUOT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LCTL, KC_LALT, LGUI_T(KC_SPC),    KC_RGUI, KC_RALT, TO(QWERTY)
                                        //`--------------------------'  `--------------------------'
)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t left_shift_pressed = get_mods() & MOD_BIT(KC_LSFT);
    uint8_t right_shift_pressed = get_mods() & MOD_BIT(KC_RSFT);
    uint8_t shift_pressed = left_shift_pressed | right_shift_pressed;
    uint16_t shift_code = KC_LSFT;
    if (right_shift_pressed) {
        shift_code = KC_RSFT;
    }
    switch (keycode) {
        case COM:
            if (record->event.pressed)
                if(shift_pressed) {
                    unregister_code(shift_code);
                    register_code(SE_LABK);
                    register_code(shift_code);
                } else {
                    register_code(SE_COMM);
                }
            else
                if(shift_pressed) {
                unregister_code(SE_LABK);
            } else {
                unregister_code(SE_COMM);
            }
            return false;
        case DOT:
            if (record->event.pressed)
                if(shift_pressed) {
                    register_code(SE_LABK);
                } else {
                    register_code(SE_DOT);
                }
            else
                if(shift_pressed) {
                unregister_code(SE_LABK);
            } else {
                unregister_code(SE_DOT);
            }
            return false;
        case SLSH:
            if (record->event.pressed)
                if(shift_pressed) {
                    register_code(KC_MINS);
                } else {
                    register_code(shift_code);
                    register_code(KC_7);
                    unregister_code(shift_code);
                }
            else
                if(shift_pressed) {
                unregister_code(KC_MINS);
            } else {
                unregister_code(KC_7);
            }
            return false;
        case QUOT:
            if (record->event.pressed)
                if(shift_pressed) {
                    register_code(KC_2);
                } else {
                    register_code(KC_NUHS);
                }
            else
                if(shift_pressed) {
                unregister_code(KC_2);
            } else {
                unregister_code(KC_NUHS);
            }
            return false;
    }
    return true;
}