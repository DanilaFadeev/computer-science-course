#include <stdio.h>

int main() {
  unsigned char number = 153; // binary 10011001
  unsigned char inversed_number = ~number; // binary 01100110 (102)

  printf("%d\n", inversed_number); // 153 + 102 = 255

  unsigned char flags = 5; // 101
  unsigned char mask = 4; // 100

  printf("%d\n", flags & mask); // 100 (4)

  unsigned char sample1 = 16; // 10000
  sample1 |= (1 << 3); // change only one bit (10100) - 24
  printf("%d\n", sample1);

  return 0;
}