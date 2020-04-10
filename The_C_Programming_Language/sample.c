#include <stdio.h>

#define PI 3.14

short isSpaceChar(char ch) {
	return ch == ' ' || ch == '\t' || ch == '\n';
}

int main() {
	int symbols = 0, words = 0, lines = 0, ch;

	printf("Input some text and enter Ctrl+D to finish the input stream.\n");

	while((ch = getchar()) != EOF) {
		symbols++;

		if (isSpaceChar(ch)) {
			words++;
		}

		if (ch == '\n') {
			lines++;
		}
	}

	printf("Symbols: %d\nWords: %d\nLines: %d", symbols, words, lines);

	return 0;
}
