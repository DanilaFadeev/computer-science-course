#include <stdlib.h>
#include "./hash_table.h"

#define HASH_TABLE_SIZE 53
#define HT_PRIME_1 73
#define HT_PRIME_2 175

#define true 1
#define false 0

// create a new hash table item in memory
static ht_item* ht_new_item(const char* key, const char* value) {
  ht_item* item = malloc(sizeof(ht_item));
  item->key = strdup(key);
  item->value = strdup(value);

  return item;
}

static void ht_clear_item(ht_item* item) {
  free(item->key);
  free(item->value);
  free(item);
}

static void ht_clear_hash_table(ht_hash_table* hash_table) {
  for (int i = 0; i < hash_table->size; i++) {
    ht_item* item = hash_table->items[i];
    if (item != NULL) {
      ht_clear_item(item);
    }
  }

  free(hash_table->items);
  free(hash_table);
}

ht_hash_table* ht_new() {
  ht_hash_table* hash_table = malloc(sizeof(ht_hash_table));
  hash_table->size = HASH_TABLE_SIZE;
  hash_table->count = 0;
  hash_table->items = calloc((size_t)hash_table->size, sizeof(ht_item*)); // wtf is calloc?

  return hash_table;
}

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
static int ht_get_hash(const char* s, const int num_buckets, const int attempt)  {
  const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
  const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);

  return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

static ht_item HT_DELETED_ITEM = { NULL, NULL };

void ht_insert(ht_hash_table* ht, const char* key, const char* value) {
  ht_item* item = ht_new_item(key, value);
  int index = ht_get_hash(item->key, ht->size, 0);

  ht_item* current_item = ht->items[index];
  int attempt = 1;

  while (current_item != NULL && current_item != &HT_DELETED_ITEM) {
    index = ht_get_hash(item->key, ht->size, attempt++);
    current_item = ht->items[index];
  }

  ht->items[index] = item;
  ht->count++;
}

char* ht_search(ht_hash_table* ht, const char* key) {
  int index = ht_get_hash(key, ht->size, 0);
  ht_item* item = ht->items[index];

  int attempt = 1;
  while (item != NULL) {
    if (strcmp(key, item->key) == 0) {
      return item->value;
    }
    index = ht_get_hash(key, ht->size, attempt++);
    item = ht->items[index];
  } 

  return NULL;
}

void ht_delete(ht_hash_table* ht, const char* key) {
  short is_item_deleted = false; 
  int index = ht_get_hash(key, ht->size, 0);
  ht_item* item = ht->items[index];

  int attempt = 1;
  while (item != NULL) {
    if (item != &HT_DELETED_ITEM) {
      if (strcmp(item->key, key) == 0) {
        ht_delete_item(item);
        ht->items[index] = &HT_DELETED_ITEM;
        is_item_deleted = true;
      }
    }
    index = ht_get_hash(key, ht->size, attempt++);
    item = ht->items[index];
  }

  if (is_item_deleted) {
    ht->count--;
  } 
}
