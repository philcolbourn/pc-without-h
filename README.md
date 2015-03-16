# pc-without-h
Automatically exported from code.google.com/p/pc-without-h

I present a simple method using a few macros and some simple discipline to incorporate C header definitions with C code.

For example:

```
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
```
