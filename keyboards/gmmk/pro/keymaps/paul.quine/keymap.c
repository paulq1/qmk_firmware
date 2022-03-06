#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"
#include "pq_color.h"

bool encoder_volume(bool clockwise);

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
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,            KC_MNXT,
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

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

#ifdef RGB_MATRIX_ENABLE
    void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max){
        for (uint8_t i=0; i<ARRAYSIZE(LED_ALL); i++) {
            rgb_matrix_set_color(LED_ALL[i], PQ_WHITE);
        }

        switch(get_highest_layer(layer_state)){
            case 0:
                for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_REDS); i++) {
                    rgb_matrix_set_color(LED_LIST_REDS[i], PQ_RED);
                }
                for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_YELLOW); i++) {
                    rgb_matrix_set_color(LED_LIST_YELLOW[i], PQ_YELLOW);
                }
                for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_BLUE); i++) {
                    rgb_matrix_set_color(LED_LIST_BLUE[i], PQ_BLUE);
                }
                break;
            case 1:
                for (uint8_t i=0; i<ARRAYSIZE(LED_ALL); i++) {
                    rgb_matrix_set_color(LED_ALL[i], PQ_BLACK);
                }
                for (uint8_t i=0; i<ARRAYSIZE(LED_SIDE_LEFT); i++) {
                    rgb_matrix_set_color(LED_SIDE_LEFT[i], PQ_WHITE);
                }
                for (uint8_t i=0; i<ARRAYSIZE(LED_SIDE_RIGHT); i++) {
                    rgb_matrix_set_color(LED_SIDE_RIGHT[i], PQ_WHITE);
                }
                for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_FN_1_KEYS); i++) {
                    rgb_matrix_set_color(LED_LIST_FN_1_KEYS[i], PQ_WHITE);
                }
                break;
        }

        if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
            for (uint8_t i=0; i<ARRAYSIZE(LED_SIDE_LEFT); i++) {
                rgb_matrix_set_color(LED_SIDE_LEFT[i], PQ_RED);
            }
            rgb_matrix_set_color(LED_CAPS, PQ_RED);
        }
    }
#endif