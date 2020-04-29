#include <stdio.h>

#include "hash_table.h"

int main(int argc, char *argv[]) {
  ht_hash_table* hash_table = ht_new();
  
  ht_upsert(hash_table, "C", "1972");
  ht_upsert(hash_table, "SQL", "1978");
  ht_upsert(hash_table, "C++", "1980");
  ht_upsert(hash_table, "Objective-C", "1986");
  ht_upsert(hash_table, "Erlang", "1986");
  ht_upsert(hash_table, "Haskell", "1990");
  ht_upsert(hash_table, "Python", "1991");
  ht_upsert(hash_table, "Java", "1995");
  ht_upsert(hash_table, "JavaScript", "1995");
  ht_upsert(hash_table, "PHP", "1995");
  ht_upsert(hash_table, "Clojure", "2007");
  ht_upsert(hash_table, "Elixir", "2011");

  char* javascript_year = ht_search(hash_table, "JavaScript");
  printf("JavaScript was developed in %s year.\n", javascript_year);
  
  return 0;
}
