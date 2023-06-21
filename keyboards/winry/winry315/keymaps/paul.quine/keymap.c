#include QMK_KEYBOARD_H
#include "pq_color.h"
#include "pq_strings.h"
#include "rgb_matrix_map.h"
#include "keymap_uk.h"
#include "sendstring_uk.h"

bool encoder_volume(bool clockwise);
bool encoder_back_forward(bool clockwise);
bool encoder_up_down(bool clockwise);

enum my_keycodes {
    SS_CUSTOM_STRING_1 = SAFE_RANGE,
    SS_CUSTOM_STRING_2
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_top(
            KC_NO,      KC_MUTE,     KC_NO,
        LCTL(LALT(KC_DEL)),    SS_CUSTOM_STRING_1,    SS_CUSTOM_STRING_2,    KC_NO,    KC_NO,
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

bool encoder_volume(bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}

bool encoder_back_forward(bool clockwise) {
    if (clockwise) {
        tap_code(KC_RGHT);
    } else {
        tap_code(KC_LEFT);
    }
    return true;
}

bool encoder_up_down(bool clockwise) {
    if (clockwise) {
        tap_code(KC_PGDN);
    } else {
        tap_code(KC_PGUP);
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            encoder_back_forward(clockwise);
            break ;
        case 1:
            encoder_volume(clockwise);
            break;
        case 2:
            encoder_up_down(clockwise);
            break;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SS_CUSTOM_STRING_1:
            if (record->event.pressed) {
                send_string(pq_custom_string_1());
            }
            return false;
        case SS_CUSTOM_STRING_2:
            if (record->event.pressed) {
                send_string(pq_custom_string_2());
            }
            return false;
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE
    bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        for (uint8_t i=0; i<ARRAYSIZE(LED_ALL); i++) {
            rgb_matrix_set_color(LED_ALL[i], PQ_WHITE);
        }
        return false;
    }
#endif