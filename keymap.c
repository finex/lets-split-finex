#include QMK_KEYBOARD_H


// Layer names
enum{
  _COLEMAKDHMK,
  _QWERTY,
  _SYMB,
  _NUMB,
  _FUNC,
  _RHSH, // Righ hand shifted keycodes
  _LHSH, // Left hand shifted keycodes
  _RHSH_QWERTY, // Righ hand shifted keycodes (qwerty version)
  _LHSH_QWERTY, // Left hand shifted keycodes (qwerty version)
  _ADJUST
};

// Custom keycodes
enum custom_keycodes {
  COLEMAKDHMK = SAFE_RANGE,
  QWERTY,
  ASC_SAR,
  ASC_DAR,
  ASC_SQT,
  ASC_DQT,
  ASC_CIRC,
  ASC_TILD,
  ASC_HAP,
  ASC_SAD,
  ASC_BKT,
  ASC_CBRL,
  ASC_CBRR,
  ASC_LAN,
  ASC_RAN
};


// Tap dance keycodes
enum tap_dance{
  TD_SCLN, // ;; -> :
  TD_LBRC, // [[ -> {
  TD_RBRC, // ]] -> }
  TD_QMRK  // // -> ?
};

// Semicolon to Colon
void dance_scln_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SCLN);
  } else {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  }
}
void dance_scln_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  }
}

// Square braket to curly bracket (left)
void dance_lbrc_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LBRC);
  } else {
    register_code (KC_RSFT);
    register_code (KC_LBRC);
  }
}
void dance_lbrc_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LBRC);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_LBRC);
  }
}

// Square braket to curly bracket (right)
void dance_rbrc_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RBRC);
  } else {
    register_code (KC_RSFT);
    register_code (KC_RBRC);
  }
}
void dance_rbrc_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RBRC);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_RBRC);
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SCLN]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_scln_finished, dance_scln_reset),
  [TD_LBRC]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lbrc_finished, dance_lbrc_reset),
  [TD_RBRC]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rbrc_finished, dance_rbrc_reset)
};


// Shortcuts to make keymap more readable

// - Adjustment Layer:
#define KC_ADEN LT(_ADJUST, KC_END)   // End / _ADJUST layer
#define KC_ADPU LT(_ADJUST, KC_PGUP)  // Page Up / _ADJUST layer
// - Custom home row layers (colemak):
#define KC_N_SH LT(_LHSH, KC_N)       // Pressing N key, enable shifted keys on other half (the left one)
#define KC_T_SH LT(_RHSH, KC_T)       // Pressing T key, enable shifted keys on other half (the right one)
// - Custom home row layers (qwerty):
#define KC_J_SH LT(_LHSH_QWERTY, KC_J)       // Pressing J key, enable shifted keys on other half (the left one)
#define KC_F_SH LT(_RHSH_QWERTY, KC_F)       // Pressing F key, enable shifted keys on other half (the right one)
// - Custom layers:
#define KC_SYSP LT(_SYMB, KC_SPC)     // Space / _symbols
#define KC_SYES LT(_SYMB, KC_ESC)     // Esc / _symbols
#define KC_NBSC LT(_NUMB, KC_BSPC)    // Backspace / _numbers
#define KC_FULE LT(_FUNC, KC_LEFT)    // Left / _functions
#define KC_FU MO(_FUNC)               // _functions
// - Custom keys/modifiers:
#define KC_ATAB RALT_T(KC_TAB)        // - Tab / Alt Gr
#define KC_CESC LCTL_T(KC_ESC)        // - Esc / Left Ctrl
#define KC_CDEL LCTL_T(KC_DEL)        // - Esc / Left Ctrl
#define KC_AEQL LALT_T(KC_EQL)        // - Equals / Left Alt
#define KC_CMIN RCTL_T(KC_MINUS)      // - Minus / Right Ctrl
#define KC_CENT RCTL_T(KC_ENT)        // Enter / Right ctrl
#define KC_GURI RGUI_T(KC_RGHT)    // Right / Right gui
#define KC_HYBL HYPR_T(KC_LBRC)       // - Left Bracket / Hyper
#define KC_MEBR MEH_T(KC_RBRC)        // - Right Bracket / Meh
#define KC_GSPC LGUI_T(KC_SPC)        // - Space / Left GUI
// Home row mod tap keys (colemak):
// - Left hand
#define KC_GU_A LGUI_T(KC_A)          // A / Left Gui
#define KC_AL_R LALT_T(KC_R)          // S / Left Alt
#define KC_CT_S LCTL_T(KC_S)          // R / Left Ctrl
// - Right hand
#define KC_GU_O RGUI_T(KC_O)          // O / Right Gui
#define KC_AL_I LALT_T(KC_I)          // E / Left Alt (left alt because used as Emacs M- )
#define KC_CT_E RCTL_T(KC_E)          // I / Right Ctrl
// Home row mod tap keys (qwerty):
// - Left hand
//#define KC_GU_A LGUI_T(KC_A)          // A / Left Gui -> already defined on colemak
#define KC_AL_S LALT_T(KC_S)          // S / Left Alt
#define KC_CT_D LCTL_T(KC_D)          // D / Left Ctrl
// - Right hand
#define KC_GU_SC RGUI_T(KC_SCLN)       // ; / Right Gui
#define KC_AL_L  LALT_T(KC_L)          // L / Left Alt (left alt because used as Emacs M- )
#define KC_CT_K  RCTL_T(KC_K)          // K / Right Ctrl
// - Tap dance:
#define KC_TDSC TD(TD_SCLN)           // ;; -> :
#define KC_TDLB TD(TD_LBRC)           // [[ -> {
#define KC_TDRB TD(TD_RBRC)           // ]] -> }
// - Keyboard base maps:
#define LR1 COLEMAKDHMK
#define LR2 QWERTY


