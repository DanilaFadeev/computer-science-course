#include <stdio.h>

#ifndef CUSTOM_VALUE
  #define CUSTOM_VALUE "My custom value"
#endif

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   //define something for Windows (32-bit and 64-bit, this part is common)
   #ifdef _WIN64
      //define something for Windows (64-bit only)
   #else
      //define something for Windows (32-bit only)
   #endif
#elif __APPLE__
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR
         // iOS Simulator
    #elif TARGET_OS_IPHONE
        // iOS device
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
    #else
      #error "Unknown Apple platform"
    #endif
#elif __linux__
    // linux
#elif __unix__ // all unices not caught above
    // Unix
#elif defined(_POSIX_VERSION)
    // POSIX
#else
  #error "Unknown compiler"
#endif

#define numeric 15
#define long_text "hello\
  from\
  multiline text\n"

#define forever for(;;;) // infinity loop

#define MAX(A, B) (A > B ? A : B)

#define getchar "some_value"
#undef getchar // clear macros reserved name

#define debug(expr) printf(#expr " = %g\n", expr) // # - replace argument with it's string value

int main() {
  printf("%d %s\n", numeric, long_text);

  printf("MAX(5, 9) = %d\n", MAX(5, 9)); // expands to (5 > 9 ? 5 : 9)

  double a = 10, b = 3;
  debug(a / b); // expands to printf("a / b" " = %g\n", a / b)

  printf("%s\n", CUSTOM_VALUE);

  return 0;
}