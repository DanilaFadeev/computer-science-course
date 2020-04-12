#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MAX_LENGTH 100

int isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 1 : 0;
}

char lower(char s) {
  if (s >= 'A' && s <= 'Z') {
    return s + ('a' - 'A');
  }
  return s;
}

int main() {
  // char
  char character = 'g';
  printf("Signed char limits: from %d to %d\n", SCHAR_MIN, SCHAR_MAX);

  unsigned character_unsign = 'z';
  printf("Unsigned char limits: from %d to %d\n\n", 0, UCHAR_MAX);

  // integer
  int number = 12;

  short int short_num_1 = 1;   // the same (16 bit)
  short short_num_2 = 1;
  printf("Signed short limits: from %d to %d\n", SHRT_MIN, SHRT_MAX);
  printf("Unsigned short limits: from %d to %d\n\n", 0, USHRT_MAX);

  long int long_num_1 = 1; // also the same (32 bit)
  long long_num_2 = 1;
  printf("Signed long limits: from %ld to %ld\n", LONG_MIN, LONG_MAX);
  printf("Unsigned long limits: from %d to %llu\n\n", 0, ULLONG_MAX);

  // double
  double pi = 3.14;
  long double long_double_num = 2.342342;

  // float
  float cost = 1.23;

  int sys8 = 0x23;
  int sys16 = 0X23A3B;

  enum boolean { NO, YES };
  enum escapes {
    BELL = '\a',
    BACKSPACE = '\b',
    TAB = '\t',
    NEWLINE = '\n',
    VTAB = '\v'
  };

  printf("Is leap year?\n1999 - %d\n2000 - %d\n2001 - %d\n", isLeapYear(1999), isLeapYear(2000), isLeapYear(2001));

  printf("lower('G'): %c\n", lower('g'));

  printf("Type conversion - sqrt(25): %d\n", (int) sqrt(25));

  // read line with for
  char string[MAX_LENGTH], ch;

  printf("Input the line 1:\n");
  for (int i = 0; i < MAX_LENGTH - 1 && (ch = getchar()) != '\n' && ch != EOF; i++) {
    string[i] = ch;
  }

  // analog without "&&" and "||"
  printf("Input the line 2:\n");
  for (int i = 0; (i < MAX_LENGTH - 1) + ((ch = getchar()) != '\n') + (ch != EOF) == 3; i++) {
    string[i] = ch;
  }

  return 0;
}