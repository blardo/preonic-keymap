#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(ZELDA_TREASURE)
    #define LAYER_DEFAULT_SONGS { \
        SONG(USSR_ANTHEM), \
        SONG(E1M1_DOOM) \
    }
#endif

#define MUSIC_MASK (keycode != KC_NO)
/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC
#define ENCODER_RESOLUTION 4

#define MEDIA_KEY_DELAY 10

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2
