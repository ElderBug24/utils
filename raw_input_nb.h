#ifndef RAW_INPUT_NB_H
#define RAW_INPUT_NB_H

#include <stdbool.h>


void enable_raw_nb(void);
void disable_raw_nb(void);
int getchrnb(void);

#ifdef _WIN32

#include <conio.h>

void enable_raw_nb(void) {}
void disable_raw_nb(void) {}

int getchrnb(void) {
  if (!_kbhit()) return -1;
  return _getch();
}

#else

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>


static struct termios orig_termios;
static int orig_flags;
static bool raw_enabled = false;

void enable_raw_nb(void) {
  struct termios raw;

  if (raw_enabled) return;

  tcgetattr(STDIN_FILENO, &orig_termios);
  memcpy(&raw, &orig_termios, sizeof(raw));
  cfmakeraw(&raw);
  tcsetattr(STDIN_FILENO, TCSANOW, &raw);

  orig_flags = fcntl(STDIN_FILENO, F_GETFL);
  fcntl(STDIN_FILENO, F_SETFL, orig_flags | O_NONBLOCK);

  raw_enabled = true;
}

void disable_raw_nb(void) {
  if (!raw_enabled) return;

  tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
  fcntl(STDIN_FILENO, F_SETFL, orig_flags);

  raw_enabled = false;
}

int getchrnb(void) {
  unsigned char c;

  if (read(STDIN_FILENO, &c, 1) == 1) return c;
  if (errno == EAGAIN || errno == EWOULDBLOCK) return -1;
  return -1;
}

#endif

#endif // RAW_INPUT_NB_H

