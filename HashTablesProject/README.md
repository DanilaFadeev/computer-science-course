## About this project

This is a custom implementation of hash-tables data structure, using open addressing collision handling in pure C language.

Project is based on the tutorial [Write a hash table in C](https://github.com/jamesroutley/write-a-hash-table).

## Hash tables

In computing, a hash table (hash map) is a data structure that implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found.

Ideally, the hash function will assign each key to a unique bucket, but most hash table designs employ an imperfect hash function, which might cause hash collisions where the hash function generates the same index for more than one key. Such collisions are always accommodated in some way.

In a well-dimensioned hash table, the average cost (number of instructions) for each lookup is independent of the number of elements stored in the table. Many hash table designs also allow arbitrary insertions and deletions of key-value pairs, at (amortized) constant average cost per operation.

In many situations, hash tables turn out to be on average more efficient than search trees or any other table lookup structure. For this reason, they are widely used in many kinds of computer software, particularly for associative arrays, database indexing, caches, and sets.

![Hash Table Visualization](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7d/Hash_table_3_1_1_0_1_0_0_SP.svg/315px-Hash_table_3_1_1_0_1_0_0_SP.svg.png)

## To do

- [X] Implement the base hash table structure
- [X] Create command line interface for work with hash tables
- [X] Add Linear probing way to handle collisions
- [X] Add Quadratic probing way to handle collisions
- [X] Load amount of items from the file
- [X] Add debug for all the operations
- [X] Add pretty header
- [ ] Add sample file
- [ ] Readme pretty
- [X] Option input value validation
- [X] Possibility to select and change hash method (make it global)
- [X] CLI prettier
- [X] Add status bar
