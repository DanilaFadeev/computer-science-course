#include <string.h>
#include <math.h>

#define HT_PRIME_1 73
#define HT_PRIME_2 175 // TODO redo with prime util

static int ht_hash(const char* str, const int a, const int m) {
  long hash = 0;
  const int str_length = strlen(str);
  for (int i = 0; i < str_length; i++) {
    hash += (long) pow(a, str_length - (i + 1)) * str[i];
    hash %= m;
  }
  return hash;
}

int ht_get_double_hash(const char* s, const int num_buckets, const int attempt)  {
  const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
  const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);

  return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

int ht_get_linear_hash(const char* key, const int num_buckets, const int attempt) {
  const int hash = ht_hash(key, HT_PRIME_1, num_buckets);
  return (hash + attempt) % num_buckets;
}

int ht_get_quadratic_hash(const char* key, const int num_buckets, const int attempt) {
  const int hash = ht_hash(key, HT_PRIME_1, num_buckets);
  return (int)(hash + pow(attempt, 2)) % num_buckets;
}