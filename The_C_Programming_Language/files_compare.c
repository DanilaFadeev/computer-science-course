#include <stdio.h>
#include <string.h>

#define MAXLEN 100

int main(int argc, char* argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Incorrect arguments count");
    return 1;
  }

  FILE *f1 = fopen(argv[1], "r");
  FILE *f2 = fopen(argv[2], "r");

  char* buf1 = malloc(sizeof(char) * MAXLEN);
  char* buf2 = malloc(sizeof(char) * MAXLEN);

  int line = 1;
  for (
    buf1 = fgets(buf1, MAXLEN, f1), buf2 = fgets(buf2, MAXLEN, f2);
    buf1 || buf2;
    buf1 = fgets(buf1, MAXLEN, f1), buf2 = fgets(buf2, MAXLEN, f2)
  ) {
    if (buf1 != NULL && buf2 != NULL) {
      if (strcmp(buf1, buf2) != 0) {
        fprintf(stdout, "%d. \033[0;31m- %s\033[0m%d. \033[0;32m+ %s\033[0m", line, buf1, line++, buf2);
      } else {
        fprintf(stdout, "%d. %s", line++, buf1);
      }
    } else if (!buf1) {
      fprintf(stdout, "%d. \033[0;32m+ %s\033[0m", line++, buf2);
    } else {
      fprintf(stdout, "\033[0;31m- %s\033[0m", buf1);
    }
  }

  // A little cleanup
  fclose(f1);
  fclose(f1);

  free(buf1);
  free(buf2);

  return 0;
}
