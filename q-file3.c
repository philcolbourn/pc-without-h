/*
    Copyright 1991, 2012 Phil Colbourn

    This file is part of pc-without-h.

    pc-without-h is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    pc-without-h is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with pc-without-h.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __header
  #define _q_file3_c
#endif

#ifndef _q_file3_h
  #define _q_file3_h
  #define __header    

#ifdef __header

// START HEADER DEFINITIONS

#include <stdio.h>
#include "q-file1.c"
#include "q-file2.c"
#include "q-file3.c"

void f3( char *m );

// END HEADER DEFINITIONS

#endif

#if defined(_q_file3_c)

// START CODE

void f3( char *m ){
  printf( "f3: %s\n",m );
}

#if __main==3
int main(){
  f1( "3rd" );
  f2( "3rd" );
  f3( "3rd" );
}
#endif

// END CODE

#endif
#endif

