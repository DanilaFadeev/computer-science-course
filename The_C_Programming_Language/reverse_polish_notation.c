#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define NUMBER_SIGNAL 'o'

char getOperator(char[]);
void push(double);
double pop(void);

int main() {
  char ch;
  double sum;

  printf("Input calculation string (e.g. 1 2 + 4 2 / -)\n");

  while(((ch = getchar()) != EOF && ch != '\n')) {
    if (isdigit(ch)) {
      char char_to_string[] = { ch };
      push(atof(char_to_string));
    } else if (ch == '+') {
      sum = pop() + pop();
      push(sum);
    } else if (ch == '-') {
      double tmp = pop();
      sum = pop() - tmp;
      push(sum);
    } else if (ch == '*') {
      sum = pop() * pop();
      push(sum);
    } else if (ch == '/') {
      double tmp = pop();
      sum = pop() / tmp;
      push(sum);
    }
  }

  double result = pop();
  printf("Result is = %f\n", result);

  return 0;
}

// available on the following code,
// unavailable in the previous
int stack_pointer = 0;
double stack[STACK_SIZE];

void push(double value) {
  if (stack_pointer >= STACK_SIZE - 1) {
    printf("Stack is full!");
    return;
  } 
  stack[stack_pointer++] = value;
}

double pop() {
  if (stack_pointer <= 0) {
    return printf("Stack is empty!");
  }
  return stack[--stack_pointer];
}

