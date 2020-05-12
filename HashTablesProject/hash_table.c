#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

#include "hash_table.h"
#include "prime.h"
#include "utils.h"

#define HASH_TABLE_SIZE 53
#define HT_INITIAL_BASE_SIZE 73

#define UP_LOAD_LIMIT 70
#define DOWN_LOAD_LIMIT 10

// empty item instance for delete operation
static ht_item HT_DELETED_ITEM = { NULL, NULL };

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

void ht_clear_hash_table(ht_hash_table* hash_table) {
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
  Resize a hash table, by creation a new temporary hash table with with a new size,
  move current existing items there and swap them in the end.
  Old hash table will be deleted from memory.
*/
static void ht_resize(ht_hash_table *hash_table, GetHashFn get_hash, const int base_size) {
  if (base_size < HT_INITIAL_BASE_SIZE) {
    return;
  }

  // create new hash table with base_size
  ht_hash_table *new_hash_table = ht_new_sized(base_size);

  // insert all the items from the old hash table
  for (int i = 0; i < hash_table->size; i++) {
    ht_item *item = hash_table->items[i];
    if (item != NULL && item != &HT_DELETED_ITEM) {
      ht_upsert(new_hash_table, get_hash, item->key, item->value);
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

  ht_clear_hash_table(new_hash_table);
}

static void ht_resize_up(ht_hash_table* hash_table, GetHashFn get_hash) {
  const int new_size = hash_table->base_size * 2;
  return ht_resize(hash_table, get_hash, new_size);
}

void ht_resize_down(ht_hash_table* hash_table, GetHashFn get_hash) {
  const int new_size = hash_table->base_size / 2;
  return ht_resize(hash_table, get_hash, new_size);
}

/*
  Create a new hash table with constant base size
*/
ht_hash_table* ht_new() {
  return ht_new_sized(HT_INITIAL_BASE_SIZE);
}

/*
  Create a new hash table with optional size. If base_size is not a prime value,
  the first prime number after it will be used
*/
ht_hash_table* ht_new_sized(const int base_size) {
  ht_hash_table* hash_table = malloc(sizeof(ht_hash_table));
  hash_table->base_size = base_size;

  hash_table->size = next_prime(base_size);

  hash_table->count = 0;
  hash_table->items = calloc((size_t)hash_table->size, sizeof(ht_item*));

  return hash_table;
}

/*
  Insert new item into hash table, or update pair value,
  if item with current key already exists
*/
void ht_upsert(ht_hash_table* ht, GetHashFn get_hash, const char* key, const char* value, ...) {
  // START check for debug option
  va_list ap;
  va_start(ap, key);
  unsigned short isDebug = false;
  unsigned short debugParameter = va_arg(ap, short);
  if (debugParameter == true) isDebug = true;
  va_end(ap);
  // END check for debug option

  ht_item* item = ht_new_item(key, value);
  int index = get_hash(item->key, ht->size, 0);

  ht_item* current_item = ht->items[index];
  int attempt = 1;

  if (isDebug) {
    printf("Generated index: %d\n", index);
  }

  while (current_item != NULL) {
    if (current_item != &HT_DELETED_ITEM) {
      // update if found with the same key
      if (strcmp(current_item->key, key) == 0) {
        ht_clear_item(current_item);
        ht->items[index] = item;

        if (isDebug) {
          printf("Item with key '%s' already exists. Update value with '%s'\n", key, value);
        }

        return;
      }
    }

    index = get_hash(item->key, ht->size, attempt++);
    current_item = ht->items[index];

    if (isDebug) {
      printf("Attempt: %d. Item index already used! Generated a new one - %d\n", attempt, index);
    }
  }

  ht->items[index] = item;
  ht->count++;

  if (isDebug) {
    printf("Item inserted into %d position\nCurrent hash table amount - %d items\n", index, ht->count);
  }

  // check and resize hash table if necessary
  const int hash_table_load = ht->count * 100 / ht->size;
  if (hash_table_load > UP_LOAD_LIMIT) {
    ht_resize_up(ht, get_hash);

    if (isDebug) {
      printf("Hash table load is %d (limit - %d). Resize up hash table\n", hash_table_load, UP_LOAD_LIMIT);
    }
  }
}

/*
  Search string value by key in a hash table
*/
char* ht_search(ht_hash_table* ht, GetHashFn get_hash, const char* key, ...) {
  // START check for debug option
  va_list ap;
  va_start(ap, key);
  unsigned short isDebug = false;
  unsigned short debugParameter = va_arg(ap, short);
  if (debugParameter == true) isDebug = true;
  va_end(ap);
  // END check for debug option

  int index = get_hash(key, ht->size, 0);
  ht_item* item = ht->items[index];

  if (isDebug) {
    printf("Generated index: %d\n", index);
  }

  int attempt = 1;
  while (item != NULL) {
    if (item != &HT_DELETED_ITEM) {
      if (strcmp(key, item->key) == 0) {
        return item->value;
      }
    }
   
    index = get_hash(key, ht->size, attempt++);
    item = ht->items[index];

    if (isDebug) {
      printf("Attempt: %d. Item index already used! Generated a new one - %d\n", attempt, index);
    }
  } 

  return NULL;
}

/*
  Mark item as deleted and clean used memory for that
*/
void ht_delete(ht_hash_table* ht, GetHashFn get_hash, const char* key, ...) {
   // START check for debug option
  va_list ap;
  va_start(ap, key);
  unsigned short isDebug = false;
  unsigned short debugParameter = va_arg(ap, short);
  if (debugParameter == true) isDebug = true;
  va_end(ap);
  // END check for debug option

  short is_item_deleted = false; 
  int index = get_hash(key, ht->size, 0);
  ht_item* item = ht->items[index];

   if (isDebug) {
    printf("Generated index: %d\n", index);
  }

  int attempt = 1;
  while (item != NULL) {
    if (item != &HT_DELETED_ITEM) {
      if (strcmp(item->key, key) == 0) {
        ht_clear_item(item);
        ht->items[index] = &HT_DELETED_ITEM;
        is_item_deleted = true;
      }
    }
    index = get_hash(key, ht->size, attempt++);
    item = ht->items[index];

    if (isDebug) {
      printf("Attempt: %d. Item index already used! Generated a new one - %d\n", attempt, index);
    }
  }

  if (is_item_deleted) {
    ht->count--;
  }

  // check and resize table if necessary
  const int hash_table_load = ht->size * 100 / ht->count;
  if (hash_table_load < DOWN_LOAD_LIMIT) {
    ht_resize_down(ht, get_hash);

    if (isDebug) {
      printf("Hash table load is %d (limit - %d). Resize up hash table\n", hash_table_load, DOWN_LOAD_LIMIT);
    }
  }
}
