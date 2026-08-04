#ifndef BRAILLE_DEF
#define BRAILLE_DEF
#endif

#ifndef BRAILLE_H
#define BRAILLE_H

#include <stdbool.h>
#include <limits.h>
#include <wchar.h>


typedef unsigned char braille_t;

extern const braille_t BRAILLE_EMPTY;
extern const braille_t BRAILLE_FULL;
extern const wchar_t BRAILLE_WCHAR_EMPTY;
extern const wchar_t BRAILLE_WCHAR_FULL;

extern const unsigned char BRAILLE_BITS_MAP[8];

BRAILLE_DEF wchar_t braille_to_wchar(braille_t braille);

BRAILLE_DEF bool braille_get_bit(braille_t braille, unsigned char index);
BRAILLE_DEF braille_t braille_set_bit(braille_t braille, unsigned char index, bool value);
BRAILLE_DEF braille_t braille_clear_bit(braille_t braille, unsigned char index);
BRAILLE_DEF braille_t braille_toggle_bit(braille_t braille, unsigned char index);

BRAILLE_DEF bool wchar_braille_get_bit(wchar_t wchar, unsigned char index);
BRAILLE_DEF wchar_t wchar_braille_set_bit(wchar_t wchar, unsigned char index, bool value);
BRAILLE_DEF wchar_t wchar_braille_clear_bit(wchar_t wchar, unsigned char index);
BRAILLE_DEF wchar_t wchar_braille_toggle_bit(wchar_t wchar, unsigned char index);

BRAILLE_DEF bool wchar_is_braille(wchar_t wchar);

#endif // BRAILLE_H

#ifdef BRAILLE_IMPLEMENTATION

const braille_t BRAILLE_EMPTY = 0;
const braille_t BRAILLE_FULL = UCHAR_MAX;
const wchar_t BRAILLE_WCHAR_EMPTY = 0x2800;
const wchar_t BRAILLE_WCHAR_FULL = 0x28FF; // BRAILLE_WCHAR_EMPTY + UCHAR_MAX

const unsigned char BRAILLE_BITS_MAP[8] = { 0, 3, 1, 4, 2, 5, 6, 7 };

BRAILLE_DEF wchar_t braille_to_wchar(braille_t braille) { return (wchar_t) ((wint_t) BRAILLE_WCHAR_EMPTY + (wint_t) braille); }

BRAILLE_DEF bool braille_get_bit(braille_t braille, unsigned char index) { return index < 8 && ((unsigned char) braille & 1 << index) != 0; }
BRAILLE_DEF braille_t braille_set_bit(braille_t braille, unsigned char index, bool value) { if (index > 7) return braille; return (braille & (braille_t) ~(1 << index)) | (braille_t) (value << index); }
BRAILLE_DEF braille_t braille_clear_bit(braille_t braille, unsigned char index) { if (index > 7) return braille; return braille & (braille_t) ~(1 << index); }
BRAILLE_DEF braille_t braille_toggle_bit(braille_t braille, unsigned char index) { if (index > 7) return braille; return braille ^ (braille_t) (1 << index); }

BRAILLE_DEF bool wchar_braille_get_bit(wchar_t wchar, unsigned char index) { return braille_get_bit((braille_t) ((wint_t) wchar - (wint_t) BRAILLE_WCHAR_EMPTY), index); }
BRAILLE_DEF wchar_t wchar_braille_set_bit(wchar_t wchar, unsigned char index, bool value) { return braille_to_wchar(braille_set_bit((braille_t) ((wint_t) wchar - (wint_t) BRAILLE_WCHAR_EMPTY), index, value)); }
BRAILLE_DEF wchar_t wchar_braille_clear_bit(wchar_t wchar, unsigned char index) { return braille_to_wchar(braille_clear_bit((braille_t) ((wint_t) wchar - (wint_t) BRAILLE_WCHAR_EMPTY), index)); }
BRAILLE_DEF wchar_t wchar_braille_toggle_bit(wchar_t wchar, unsigned char index) { return braille_to_wchar(braille_toggle_bit((braille_t) ((wint_t) wchar - (wint_t) BRAILLE_WCHAR_EMPTY), index)); }

BRAILLE_DEF bool wchar_is_braille(wchar_t wchar) { return ((wint_t) wchar >= (wint_t) BRAILLE_WCHAR_EMPTY) & ((wint_t) wchar <= (wint_t) BRAILLE_WCHAR_FULL); }

#endif // BRAILLE_IMPLEMENTATION

