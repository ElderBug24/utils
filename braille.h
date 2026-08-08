#ifndef BRAILLE_DEF
#define BRAILLE_DEF
#endif

#ifndef BRAILLE_H
#define BRAILLE_H

#include <stdbool.h> // bool
#include <limits.h> // UCHAR_MAX
#include <wchar.h> // wchar_t


typedef unsigned char braille_t;

typedef struct {
  braille_t* items;
  unsigned width, height;
} braille_2da_t;

typedef struct {
  wchar_t* items;
  unsigned width, height;
} wchar_braille_2da_t;

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
BRAILLE_DEF braille_t braille_assign_bit(braille_t braille, unsigned char index, bool value);
BRAILLE_DEF braille_t braille_set_bit(braille_t braille, unsigned char index);
BRAILLE_DEF braille_t braille_clear_bit(braille_t braille, unsigned char index);
BRAILLE_DEF braille_t braille_toggle_bit(braille_t braille, unsigned char index);

BRAILLE_DEF bool wchar_braille_get_bit(wchar_t wchar, unsigned char index);
BRAILLE_DEF wchar_t wchar_braille_assign_bit(wchar_t wchar, unsigned char index, bool value);
BRAILLE_DEF wchar_t wchar_braille_set_bit(wchar_t wchar, unsigned char index);
BRAILLE_DEF wchar_t wchar_braille_clear_bit(wchar_t wchar, unsigned char index);
BRAILLE_DEF wchar_t wchar_braille_toggle_bit(wchar_t wchar, unsigned char index);

BRAILLE_DEF bool wchar_is_braille(wchar_t wchar);
BRAILLE_DEF unsigned char braille_bit_index_2d(unsigned char x, unsigned char y);

BRAILLE_DEF braille_2da_t braille_2da_new(unsigned width, unsigned height);
BRAILLE_DEF void braille_2da_free(braille_2da_t arr);
BRAILLE_DEF bool braille_2da_get_bit(braille_2da_t arr, unsigned x, unsigned y);
BRAILLE_DEF void braille_2da_assign_bit(braille_2da_t arr, unsigned x, unsigned y, bool value);
BRAILLE_DEF void braille_2da_set_bit(braille_2da_t arr, unsigned x, unsigned y);
BRAILLE_DEF void braille_2da_clear_bit(braille_2da_t arr, unsigned x, unsigned y);
BRAILLE_DEF void braille_2da_toggle_bit(braille_2da_t arr, unsigned x, unsigned y);
BRAILLE_DEF braille_t braille_2da_get_braille(braille_2da_t arr, unsigned x, unsigned y);
BRAILLE_DEF braille_t* braille_2da_get_braille_ptr(braille_2da_t arr, unsigned x, unsigned y);
BRAILLE_DEF void braille_2da_assign_braille(braille_2da_t arr, unsigned x, unsigned y, braille_t value);
BRAILLE_DEF void braille_2da_copy_braille_rect_into(braille_2da_t arr, braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy);
BRAILLE_DEF void braille_2da_move_braille_rect_into(braille_2da_t arr, braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy);
BRAILLE_DEF void braille_2da_copy_bit_rect_into(braille_2da_t arr, braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy);
BRAILLE_DEF void braille_2da_move_bit_rect_into(braille_2da_t arr, braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy);
BRAILLE_DEF unsigned long braille_2da_neighborhood_count(braille_2da_t arr, unsigned x, unsigned y, unsigned rx, unsigned ry, bool value, bool outbound_value);
BRAILLE_DEF double braille_2da_neighborhood_count_gaussian(braille_2da_t arr, unsigned x, unsigned y, unsigned rx, unsigned ry, bool value, bool outbound_value);
BRAILLE_DEF float braille_2da_neighborhood_count_gaussianf(braille_2da_t arr, unsigned x, unsigned y, unsigned rx, unsigned ry, bool value, bool outbound_value);

