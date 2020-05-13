#include <math.h>
#include <time.h>
#include <string.h>

#include "utils.h"

// check of number is prime
Boolean is_prime(const int number) {
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

// print timestamp string
void print_timestamp() {
  // get current cal time
  time_t ltime = time(NULL);
  char *timestamp = ctime( localtime(&ltime) );

  // remove new line
  timestamp[strlen(timestamp) - 1] = '\0';

  // print colorised timestamp
  char timestamp_text[strlen(timestamp) + 2];
  sprintf(timestamp_text, "%s: ", timestamp);
  colorise_yellow(timestamp_text);
}
