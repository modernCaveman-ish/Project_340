#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

	char *string = "\n\n\none argument (not %d) expected in 'typeof\n\n\n";

	printf(string, 4);
	return 0;
}