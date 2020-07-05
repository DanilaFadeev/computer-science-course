#include <stdio.h>
#include <stdlib.h>

typedef int Length;
typedef char* String;

typedef struct tnode {
  String word;
  Length count;
  struct tnode* left;
  struct tnode* right;
} TNode;

// Allocate memory for the new node
TNode* talloc(void) {
  return (TNode*) malloc(sizeof(TNode));
}

int main (int argc, char* argv[]) {
  String name = "Danila";
  printf("%s", name);
  return 0;
}
