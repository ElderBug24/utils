#include <stdio.h>

#ifdef _WIN32

#include <windows.h>

unsigned get_term_width(void) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) return 0;
  return (unsigned)(csbi.srWindow.Right - csbi.srWindow.Left + 1);
}

unsigned get_term_height(void) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) return 0;
  return (unsigned)(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
}

#else

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

unsigned get_term_width(void) {
  struct winsize ws;
  if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) != 0 &&
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != 0 &&
    ioctl(STDERR_FILENO, TIOCGWINSZ, &ws) != 0) {
    fprintf(stderr, "ioctl() failed (%d): %s\n", errno, strerror(errno));
    return 0;
  }

  return ws.ws_col;
}

unsigned get_term_height(void) {
  struct winsize ws;
  if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) != 0 &&
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != 0 &&
    ioctl(STDERR_FILENO, TIOCGWINSZ, &ws) != 0) {
    fprintf(stderr, "ioctl() failed (%d): %s\n", errno, strerror(errno));
    return 0;
  }
  return ws.ws_row;
}

#endif

