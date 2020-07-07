#define BUFSIZE 1024

// analog of the standart getch function
int getch() {
  char c;
  // read one char from stdin (1) and return
  return read(0, &c, 1) == 1 ? (unsigned char) c : '\0';
}

int getch_buf() {
  static char buf[BUFSIZE]; // be saved around function calls
  static char* bufpt;
  static int n = 0;

  if (n == 0) {
    read(0, &buf, BUFSIZE); // read a as much data as we can
    n = BUFSIZE;
    bufpt = buf;
  }

  return (--n > 0) ? (unsigned char) *bufpt++ : '\0'; // return symbol by symbol
}

int main(int argc, char* argv[]) {
  char ch;

  while ((ch = getch()) != '\n') {
    printf("%c", ch);
  }

  while ((ch = getch_buf()) != '\n') {
    printf("%c", ch);
  }

  return 0;
}
