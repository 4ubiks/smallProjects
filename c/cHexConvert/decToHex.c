#include <stdio.h>
#include <string.h>

// headers
#include "dictionary.h"

;
int main(){
    int initial = 0;
    int rem = 1;

	struct hexvalues h;

	test(&h);

	char hex[12];
	printf("%s", hex);
    
    scanf("%d", &initial);

    int dec = initial;
	
	while (rem != 0){
		rem = dec % 16;
		printf("%d", rem);
		putchar('\n');
		dec = dec / 16;
	}


	printf("your value in hex is");
	printf("%s", hex);
	
	

	putchar('\n');
    return 0;
}
