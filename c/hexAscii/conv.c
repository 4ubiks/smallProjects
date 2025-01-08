#include <stdio.h>
#include <string.h>

int main(){
	printf("ascii:");

	char str[1024];

	strcpy(str, "45 52 52 4f 52 3a");

	printf("%c\n", str[0]);

	for (int i=0; i < 1024; i++){
		char new[2];

		new[0] = str[i];
		new[1] = str[i+1];
		i++;

		printf("%s", new);
	}

	return 0;
}
