#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"
#include "pq_color.h"
#include "pq_strings.h"
#include "keymap_uk.h"
#include "sendstring_uk.h"

bool encoder_volume(bool clockwise);
void pq_toggle_rgb(void);

bool pq_is_rgb_enabled = false;

enum my_keycodes {
    SS_CUSTOM_STRING_1 = SAFE_RANGE,
    SS_CUSTOM_STRING_2,
    SS_CUSTOM_STRING_3,
    SS_CUSTOM_STRING_4,
    SS_CUSTOM_STRING_5,
    SS_CUSTOM_STRING_6,
    SS_CUSTOM_STRING_7,
    LED_OFF
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Del           Rotary(Mute)
    //      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           PgUp
    //      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgDn
    //      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             Home
    //      Sh_L     \        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
    //      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_HOME,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, OSL(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        KC_TRNS, SS_CUSTOM_STRING_1, SS_CUSTOM_STRING_2, SS_CUSTOM_STRING_3, SS_CUSTOM_STRING_4, SS_CUSTOM_STRING_5, SS_CUSTOM_STRING_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SS_CUSTOM_STRING_7, KC_TRNS, LED_OFF,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,          KC_MNXT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_MPRV,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_MPLY,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_MSTP,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(get_highest_layer(layer_state)) {
        case 0:
            encoder_volume(clockwise);
            break;
    }
    return true;
}

bool encoder_volume(bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}

void pq_toggle_rgb(void) {
    pq_is_rgb_enabled = !pq_is_rgb_enabled;
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
        case SS_CUSTOM_STRING_3:
            if (record->event.pressed) {
                send_string(pq_custom_string_3());
            }
            return false;
        case SS_CUSTOM_STRING_4:
            if (record->event.pressed) {
                send_string(pq_custom_string_4());
            }
            return false;
        case SS_CUSTOM_STRING_5:
            if (record->event.pressed) {
                send_string(pq_custom_string_5());
            }
            return false;
        case SS_CUSTOM_STRING_6:
            if (record->event.pressed) {
                send_string(pq_custom_string_6());
            }
            return false;
        case SS_CUSTOM_STRING_7:
            if (record->event.pressed) {
                send_string(pq_custom_string_7());
            }
            return false;
        case LED_OFF:
            if (record->event.pressed) {
                pq_toggle_rgb();
            }
            return false;
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE
void pq_rgb(const uint8_t array[], size_t pq_size, uint8_t colour) {
    int red;
    int green;
    int blue;

    switch (colour) {
        case PQ_BLACK: // black
            red   = 0x00;
            green = 0x00;
            blue  = 0x00;
            break;
        case PQ_WHITE: // white
        default:
            red   = 0xFF;
            green = 0xFF;
            blue  = 0xFF;
            break;
        case PQ_BLUE: // blue
            red   = 0x00;
            green = 0x80;
            blue  = 0xFF;
            break;
        case PQ_RED: // red
            red   = 0xFF;
            green = 0x05;
            blue  = 0x05;
            break;
        case PQ_YELLOW: // yellow
            red   = 0xFF;
            green = 0xEF;
            blue  = 0x00;
            break;
        case PQ_PURPLE: //purple
            red   = 0xFF;
            green = 0x00;
            blue  = 0xFF;
            break;
    }
    for (uint8_t i = 0; i < pq_size; i++) {
        rgb_matrix_set_color(array[i], red, green, blue);
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    rgb_matrix_set_color(LED_LALT, 0x00, 0x00, 0x00);
    if (!pq_is_rgb_enabled) {
        pq_rgb(LED_ALL, ARRAYSIZE(LED_ALL), PQ_BLACK);
        if (host_keyboard_led_state().caps_lock) {
            pq_rgb(LED_SIDE_LEFT, ARRAYSIZE(LED_SIDE_LEFT), PQ_RED);
            rgb_matrix_set_color(LED_CAPS, 0xFF, 0x05, 0x05);
        }
        return false;
    }

    pq_rgb(LED_ALL, ARRAYSIZE(LED_ALL), PQ_WHITE);

    switch (get_highest_layer(layer_state)) {
        case 0:
            pq_rgb(LED_LIST_REDS, ARRAYSIZE(LED_LIST_REDS), PQ_RED);
            pq_rgb(LED_LIST_YELLOW, ARRAYSIZE(LED_LIST_YELLOW), PQ_YELLOW);
            pq_rgb(LED_LIST_BLUE, ARRAYSIZE(LED_LIST_BLUE), PQ_BLUE);
            break;
        case 1:
            pq_rgb(LED_ALL, ARRAYSIZE(LED_ALL), PQ_BLACK);
            pq_rgb(LED_SIDE_LEFT, ARRAYSIZE(LED_SIDE_LEFT), PQ_WHITE);
            pq_rgb(LED_SIDE_RIGHT, ARRAYSIZE(LED_SIDE_RIGHT), PQ_WHITE);
            pq_rgb(LED_LAYER_1_WHITE, ARRAYSIZE(LED_LAYER_1_WHITE), PQ_WHITE);
            pq_rgb(LED_LAYER_1_RED, ARRAYSIZE(LED_LAYER_1_RED), PQ_RED);
            pq_rgb(LED_LAYER_1_BLUE, ARRAYSIZE(LED_LAYER_1_BLUE), PQ_BLUE);
            pq_rgb(LED_LAYER_1_YELLOW, ARRAYSIZE(LED_LAYER_1_YELLOW), PQ_YELLOW);
            pq_rgb(LED_LAYER_1_PURPLE, ARRAYSIZE(LED_LAYER_1_PURPLE), PQ_PURPLE);
            break;
    }

    if (host_keyboard_led_state().caps_lock) {
        pq_rgb(LED_SIDE_LEFT, ARRAYSIZE(LED_SIDE_LEFT), PQ_RED);
        rgb_matrix_set_color(LED_CAPS, 0xFF, 0x05, 0x05);
    }

    return false;
}
#endif