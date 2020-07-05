#include <stdio.h>
#include <stdlib.h>

#define NSYM 100

enum Type {
  INT,
  FLOAT,
  CHAR_PTR
};

typedef union {
  int ival;
  float fval;
  char* sval;
} u_tag;

typedef struct {
  char* name;
  int utype;
  u_tag value;
} symtab;


int main (int argc, char* argv[]) {
  u_tag u;

  u.ival = 10;
  printf("%d\n", u.ival); 

  u.sval = "hi";
  // printf("%d\n", u.ival); // not accessible anymore
  printf("%s\n", u.sval); // will work

  symtab tab1 = { "MAXVALUE", FLOAT };
  tab1.value.fval = 2.3;

  if (tab1.utype == INT) {
    printf("%s %d\n", tab1.name, tab1.value.ival);
  } else if (tab1.utype == FLOAT) {
    printf("%s %.2f\n", tab1.name, tab1.value.fval);
  } else if (tab1.utype == CHAR_PTR) {
    printf("%s %s\n", tab1.name, tab1.value.sval);
  } else {
    printf("Bad type %d\n", tab1.name, tab1.value.ival);
  }
  
  return 0;
}
