/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

#include <stdlib.h>

using uint32 = uint32_t;

void convert_all(unsigned nlines, char *lines[], uint32 nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    nums[i] = atoi(lines[i]);
  }
}
