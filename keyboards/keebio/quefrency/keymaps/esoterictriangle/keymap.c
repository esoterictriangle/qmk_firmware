#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)
#define KC_UNDO LCTL(KC_Z)
#define KC_NTAB LCTL(KC_T)
#define KC_KEE LCTL(LALT(KC_A))
#define KC_TASK LCTL(LSFT(KC_ESC))

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	/*
	* +-----------+   +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------+-----------+-----+
	* | ESC |TASK |   | GRV |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |MINS | EQL |BSPC | DEL |
	* |-----|-----|   +-----------------------------------------------------------------------------------------+
	* |HOME | END |   | TAB |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |LBRC |RBRC |BSLS |PSCR |
	* |-----|-----|   +-----+-+---+-+---+-+---+-+---+-+---+-+---+-+---+-+---+-+---+-------------+---------------+
	* |NTAB | F5  |   | CAPS  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |SCLN |QUOT |   ENT   |PGUP |
	* |-----|-----|   +-------+-+---+-+---+-+---+-+---+-+---+-+---+-+---+-----+-+---------------+---+-----------+
	* | KEE |UNDO |   |   LSFT   |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |COMM | DOT |SLSH | RSFT | UP  |PGDN |
	* |-----|-----|   +---------+-----+-----+-----+-----+-+---+-----+-----------+-------------------------------+
	* |COPY |PASTE|   |RCTL |LGUI |LALT |MO(1)|   SPACE   |       SPACE     |MO(1)|RALT |RCTL |LEFT |DOWN |RGHT |
	* +-----------+   +-----------------------------------+-----------------------------------------------+-----+
	*/
	
  [_BASE] = LAYOUT_65_with_macro(
    KC_ESC,   KC_TASK,   KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, XXXXXXX, KC_BSPC,  KC_DEL, \
    KC_HOME,   KC_END,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PSCR, \
    KC_NTAB,   KC_F5,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP, \
    KC_KEE,   KC_UNDO,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, \
    KC_COPY,   KC_PASTE,  KC_LCTL, KC_LGUI, KC_LALT, MO(_FN1), KC_SPC,        KC_SPC, XXXXXXX, MO(_FN1), KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

	/*
	* +-----------+   +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----------+-----------+-----+
	* |     |     |   |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |BSPC |RESET|
	* |-----|-----|   +-----------------------------------------------------------------------------------------+
	* |VOLU |VOLD |   |     |     | UP  |     |     |     | KP7 | KP8 | KP9 |     |     |     |     |     |     |
	* |-----|-----|   +-----+-+---+-+---+-+---+-+---+-+---+-+---+-+---+-+---+-+---+-------------+---------------+
	* |CALC |     |   |       |LEFT |DOWN |RGHT |     |     | KP4 | KP5 | KP6 |     |     |     |         |     |
	* |-----|-----|   +-------+-+---+-+---+-+---+-+---+-+---+-+---+-+---+-----+-+---------------+---+-----------+
	* |     |     |   |          |     |     |     |     |     | KP1 | KP2 | KP3 |     |     |      |     |     |
	* |-----|-----|   +---------+-----+-----+-----+-----+-+---+-----+-----------+-------------------------------+
	* |     |     |   |     |     |     |     |           |                 |     |     |     |     |     |     |
	* +-----------+   +-----------------------------------+-----------------------------------------------+-----+
	*/
	
  [_FN1] = LAYOUT_65_with_macro(
    _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,  _______, RESET, \
    KC_VOLU, KC_VOLD, _______, _______, KC_UP, _______,  _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______, _______, _______, _______, _______, \
    KC_CALC, _______, _______,  KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,      KC_KP_0, XXXXXXX, _______, _______, _______, _______, _______, _______
  )
};
