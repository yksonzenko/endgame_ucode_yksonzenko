#include "header.h"


char **mx_file_to_arr(const char *filename) {
	int file;
	char buffer[57];

	file = open(filename, O_RDONLY);
		char **string = malloc(sizeof(char*) * 31);
		for (int i = 0; i < 31; i ++) {
			string[i] = mx_strnew(57);
			read(file, buffer, 57);
			mx_strcpy(string[i], buffer);
		}
		string[31] = NULL;
	free(*string);
	close(file);
	return string;
}