BRAILLE_DEF wchar_braille_2da_t wchar_braille_2da_new(unsigned width, unsigned height);
BRAILLE_DEF void wchar_braille_2da_free(wchar_braille_2da_t arr);
BRAILLE_DEF bool wchar_braille_2da_get_bit(wchar_braille_2da_t arr, unsigned x, unsigned y);
BRAILLE_DEF void wchar_braille_2da_assign_bit(wchar_braille_2da_t arr, unsigned x, unsigned y, bool value);
BRAILLE_DEF void wchar_braille_2da_set_bit(wchar_braille_2da_t arr, unsigned x, unsigned y);
BRAILLE_DEF void wchar_braille_2da_clear_bit(wchar_braille_2da_t arr, unsigned x, unsigned y);
BRAILLE_DEF void wchar_braille_2da_toggle_bit(wchar_braille_2da_t arr, unsigned x, unsigned y);
BRAILLE_DEF wchar_t wchar_braille_2da_get_wchar_braille(wchar_braille_2da_t arr, unsigned x, unsigned y);
BRAILLE_DEF wchar_t* wchar_braille_2da_get_wchar_braille_ptr(wchar_braille_2da_t arr, unsigned x, unsigned y);
BRAILLE_DEF void wchar_braille_2da_assign_wchar_braille(wchar_braille_2da_t arr, unsigned x, unsigned y, wchar_t value);
BRAILLE_DEF void wchar_braille_2da_copy_wchar_braille_rect_into(wchar_braille_2da_t arr, wchar_braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy);
BRAILLE_DEF void wchar_braille_2da_move_wchar_braille_rect_into(wchar_braille_2da_t arr, wchar_braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy);
BRAILLE_DEF void wchar_braille_2da_copy_bit_rect_into(wchar_braille_2da_t arr, wchar_braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy);
BRAILLE_DEF void wchar_braille_2da_move_bit_rect_into(wchar_braille_2da_t arr, wchar_braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy);
BRAILLE_DEF unsigned long wchar_braille_2da_neighborhood_count(wchar_braille_2da_t arr, unsigned x, unsigned y, unsigned rx, unsigned ry, bool value, bool outbound_value);
BRAILLE_DEF double wchar_braille_2da_neighborhood_count_gaussian(wchar_braille_2da_t arr, unsigned x, unsigned y, unsigned rx, unsigned ry, bool value, bool outbound_value);
BRAILLE_DEF float wchar_braille_2da_neighborhood_count_gaussianf(wchar_braille_2da_t arr, unsigned x, unsigned y, unsigned rx, unsigned ry, bool value, bool outbound_value);

#endif // BRAILLE_H

#ifdef BRAILLE_IMPLEMENTATION

#ifndef BRAILLE_MALLOC
#define BRAILLE_MALLOC malloc
#endif

#ifndef BRAILLE_CALLOC
#define BRAILLE_CALLOC calloc
#endif

#ifndef BRAILLE_REALLOC
#define BRAILLE_REALLOC realloc
#endif

#ifndef BRAILLE_FREE
#define BRAILLE_FREE free
#endif

#ifndef BRAILLE_PI
#define BRAILLE_PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128
#endif

#include <math.h> // exp & expf
#include <stdlib.h> // malloc, calloc, realloc & free
#include <string.h> // memcpy & memmove


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
const wchar_t WCHAR_BRAILLE_FULL  = 0x28FF; // WCHAR_BRAILLE_EMPTY + UCHAR_MAX
const wchar_t WCHAR_BRAILLE_BIT_0 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_0;
const wchar_t WCHAR_BRAILLE_BIT_1 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_1;
const wchar_t WCHAR_BRAILLE_BIT_2 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_2;
const wchar_t WCHAR_BRAILLE_BIT_3 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_3;
const wchar_t WCHAR_BRAILLE_BIT_4 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_4;
const wchar_t WCHAR_BRAILLE_BIT_5 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_5;
const wchar_t WCHAR_BRAILLE_BIT_6 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_6;
const wchar_t WCHAR_BRAILLE_BIT_7 = WCHAR_BRAILLE_EMPTY + BRAILLE_BIT_7;
const wchar_t WCHAR_BRAILLE_BITS[8] = { WCHAR_BRAILLE_BIT_0, WCHAR_BRAILLE_BIT_1, WCHAR_BRAILLE_BIT_2, WCHAR_BRAILLE_BIT_3, WCHAR_BRAILLE_BIT_4, WCHAR_BRAILLE_BIT_5, WCHAR_BRAILLE_BIT_6, WCHAR_BRAILLE_BIT_7 };

const unsigned char BRAILLE_WIDTH  = 2;
const unsigned char BRAILLE_HEIGHT = 4;

const unsigned char BRAILLE_BITS_MAP_NATURAL[8]   = { 0, 3, 1, 4, 2, 5, 6, 7 };
const unsigned char BRAILLE_BITS_MAP_CLOCKWISE[8] = { 3, 4, 5, 7, 6, 2, 1, 0 };

