#ifndef RAW_INPUT_H
#define RAW_INPUT_H

void enable_raw_mode(void);
void disable_raw_mode(void);

typedef int (*getchr_t) (void);

#ifdef _WIN32

#include <conio.h>


void enable_raw_mode(void) {}
void disable_raw_mode(void) {}
getchr_t getchr = _getch;

#else

#include <stdio.h>
#include <termios.h>
#include <unistd.h>


struct termios orig;

void enable_raw_mode(void) {
  struct termios raw;
  tcgetattr(STDIN_FILENO, &orig);
  raw = orig;
  raw.c_lflag &= (tcflag_t) ~(ICANON | ECHO);
  raw.c_cc[VMIN] = 1;
  raw.c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void disable_raw_mode(void) {
  tcsetattr(STDIN_FILENO, TCSANOW, &orig);
}

getchr_t getchr = getchar;

#endif

#endif // RAW_INPUT_H

