#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _NAV,
    _MOUSE,
};

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     *        +------+------+------+------+------+                                  +------+------+------+------+------+
     *        |   q  |   w  |   e  |   r  |   t  |                                  |   y  |   u  |   i  |   o  |   p  |
     * +------+------+------+------+------+------|                                  |------+------+------+------+------+------|
     * |      |   a  |   s  |   d  |   f  |   g  |                                  |   h  |   j  |   k  |   l  |   ;  |   '  |
     * +------+------+------+------+------+------|                                  |------+------+------+------+------+------|
     *        |   z  |   x  |   c  |   v  |   b  |                                  |   n  |   m  |   ,  |   .  |   /  |
     *        +------+------+------+-------------+------+------+      +------+------+------+------+------+------+------+
     *                                    |ctlesc|lwrspc|suptab|      |shftbk|uprent|altdel|
     *                                    +------+------+------+      +------+------+------+
     */
    [_BASE] = LAYOUT(
                       KC_Q,     KC_W,   KC_E,     KC_R,    KC_T,         KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,
   LT(_NAV, KC_ESC),   KC_A,     KC_S,   KC_D,     KC_F,    KC_G,         KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,   KC_QUOT,
                       KC_Z,     KC_X,   KC_C,     KC_V,    KC_B,         KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,
              LCTL_T(KC_ESC), LT(_LOWER, KC_SPC), LGUI_T(KC_TAB),         RSFT_T(KC_BSPC), LT(_RAISE, KC_ENT), RALT_T(KC_DEL)
    ),

    /* Lower
     *        +------+------+------+------+------+                                  +------+------+------+------+------+
     *        |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |
     * +------+------+------+------+------+------|                                  |------+------+------+------+------+------|
     * |   ~  |   !  |   @  |   #  |   $  |   %  |                                  |   ^  |   &  |   *  |   (  |   )  |   |  |
     * +------+------+------+------+------+------|                                  |------+------+------+------+------+------|
     *        |   +  |   -  |   =  |   _  |      |                                  |      |      |      |      |      |
     *        +------+------+------+-------------+------+------+      +------+------+------+------+------+------+------+
     *                                    |      |      |      |      |      |      |      |
     *                                    +------+------+------+      +------+------+------+
     */
    [_LOWER] = LAYOUT(
                   KC_1,     KC_2,    KC_3,     KC_4,     KC_5,         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
        KC_TILDE,  KC_EXLM,  KC_AT,   KC_HASH,  KC_DLR,   KC_PERC,      KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,   KC_PIPE,
                   KC_PLUS,  KC_MINS, KC_EQL,   KC_UNDS,  _______,      _______,  _______,  _______,  _______,  _______,
                                      _______,  _______,  _______,      _______,  _______,   _______
    ),

    /* Upper
     *        +------+------+------+------+------+                                  +------+------+------+------+------+
     *        |  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  |  F10 |
     * +------+------+------+------+------+------|                                  |------+------+------+------+------+------|
     * |   `  |  F11 |  F12 |      |      |      |                                  |      |   [  |   ]  |   {  |   }  |  \   |
     * +------+------+------+------+------+------|                                  |------+------+------+------+------+------|
     *        |      |      |      |      |      |                                  |      |      |      |      |      |
     *        +------+------+------+-------------+------+------+      +------+------+------+------+------+------+------+
     *                                    |      |      |      |      |      |      |      |
     *                                    +------+------+------+      +------+------+------+
     */
    [_RAISE] = LAYOUT(
                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_GRV,  KC_F11,  KC_F12,  _______, _______, _______,    _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,   KC_BSLS,
                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
                                   _______, _______, _______,    _______, _______, _______
    ),

    /* Navigate
     *        +------+------+------+------+------+                                  +------+------+------+------+------+
     *        |      |      |      |      |      |                                  |      |      |      |      |      |
     * +------+------+------+------+------+------|                                  |------+------+------+------+------+------|
     * |      |      | home | pgup | end  |      |                                  |      | left |  up  | right|      |      |
     * +------+------+------+------+------+------|                                  |------+------+------+------+------+------|
     *        |      |      | pgdn |      |      |                                  |      |      | down |      |      |
     *        +------+------+------+-------------+------+------+      +------+------+------+------+------+------+------+
     *                                    |      |      |      |      |      |      |      |
     *                                    +------+------+------+      +------+------+------+
     */
    [_NAV] = LAYOUT(
                 _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        _______, _______, KC_HOME, KC_PGUP, KC_END,  _______,      _______, KC_LEFT, KC_UP,   KC_RGHT, _______,   _______,
                 _______, _______, KC_PGDN, _______, _______,      _______, _______, KC_DOWN, _______, _______,
                                   _______, _______, _______,      _______, _______, _______
    ),

    [_MOUSE] = LAYOUT(
                 _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,      _______, _______, _______,_______, _______,   _______,
                 _______, _______, _______, _______, _______,      DRAG_SCROLL, _______, _______, _______, TG(_MOUSE),
                            MO(_MOUSE), DRAG_SCROLL, _______,      KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2
    ),
};

bool set_scrolling = false;

#define SCROLL_DIVISOR_H 32.0
#define SCROLL_DIVISOR_V 32.0

float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = -(int8_t)scroll_accumulated_v;

        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DRAG_SCROLL) {
        set_scrolling = record->event.pressed;
        return false;
    }
    return true;
}

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
}
