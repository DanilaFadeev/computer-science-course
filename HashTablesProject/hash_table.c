#include <stdlib.h>
#include "hash_table.h"
#include "prime.h"
#include "utils.h";

#define HASH_TABLE_SIZE 53
#define HT_INITIAL_BASE_SIZE 73
#define HT_PRIME_1 73
#define HT_PRIME_2 175

#define UP_LOAD_LIMIT 70
#define DOWN_LOAD_LIMIT 10

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

/*
  Create a new hash table with optional size. If base_size is not a prime value,
  the first prime number after it will be used.
*/
ht_hash_table* ht_new_sized(const int base_size) {
  ht_hash_table* hash_table = xmalloc(sizeof(ht_hash_table)); // change to malloc if need
  hash_table->base_size = base_size;

  hash_table->size = next_prime(base_size);

  hash_table->count = 0;
  hash_table->items = xcalloc((size_t)hash_table->size, sizeof(ht_item*)); // change to calloc if need

  return hash_table;
}

/*
  Create a new hash table with constant base size
*/
ht_hash_table* ht_new() {
  return ht_new_sized(HT_INITIAL_BASE_SIZE);
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

/*
  Resize a hash table, by creation a new temporary hash table with with a new size,
  move current existing items there and swap them in the end.
  Old hash table will be deleted from memory.
*/
void ht_resize(ht_hash_table *hash_table, const int base_size) {
  if (base_size < HT_INITIAL_BASE_SIZE) {
    return;
  }

  // create new hash table with base_size
  ht_hash_table *new_hash_table = ht_new_sized(base_size);

  // insert all the items from the old hash table
  for (int i = 0; i < hash_table->size; i++) {
    ht_item *item = hash_table->items[i];
    if (item != NULL && item != &HT_DELETED_ITEM) {
      ht_upsert(new_hash_table, item->key, item->value);
    }
  }

  // update old hash table options with new processed ones
  hash_table->count = new_hash_table->count;
  hash_table->base_size = new_hash_table->base_size;

  // to delete new_ht, we give it old hash table size and items 
  const int tmp_size = hash_table->size;
  hash_table->size = new_hash_table->size;
  new_hash_table->size = tmp_size;

  ht_item** tmp_items = hash_table->items;
  hash_table->items = new_hash_table->items;
  new_hash_table->items = tmp_items;

  ht_del_hash_table(new_hash_table);
}

void ht_resize_up(ht_hash_table* hash_table) {
  const int new_size = hash_table->base_size * 2;
  return ht_resize(hash_table, new_size);
}

void ht_resize_down(ht_hash_table* hash_table) {
  const int new_size = hash_table->base_size / 2;
  return ht_resize(hash_table, new_size);
}


// double hashing method
static int ht_get_hash(const char* s, const int num_buckets, const int attempt)  {
  const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
  const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);

  return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

static ht_item HT_DELETED_ITEM = { NULL, NULL };

void ht_upsert(ht_hash_table* ht, const char* key, const char* value) {
  ht_item* item = ht_new_item(key, value);
  int index = ht_get_hash(item->key, ht->size, 0);

  ht_item* current_item = ht->items[index];
  int attempt = 1;

  while (current_item != NULL) {
    if (current_item != &HT_DELETED_ITEM) {
      // update if found with the same key
      if (strcmp(current_item->key, key) == 0) {
        ht_delete_item(current_item);
        ht->items[index] = item;
        return;
      }
    }

    index = ht_get_hash(item->key, ht->size, attempt++);
    current_item = ht->items[index];
  }

  ht->items[index] = item;
  ht->count++;

  // check and resize hash table if necessary
  const int hash_table_load = ht->count * 100 / ht->size;
  if (hash_table_load > UP_LOAD_LIMIT) {
    ht_resize_up(ht);
  }
}

char* ht_search(ht_hash_table* ht, const char* key) {
  int index = ht_get_hash(key, ht->size, 0);
  ht_item* item = ht->items[index];

  int attempt = 1;
  while (item != NULL) {
    if (item != &HT_DELETED_ITEM) {
      if (strcmp(key, item->key) == 0) {
        return item->value;
      }
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

  // check and resize table if necessary
  const int hash_table_load = ht->size * 100 / ht->count;
  if (hash_table_load < DOWN_LOAD_LIMIT) {
    ht_resize_down(ht);
  }
}
