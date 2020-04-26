#include <stdio.h>

static char days_table[2][12] = {
  {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31},
  {31, 29, 31, 30, 31, 30, 31, 30, 31, 30, 31},
};

char *get_month_name(unsigned int index) {
  static char *months[] = {"January", "February", "March", "April", "May", "June",
   "July", "August", "September", "October", "November", "December"};

  return (index > 11) ? months[0] : months[index]; 
}

void month_day(int year, int days, int *month, int *month_day) {
  short leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  unsigned int month_index = 0;
  
  if (days < 0 || days > (365 + leap)) {
    return;
  }

  while (days_table[leap][month_index] < days) {
    days -= days_table[leap][month_index];
    month_index++;
  }

  *month = month_index + 1;
  *month_day = days;
}

int main() {
  unsigned int month, day;

  month_day(2000, 60, &month, &day);
  printf("Month - %s, Day - %d", get_month_name(month - 1), day);

  return 0;
}