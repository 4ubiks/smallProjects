#include "dictionary.h"
#include <stdio.h>
#include <string.h>

struct key_value{
	int key;
	char* value;
};

void test(struct hexvalues *h){
	printf("hi\n");
}

bool listMapInsert(struct hexvalues* hex, int decimals, const char* hexDigits){
	if (hex->count == listMapCapacity){
		return false;	
	}


	hex->kvPairs[hex->count].decimals = decimals;
	hex->kvPairs[hex->count].hexDigits = strdup(hexDigits);
	hex->count++;
	return true;
	
}
