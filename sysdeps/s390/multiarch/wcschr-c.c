/* Default wcschr implementation for S/390.
   Copyright (C) 2015-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#if defined HAVE_S390_VX_ASM_SUPPORT && IS_IN (libc)
# define WCSCHR  __wcschr_c

# include <wchar.h>
extern __typeof (__wcschr) __wcschr_c;
# undef weak_alias
# define weak_alias(name, alias)
# ifdef SHARED
#  undef libc_hidden_def
#  define libc_hidden_def(name)					\
  __hidden_ver1 (__wcschr_c, __GI_wcschr, __wcschr_c);		\
  strong_alias (__wcschr_c, __wcschr_c_1);			\
  __hidden_ver1 (__wcschr_c_1, __GI___wcschr, __wcschr_c_1);
#  undef libc_hidden_weak
#  define libc_hidden_weak(name)
# endif /* SHARED */

# include <wcsmbs/wcschr.c>
#endif /* HAVE_S390_VX_ASM_SUPPORT && IS_IN (libc) */
