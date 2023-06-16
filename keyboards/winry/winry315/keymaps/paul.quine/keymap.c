#include QMK_KEYBOARD_H
#include "pq_color.h"

bool encoder_volume(bool clockwise);
const char* pq_temp(void);

enum my_keycodes {
    SS_HELLO = SAFE_RANGE
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_top(
            KC_NO,      KC_MUTE,     KC_MPLY,
        LCTL(LALT(KC_DEL)),    SS_HELLO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        MO(1),    KC_NO,    KC_NO,    KC_NO,    KC_NO
    ),

    [1] = LAYOUT_top(
            KC_NO,      KC_NO,     KC_NO,
        QK_BOOT,   KC_F13,    KC_F14,    KC_F15,    KC_F16,
        KC_F17,    KC_F18,    KC_F19,    KC_F20,    KC_F21,
        KC_TRNS,  KC_F22,    KC_F23,    KC_F24,    KC_NO
    ),
};
// clang-format on

const char* pq_temp(void){
    return "Hello, world!\n";
}

bool encoder_volume(bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 1:
            encoder_volume(clockwise);
            break;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SS_HELLO:
            if (record->event.pressed) {
                send_string(pq_temp());
            }
            return false;
    }
    return true;
}