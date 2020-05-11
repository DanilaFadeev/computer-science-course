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

// functions to colorise input
#define colorise_red() printf("\033[0;31m")
#define colorise_green() printf("\033[0;32m")
#define colorise_yellow() printf("\033[0;33m")
#define colorise_blue() printf("\033[0;34m")
#define colorise_reset() printf("\033[0m")

enum OPERATIONS {
  ADD_ITEM = 1,
  SEARCH_ITEM,
  DELETE_ITEM,
  SWITCH_DEBUG,
  LOAD_DATA,
  EXIT
};

// helper function to return the line of spaces
char* s(int number) {
  char *spaces = calloc(number, sizeof(char));
  for (int i = 0; i < number; i++) spaces[i] = ' ';
  return spaces;
}

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
  printf("\u250f");
  for (int i = 0; i < 50; i++)
    printf("\u2501");
  printf("\u2513\n");

  printf("\u2503%s\033[0;31m HASH\033[0;32m TABLES\033[0;33m PROJECT\033[0m%s\u2503\n", s(15), s(15));
  printf("\u2503%s\u2503\n", s(50));
  printf("\u2503 * Developed by Danila Demidovich 💻%s\u2503\n\u2503 * GitHub: @DanilaFadeev 💼%s\u2503\n", s(14), s(23));

  printf("\u2517");
  for (int i = 0; i < 50; i++)
    printf("\u2501");
  printf("\u251b\n\n");
}

// program main menu display with option selection
static void display_menu() {
  colorise_blue();
  printf("\u261E SELECT THE OPERATION (1-6):\n");

  colorise_green();
  printf("\
  \u2460  Add new item\n\
  \u2461  Search an item by key\n\
  \u2462  Delete an item by key\n\
  \u2463  %s debug mode\n\
  \u2464  Load data from file\n\
  \u2465  Exit\n", is_debug_mode_enabled ? "Disable" : "Enable");
  colorise_reset();
}

// re-draw program screen with header and menu
static void update_screen() {
  clrscr();
  print_header();
  display_menu();
}

// ask user for operation number input
static unsigned short get_operation() {
  short selected_operation; 
  printf("\nYour choice: ");
  scanf("%hd", &selected_operation);

  return selected_operation;
}

/* main operation to start endless loop with main menu options */
void run_program_loop() {
  unsigned short selected_operation; 

  GetHashFn get_hash = ht_get_linear_hash;
  ht_hash_table* hash_table = ht_new();

  update_screen();

  while (true) {
    selected_operation = get_operation();
    update_screen();

    colorise_blue();
    printf("\nYour choice: %d\n\n", selected_operation);
    colorise_reset();

    switch (selected_operation) {
      case ADD_ITEM:
        colorise_yellow();
        printf("Adding new item to hash table\n");
        colorise_reset();
        add_item(hash_table, get_hash);
        break;
      case SEARCH_ITEM:
        colorise_yellow();
        printf("Searching an item on the hash table:\n");
        colorise_reset();
        search_item(hash_table, get_hash);
        break;
      case DELETE_ITEM:
        colorise_yellow();
        printf("Delete an item from the hash table:\n");
        colorise_reset();
        delete_item(hash_table, get_hash);
        break;
      case SWITCH_DEBUG:
        switch_debug_mode();
        colorise_yellow();
        printf("Debug mode was %s.\n", is_debug_mode_enabled ? "enabled" : "disabled");
        colorise_reset();
        break;
      case LOAD_DATA:
        colorise_yellow();
        printf("Loading some hash table from the data file:\n");
        colorise_reset();
        read_file_data(hash_table, get_hash);
        break;  
      case EXIT:
        colorise_yellow();
        printf("Thanks for playing! Have a nice time!\n");
        colorise_reset();
        return;
      default:
        printf("Unknown operation!");
        break;
      }
  }
}
