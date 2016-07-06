#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * s_reverse(char * un_string) {
	char * str_aux = malloc(sizeof(strlen(un_string) + 1));
	int j, i = strlen(un_string) -1;
	for(j = 0 ; j < strlen(un_string) ; j++) {
		str_aux[i] = un_string[j];
		i--;
	}
	str_aux[j] = '\0';
	return str_aux;
}
