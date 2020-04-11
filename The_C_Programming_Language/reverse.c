#include <stdio.h>

#define MAX_LEN 80

void reverse(char str[], int length) {
	int middle = length / 2;
	int i = 0;

	while (i < middle) {
		int buffer = str[length - 1 - i];
		str[length - 1 - i] = str[i];
		str[i] = buffer;
		i++;
	}
}

int getLine(char s[]) {
	char ch;
	int i;

	for (i = 0; (ch = getchar()) != '\n'; i++) {
		s[i] = ch;
	}

	return i;
}

int main() {
	char string[MAX_LEN];

	printf("Input some string line\n");
	int input_length = getLine(string);

	reverse(string, input_length);
	printf("%s\n", string);

	return 0;
}
