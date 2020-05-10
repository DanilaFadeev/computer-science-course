#include <stdio.h>

#include "utils.h"
#include "hash_table.h"
#include "hashing_methods.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

enum OPERATIONS {
  ADD_ITEM = 1,
  SEARCH_ITEM,
  DELETE_ITEM,
  SWITCH_DEBUG,
  LOAD_DATA
};

// global debug mode flag
static unsigned int is_debug_mode_enabled = false;

// ADD_ITEM
static void add_item(ht_hash_table *hash_table, GetHashFn get_hash) {
  char key[100], value[100];

  printf("Item key: ");
  scanf("%s", &key);

  printf("Item value: ");
  scanf("%s", &value);

  ht_upsert(hash_table, get_hash, key, value, is_debug_mode_enabled);
}

// SEARCH_ITEM
static void search_item(ht_hash_table *hash_table, GetHashFn get_hash) {
  char key[100], *found;

  printf("Item searching key: ");
  scanf("%s", &key);

  GetHashFn get_hash1 = ht_get_linear_hash;
  found = ht_search(hash_table, get_hash1, key);

  if (found != NULL) {
    printf("Item '%s' was found. It's value - %s\n", key, found);
  } else {
    printf("Item '%s' wasn't found\n", key);
  }
}

// DELETE_ITEM
static void delete_item(ht_hash_table *hash_table, GetHashFn get_hash) {
  char key[100];

  printf("Item key to remove: ");
  scanf("%s", &key);

  ht_delete(hash_table, get_hash, key);
}

// SWITCH_DEBUG
static void switch_debug_mode() {
  is_debug_mode_enabled = (is_debug_mode_enabled == true) ? false : true;
}

// LOAD_DATA
static void read_file_data(ht_hash_table* hash_table, GetHashFn get_hash) {
  char *filename = "data.txt";
  FILE *fp;

  if ((fp = fopen(filename, "r")) == NULL) {
    perror("Error occured while opening file");
  }

  int count = 0;
  char key[100], value[100];
  while ((fscanf(fp, "%s %s\n", &key, &value)) != EOF) {
    ht_upsert(hash_table, get_hash, key, value);
    count++;
  }

  printf("%d items was loaded from data file.\n", count);
  fclose(fp);
}

// program header display
static void print_header() {
  printf("Hash Tables Project\n*** Template for now ***\n\n");
}

// program main menu display with option selection
static short display_menu() {
  printf("\u261E Select the operation:\n\
  \u2460  Add new item\n\
  \u2461  Search an item by key\n\
  \u2462  Delete an item by key\n\
  \u2463  %s debug mode\n\
  \u2464  Load data from file\n", is_debug_mode_enabled ? "Disable" : "Enable");

  // TODO add error handling
  short input; 
  scanf("%hd", &input);

  clrscr(); // clear screen

  return input;
}

/* main operation to start endless loop with main menu options */
void run_program_loop() {
  short selected_operation;

  GetHashFn get_hash = ht_get_linear_hash;
  ht_hash_table* hash_table = ht_new();

  // clear screen for program initial start
  clrscr();

  while (true) {
    print_header();
    selected_operation = display_menu();
    switch (selected_operation) {
      case ADD_ITEM:
        printf("Add new item:\n");
        add_item(hash_table, get_hash);
        break;
      case SEARCH_ITEM:
        printf("Search item:\n");
        search_item(hash_table, get_hash);
        break;
      case DELETE_ITEM:
        printf("Delete item:\n");
        delete_item(hash_table, get_hash);
        break;
      case SWITCH_DEBUG:
        switch_debug_mode();
        printf("Debug mode was %s\n", is_debug_mode_enabled ? "enabled" : "disabled");
      case LOAD_DATA:
        printf("Load data from file:\n");
        read_file_data(hash_table, get_hash);
        break;  
      default:
        printf("Unknown operation!");
        break;
      }
  }
}
