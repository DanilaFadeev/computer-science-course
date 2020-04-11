#include <stdio.h>

#define MAX_LEN 80
#define TAB_INDENT 4

int getLine(char s[]) {
	char ch;
	int i;
	for (i = 0; (ch = getchar()) != '\n'; i++) {
		s[i] = ch;
	}
	return i;
}

int detab(char string[], int length) {
  int new_length = length;
  for (int i = 0; i < length; i++) {
    if (string[i] == '\t') {
      new_length += TAB_INDENT - 1;
      for (int j = new_length - 1; j >= i; j--) {
        if (j >= i + TAB_INDENT) {
          string[j] = string[j - TAB_INDENT + 1];
        } else {
          string[j] = ' ';
        }
      }
    }
  }
  return new_length;
}

int main() {
  char str[MAX_LEN];
  int source_length = getLine(str);
  int updated_length = detab(str, source_length);

  for (int i = 0; i < updated_length; i++) {
    printf("%c- ", str[i]);
  }

  printf("\nUpdated Length: %d\n", updated_length);

  return 0;
}