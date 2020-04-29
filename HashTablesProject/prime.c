#include <math.h>

#include "prime.h"
#include "utils.h"

// check of number is prime
short is_prime(const int number) {
  if (number < 2) { return false; }
  if (number < 4) { return true; }
  if (number % 2 == 0) { return false; }
  for (int i = 3; i < floor(sqrt((double) number)); i+= 2) {
    if ((number % i) == 0) {
      return false;
    }
  }
  return true;
}

// return the next prime value after number
int next_prime(int number) {
  while (!is_prime(number++));
  return number - 1;
}
