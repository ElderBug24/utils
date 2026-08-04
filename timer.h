#ifndef TIME_H
#define TIME_H

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

static double time_now(void) {
  static LARGE_INTEGER frequency;
  static int initialized = 0;

  if (!initialized) {
    QueryPerformanceFrequency(&frequency);
    initialized = 1;
  }

  LARGE_INTEGER counter;
  QueryPerformanceCounter(&counter);

  return (double)counter.QuadPart / (double)frequency.QuadPart;
}

static void time_sleep_for(double seconds) {
  if (seconds <= 0.0)
    return;

  DWORD milliseconds = (DWORD)(seconds * 1000.0);

  if (milliseconds == 0)
    milliseconds = 1;

  Sleep(milliseconds);
}

#else

#include <time.h>
#include <errno.h>

static double time_now(void) {
  struct timespec ts;

  clock_gettime(CLOCK_MONOTONIC, &ts);

  return (double)ts.tv_sec +
    (double)ts.tv_nsec / 1000000000.0;
}

static void time_sleep_for(double seconds) {
  if (seconds <= 0.0)
    return;

  struct timespec ts;

  ts.tv_sec = (time_t)seconds;
  ts.tv_nsec = (long)((seconds - (double)ts.tv_sec) * 1000000000.0);

  while (nanosleep(&ts, &ts) == -1 && errno == EINTR) {
  }
}

#endif

#endif // TIME_H

