#include "header.h"

char *mx_strnew(const int size) {
	char *c = malloc(size + 1);

	if (c != NULL && size > 0) {
		for (int i = 0; i < size + 1; i++) {
			c[i] = '\0';
		}
		return c;
	}
	return NULL;
}
