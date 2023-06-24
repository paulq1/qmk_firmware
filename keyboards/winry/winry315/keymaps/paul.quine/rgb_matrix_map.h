#define ARRAYSIZE(arr) sizeof(arr) / sizeof(arr[0])

#ifdef RGB_MATRIX_ENABLE

enum led_location_map {
    LED_ENCODE_RIGHT_TOP_RIGHT,  //   0 - right encoder, top right
    LED_ENCODE_RIGHT_TOP_LEFT,   //   1 - right encoder, top left
    LED_ENCODE_CENTRE_TOP_RIGHT, //   2 - center encoder, top right
    LED_ENCODE_CENTRE_TOP_LEFT,  //   3 - center encoder, top left
    LED_ENCODE_LEFT_TOP_RIGHT,   //   4 - left encoder, top right
    LED_ENCODE_LEFT_TOP_LEFT,    //   5 - left encoder, top left
    LED_R0_C0,                   //   6 - row 0, column 0
    LED_R1_C0,                   //   7 - row 1, column 0
    LED_R2_C0,                   //   8 - row 2, column 0
    LED_R2_C1,                   //   9 - row 2, column 1
    LED_R1_C1,                   //  10 - row 1, column 1
    LED_R0_C1,                   //  11 - row 0, column 1
    LED_R0_C2,                   //  12 - row 0, column 2
    LED_R1_C2,                   //  13 - row 1, column 2
    LED_R2_C2,                   //  14 - row 2, column 2
    LED_R2_C3,                   //  15 - row 2, column 3
    LED_R1_C3,                   //  16 - row 1, column 3
    LED_R0_C3,                   //  17 - row 0, column 3
    LED_R0_C4,                   //  18 - row 0, column 4
    LED_R1_C4,                   //  19 - row 1, column 4
    LED_R2_C4,                   //  20 - row 2, column 4
    LED_UNDER_RB,                //  21 - underglow, right bottom
    LED_UNDER_LB,                //  22 - underglow, left bottom
    LED_UNDER_LM,                //  23 - underglow, left middle
    LED_UNDER_LT,                //  24 - underglow, left top
    LED_UNDER_RT,                //  25 - underglow, right top
    LED_UNDER_RM,                //  26 - underglow, right middle
};

const uint8_t LED_LIST_REDS[] = {LED_R0_C0};

const uint8_t LED_LIST_YELLOW[] = {LED_R2_C0};

const uint8_t LED_LIST_BLUE[] = {LED_R0_C1, LED_R0_C2, LED_R0_C3, LED_R0_C4, LED_R2_C1, LED_R2_C2, LED_R2_C3, LED_R2_C4};

const uint8_t LED_LIST_BLACK[] = {LED_ENCODE_RIGHT_TOP_RIGHT, LED_ENCODE_RIGHT_TOP_LEFT, LED_ENCODE_CENTRE_TOP_RIGHT, LED_ENCODE_CENTRE_TOP_LEFT, LED_ENCODE_LEFT_TOP_RIGHT, LED_ENCODE_LEFT_TOP_LEFT, LED_UNDER_RB, LED_UNDER_LB, LED_UNDER_LM, LED_UNDER_LT, LED_UNDER_RT, LED_UNDER_RM};

const uint8_t LED_ALL[] = {LED_R0_C0, LED_R1_C0, LED_R2_C0, LED_R2_C1, LED_R1_C1, LED_R0_C1, LED_R0_C2, LED_R1_C2, LED_R2_C2, LED_R2_C3, LED_R1_C3, LED_R0_C3, LED_R0_C4, LED_R1_C4, LED_R2_C4};

const uint8_t LED_LAYER_1_WHITE[]  = {LED_ENCODE_LEFT_TOP_LEFT};
const uint8_t LED_LAYER_1_RED[]    = {LED_R0_C0};
const uint8_t LED_LAYER_1_BLUE[]   = {};
const uint8_t LED_LAYER_1_YELLOW[] = {};

#endif