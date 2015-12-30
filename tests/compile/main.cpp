/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2015 Liviu Ionescu.
 *
 * µOS++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * µOS++ is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "diag/trace.h"
#include <stdlib.h>
#include <assert.h>

char _Heap_Begin; // Defined by the linker.
char _Heap_Limit; // Defined by the linker.

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

int
main (int argc, char* argv[])
{
  void* m = malloc (7);
  trace_printf ("0x%08X\n", m);

  assert(0 == 0);
  return 0;
}

#pragma GCC diagnostic pop

extern "C" void __attribute__((noreturn))
__reset_hardware (void);

void
__reset_hardware (void)
{
  for (;;)
    ;
}
