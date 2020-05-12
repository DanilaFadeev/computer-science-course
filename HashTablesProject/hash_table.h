// hash table item
typedef struct {
  char* key;
  char* value;
} ht_item;

// hash table
typedef struct {
  /* max items capacity */
  int size;

  int base_size;

  /* the total count of existing items */
  int count;

  /* array of items */
  ht_item** items;
} ht_hash_table;

typedef int (*GetHashFn)(const char* key, const int buckets_num, const int attempts);

ht_hash_table* ht_new();

ht_hash_table* ht_new_sized(const int base_size);

void ht_clear_hash_table(ht_hash_table* hash_table);

void ht_upsert(ht_hash_table* ht, GetHashFn get_hash, const char* key, const char* value, ...);

char* ht_search(ht_hash_table* ht, GetHashFn get_hash, const char* key, ...);

void ht_delete(ht_hash_table* h, GetHashFn get_hash, const char* key, ...);
