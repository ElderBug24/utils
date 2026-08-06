#ifndef BRAILLE_DEF
#define BRAILLE_DEF
#endif

#ifndef BRAILLE_H
#define BRAILLE_H

#include <stdbool.h> // bool
#include <limits.h> // UCHAR_MAX
#include <wchar.h> // wchar_t


typedef unsigned char braille_t;

extern const braille_t BRAILLE_EMPTY;
extern const braille_t BRAILLE_FULL;
extern const braille_t BRAILLE_BIT_0;
extern const braille_t BRAILLE_BIT_1;
extern const braille_t BRAILLE_BIT_2;
extern const braille_t BRAILLE_BIT_3;
extern const braille_t BRAILLE_BIT_4;
extern const braille_t BRAILLE_BIT_5;
extern const braille_t BRAILLE_BIT_6;
extern const braille_t BRAILLE_BIT_7;
extern const braille_t BRAILLE_BITS[8];

extern const wchar_t WCHAR_BRAILLE_EMPTY;
extern const wchar_t WCHAR_BRAILLE_FULL;
extern const wchar_t WCHAR_BRAILLE_BIT_0;
extern const wchar_t WCHAR_BRAILLE_BIT_1;
extern const wchar_t WCHAR_BRAILLE_BIT_2;
extern const wchar_t WCHAR_BRAILLE_BIT_3;
extern const wchar_t WCHAR_BRAILLE_BIT_4;
extern const wchar_t WCHAR_BRAILLE_BIT_5;
extern const wchar_t WCHAR_BRAILLE_BIT_6;
extern const wchar_t WCHAR_BRAILLE_BIT_7;
extern const wchar_t WCHAR_BRAILLE_BITS[8];

extern const unsigned char BRAILLE_WIDTH;
extern const unsigned char BRAILLE_HEIGHT;

extern const unsigned char BRAILLE_BITS_MAP_NATURAL[8];
extern const unsigned char BRAILLE_BITS_MAP_CLOCKWISE[8];

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
BRAILLE_DEF unsigned char braille_bit_index_2d(unsigned char x, unsigned char y);

#endif // BRAILLE_H

#ifdef BRAILLE_IMPLEMENTATION

#ifndef BRAILLE_MALLOC
#define BRAILLE_MALLOC malloc
#endif

#ifndef BRAILLE_FREE
#define BRAILLE_FREE free
#endif

#include <stdlib.h> // malloc and free


const braille_t BRAILLE_EMPTY = 0;
const braille_t BRAILLE_FULL = UCHAR_MAX;
const braille_t BRAILLE_BIT_0 =   1;
const braille_t BRAILLE_BIT_1 =   2;
const braille_t BRAILLE_BIT_2 =   4;
const braille_t BRAILLE_BIT_3 =   8;
const braille_t BRAILLE_BIT_4 =  16;
const braille_t BRAILLE_BIT_5 =  32;
const braille_t BRAILLE_BIT_6 =  64;
const braille_t BRAILLE_BIT_7 = 128;
const braille_t BRAILLE_BITS[8] = { BRAILLE_BIT_0, BRAILLE_BIT_1, BRAILLE_BIT_2, BRAILLE_BIT_3, BRAILLE_BIT_4, BRAILLE_BIT_5, BRAILLE_BIT_6, BRAILLE_BIT_7 };

const wchar_t WCHAR_BRAILLE_EMPTY = 0x2800;
const wchar_t WCHAR_BRAILLE_FULL = 0x28FF; // WCHAR_BRAILLE_EMPTY + UCHAR_MAX
const wchar_t WCHAR_BRAILLE_BIT_0 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_0;
const wchar_t WCHAR_BRAILLE_BIT_1 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_1;
const wchar_t WCHAR_BRAILLE_BIT_2 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_2;
const wchar_t WCHAR_BRAILLE_BIT_3 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_3;
const wchar_t WCHAR_BRAILLE_BIT_4 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_4;
const wchar_t WCHAR_BRAILLE_BIT_5 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_5;
const wchar_t WCHAR_BRAILLE_BIT_6 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_6;
const wchar_t WCHAR_BRAILLE_BIT_7 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_7;
const wchar_t WCHAR_BRAILLE_BITS[8] = { WCHAR_BRAILLE_BIT_0, WCHAR_BRAILLE_BIT_1, WCHAR_BRAILLE_BIT_2, WCHAR_BRAILLE_BIT_3, WCHAR_BRAILLE_BIT_4, WCHAR_BRAILLE_BIT_5, WCHAR_BRAILLE_BIT_6, WCHAR_BRAILLE_BIT_7 };

const unsigned char BRAILLE_WIDTH = 2;
const unsigned char BRAILLE_HEIGHT = 4;

const unsigned char BRAILLE_BITS_MAP_NATURAL[8] = { 0, 3, 1, 4, 2, 5, 6, 7 };
const unsigned char BRAILLE_BITS_MAP_CLOCKWISE[8] = { 3, 4, 5, 7, 6, 2, 1, 0 };

BRAILLE_DEF wchar_t braille_to_wchar(braille_t braille) { return (wchar_t) ((wint_t) WCHAR_BRAILLE_EMPTY + (wint_t) braille); }

BRAILLE_DEF bool braille_get_bit(braille_t braille, unsigned char index) { return ((unsigned char) braille & 1 << index) != 0; }
BRAILLE_DEF braille_t braille_set_bit(braille_t braille, unsigned char index, bool value) { return (braille & (braille_t) ~(1 << index)) | (braille_t) (value << index); }
BRAILLE_DEF braille_t braille_clear_bit(braille_t braille, unsigned char index) { return braille & (braille_t) ~(1 << index); }
BRAILLE_DEF braille_t braille_toggle_bit(braille_t braille, unsigned char index) { return braille ^ (braille_t) (1 << index); }

BRAILLE_DEF bool wchar_braille_get_bit(wchar_t wchar, unsigned char index) { return braille_get_bit((braille_t) ((wint_t) wchar - (wint_t) WCHAR_BRAILLE_EMPTY), index); }
BRAILLE_DEF wchar_t wchar_braille_set_bit(wchar_t wchar, unsigned char index, bool value) { return braille_to_wchar(braille_set_bit((braille_t) ((wint_t) wchar - (wint_t) WCHAR_BRAILLE_EMPTY), index, value)); }
BRAILLE_DEF wchar_t wchar_braille_clear_bit(wchar_t wchar, unsigned char index) { return braille_to_wchar(braille_clear_bit((braille_t) ((wint_t) wchar - (wint_t) WCHAR_BRAILLE_EMPTY), index)); }
BRAILLE_DEF wchar_t wchar_braille_toggle_bit(wchar_t wchar, unsigned char index) { return braille_to_wchar(braille_toggle_bit((braille_t) ((wint_t) wchar - (wint_t) WCHAR_BRAILLE_EMPTY), index)); }

BRAILLE_DEF bool wchar_is_braille(wchar_t wchar) { return ((wint_t) wchar >= (wint_t) WCHAR_BRAILLE_EMPTY) & ((wint_t) wchar <= (wint_t) WCHAR_BRAILLE_FULL); }
BRAILLE_DEF unsigned char braille_bit_index_2d(unsigned char x, unsigned char y) { return (unsigned char) (x + y * BRAILLE_WIDTH); }

#endif // BRAILLE_IMPLEMENTATION