BRAILLE_DEF wchar_t braille_to_wchar(braille_t braille) { return (wchar_t) ((wint_t) WCHAR_BRAILLE_EMPTY + (wint_t) braille); }

BRAILLE_DEF bool braille_get_bit(braille_t braille, unsigned char index) { return ((unsigned char) braille & 1 << index) != 0; }
BRAILLE_DEF braille_t braille_assign_bit(braille_t braille, unsigned char index, bool value) { return (braille & (braille_t) ~(1 << index)) | (braille_t) (value << index); }
BRAILLE_DEF braille_t braille_set_bit(braille_t braille, unsigned char index) { return braille | (braille_t) (1 << index); }
BRAILLE_DEF braille_t braille_clear_bit(braille_t braille, unsigned char index) { return braille & (braille_t) ~(1 << index); }
BRAILLE_DEF braille_t braille_toggle_bit(braille_t braille, unsigned char index) { return braille ^ (braille_t) (1 << index); }

BRAILLE_DEF bool wchar_braille_get_bit(wchar_t wchar, unsigned char index) { return braille_get_bit((braille_t) ((wint_t) wchar - (wint_t) WCHAR_BRAILLE_EMPTY), index); }
BRAILLE_DEF wchar_t wchar_braille_assign_bit(wchar_t wchar, unsigned char index, bool value) { return braille_to_wchar(braille_assign_bit((braille_t) ((wint_t) wchar - (wint_t) WCHAR_BRAILLE_EMPTY), index, value)); }
BRAILLE_DEF wchar_t wchar_braille_set_bit(wchar_t wchar, unsigned char index) { return braille_to_wchar(braille_set_bit((braille_t) ((wint_t) wchar - (wint_t) WCHAR_BRAILLE_EMPTY), index)); }
BRAILLE_DEF wchar_t wchar_braille_clear_bit(wchar_t wchar, unsigned char index) { return braille_to_wchar(braille_clear_bit((braille_t) ((wint_t) wchar - (wint_t) WCHAR_BRAILLE_EMPTY), index)); }
BRAILLE_DEF wchar_t wchar_braille_toggle_bit(wchar_t wchar, unsigned char index) { return braille_to_wchar(braille_toggle_bit((braille_t) ((wint_t) wchar - (wint_t) WCHAR_BRAILLE_EMPTY), index)); }

BRAILLE_DEF bool wchar_is_braille(wchar_t wchar) { return ((wint_t) wchar >= (wint_t) WCHAR_BRAILLE_EMPTY) & ((wint_t) wchar <= (wint_t) WCHAR_BRAILLE_FULL); }
BRAILLE_DEF unsigned char braille_bit_index_2d(unsigned char x, unsigned char y) { return BRAILLE_BITS_MAP_NATURAL[(unsigned char) (x + y * BRAILLE_WIDTH)]; }

