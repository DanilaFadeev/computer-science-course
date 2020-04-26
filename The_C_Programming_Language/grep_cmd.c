#include <stdio.h>
#include <string.h>

int get_line(char *str);

int main(int argc, char *argv[]) {
  // display all the input arguments 
  // for (int i = 0; i < argc; i++) {
  //   printf("Argument #%d: %s\n", i + 1, argv[i]);
  // }

  if (argc < 2) {
    printf("Input search pattern argument!\n");
    return 0;
  }

  int total = 0;
  char line[100];
  while(get_line(&line) > 0) {
    if (strstr(line, argv[1])) {
      printf("%s\n", line);
      total++;
    }
  }

  printf("Total found: %d", total);

  return 0;
}