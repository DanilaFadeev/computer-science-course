#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
  int mode = 0; // lower case mode
  if (argv[1] != NULL && (argv[1][0] == 'u' || argv[1][0] == 'U')) {
    mode = 1; // uppercase mode;
  }
  
  int c;
  while ((c = getchar()) != EOF) {
    putchar(mode == 0 ? tolower(c) : toupper(c));
  }

  return 0;
}
