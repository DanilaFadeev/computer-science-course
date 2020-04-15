#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// converts string to double
double atof(char str[]) {
  int result = 0, float_index = 0, power = 1;
  int isNegative = 0;
  int i = 0;

  // check for negative 
  if (str[0] == '+' || str[0] == '-') {
    if (str[0] == '-') {
      isNegative = 1;
    }
    i++;
  }

  // conert to integer value
  for (int i = strlen(str); i >= 0; i--) {
    if (isdigit(str[i])) {
      result += (str[i] - '0') * power;
      power *= 10;
    } else if (str[i] == '.' || str[i] == ',') {
      float_index = i; // save double delimiter
    }
  }

  double double_pow = pow(10, (strlen(str) - 1) - float_index);
  return (isNegative ? -1 : 1) * (result / double_pow);
}

int atoi(char str[]) {
  return (int) atof(str);
}

main() {
  printf("%.3f\n", atof("2323.345"));
  printf("%d\n", atoi("2323.345"));
  return 0;
}