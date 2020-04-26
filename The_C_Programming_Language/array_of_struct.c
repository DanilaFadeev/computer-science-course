#include <stdio.h>
#include <string.h>
#include <math.h>

struct key {
  char *word;
  int count;
} keytab[] = {
  "auto", 0,
  "break", 0,
  "case", 0,
  "char", 0,
  "const", 0,
  "continue", 0,
  "default", 0,
  "do", 0,
  "double", 0,
  "else", 0,
  "enum", 0,
  "extern", 0,
  "float", 0,
  "for", 0,
  "goto", 0,
  "if", 0,
  "int", 0,
  "long", 0,
  "register", 0,
  "return", 0,
  "short", 0,
  "signed", 0,
  "sizeof", 0,
  "static", 0,
  "struct", 0,
  "switch", 0,
  "typedef", 0,
  "union", 0,
  "unsigned", 0,
  "void", 0,
  "volatile", 0,
  "while", 0
};

#define NKEYS (sizeof keytab / sizeof(struct key))

int binsearch(char *, struct key *, int n);

int main(int argc, char* argv[]) {
  char *found_words[] = {"do", "while", "for", "sizeof", "sizeof", "const",
   "return", "int", "short", "do", "while", "return", "switch",  0};

  int found_index;
  char **pt = found_words;
  while(*pt != 0) {
    if ((found_index = binsearch(*pt, keytab, NKEYS)) >= 0) {
      keytab[found_index].count++;
    }
    *pt++;
  }

  for (int i = 0; i < NKEYS; i++) {
    printf("\"%s\" was found %d times.\n", keytab[i].word, keytab[i].count);
  }

  return 0;
}

/* use binary search to find a word mapping index on the keywords table */
int binsearch(char *word, struct key keytab[], int n) {
  int start = 0, end = n, middle, compare_result;

  do {
    middle = floor((double)(start + end) / 2);
    compare_result = strcmp(keytab[middle].word, word);

    if (compare_result > 0) {
      end = middle;
    } else {
      start = middle + 1;
    }
  } while (start < end && compare_result != 0);

  return compare_result == 0 ? middle : -1;
}
