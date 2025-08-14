#include QMK_KEYBOARD_H

// left homerow keys
#define LA(k) LALT_T(k)
#define LG(k) LGUI_T(k)
#define LC(k) LCTL_T(k)

// right homerow keys
#define RA(k) RALT_T(k)
#define RG(k) RGUI_T(k)
#define RC(k) RCTL_T(k)

// define custom shifted keys (see https://getreuer.info/posts/keyboards/custom-shift-keys/index.html)
const custom_shift_key_t custom_shift_keys[] = {{KC_DOT, KC_COLN}, {KC_COMM, KC_SCLN}};

enum layers {
    _BASE,
    _LOWER,
    _UPPER,
    // adjust is activated when lower and upper are activated (see https://docs.qmk.fm/features/tri_layer)
    _ADJUST
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LG(KC_LCBR):
            if (record->tap.count && record->event.pressed) {
                // fix shifted mod tap
                tap_code16(KC_LCBR);
                return false;
            }
            break;
        case LC(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
        case RA(KC_QUES):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_QUES);
                return false;
            }
            break;
    }
    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_2(
    //╭──────────┬─────────────┬─────────────┬─────────────┬──────────╮   ╭──────────┬─────────────┬─────────────┬─────────────┬──────────╮
    //│  Q       │  W          │  E          │  R          │  T       │   │  Z       │  U          │  I          │  O          │  P       │
         KC_Q,      KC_W,         KC_E,         KC_R,         KC_T,          KC_Z,      KC_U,         KC_I,         KC_O,         KC_P,
    //├──────────┼─────────────┼─────────────┼─────────────┼──────────┤   ├──────────┼─────────────┼─────────────┼─────────────┼──────────┤
    //│  A       │ LAlt, S     │ LGui, D     │ LCtl, F     │  G       │   │  H       │ RCtl, J     │ RGui, K     │  RAlt, L    │BACKSPACE │
         KC_A,     LA(KC_S),      LG(KC_D),     LC(KC_F),     KC_G,          KC_H,     RC(KC_J),      RG(KC_K),      RA(KC_L),    KC_BSPC,
    //├──────────┼─────────────┼─────────────┼─────────────┼──────────┤   ├──────────┼─────────────┼─────────────┼─────────────┼──────────┤
    //│  Y       │  X          │  C          │  V          │  B       │   │  N       │  M          │ , ;         │ . :         │ ENTER    │
         KC_Y,      KC_X,         KC_C,         KC_V,         KC_B,          KC_N,      KC_M,         KC_COMM,      KC_DOT,       KC_ENT,
    //╰──────────┴─────────────┴─────────────┼─────────────┼──────────┤   ├──────────┼─────────────┼─────────────┴─────────────┴──────────╯
    //                                       │  Layer 2    │  LShift  │   │  Space   │   Layer 1   │
                                                TL_UPPR,     KC_LSFT,        KC_SPC,     TL_LOWR
    //                                       ╰─────────────┴──────────╯   ╰──────────┴─────────────╯
    ),

    [_LOWER] = LAYOUT_split_3x5_2(
    //╭──────────┬─────────────┬─────────────┬─────────────┬──────────╮   ╭──────────┬─────────────┬─────────────┬─────────────┬──────────╮
    //│  1       │  2          │  3          │  4          │  5       │   │  6       │  7          │  8          │  9          │  0       │
         KC_1,      KC_2,         KC_3,         KC_4,         KC_5,          KC_6,      KC_7,         KC_8,         KC_9,         KC_0,
    //├──────────┼─────────────┼─────────────┼─────────────┼──────────┤   ├──────────┼─────────────┼─────────────┼─────────────┼──────────┤
    //│          │ LAlt,Del    │ LGui,Caps   │ LCtl,Print  │  Insert  │   │ LArrow   │ RCtl,DArrow │ RGui,UArrow │ RAlt,RArrow │          │
         KC_TRNS,   LA(KC_DEL),  LG(KC_CAPS),  LC(KC_PSCR),   KC_INS,       KC_LEFT,   RC(KC_DOWN),  RG(KC_UP),   RA(KC_RGHT),   KC_TRNS,
    //├──────────┼─────────────┼─────────────┼─────────────┼──────────┤   ├──────────┼─────────────┼─────────────┼─────────────┼──────────┤
    //│          │             │             │             │          │   │ Home     │  PageDown   │ PageUp      │  End        │          │
        KC_TRNS,   KC_TRNS,       KC_TRNS,      KC_TRNS,     KC_TRNS,       KC_HOME,   KC_PGDN,      KC_PGUP,       KC_END,      KC_TRNS,
    //╰──────────┴─────────────┴─────────────┼─────────────┼──────────┤   ├──────────┼─────────────┼─────────────┴─────────────┴──────────╯
    //                                       │             │  Esc     │   │          │             │
                                               KC_TRNS,       KC_ESC,       KC_TRNS,   KC_TRNS
    //                                       ╰─────────────┴──────────╯   ╰──────────┴─────────────╯
    ),

    [_UPPER] = LAYOUT_split_3x5_2(
    //╭──────────┬─────────────┬─────────────┬─────────────┬──────────╮   ╭──────────┬─────────────┬─────────────┬─────────────┬──────────╮
    //│  !       │  @          │  #          │  $          │  %       │   │  ^       │  &          │  *          │  `          │  ~       │
        KC_EXLM,    KC_AT,        KC_HASH,      KC_DLR,      KC_PERC,       KC_CIRC,    KC_AMPR,      KC_ASTR,      KC_GRV,      KC_TILD,
    //├──────────┼─────────────┼─────────────┼─────────────┼──────────┤   ├──────────┼─────────────┼─────────────┼─────────────┼──────────┤
    //│  "       │  LAlt, [    │  LGui, {    │  LCtl, (    │  <       │   │  /       │  RCtl, -    │  RGui, =    │  RAlt, ?    │  Tab     │
        KC_DQUO,  LA(KC_LBRC),  LG(KC_LCBR),   LC(KC_LPRN), S(KC_COMM),     KC_SLSH,  RC(KC_MINS),   RG(KC_EQL),   RA(KC_QUES),  KC_TAB,
    //├──────────┼─────────────┼─────────────┼─────────────┼──────────┤   ├──────────┼─────────────┼─────────────┼─────────────┼──────────┤
    //│  '       │  ]          │  }          │  )          │  >       │   │  \       │   _         │   +         │   |         │          │
        KC_QUOT,   KC_RBRC,      KC_RCBR,      KC_RPRN,     S(KC_DOT),       KC_BSLS,    KC_UNDS,      KC_PLUS,      KC_PIPE,    KC_TRNS,
    //╰──────────┴─────────────┴─────────────┼─────────────┼──────────┤   ├──────────┼─────────────┼─────────────┴─────────────┴──────────╯
    //                                       │             │          │   │          │             │
                                               KC_TRNS,      KC_TRNS,       KC_TRNS,    KC_TRNS
    //                                       ╰─────────────┴──────────╯   ╰──────────┴─────────────╯
    ),

    [_ADJUST] = LAYOUT_split_3x5_2(
    //╭──────────┬─────────────┬─────────────┬─────────────┬──────────╮   ╭──────────┬─────────────┬─────────────┬─────────────┬──────────╮
    //│  F1      │  F2         │  F3         │  F4         │          │   │          │  Vol-       │  Vol+       │ AudioMute   │ NextSong │
        KC_F1,     KC_F2,        KC_F3,        KC_F4,        KC_TRNS,       KC_TRNS,    KC_VOLD,      KC_VOLU,      KC_MUTE,     KC_MNXT,
    //├──────────┼─────────────┼─────────────┼─────────────┼──────────┤   ├──────────┼─────────────┼─────────────┼─────────────┼──────────┤
    //│  F5      │ LAlt, F6    │  LGui, F7   │  LCtl, F4   │          │   │  MouseL  │ RCtl,MouseD │ LGui,MouseU │ RAlt,MouseR │Play/Pause│
        KC_F5,     LA(KC_F6),    LG(KC_F7),    LC(KC_F8),    KC_TRNS,       MS_LEFT,   RC(MS_DOWN),  RG(MS_UP),    RA(MS_RGHT),  KC_MPLY,
    //├──────────┼─────────────┼─────────────┼─────────────┼──────────┤   ├──────────┼─────────────┼─────────────┼─────────────┼──────────┤
    //│  F9      │  F10        │  F11        │  F12        │ LClick   │   │  RClick  │  Brgt-      │  Brgt+      │             │ PrevSong │
        KC_F9,     KC_F10,       KC_F11,       KC_F12,       MS_BTN1,        MS_BTN2,   KC_BRID,      KC_BRIU,      KC_TRNS,     KC_MPRV,
    //╰──────────┴─────────────┴─────────────┼─────────────┼──────────┤   ├──────────┼─────────────┼─────────────┴─────────────┴──────────╯
    //                                       │             │          │   │          │             │
                                               KC_TRNS,      KC_TRNS,       KC_TRNS,    KC_TRNS
    //                                       ╰─────────────┴──────────╯   ╰──────────┴─────────────╯
    )
};
// clang-format on
