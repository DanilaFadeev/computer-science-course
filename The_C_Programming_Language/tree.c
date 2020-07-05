#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* word; 
  int count;
  struct tnode* left;
  struct tnode* right;
} tnode;

void add_to_tree(tnode** root, char* word) {
  if (*root == NULL) {
    *root = malloc(sizeof(tnode));
    (*root)->word = word;
    (*root)->count = 1;
    return;
  }

  int comparation = strcmp((*root)->word, word);
  if (comparation == 0) {
    (*root)->count++;
  } else if (comparation > 0) {
    add_to_tree(&((*root)->right), word);
  } else {
    add_to_tree(&((*root)->left), word);
  }
}

void print_tree(tnode* root) {
  if (root != NULL) {
    print_tree(root->left);
    printf("%s (%d)\n", root->word, root->count);
    print_tree(root->right);
  }
}

int main(int argc, char* argv[]) {
  tnode* root;

  add_to_tree(&root, "Hello");
  add_to_tree(&root, "Lol");
  add_to_tree(&root, "Summer");
  add_to_tree(&root, "Strict");
  add_to_tree(&root, "Hohoho");
  add_to_tree(&root, "Lol");

  print_tree(root);

  return 0;
}