BRAILLE_DEF braille_2da_t braille_2da_new(unsigned width, unsigned height) { return (braille_2da_t) { .items = BRAILLE_MALLOC(width * height * sizeof(braille_t)), .width = width, .height = height }; }
BRAILLE_DEF void braille_2da_free(braille_2da_t arr) { BRAILLE_FREE(arr.items); }
BRAILLE_DEF bool braille_2da_get_bit(braille_2da_t arr, unsigned x, unsigned y) { return braille_get_bit(braille_2da_get_braille(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT), braille_bit_index_2d((unsigned char) (x % BRAILLE_WIDTH), (unsigned char) (y % BRAILLE_HEIGHT))); }
BRAILLE_DEF void braille_2da_assign_bit(braille_2da_t arr, unsigned x, unsigned y, bool value) { *braille_2da_get_braille_ptr(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT) = braille_assign_bit(braille_2da_get_braille(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT), braille_bit_index_2d((unsigned char) (x % BRAILLE_WIDTH), (unsigned char) (y % BRAILLE_HEIGHT)), value); }
BRAILLE_DEF void braille_2da_set_bit(braille_2da_t arr, unsigned x, unsigned y) { *braille_2da_get_braille_ptr(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT) = braille_set_bit(braille_2da_get_braille(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT), braille_bit_index_2d((unsigned char) (x % BRAILLE_WIDTH), (unsigned char) (y % BRAILLE_HEIGHT))); }
BRAILLE_DEF void braille_2da_clear_bit(braille_2da_t arr, unsigned x, unsigned y) { *braille_2da_get_braille_ptr(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT) = braille_clear_bit(braille_2da_get_braille(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT), braille_bit_index_2d((unsigned char) (x % BRAILLE_WIDTH), (unsigned char) (y % BRAILLE_HEIGHT))); }
BRAILLE_DEF void braille_2da_toggle_bit(braille_2da_t arr, unsigned x, unsigned y) { *braille_2da_get_braille_ptr(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT) = braille_toggle_bit(braille_2da_get_braille(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT), braille_bit_index_2d((unsigned char) (x % BRAILLE_WIDTH), (unsigned char) (y % BRAILLE_HEIGHT))); }
BRAILLE_DEF braille_t braille_2da_get_braille(braille_2da_t arr, unsigned x, unsigned y) { return arr.items[x + y * arr.width]; }
BRAILLE_DEF braille_t* braille_2da_get_braille_ptr(braille_2da_t arr, unsigned x, unsigned y) { return &arr.items[x + y * arr.width]; }
BRAILLE_DEF void braille_2da_assign_braille(braille_2da_t arr, unsigned x, unsigned y, braille_t value) { arr.items[x + y * arr.width] = value; }
BRAILLE_DEF void braille_2da_copy_braille_rect_into(braille_2da_t arr, braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy) { for (unsigned i = 0; i < h; ++i) memcpy(&out.items[ox + (oy + i) * out.width], &arr.items[x + (y + i) * arr.width], w * sizeof(braille_t)); }
BRAILLE_DEF void braille_2da_move_braille_rect_into(braille_2da_t arr, braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy) { for (unsigned i = 0; i < h; ++i) memmove(&out.items[ox + (oy + i) * out.width], &arr.items[x + (y + i) * arr.width], w * sizeof(braille_t)); }
BRAILLE_DEF void braille_2da_copy_bit_rect_into(braille_2da_t arr, braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy) { if (!(x % BRAILLE_WIDTH == ox % BRAILLE_WIDTH && y % BRAILLE_HEIGHT == oy % BRAILLE_HEIGHT)) for (unsigned i = 0; i < w; ++i) for (unsigned j = 0; j < h; ++j) braille_2da_assign_bit(out, ox + i, oy + j, braille_2da_get_bit(arr, x + i, y + j)); else { unsigned  X =  x / BRAILLE_WIDTH  + ( x % BRAILLE_WIDTH  != 0); unsigned  Y =  y / BRAILLE_HEIGHT + ( y % BRAILLE_HEIGHT != 0); unsigned OX = ox / BRAILLE_WIDTH  + (ox % BRAILLE_WIDTH  != 0); unsigned OY = oy / BRAILLE_HEIGHT + (oy % BRAILLE_HEIGHT != 0); unsigned  W = (x + w) / BRAILLE_WIDTH  - X; unsigned  H = (y + h) / BRAILLE_HEIGHT - Y; braille_2da_copy_braille_rect_into(arr, out, X, Y, W, H, OX, OY); for (unsigned j = 0; j < h; ++j) { for (unsigned char i = 0; i < X * BRAILLE_WIDTH - x; ++i) braille_2da_assign_bit(out, ox + i, oy + j, braille_2da_get_bit(arr, x + i, y + j)); for (unsigned char i = 0; i < (x + w) - (X + W) * BRAILLE_WIDTH; ++i) braille_2da_assign_bit(out, (OX + W) * BRAILLE_WIDTH + i, oy + j, braille_2da_get_bit(arr, (X + W) * BRAILLE_WIDTH + i, y + j)); } for (unsigned i = 0; i < W * BRAILLE_WIDTH; ++i) { for (unsigned char j = 0; j < Y * BRAILLE_HEIGHT - y; ++j) braille_2da_assign_bit(out, OX * BRAILLE_WIDTH + i, oy + j, braille_2da_get_bit(arr, X * BRAILLE_WIDTH + i, y + j)); for (unsigned char j = 0; j < (y + h) - (Y + H) * BRAILLE_HEIGHT; ++j) braille_2da_assign_bit(out, OX * BRAILLE_WIDTH + i, (OY + H) * BRAILLE_HEIGHT + j, braille_2da_get_bit(arr, X + BRAILLE_WIDTH + i, (Y + H) * BRAILLE_HEIGHT + j)); } } }
BRAILLE_DEF void braille_2da_move_bit_rect_into(braille_2da_t arr, braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy) { braille_2da_t buf = braille_2da_new(w / BRAILLE_WIDTH + 1, h / BRAILLE_HEIGHT + 1); braille_2da_copy_braille_rect_into(arr, buf, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT, w / BRAILLE_WIDTH + 1, h / BRAILLE_HEIGHT + 1, 0, 0); braille_2da_copy_bit_rect_into(buf, out, x % BRAILLE_WIDTH, y % BRAILLE_HEIGHT, w, h, ox, oy); braille_2da_free(buf); }
BRAILLE_DEF unsigned long braille_2da_neighborhood_count(braille_2da_t arr, unsigned x, unsigned y, unsigned rx, unsigned ry, bool value, bool outbound_value) { unsigned long total = 0; unsigned width = arr.width * BRAILLE_WIDTH; unsigned height = arr.height * BRAILLE_HEIGHT; for (unsigned dx = 0; dx <= rx; ++dx) { for (unsigned dy = 0; dy <= ry; ++dy) { if (dx == 0) { if (dy == 0) { total += braille_2da_get_bit(arr, x, y) == value; continue; } if (dy > y) total += outbound_value == value; else total += braille_2da_get_bit(arr, x, y - dy) == value; if (y + dy >= height) total += outbound_value == value; else total += braille_2da_get_bit(arr, x, y + dy) == value; continue; } if (dy == 0) { if (dx > x) total += outbound_value == value; else total += braille_2da_get_bit(arr, x - dx, y) == value; if (x + dx >= width) total += outbound_value == value; else total += braille_2da_get_bit(arr, x + dx, y) == value; continue; } if (dx > x || dy > y) total += outbound_value == value; else total += braille_2da_get_bit(arr, x - dx, y - dy) == value; if (dx > x || y + dy >= height) total += outbound_value == value; else total += braille_2da_get_bit(arr, x - dx, y + dy) == value; if (x + dx >= width || dy > y) total += outbound_value == value; else total += braille_2da_get_bit(arr, x + dx, y - dy) == value; if (x + dx >= width || y + dy >= height) total += outbound_value == value; else total += braille_2da_get_bit(arr, x + dx, y + dy) == value; } } return total; }
BRAILLE_DEF double braille_2da_neighborhood_count_gaussian(braille_2da_t arr, unsigned x, unsigned y, unsigned rx, unsigned ry, bool value, bool outbound_value) { double total = 0.0; unsigned width = arr.width * BRAILLE_WIDTH; unsigned height = arr.height * BRAILLE_HEIGHT; if (rx == 0 || ry == 0) return 0.0; double normalization = 1.0 / (BRAILLE_PI * (double) rx * (double) ry); for (unsigned dx = 0; dx <= rx; ++dx) { for (unsigned dy = 0; dy <= ry; ++dy) { double weight = normalization * exp(-((double) dx * dx / ((double) rx * rx)) -((double) dy * dy / ((double) ry * ry))); if (dx == 0) { if (dy == 0) { total += (braille_2da_get_bit(arr, x, y) == value) * weight; continue; } if (dy > y) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x, y - dy) == value) * weight; if (y + dy >= height) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x, y + dy) == value) * weight; continue; } if (dy == 0) { if (dx > x) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x - dx, y) == value) * weight; if (x + dx >= width) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x + dx, y) == value) * weight; continue; } if (dx > x || dy > y) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x - dx, y - dy) == value) * weight; if (dx > x || y + dy >= height) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x - dx, y + dy) == value) * weight; if (x + dx >= width || dy > y) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x + dx, y - dy) == value) * weight; if (x + dx >= width || y + dy >= height) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x + dx, y + dy) == value) * weight; } } return total; }
BRAILLE_DEF float braille_2da_neighborhood_count_gaussianf(braille_2da_t arr, unsigned x, unsigned y, unsigned rx, unsigned ry, bool value, bool outbound_value) { float total = 0.0f; unsigned width = arr.width * BRAILLE_WIDTH; unsigned height = arr.height * BRAILLE_HEIGHT; if (rx == 0 || ry == 0) return 0.0f; float normalization = 1.0f / ((float) BRAILLE_PI * (float) rx * (float) ry); for (unsigned dx = 0; dx <= rx; ++dx) { for (unsigned dy = 0; dy <= ry; ++dy) { float weight = normalization * expf(-((float) (dx * dx) / (float) (rx * rx)) -((float) (dy * dy) / (float) (ry * ry))); if (dx == 0) { if (dy == 0) { total += (braille_2da_get_bit(arr, x, y) == value) * weight; continue; } if (dy > y) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x, y - dy) == value) * weight; if (y + dy >= height) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x, y + dy) == value) * weight; continue; } if (dy == 0) { if (dx > x) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x - dx, y) == value) * weight; if (x + dx >= width) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x + dx, y) == value) * weight; continue; } if (dx > x || dy > y) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x - dx, y - dy) == value) * weight; if (dx > x || y + dy >= height) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x - dx, y + dy) == value) * weight; if (x + dx >= width || dy > y) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x + dx, y - dy) == value) * weight; if (x + dx >= width || y + dy >= height) total += (outbound_value == value) * weight; else total += (braille_2da_get_bit(arr, x + dx, y + dy) == value) * weight; } } return total; }

