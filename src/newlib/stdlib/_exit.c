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

#include <stdlib.h>
#include "diag/trace.h"

// ----------------------------------------------------------------------------

#if defined(DEBUG)
#define __DEBUG_BKPT()  asm volatile ("bkpt 0")
#endif

#if !defined(DEBUG)
extern void __attribute__((noreturn))
__reset_hardware(void);
#endif

void
_exit (int code);

// ----------------------------------------------------------------------------

// On Release, call the hardware reset procedure.
// On Debug we just enter an infinite loop, to be used as landmark when halting
// the debugger.
//
// It can be redefined in the application, if more functionality
// is required.

void __attribute__((weak))
_exit (int code __attribute__((unused)))
{
  trace_puts("_exit()");
#if !defined(DEBUG)
  __reset_hardware();
#else
  __DEBUG_BKPT();
#endif

  // For just in case.
  while (1)
    ;
  /* NOTREACHED */
}

// ----------------------------------------------------------------------------
