#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	printf("ascii: ");

	char str[1024];

	strcpy(str, "48454C4C4F");
	printf("original: %s", str);
	printf("\n");
	printf("\n");

	int length = strlen(str);

	if (length % 2 != 0){printf("invalid"); return 0;}
	char ascii;
	for (int i=0; str[i] != 0; i++){
		char new[3];

		new[0] = str[i];
		i++;
		new[1] = str[i];
		new[2] = '\0';
		//printf("%s\n", new);

		int dec = (int)strtol(new, NULL, 16);
		ascii = (char)dec;

		printf("%c", ascii);
	}
	printf("\n");
	return 0;
}