BRAILLE_DEF wchar_braille_2da_t wchar_braille_2da_new(unsigned width, unsigned height) { return (wchar_braille_2da_t) { .items = BRAILLE_MALLOC(width * height * sizeof(wchar_t)), .width = width, .height = height }; }
BRAILLE_DEF void wchar_braille_2da_free(wchar_braille_2da_t arr) { BRAILLE_FREE(arr.items); }
BRAILLE_DEF bool wchar_braille_2da_get_bit(wchar_braille_2da_t arr, unsigned x, unsigned y) { return wchar_braille_get_bit(wchar_braille_2da_get_wchar_braille(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT), braille_bit_index_2d((unsigned char) (x % BRAILLE_WIDTH), (unsigned char) (y % BRAILLE_HEIGHT))); }
BRAILLE_DEF void wchar_braille_2da_assign_bit(wchar_braille_2da_t arr, unsigned x, unsigned y, bool value) { *wchar_braille_2da_get_wchar_braille_ptr(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT) = wchar_braille_assign_bit(wchar_braille_2da_get_wchar_braille(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT), braille_bit_index_2d((unsigned char) (x % BRAILLE_WIDTH), (unsigned char) (y % BRAILLE_HEIGHT)), value); }
BRAILLE_DEF void wchar_braille_2da_set_bit(wchar_braille_2da_t arr, unsigned x, unsigned y) { *wchar_braille_2da_get_wchar_braille_ptr(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT) = wchar_braille_set_bit(wchar_braille_2da_get_wchar_braille(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT), braille_bit_index_2d((unsigned char) (x % BRAILLE_WIDTH), (unsigned char) (y % BRAILLE_HEIGHT))); }
BRAILLE_DEF void wchar_braille_2da_clear_bit(wchar_braille_2da_t arr, unsigned x, unsigned y) { *wchar_braille_2da_get_wchar_braille_ptr(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT) = wchar_braille_clear_bit(wchar_braille_2da_get_wchar_braille(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT), braille_bit_index_2d((unsigned char) (x % BRAILLE_WIDTH), (unsigned char) (y % BRAILLE_HEIGHT))); }
BRAILLE_DEF void wchar_braille_2da_toggle_bit(wchar_braille_2da_t arr, unsigned x, unsigned y) { *wchar_braille_2da_get_wchar_braille_ptr(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT) = wchar_braille_toggle_bit(wchar_braille_2da_get_wchar_braille(arr, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT), braille_bit_index_2d((unsigned char) (x % BRAILLE_WIDTH), (unsigned char) (y % BRAILLE_HEIGHT))); }
BRAILLE_DEF wchar_t wchar_braille_2da_get_wchar_braille(wchar_braille_2da_t arr, unsigned x, unsigned y) { return arr.items[x + y * arr.width]; }
BRAILLE_DEF wchar_t* wchar_braille_2da_get_wchar_braille_ptr(wchar_braille_2da_t arr, unsigned x, unsigned y) { return &arr.items[x + y * arr.width]; }
BRAILLE_DEF void wchar_braille_2da_assign_wchar_braille(wchar_braille_2da_t arr, unsigned x, unsigned y, wchar_t value) { arr.items[x + y * arr.width] = value; }
BRAILLE_DEF void wchar_braille_2da_copy_wchar_braille_rect_into(wchar_braille_2da_t arr, wchar_braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy) { for (unsigned i = 0; i < h; ++i) memcpy(&out.items[ox + (oy + i) * out.width], &arr.items[x + (y + i) * arr.width], w * sizeof(wchar_t)); }
BRAILLE_DEF void wchar_braille_2da_move_wchar_braille_rect_into(wchar_braille_2da_t arr, wchar_braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy) { for (unsigned i = 0; i < h; ++i) memmove(&out.items[ox + (oy + i) * out.width], &arr.items[x + (y + i) * arr.width], w * sizeof(wchar_t)); }
BRAILLE_DEF void wchar_braille_2da_copy_bit_rect_into(wchar_braille_2da_t arr, wchar_braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy) { if (!(x % BRAILLE_WIDTH == ox % BRAILLE_WIDTH && y % BRAILLE_HEIGHT == oy % BRAILLE_HEIGHT)) for (unsigned i = 0; i < w; ++i) for (unsigned j = 0; j < h; ++j) wchar_braille_2da_assign_bit(out, ox + i, oy + j, wchar_braille_2da_get_bit(arr, x + i, y + j)); else { unsigned  X =  x / BRAILLE_WIDTH  + ( x % BRAILLE_WIDTH  != 0); unsigned  Y =  y / BRAILLE_HEIGHT + ( y % BRAILLE_HEIGHT != 0); unsigned OX = ox / BRAILLE_WIDTH  + (ox % BRAILLE_WIDTH  != 0); unsigned OY = oy / BRAILLE_HEIGHT + (oy % BRAILLE_HEIGHT != 0); unsigned  W = (x + w) / BRAILLE_WIDTH  - X; unsigned  H = (y + h) / BRAILLE_HEIGHT - Y; wchar_braille_2da_copy_wchar_braille_rect_into(arr, out, X, Y, W, H, OX, OY); for (unsigned j = 0; j < h; ++j) { for (unsigned char i = 0; i < X * BRAILLE_WIDTH - x; ++i) wchar_braille_2da_assign_bit(out, ox + i, oy + j, wchar_braille_2da_get_bit(arr, x + i, y + j)); for (unsigned char i = 0; i < (x + w) - (X + W) * BRAILLE_WIDTH; ++i) wchar_braille_2da_assign_bit(out, (OX + W) * BRAILLE_WIDTH + i, oy + j, wchar_braille_2da_get_bit(arr, (X + W) * BRAILLE_WIDTH + i, y + j)); } for (unsigned i = 0; i < W * BRAILLE_WIDTH; ++i) { for (unsigned char j = 0; j < Y * BRAILLE_HEIGHT - y; ++j) wchar_braille_2da_assign_bit(out, OX * BRAILLE_WIDTH + i, oy + j, wchar_braille_2da_get_bit(arr, X * BRAILLE_WIDTH + i, y + j)); for (unsigned char j = 0; j < (y + h) - (Y + H) * BRAILLE_HEIGHT; ++j) wchar_braille_2da_assign_bit(out, OX * BRAILLE_WIDTH + i, (OY + H) * BRAILLE_HEIGHT + j, wchar_braille_2da_get_bit(arr, X + BRAILLE_WIDTH + i, (Y + H) * BRAILLE_HEIGHT + j)); } } }
BRAILLE_DEF void wchar_braille_2da_move_bit_rect_into(wchar_braille_2da_t arr, wchar_braille_2da_t out, unsigned x, unsigned y, unsigned w, unsigned h, unsigned ox, unsigned oy) { wchar_braille_2da_t buf = wchar_braille_2da_new(w / BRAILLE_WIDTH + 1, h / BRAILLE_HEIGHT + 1); wchar_braille_2da_copy_wchar_braille_rect_into(arr, buf, x / BRAILLE_WIDTH, y / BRAILLE_HEIGHT, w / BRAILLE_WIDTH + 1, h / BRAILLE_HEIGHT + 1, 0, 0); wchar_braille_2da_copy_bit_rect_into(buf, out, x % BRAILLE_WIDTH, y % BRAILLE_HEIGHT, w, h, ox, oy); wchar_braille_2da_free(buf); }
BRAILLE_DEF unsigned long wchar_braille_2da_neighborhood_count(wchar_braille_2da_t arr, unsigned x, unsigned y, unsigned rx, unsigned ry, bool value, bool outbound_value) { unsigned long total = 0; unsigned width = arr.width * BRAILLE_WIDTH; unsigned height = arr.height * BRAILLE_HEIGHT; for (unsigned dx = 0; dx <= rx; ++dx) { for (unsigned dy = 0; dy <= ry; ++dy) { if (dx == 0) { if (dy == 0) { total += wchar_braille_2da_get_bit(arr, x, y) == value; continue; } if (dy > y) total += outbound_value == value; else total += wchar_braille_2da_get_bit(arr, x, y - dy) == value; if (y + dy >= height) total += outbound_value == value; else total += wchar_braille_2da_get_bit(arr, x, y + dy) == value; continue; } if (dy == 0) { if (dx > x) total += outbound_value == value; else total += wchar_braille_2da_get_bit(arr, x - dx, y) == value; if (x + dx >= width) total += outbound_value == value; else total += wchar_braille_2da_get_bit(arr, x + dx, y) == value; continue; } if (dx > x || dy > y) total += outbound_value == value; else total += wchar_braille_2da_get_bit(arr, x - dx, y - dy) == value; if (dx > x || y + dy >= height) total += outbound_value == value; else total += wchar_braille_2da_get_bit(arr, x - dx, y + dy) == value; if (x + dx >= width || dy > y) total += outbound_value == value; else total += wchar_braille_2da_get_bit(arr, x + dx, y - dy) == value; if (x + dx >= width || y + dy >= height) total += outbound_value == value; else total += wchar_braille_2da_get_bit(arr, x + dx, y + dy) == value; } } return total; }
BRAILLE_DEF double wchar_braille_2da_neighborhood_count_gaussian(wchar_braille_2da_t arr, unsigned x, unsigned y, unsigned rx, unsigned ry, bool value, bool outbound_value) { double total = 0.0; unsigned width = arr.width * BRAILLE_WIDTH; unsigned height = arr.height * BRAILLE_HEIGHT; if (rx == 0 || ry == 0) return 0.0; double normalization = 1.0 / (BRAILLE_PI * (double) rx * (double) ry); for (unsigned dx = 0; dx <= rx; ++dx) { for (unsigned dy = 0; dy <= ry; ++dy) { double weight = normalization * exp(-((double) dx * dx / ((double) rx * rx)) -((double) dy * dy / ((double) ry * ry))); if (dx == 0) { if (dy == 0) { total += (wchar_braille_2da_get_bit(arr, x, y) == value) * weight; continue; } if (dy > y) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x, y - dy) == value) * weight; if (y + dy >= height) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x, y + dy) == value) * weight; continue; } if (dy == 0) { if (dx > x) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x - dx, y) == value) * weight; if (x + dx >= width) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x + dx, y) == value) * weight; continue; } if (dx > x || dy > y) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x - dx, y - dy) == value) * weight; if (dx > x || y + dy >= height) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x - dx, y + dy) == value) * weight; if (x + dx >= width || dy > y) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x + dx, y - dy) == value) * weight; if (x + dx >= width || y + dy >= height) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x + dx, y + dy) == value) * weight; } } return total; }
BRAILLE_DEF float wchar_braille_2da_neighborhood_count_gaussianf(wchar_braille_2da_t arr, unsigned x, unsigned y, unsigned rx, unsigned ry, bool value, bool outbound_value) { float total = 0.0f; unsigned width = arr.width * BRAILLE_WIDTH; unsigned height = arr.height * BRAILLE_HEIGHT; if (rx == 0 || ry == 0) return 0.0f; float normalization = 1.0f / ((float) BRAILLE_PI * (float) rx * (float) ry); for (unsigned dx = 0; dx <= rx; ++dx) { for (unsigned dy = 0; dy <= ry; ++dy) { float weight = normalization * expf(-((float) (dx * dx) / (float) (rx * rx)) -((float) (dy * dy) / (float) (ry * ry))); if (dx == 0) { if (dy == 0) { total += (wchar_braille_2da_get_bit(arr, x, y) == value) * weight; continue; } if (dy > y) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x, y - dy) == value) * weight; if (y + dy >= height) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x, y + dy) == value) * weight; continue; } if (dy == 0) { if (dx > x) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x - dx, y) == value) * weight; if (x + dx >= width) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x + dx, y) == value) * weight; continue; } if (dx > x || dy > y) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x - dx, y - dy) == value) * weight; if (dx > x || y + dy >= height) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x - dx, y + dy) == value) * weight; if (x + dx >= width || dy > y) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x + dx, y - dy) == value) * weight; if (x + dx >= width || y + dy >= height) total += (outbound_value == value) * weight; else total += (wchar_braille_2da_get_bit(arr, x + dx, y + dy) == value) * weight; } } return total; }

#endif // BRAILLE_IMPLEMENTATION

