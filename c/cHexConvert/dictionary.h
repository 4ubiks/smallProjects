#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stdbool.h>
#include <stdio.h>

enum {
	listMapCapacity = 16 
};


struct hexvalues{
	struct key_value kvPairs[listMapCapacity];
	size_t count;
};

void test(struct hexvalues *h);

bool listMapInsert(struct hexvalues* hex, int decimals, const char* hexDigit);
const char* listMapValueForKey(struct hexvalues* hex, int decimals);
struct hexvalues* newListMap();
void freeListMap(struct hexvalues* hex);

#endif
