#include <stdio.h>

void filecopy(FILE *in, FILE *out) {
  char ch;
  while ((ch = fgetc(in)) != EOF)
    fputc(ch, out);
}

int main(int argc, const char* argv[]) {
  if (argc == 1) {
    return 0;
  }

  FILE *fp;
  char ch;

  while (--argc > 0) {
    if ((fp = fopen(*++argv, "r")) == NULL) {
      fprintf(stderr, "Error during opening file %s\n", *argv);
      exit(1);
    }
    filecopy(fp, stdout);
    fclose(fp);
  }

  if (ferror(stdout)) {
    fprintf(stderr, "Error writing stdout");
    exit(2);
  }

  exit(0);
}
