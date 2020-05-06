#include <stdio.h>

#include "hash_table.h"
#include <string.h>
#include <math.h>

#define HT_PRIME_1 73
#define HT_PRIME_2 175

// hash function
static int ht_hash(const char* str, const int a, const int m) {
  long hash = 0;
  const int str_length = strlen(str);
  for (int i = 0; i < str_length; i++) {
    hash += (long) pow(a, str_length - (i + 1)) * str[i];
    hash %= m;
  }
  return hash;
}

// double hashing method
int ht_get_double_hash(const char* s, const int num_buckets, const int attempt)  {
  const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
  const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);

  return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

// Linear probing method
int ht_get_linear_hash(const char* key, const int num_buckets, const int attempt) {
  const int hash = ht_hash(key, HT_PRIME_1, num_buckets);
  return (hash + attempt) % num_buckets;
}

// Quadratic probing method
int ht_get_quadratic_hash(const char* key, const int num_buckets, const int attempt) {
  const int hash = ht_hash(key, HT_PRIME_1, num_buckets);
  return (int)(hash + pow(attempt, 2)) % num_buckets;
}

int main(int argc, char *argv[]) {
  GetHashFn get_hash = ht_get_linear_hash;

  ht_hash_table* hash_table = ht_new();
  
  ht_upsert(hash_table, get_hash, "C", "1972");
  ht_upsert(hash_table, get_hash, "C++", "1980");
  ht_upsert(hash_table, get_hash, "SQL", "1978");
  ht_upsert(hash_table, get_hash, "Objective-C", "1986");
  ht_upsert(hash_table, get_hash, "Erlang", "1986");
  ht_upsert(hash_table, get_hash, "Haskell", "1990");
  ht_upsert(hash_table, get_hash, "Python", "1991");
  ht_upsert(hash_table, get_hash, "Lua", "1993");
  ht_upsert(hash_table, get_hash, "R", "1993");
  ht_upsert(hash_table, get_hash, "Ruby", "1995");
  ht_upsert(hash_table, get_hash, "Java", "1995");
  ht_upsert(hash_table, get_hash, "JavaScript", "1995");
  ht_upsert(hash_table, get_hash, "Delphi", "1993");
  ht_upsert(hash_table, get_hash, "PHP", "1995");
  ht_upsert(hash_table, get_hash, "ActionScript", "2000");
  ht_upsert(hash_table, get_hash, "C#", "2001");
  ht_upsert(hash_table, get_hash, "D", "2001");
  ht_upsert(hash_table, get_hash, "Scratch", "2002");
  ht_upsert(hash_table, get_hash, "Scala", "2003");
  ht_upsert(hash_table, get_hash, "F#", "2005");
  ht_upsert(hash_table, get_hash, "PowerShell", "2006");
  ht_upsert(hash_table, get_hash, "Clojure", "2007");
  ht_upsert(hash_table, get_hash, "Go", "2009");
  ht_upsert(hash_table, get_hash, "Rust", "2010");
  ht_upsert(hash_table, get_hash, "Elixir", "2011");
  ht_upsert(hash_table, get_hash, "Dart", "2011");
  ht_upsert(hash_table, get_hash, "Kotlin", "2011");
  ht_upsert(hash_table, get_hash, "Julia", "2012");
  ht_upsert(hash_table, get_hash, "TypeScript", "2012");
  ht_upsert(hash_table, get_hash, "Swift", "2014");

  char* javascript_year = ht_search(hash_table, get_hash, "TypeScript");
  printf("TypeScript was developed in %s year.\n", javascript_year);
  
  return 0;
}
