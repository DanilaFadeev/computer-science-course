// Double hashing method
int ht_get_double_hash(const char* s, const int num_buckets, const int attempt);

// Linear probing method
int ht_get_linear_hash(const char* key, const int num_buckets, const int attempt);

// Quadratic probing method
int ht_get_quadratic_hash(const char* key, const int num_buckets, const int attempt);