// Send custom strings or change default base layer
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case ASC_SAR:
        SEND_STRING("->");
        return false;
      case ASC_DAR:
        SEND_STRING("=>");
        return false;
      case ASC_SQT:
        // SS_RALT(): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT("'"));
        return false;
      case ASC_DQT:
        // SS_RALT(SS_LSFT()): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT(SS_LSFT("\"")));
        return false;
      case ASC_CIRC:
        // SS_RALT(): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT("^"));
        return false;
      case ASC_TILD:
        // SS_RALT(SS_LSFT()): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT(SS_LSFT("~")));
        return false;
      case ASC_HAP:
        SEND_STRING(":-) ");
        return false;
      case ASC_SAD:
        SEND_STRING(":-( ");
        return false;
      case ASC_BKT:
        // SS_RALT(): Avoid sending dead key on software intl layouts
        SEND_STRING(SS_RALT("`"));
        return false;
      case ASC_CBRL:
        SEND_STRING("{");
        return false;
      case ASC_CBRR:
        SEND_STRING("}");
        return false;
      case ASC_LAN:
        SEND_STRING(SS_RALT("["));
        return false;
      case ASC_RAN:
        SEND_STRING(SS_RALT("]"));
        return false;
      case QWERTY:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;
      case COLEMAKDHMK:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_COLEMAKDHMK);
        }
        return false;
        break;
    }
  }
  return true;
};


// Fine tuning of TAPPING_TERM valuer on some home row modifiers to avoid errors during typing.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  // Ring fingers
  case KC_AL_I:
  case KC_AL_R:
  case KC_AL_S:
  case KC_AL_L:
    return TAPPING_TERM + 200;
  // Pinkies
  case KC_GU_O:
  case KC_GU_A:
  case KC_GU_SC:
    return TAPPING_TERM + 50;
  // Middle fingers
  case KC_CT_S:
  case KC_CT_E:
  case KC_CT_D:
  case KC_CT_K:
    return TAPPING_TERM - 30;
  // Right thumb for "symbols" layer
  case KC_SYSP:
    return TAPPING_TERM - 50;
  default:
    return TAPPING_TERM;
  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak Mod DH-MK */
[_COLEMAKDHMK] = LAYOUT_ortho_4x12(
   KC_ATAB, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_TDSC, KC_AEQL, \
   KC_CESC, KC_GU_A, KC_AL_R, KC_CT_S, KC_T_SH, KC_G,    KC_M,    KC_N_SH, KC_CT_E, KC_AL_I, KC_GU_O, KC_CMIN, \
   KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
   KC_GSPC, KC_HYBL, KC_MEBR, KC_FU,   KC_NBSC, KC_CDEL, KC_CENT, KC_SYSP, KC_FULE, KC_DOWN, KC_UP,   KC_GURI  \
),

