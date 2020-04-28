#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"





int main(int argc, char *argv[]) {
  ht_hash_table* hash_table = ht_new();
  ht_clear_hash_table(hash_table);

  printf("%d\n", ht_hash("fello", 163, 53));
  
  return 0;
}
