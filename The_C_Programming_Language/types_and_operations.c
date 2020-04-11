#include <stdio.h>
#include <limits.h>

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

  return 0;
}