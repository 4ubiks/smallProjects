#include "stdio.h"

int main(){
	for (int i = 0x00; i <= 0xff; i++){
		char str[255];
		str[0] = i;
		printf("%02X",(unsigned char)str[0]);
		printf(" ");
	}

	return 0;
}
