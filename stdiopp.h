#ifndef STDIOPP_H
#define STDIOPP_H

#include <stdio.h>
#include <stdlib.h>


int set_stdout_buf_size(unsigned long size) {
  if (setvbuf(stdout, malloc(size), _IOFBF, size) != 0)
    return 1;
  return 0;
}

#endif // STDIOPP_H

