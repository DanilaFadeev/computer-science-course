#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
  CHANGE_METHOD,
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

// define global hash table and hashing method
GetHashFn get_hash;
ht_hash_table* hash_table;

// ADD_ITEM
static void add_item() {
  char key[100], value[100];

  printf("Item key: ");
  scanf("%s", &key);

  printf("Item value: ");
  scanf("%s", &value);

  ht_upsert(hash_table, get_hash, key, value, is_debug_mode_enabled);
}

// SEARCH_ITEM
static void search_item() {
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
static void delete_item() {
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
static void read_file_data() {
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

// CHANGE_METHOD
static void change_method() {
  char input_str[20], selected_method[20];

  do {
    printf("1. Linear\n2. Quadratic\n3. Double\n");
    scanf("%s", &input_str);
  } while (strlen(input_str) != 1 || !isdigit(input_str[0])
    || (input_str[0] - '0') < 1 || (input_str[0] - '0') > 3);

  switch (input_str[0] - '0') {
    case 1:
      get_hash = ht_get_linear_hash;
      strcpy(selected_method, "Linear");
    case 2:
      get_hash = ht_get_quadratic_hash;
      strcpy(selected_method, "Quadratic");
    case 3:
      get_hash = ht_get_double_hash;    
      strcpy(selected_method, "Double");
  }

  ht_clear_hash_table(hash_table);
  hash_table = ht_new();
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
  printf("\u251b\n");
}

static void print_status_bar() {
  char current_hash_method[20] = "Linear";
  if (get_hash == ht_get_quadratic_hash) {
    strcpy(current_hash_method, "Quadratic");
  } else if (get_hash == ht_get_double_hash) {
     strcpy(current_hash_method, "Double");
  }

  printf("| Hash Table -");
  printf(" Size:\033[0;31m %d \033[0m,", hash_table->size);
  printf(" Items:\033[0;32m %d \033[0m,", hash_table->count);
  printf(" Load:\033[0;34m %d%% \033[0m", (hash_table->count * 100) / hash_table->size);
  printf(" | Hash probing method:\033[0;33m %s \033[0m|\n\n", current_hash_method);
}

// program main menu display with option selection
static void display_menu() {
  colorise_blue();
  printf("\u261E SELECT THE OPERATION (1-7):\n");

  colorise_green();
  printf("\
  \u2460  Add new item\n\
  \u2461  Search an item by key\n\
  \u2462  Delete an item by key\n\
  \u2463  %s debug mode\n\
  \u2464  Load data from file\n\
  \u2465  Change hash probing method\n\
  \u2466  Exit\n", is_debug_mode_enabled ? "Disable" : "Enable");
  colorise_reset();
}

// re-draw program screen with header and menu
static void update_screen() {
  clrscr();

  print_header();
  print_status_bar();
  display_menu();
}

// ask user for operation number input
static unsigned short get_operation() {
  char str_input[20];
  unsigned short isFailed = false;

  do {
    // show the error if failed on the previous iteration
    if (isFailed) { 
      colorise_red();
      printf("\nError: Incorrect input! Please, enter a single number from 1 to 6.");
      colorise_reset();
    }

    printf("\nYour choice (1-7): ");
    scanf("%s", &str_input);
    update_screen();

    isFailed = true;
  } while (strlen(str_input) != 1 || !isdigit(str_input[0]));

  return str_input[0] - '0';
}

/* main operation to start endless loop with main menu options */
void run_program_loop() {
  unsigned short selected_operation;

  get_hash = ht_get_linear_hash;
  hash_table = ht_new();

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
        add_item();
        break;
      case SEARCH_ITEM:
        colorise_yellow();
        printf("Searching an item on the hash table:\n");
        colorise_reset();
        search_item();
        break;
      case DELETE_ITEM:
        colorise_yellow();
        printf("Delete an item from the hash table:\n");
        colorise_reset();
        delete_item();
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
        read_file_data();
        break;
      case CHANGE_METHOD:
        colorise_yellow();
        printf("Change base hash probing method (hash table will be recreated):\n");
        colorise_reset();
        change_method();
        break;
      case EXIT:
        colorise_yellow();
        printf("Thanks for playing! Have a nice time!\n");
        colorise_reset();
        return;
      default:
        colorise_yellow();
        printf("Unknown operation!\n");
        colorise_reset();
        break;
      }
  }
}
