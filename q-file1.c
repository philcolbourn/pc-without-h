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

/*
How does it work?
=================

This uses standard 'wrapper #ifndef' methods to ensure a file is read only once.

If __header is undefined both header and code parts will be read. This will compile a code file as normal.

But, if __header is defined a file will act as a C header file.

In addition if __main equals some unique value, a main procedure can be compiled. Each file can have a main procedure to allow unit testing as demonstrated in these examples.

See also

http://gcc.gnu.org/onlinedocs/gcc-3.2/cpp/Obsolete-once-only-headers.html


Operating Modes
===============

Mode:     Stand-alone compile

On entry: nothing is defined

Action:   _file_c is defined
          _file_h is defined
          __header is defined
          File is processed as a header file
          Other files will be included as header files
          File is also processed as a code file
          main will be compiled if __main has specified value


Mode:     Header file - included from another file

On entry: __header is defined

Action:   _file_h is defined
          File is processed as a header file
          Other files will be included as header files


Mode:     Multiple include - included from another file again

On entry: __header and _file_h are defined

Action:   File is skipped

*/

#ifndef __header         // must be compiling c file
  #define _q_file1_c     // compile code and not others that are included
#endif

#ifndef _q_file1_h       // only load once
  #define _q_file1_h     // dont reload this file
  #define __header       // tell included files we only want header parts

#ifdef __header          // normal header part

// START HEADER DEFINITIONS

#include <stdio.h>
#include "q-file1.c"     // this file will skip itself!
#include "q-file2.c"
#include "q-file3.c"

void f1( char *m );

// END HEADER DEFINITIONS

#endif // __header

#if defined(_q_file1_c)  // compile this code

// START CODE

void f1( char *m ){
  printf( "f1: %s\n",m );
}

#if __main==1            // we want main for this one
int main(){
  f1( "main" );
  f2( "main" );
  f3( "main" );
}
#endif

// END CODE

#endif  // compile this code
#endif  // only load once

