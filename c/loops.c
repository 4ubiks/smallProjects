#include "stdio.h"

int main(){
	for (int i = 0x00; i < 256; i++){
		printf("%x", i);
		printf(" ");
	}

	return 0;
}
