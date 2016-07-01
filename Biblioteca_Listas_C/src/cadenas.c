#include <stdio.h>
#include <stdlib.h>


int length(char * un_string) {
	char * p = un_string;
	int cant = 1;
	while(p[cant] != '\0') {
		p++;
		cant++;
	}
	return cant;
}

char * s_reverse(char * un_string) {
	char * otra = malloc(sizeof(length(un_string) + 1));
	int j, i = length(un_string) -1;
	for(j = 0; j < length(un_string); j++) {
		otra[i] = un_string[j];
		i--;
	}
	otra[length(un_string) + 1] = '\0';
	return otra;
}
