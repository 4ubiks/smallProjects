#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char str[1024];

	printf("hex: ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0'; 						// gets rid of "\n", if exists
	
	printf("original: %s", str);
	printf("\n");
	printf("\n");

	// get rid of spaces	
	int length = strlen(str);
	int j = 0;
	for (int i=0; i < length; i++){ 						// gets rid of spaces in hex
		if (str[i] != ' '){
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
	
	length = strlen(str);									// redeclare length, after fixes
	if (length % 2 != 0){printf("invalid"); return 0;} 		// quit if not even

	
	char ascii;
	for (int i=0; str[i] != 0; i++){
		char new[3];
		
		new[0] = str[i];
		i++;
		new[1] = str[i];
		new[2] = '\0';

		int dec = (int)strtol(new, NULL, 16);
		ascii = (char)dec;

		printf("%c", ascii);
	}
	printf("\n");
	return 0;
}
