#include <stdio.h>
#include <string.h>

#define MAX_LINES 100

// libs definitions
char *alloc(int);
int get_line(char*);
// end libs definitions

char *lineptr[MAX_LINES];

int readlines(char *lineptr[]) {
  int len, nlines = 0;
  char *p, temp[100];

  while(len = get_line(temp)) {
    p = alloc(len);
    if (p) {
      // not working somehow ;(
      printf("yes");
    }
    //*lineptr++ = p;
    nlines++;
  }

  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  while(nlines--) {
    printf("%s", *lineptr++);
  }
}

int main() {
  int nlines = readlines(lineptr);
  writelines(lineptr, nlines);

  return 0;
}
