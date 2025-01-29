#include <stdio.h>

int main() {
	unsigned char upper;
	unsigned char lower;


	for (int i=0; i < 256; i++){
		upper=(i >> 4);
		lower=(i&0x0f);
		
		if (upper < 10){
			upper+=48;
		}

		else {
			upper+=87;
		}

		if (lower < 10){
			lower +=48;
		}

		else {
			lower+=87;
		}
		
		putchar(upper);
		putchar(lower);
		printf(" ");
	}	
	printf("\n");
}
