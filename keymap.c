#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _GAMING,
  _LOWER,
  _RAISE,
  _UTIL,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  RAISE,
  LOWER
};

void knob_code(uint16_t keycode) {
  uint16_t held_keycode_timer = timer_read();
  register_code(keycode);
  while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
      // no-op
  }
  unregister_code(keycode);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_preonic_1x2uC(\
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, \
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, \
        LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, \
        MO(_UTIL), KC_LCTL, KC_LGUI, KC_LALT, LOWER, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT \
    ),

    [_GAMING] = LAYOUT_preonic_1x2uC(\
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, KC_NO, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    [_LOWER] = LAYOUT_preonic_1x2uC(\
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PSCR, \
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
        _______, KC_COMM, KC_EXLM, KC_QUES, KC_DOT, KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
        _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END\
    ),

    [_RAISE] = LAYOUT_preonic_1x2uC(\
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, \
        _______, KC_COMM, KC_EXLM, KC_QUES, KC_DOT, KC_LPRN, KC_RPRN, KC_PMNS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, \
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
    ),

    [_ADJUST] = LAYOUT_preonic_1x2uC(\
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
        _______, RESET, DEBUG, _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______, KC_DEL, \
        EEP_RST, _______, AU_ON, MU_MOD, AU_OFF, AG_NORM, AG_SWAP, QWERTY, GAMING, _______, _______, _______, \
        _______, MUV_DE, MUV_IN, MU_ON, MU_OFF, MI_ON, MI_OFF, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
    ),

    [_UTIL] = LAYOUT_preonic_1x2uC(\
        KC_PSCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        KC_MUTE, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______\
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_on(_QWERTY);
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
          layer_on(_GAMING);
          set_single_persistent_default_layer(_GAMING);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    switch (biton32(layer_state)) {
      case 4:
        if (clockwise) {
          knob_code(KC_VOLU);
          break;
        } else {
          knob_code(KC_VOLD);
          break;
        }
      case 3:
        if (clockwise) {
          knob_code(KC_PGDN);
          break;
        } else {
          knob_code(KC_PGUP);
          break;
        }
      case 2:
        if (clockwise) {
          knob_code(KC_RIGHT);
          break;
        } else {
          knob_code(KC_LEFT);
          break;
        }
      case 0:
        if (clockwise) {
          knob_code(KC_MS_WH_DOWN);
          break;
        } else {
          knob_code(KC_MS_WH_UP);
          break;
        }
    }
  }
}



void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

