#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// point to the first array item as an argument
// with it we could iterate input array and count symbols
int strlen(char *string) {
  int total = 0;
  for (total = 0; *string != '\0'; total++, string++);
  return total;
}

// copy source string into dest
void strcopy(char *source, char *dest) {
  while(*dest++ = *source++);
}

// compare two strings
int strcmp(char *source, char *compare) {
  while(*source++ == *compare++ && *source != '\0');
  return !*(--source) ? 0 : *source - *(--compare);
}

// strings concatination
char *strcat(char *source, char *str) {
  char buffer[100];
  char *buffer_p = buffer;

  while (*buffer_p++ = *source++);
  buffer_p--;
  while (*buffer_p++ = *str++);
  *buffer_p = '\0';
  
  return buffer;
}

int main() {
  int ten = 10, five = 5;
  swap(&ten, &five);

  printf("ten = %d, five = %d\n", ten, five);

  int numbers[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
  int *numbers_pointer = &numbers[0];    

  printf("%d\n", *(numbers_pointer + 1)); // move pointer to next item

  char string[] = "Hello! This is custom string with length 44.";
  printf("Input: %s\nActual length: %d\n", string, strlen(string));

  char source_str[] = "ABCDEF";
  char dest_str[6];

  strcopy(source_str, dest_str);
  printf("Copied string: %s\n", dest_str);

  printf("Compare 'hello' and 'hello': %d\n", strcmp("hello", "hello"));
  printf("Compare 'hello' and 'hewlo': %d\n", strcmp("hello", "hewlo"));
  printf("Compare 'hello' and 'hedlo': %d\n", strcmp("hello", "hedlo"));

  char string_source[] = "first->";
  printf("String concatination: %s\n", strcat(string_source, "second"));

  return 0;
}