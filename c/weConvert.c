#include <stdio.h>

int main() {
	unsigned char upper;
	unsigned char lower;


	for (int i=0; i < 256; i++){
		upper=(i >> 4);
		lower=(i&0x0f);
		if (upper > 10 && upper < 16){
			upper+=87;
		}

		else if (upper > 0 && upper < 10){
			upper+=48;
		}

		if (lower > 10 && lower < 16){
			lower +=87;
		}

		else if (lower > 0 && lower < 10){
			lower+=48;
		}
		
		putchar(upper);
		putchar(lower);
		printf(" ");
	}	
}
