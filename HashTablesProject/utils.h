// functions to colorise string input
#define colorise_red(string) printf("\033[0;31m%s\033[0m", string)
#define colorise_green(string) printf("\033[0;32m%s\033[0m", string)
#define colorise_yellow(string) printf("\033[0;33m%s\033[0m", string)
#define colorise_blue(string) printf("\033[0;34m%s\033[0m", string)

// boolean type values
#define true 1
#define false 0

// boolean data type
typedef unsigned short Boolean;

Boolean is_prime(const int number);

int next_prime(int x);

void print_timestamp();
