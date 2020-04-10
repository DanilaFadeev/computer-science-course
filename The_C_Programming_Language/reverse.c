#include <stdio.h>

#define MAX_LEN 80

char reverse(char str[], int length) {
	int middle = length / 2;
	int i = 0;
	while (i < middle) {
		int buffer = str[length - 1 - i];
        str[length - 1 - i] = str[i];
	    str[i] = buffer;
		i++;
	}
	return str[0];
}

int main() {
	char string[] = {'h', 'e', 'l', 'l', 'o'};
	printf("%c", reverse(string, 5));
	return 0;
}
