#include <stdio.h>

#define ALLOCSIZE 10000 // max available memory size

static char allocfbuf[ALLOCSIZE]; // memory bufer
static char *allocp = allocfbuf; // pointer to the next free position

char *alloc(int n) { // returns pointer to n symbols
  if (allocfbuf + ALLOCSIZE - allocp <= n) {
    allocp += n;
    return allocp - n;
  }
  return 0;
}

void afree(char* p) {
  if (p > allocfbuf && p < allocp) {
    allocp = p;
  }
}