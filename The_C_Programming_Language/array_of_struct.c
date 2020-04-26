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

struct key *binsearch(char *, struct key *, int n);

int main(int argc, char* argv[]) {
  char *found_words[] = {"do", "while", "for", "sizeof", "sizeof", "const",
   "return", "int", "short", "do", "while", "return", "switch",  0};

  char **pt = found_words;
  struct key *found;
  
  while(*pt != 0) {
    if ((found = binsearch(*pt, keytab, NKEYS)) != NULL) {
      found->count++;
    }
    *pt++;
  }

  for (int i = 0; i < NKEYS; i++) {
    printf("\"%s\" was found %d times.\n", keytab[i].word, keytab[i].count);
  }

  return 0;
}

/* use binary search to find a word mapping index on the keywords table */
struct key *binsearch(char *word, struct key *keytab, int n) {
  struct key *start = keytab;
  struct key *end = &keytab[n];
  struct key *middle;

  int compare_result;

  do {
    middle = start + (end - start) / 2;
    compare_result = strcmp(middle->word, word);

    if (compare_result == 0) {
      return middle;
    } else if (compare_result > 0) {
      end = middle;
    } else {
      start = middle + 1;
    }
  } while (start < end);

  return NULL;
}