/* QWERTY */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_ATAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_AEQL, \
   KC_CESC, KC_GU_A, KC_AL_S, KC_CT_D, KC_F_SH, KC_G,    KC_H,    KC_J_SH, KC_CT_K, KC_AL_L, KC_GU_SC,KC_CMIN, \
   KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
   KC_GSPC, KC_HYBL, KC_MEBR, KC_FU,   KC_NBSC, KC_CDEL, KC_CENT, KC_SYSP, KC_FULE, KC_DOWN, KC_UP,   KC_GURI  \
),

/* Numbers (Lower) */
[_NUMB] = LAYOUT_ortho_4x12( \
  _______, _______, KC_UP,   _______, _______, ASC_LAN, ASC_RAN, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, _______, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, ASC_CBRL,ASC_CBRR,KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, _______, \
  _______, _______, ASC_SAD, ASC_HAP, _______, KC_TDLB, KC_TDRB, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_0, KC_PDOT, KC_PAST, _______ \
),

/* Symbols (Raise) */
[_SYMB] = LAYOUT_ortho_4x12( \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, ASC_CIRC,KC_AMPR, KC_ASTR, KC_PLUS, _______, _______, \
  _______, KC_PIPE, KC_PMNS, ASC_SQT, ASC_DQT, KC_GRV,  KC_QUOT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
  _______, KC_BSLS, KC_UNDS, KC_COLN, ASC_TILD,KC_EQL,  ASC_BKT, KC_PGUP, KC_PGDN, KC_HOME, KC_END,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Function */
[_FUNC] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F7,   KC_F12,  _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, \
  _______, KC_PSCR, KC_NLCK, KC_INS,  KC_CAPS, KC_APP,  _______, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Left hand shifted keycodes (colemak) */
[_LHSH] = LAYOUT_ortho_4x12( \
  _______, S(KC_Q) ,S(KC_W) ,S(KC_F) ,S(KC_P) ,S(KC_B), _______, _______, _______, _______, _______, _______, \
  _______, S(KC_A) ,S(KC_R) ,S(KC_S) ,S(KC_T) ,S(KC_G), _______, _______, _______, _______, _______, _______, \
  _______, S(KC_Z) ,S(KC_X) ,S(KC_C) ,S(KC_D) ,S(KC_V), _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_DEL , KC_BSPC, _______,_______, _______, _______ \
),

/* Right hand shifted keycodes (colemak)*/
[_RHSH] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, S(KC_J) ,S(KC_L) ,S(KC_U) ,S(KC_Y) ,KC_COLN, _______, \
  _______, _______, _______, _______, _______, _______, S(KC_M) ,S(KC_N) ,S(KC_E) ,S(KC_I) ,S(KC_O), _______, \
  _______, _______, _______, _______, _______, _______, S(KC_K) ,S(KC_H) ,KC_LABK ,KC_RABK ,KC_QUES, _______, \
  _______, _______, _______, _______, KC_SPC , KC_ENT , _______, _______, _______, _______, _______, _______ \
),

/* Left hand shifted keycodes (qwerty) */
[_LHSH_QWERTY] = LAYOUT_ortho_4x12( \
  _______, S(KC_Q) ,S(KC_W) ,S(KC_E) ,S(KC_R) ,S(KC_T), _______, _______, _______, _______, _______, _______, \
  _______, S(KC_A) ,S(KC_S) ,S(KC_D) ,S(KC_F) ,S(KC_G), _______, _______, _______, _______, _______, _______, \
  _______, S(KC_Z) ,S(KC_X) ,S(KC_C) ,S(KC_V) ,S(KC_B), _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_DEL , KC_BSPC, _______,_______, _______, _______ \
),

/* Right hand shifted keycodes (qwerty)*/
[_RHSH_QWERTY] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, S(KC_Y) ,S(KC_U) ,S(KC_I) ,S(KC_O) ,S(KC_P), _______, \
  _______, _______, _______, _______, _______, _______, S(KC_H) ,S(KC_J) ,S(KC_K) ,S(KC_L) ,KC_COLN, _______, \
  _______, _______, _______, _______, _______, _______, S(KC_N) ,S(KC_M) ,KC_LABK ,KC_RABK ,KC_QUES, _______, \
  _______, _______, _______, _______, KC_SPC , KC_ENT , _______, _______, _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise) */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   LR1,     LR2,     _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};


// Enable adjust layer pressing  _NUMB & _SYMB together.
uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _NUMB, _SYMB, _ADJUST);
}
