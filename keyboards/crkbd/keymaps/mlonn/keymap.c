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
#include <string.h>
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
#define M_V MT(MOD_RCTL | MOD_RALT, SE_V)
#define H_G HYPR_T(SE_G)

#define G_J  RGUI_T(SE_J)
#define S_K  RSFT_T(SE_K)
#define A_L  RALT_T(SE_L)
#define M_M MT(MOD_LCTL | MOD_LALT, SE_M)
#define C_OE RCTL_T(SE_ODIA)
#define H_H HYPR_T(SE_H)

#define U_RDO LSFT(LCMD(KC_Z))
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)

#define S_ENT LT(SYM_R,KC_ENT)
#define S_SPC LT(SYM_L,KC_SPC)
#define N_TAB LT(NAV,KC_TAB)
#define N_ESC LT(NUM,KC_ESC)
#define M_B LT(MOUSE,SE_B)


#define ___X___ KC_NO


enum layers {
    QWERTY,
    GAME,
    MOUSE,
    G_N,
    SYM_L,
    SYM_R,
    NUM,
    NAV
};

enum custom_keycodes {
    SLSH = SAFE_RANGE,
    COM,
    DOT,
    QUOT,
    ANSIBSLS,
    M_ARROW,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        ___X___,    SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,                         SE_Y,    SE_U,    SE_I,    SE_O, SE_P,    SE_ARNG,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ___X___,     C_A,     A_S,     S_D,     G_F,     H_G,                          H_H,     G_J,     S_K,     A_L,    C_OE, SE_ADIA,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ___X___,    SE_Z,    SE_X,    SE_C,     M_V,     M_B,                         SE_N,     M_M,     COM,     DOT,    SLSH,    QUOT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              N_ESC,   N_TAB,   S_ENT,      S_SPC, KC_BSPC, MO(G_N)
                                        //`--------------------------'  `-------------------------
  ),
  [GAME] = LAYOUT_split_3x6_3(
     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          KC_ESC,    SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,                         SE_Y,    SE_U,    SE_I,    SE_O,    SE_P, SE_ARNG,
     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_LSFT,    SE_A,    SE_S,    SE_D,    SE_F,    SE_G,                         SE_H,    SE_J,    SE_K,    SE_L, SE_ODIA, SE_ADIA,
     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_LALT,    SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,                         SE_N,    SE_M,     COM,     DOT,    SLSH,    QUOT,
     //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI, KC_TAB ,KC_ENT,            KC_SPC, KC_BSPC, MO(G_N)
                                         //`--------------------------'  `-------------------------
    ),
  [G_N] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------
        ___X___,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ___X___,    SE_1,    SE_2,    SE_3,    SE_4,    SE_5,                         SE_6,    SE_7,    SE_8,    SE_9,    SE_0,  KC_F12,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------
                                           TG(GAME), _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
  ),
  [SYM_R] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        ___X___, ___X___, ___X___, ___X___, KC_VOLU, ___X___,                      SE_PIPE, SE_LABK, SE_RABK,   SE_AT, SE_PERC, ___X___,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ___X___, ___X___, KC_MPRV, KC_MNXT, KC_MPLY, KC_MUTE,                      SE_AMPR, SE_EXLM, SE_COLN,  SE_EQL, SE_QUES, ___X___,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ___X___, ___X___, ___X___, ___X___, KC_VOLD, _______,                      SE_MINS, SE_PLUS, SE_SLSH, SE_ASTR, SE_BSLS, ___X___,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------
                                            _______, _______, _______,       _______, _______, _______
                                        //`--------------------------'  `--------------------------'
    ),
    [SYM_L] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        ___X___, SE_CIRC, SE_QUOT, SE_LBRC, SE_RBRC, SE_DQUO,                      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ___X___, SE_GRV,   SE_DLR, SE_LCBR, SE_RCBR, SE_UNDS,                      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ___X___, SE_TILD, SE_HASH, SE_LPRN, SE_RPRN, SE_SCLN,                      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------
                                            _______, _______, _______,    _______, _______, _______
    //`--------------------------'  `--------------------------'
    ),
    [NUM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                     ___X___,     SE_7,    SE_8,    SE_9, SE_MINS, SE_PLUS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                     KC_TAB ,     SE_4,    SE_5,    SE_6, SE_SLSH, SE_ASTR,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        QK_BOOT, ___X___, ___X___, ___X___, ___X___, ___X___,                         SE_0,    SE_1,    SE_2,    SE_3,  SE_DOT, SE_COMM,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------
                                            _______, _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
        ),
    [NAV] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                 ,-----------------------------------------------------.
        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                      ___X___, KC_PGUP,   KC_UP, KC_PGDN, ___X___, ___X___,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ___X___, _______, _______, _______, _______, ___X___,                      ___X___, KC_LEFT, KC_DOWN,KC_RIGHT, ___X___, ___X___,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,                      ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------
                                            _______, _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
    ),
    [MOUSE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, _______, _______, _______, _______, _______,                          ___X___, KC_WH_D, KC_MS_U, KC_WH_U, ___X___,___X___ ,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______,                          KC_WH_R, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_L, ___X___,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______, _______,                          ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------
                                    MO(QWERTY), TG(MOUSE), KC_MS_BTN1,   KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3
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

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
            // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case SE_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

#ifdef OLED_ENABLE
// Animation parameters
#define FRAME_DURATION 1000 // How long each frame lasts in milliseconds

// Animation variables
uint32_t timer = 0;
uint8_t current_frame = 0;

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0,
        0xf0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xfe, 0xf8, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x1f, 0x3f,
        0xff, 0xff, 0xff, 0x7f, 0x3f, 0x3f, 0x1f, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0xff, 0xe7, 0xc3, 0xc3, 0xc3, 0x83, 0x83, 0x87, 0x1f, 0x1e,
        0x18, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0x30, 0x38, 0x18, 0x18, 0x38, 0x30, 0xf0, 0xe0, 0xc0, 0x00,
        0x00, 0xf0, 0xf0, 0xf0, 0x30, 0x30, 0x38, 0x38, 0x38, 0xf8, 0xf0, 0xe0, 0x00, 0x00, 0xc0, 0xe0,
        0xf0, 0x70, 0x38, 0x38, 0x38, 0x30, 0x70, 0xff, 0xff, 0xff, 0x00, 0x00, 0xf1, 0xf3, 0xf1, 0x00,
        0x30, 0x30, 0xff, 0xff, 0xff, 0x31, 0x31, 0x00, 0x10, 0xf0, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x80, 0xf0, 0xf0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe0, 0xe0,
        0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xfe, 0xf8, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x38, 0x78, 0xf8, 0xe0, 0xc1, 0xc1, 0xc1, 0x83, 0xc3, 0xc3, 0xe7, 0xff,
        0x7e, 0x00, 0x00, 0x3f, 0x7f, 0xf6, 0xc6, 0xc6, 0x86, 0x86, 0xc6, 0xc6, 0xe7, 0xe7, 0x27, 0x00,
        0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x3f, 0x7f,
        0xf0, 0xc0, 0xc0, 0x80, 0x80, 0xc0, 0xe0, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00,
        0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x7f, 0xf8, 0xf0, 0xfc,
        0x3f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x1f, 0x3f,
        0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x1f, 0x1f, 0x0f, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00,
        0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1c, 0x1c, 0x1e, 0x0f, 0x07, 0x01,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
     static const char PROGMEM raw_logo2[] = {
             0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x1f,
            0x0f, 0x0f, 0x07, 0x03, 0x03, 0x01, 0x00, 0x01, 0x07, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x3f, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0xff,
            0xff, 0xff, 0xff, 0x7f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xe0, 0xc0,
            0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xf0, 0xf0, 0xf8, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0x81, 0x00, 0x18, 0x3c, 0x3c, 0x3c, 0x7c, 0x7c, 0x78, 0xe0, 0xe1,
            0xe7, 0xff, 0xff, 0x3f, 0x1f, 0x0f, 0xcf, 0xc7, 0xc7, 0xe7, 0xc7, 0xcf, 0x0f, 0x1f, 0x3f, 0xff,
            0xff, 0x0f, 0x0f, 0x0f, 0xcf, 0xcf, 0xc7, 0xc7, 0xc7, 0x0f, 0x0f, 0x1f, 0xff, 0xff, 0x3f, 0x1f,
            0x0f, 0x8f, 0xc7, 0xc7, 0xc7, 0xcf, 0x8f, 0x00, 0x00, 0x00, 0xff, 0xff, 0x0e, 0x0c, 0x0e, 0xff,
            0xcf, 0xcf, 0x00, 0x00, 0x00, 0xce, 0xce, 0xff, 0xef, 0x0f, 0x0f, 0x3f, 0xff, 0xff, 0xff, 0xff,
            0x7f, 0x0f, 0x0f, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x1f, 0x1f,
            0x0f, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xc7, 0x87, 0x07, 0x1f, 0x3e, 0x3e, 0x3e, 0x7c, 0x3c, 0x3c, 0x18, 0x00,
            0x81, 0xff, 0xff, 0xc0, 0x80, 0x09, 0x39, 0x39, 0x79, 0x79, 0x39, 0x39, 0x18, 0x18, 0xd8, 0xff,
            0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x00,
            0x0f, 0x3f, 0x3f, 0x7f, 0x7f, 0x3f, 0x1f, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff,
            0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xe0, 0x80, 0x07, 0x0f, 0x03,
            0xc0, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xe0, 0xc0,
            0x00, 0x00, 0x80, 0x80, 0xc0, 0xe0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff,
            0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xe3, 0xe3, 0xe1, 0xf0, 0xf8, 0xfe,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
     };
// Animation frames array
    const char* epd_bitmap_allArray [] = {
        raw_logo,
        raw_logo2
    };

    // Frame sizes array
    uint16_t frame_sizes[2] = {
        sizeof(raw_logo),
        sizeof(raw_logo2)
    };

    // Run animation
    if (timer_elapsed(timer) > FRAME_DURATION) {
        // Set timer to updated tim
        timer = timer_read();

        // Increment frame
        current_frame = (current_frame + 1) % (sizeof(epd_bitmap_allArray) / sizeof(epd_bitmap_allArray[0]));

        // Draw frame to OLED
        oled_write_raw_P(epd_bitmap_allArray[current_frame], frame_sizes[current_frame]);
    }
}
static void oled_render_modifiers(void) {
    oled_write_P(PSTR("Mods: "), false);
    if (get_mods() & MOD_BIT(KC_LCTL)) {
        oled_write_P(PSTR("LCtrl "), false);
    }
    if (get_mods() & MOD_BIT(KC_LSFT)) {
        oled_write_P(PSTR("LShift "), false);
    }
    if (get_mods() & MOD_BIT(KC_LALT)) {
        oled_write_P(PSTR("LAlt "), false);
    }
    if (get_mods() & MOD_BIT(KC_LGUI)) {
        oled_write_P(PSTR("LGui "), false);
    }
    if (get_mods() & MOD_BIT(KC_RCTL)) {
        oled_write_P(PSTR("RCtrl "), false);
    }
    if (get_mods() & MOD_BIT(KC_RSFT)) {
        oled_write_P(PSTR("RShift "), false);
    }
    if (get_mods() & MOD_BIT(KC_RALT)) {
        oled_write_P(PSTR("RAlt "), false);
    }
    if (get_mods() & MOD_BIT(KC_RGUI)) {
        oled_write_P(PSTR("RGui "), false);
    }
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(""), false);
}
static void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case QWERTY:
            oled_write_ln_P(PSTR("QWERTY"),false);
            break;
        case GAME:
            oled_write_ln_P(PSTR("GAME"),false);
            break;
        case MOUSE:
            oled_write_ln_P(PSTR("Mouse"),false);
            break;
        case G_N:
            oled_write_ln_P(PSTR("Number row"),false);
            break;
        case SYM_L:
            oled_write_ln_P(PSTR("Symbol Left"),false);
            break;
        case SYM_R:
            oled_write_ln_P(PSTR("Symbol Right"),false);
            break;
        case NUM:
            oled_write_ln_P(PSTR("Number pad"),false);
            break;
        case NAV:
            oled_write_ln_P(PSTR("Navigation"),false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
            break;
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_modifiers();
    } else {
        render_logo();
    }
    return false;
}

#endif