int get_line(char *str) {
  int length = 0;
  while((*str++ = getchar()) != '\n') {
    length++;
  }

  *(str - 1) = '\0';
  return length;
}
