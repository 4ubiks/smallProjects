#include "stdio.h"
#include "stdlib.h"

char* castLowerChar(unsigned char bitToCast, int bitsToPermute);
char* castUpperChar(unsigned char bitToCast, int bitsToPermute);
char* castWholeChar(unsigned char bitToCast, int bitsToPermute);
unsigned char exhibitA(unsigned char message);
char* exhibitD(char* right_o);
char* exhibitE(char* key_p);
char* exhibitG(char* sipher_p);
char* xor_rightop_key1(char* right_o, char* key_1);
char* xor_sipherpp_left_o(char* right_o, char* key_1);
char* final_permutation(char* lr_1);

char* rotate_sipher(char* sipher);

char* rotateKey(char* key, int round);

unsigned char backToByte(char* lr_1);

int main(){
	// variables
	int userRound=0;
	printf("Rounds (DEC):");
	scanf("%d", &userRound);
	printf("Rounds: %d\n", userRound);
	unsigned char message=0x57;
	unsigned char left_o=0;
	unsigned char right_o=0;
	unsigned char lr_o=0;

	char* left_ooh = malloc(5);
	char* right_ooh = malloc(5);
	char *key_cast = malloc(9);

	unsigned char key=0xac;

	char* right_op=0;
	char* key_p=0;

	char* key_1=0;
	char* sipher=0;

	char* sipher_p=0;
	char* sipher_pp=0;

	char* right_1=0;
	char* left_1=0;

	char* lr_1=malloc(9);
	char* final=malloc(9);

	// initial permutation
	for (int rounds=1; rounds<=userRound; rounds++){
		printf("\n\n==========NEW ROUND============\n\n");
		printf("Initial (x): %x\n", message);
		printf("Initial key (x): %x\n", key);
		printf("Rounds: %d\n", userRound);
		printf("Initial (b): %b\n", message);
		lr_o = exhibitA(message);
		printf("Permutated message: %b\n", lr_o);

		left_o = lr_o & 0xf0;
		right_o |= (lr_o & 0x0f);

		left_ooh = castUpperChar(left_o, 8);
		printf("left_o: %s\n", left_ooh);

		right_ooh = castLowerChar(right_o, 8);
		printf("right_o: %s\n", right_ooh);

		
		// expanded permutation on right_o with ExhibitD
		right_op = exhibitD(right_ooh);
		printf("======================\n\n");
		
	 	
		// last bit off of key
		printf("Initial key: %b\n", key);

		if (rounds == 1){
			key_cast = castWholeChar(key, 8);
		}
		else{
			key_cast = key_p;
		}
		printf("Casted key: %s\n", key_cast);

		key_cast[7] = '\0';
		printf("Stripped Bit key: %s\n", key_cast);

		// Rotate key_o, set to key_p
		printf("Rotate key_o and set key_p\n");
		printf("Round: %d\n", rounds);
		key_p = rotateKey(key_cast, rounds);
		printf("Rotated key: %s\n", key_p);
		printf("======================\n\n");


		// Perform contradiction permutation on key_p with ExhibitE, set to key_1
		printf("Contradiction permutation on key_p with ExhibitE, set key_1\n");
		key_1 = exhibitE(key_cast);
		printf("Contraction Permutation key: %s\n", key_1);
		printf("======================\n\n");


		// XOR on right_op and key_1, set to sipher
		printf("XOR on right_op and key_1, set to sipher_1\n");
		sipher = xor_rightop_key1(right_op, key_1);
		printf("Sipher_1: %s\n\n", sipher);

		// produce sipher_p
		printf("Produce sipher_p\n");
		sipher_p = rotate_sipher(sipher);
		printf("Rotated sipher: %s\n", sipher_p);
		printf("======================\n\n");


		// use ExhibitG to get sipher_pp
		printf("Use exhibitG to get sipher_pp\n");
		char* sipher_p_4x4 = malloc(5);
		for (int i=0; i<4; i++){
			sipher_p_4x4[i] = sipher_p[i];
		}
		sipher_pp = exhibitG(sipher_p_4x4);
		printf("Sipher_PP: %s\n", sipher_pp);
		printf("======================\n\n");

		// sipher_pp XOR left_o to get right_1
		printf("XOR on sipher_pp and left_o to get right_1\n");
		right_1 = xor_sipherpp_left_o(sipher_pp, left_ooh);
		printf("right_1: %s\n", right_1);

		// left_1 = right_o
		printf("\nSet left_1 to right_o\n");
		left_1 = right_ooh;
		printf("left_1: %s\n", left_1);

		// now we have lr_1
		printf("Establish lr_1\n");
		for (int i=0; i<4; i++){
			lr_1[i] = left_1[i];
		}
		for (int j=4; j<8; j++){
			lr_1[j] = right_1[j-4];
		}

		lr_1[8] = '\0';

		printf("\nLR_1 after round 1: %s\n", lr_1);
		message = backToByte(lr_1);
	}
	final = final_permutation(lr_1);
	printf("Final: %s\n", final);
	
	unsigned char final_real;
	final_real = backToByte(final);
	printf("FINAL: %x\n", final_real);
	
}

char* castLowerChar(unsigned char bitToCast, int bitsToPermute){
	char* stringToReturn = malloc(5);
	for (int i = bitsToPermute-5; i >= 0; i--) {
	    stringToReturn[3 - i] = ((bitToCast >> i) & 1) ? '1' : '0';
	}

	stringToReturn[4] = '\0';

	return stringToReturn;
}

char* castUpperChar(unsigned char bitToCast, int bitsToPermute){
	char* stringToReturn = malloc(5);
	for (int i = bitsToPermute-1; i >= 4; i--) {
	    stringToReturn[7 - i] = ((bitToCast >> i) & 1) ? '1' : '0';
	}

	stringToReturn[4] = '\0';

	return stringToReturn;
}


char* castWholeChar(unsigned char bitToCast, int bitsToPermute){
	char* stringToReturn = malloc(9);
	for (int i=bitsToPermute-1; i>=0; i--){
		stringToReturn[7-i] = ((bitToCast >> i) & 1) ? '1' : '0';
	}

	stringToReturn[8] = '\0';

	return stringToReturn;
}

unsigned char exhibitA(unsigned char message){
	unsigned char lr=0;
	unsigned char tmpBit=0;

	// message[0] -> lr[3]
	tmpBit = (message >> 0) & 1;
	lr &= ~(1 << 3);
	lr |= (tmpBit << 3);
	//printf("The 3rd bit of %d is %x\n", lr, tmpBit);

	// message[1] -> lr[5]
	tmpBit = (message >> 1) & 1;
	lr &= ~(1 << 5);
	lr |= (tmpBit << 5);
	//printf("The 5th bit of %d is %x\n", lr, tmpBit);

	// message[2] -> lr[1]
	tmpBit = (message >> 2) & 1;
	lr &= ~(1 << 1);
	lr |= (tmpBit << 1);
	//printf("The 1st bit of %d is %x\n", lr, tmpBit);

	// message[3] -> lr[6]
	tmpBit = (message >> 3) & 1;
	lr &= ~(1 << 6);
	lr |= (tmpBit << 6);
	//printf("The 6th bit of %d is %x\n", lr, tmpBit);

	// message[4] -> lr[7]
	tmpBit = (message >> 4) & 1;
	lr &= ~(1 << 7);
	lr |= (tmpBit << 7);
	//printf("The 7th bit of %d is %x\n", lr, tmpBit);

	// message[5] -> lr[0]
	tmpBit = (message >> 5) & 1;
	lr &= ~(1 << 0);
	lr |= (tmpBit << 0);
	//printf("The 0th bit of %d is %x\n", lr, tmpBit);

	// message[6] -> lr[2]
	tmpBit = (message >> 6) & 1;
	lr &= ~(1 << 2);
	lr |= (tmpBit << 2);
	//printf("The 2nd bit of %d is %x\n", lr, tmpBit);

	// message[7] -> lr[4]
	tmpBit = (message >> 7) & 1;
	lr &= ~(1 << 4);
	lr |= (tmpBit << 4);
	//printf("The 4th bit of %d is %x\n", lr, tmpBit);

	return lr;
}

char* exhibitD(char* right_o){
	char* right_op=malloc(9);
	char tmpBit;

	printf("right_o (b): %s\n", right_o);
	
	// right[3] -> right_op[4]
	tmpBit = right_o[0] + '\0';
	printf("%c goes to position 4\n", tmpBit);
	right_op[4] = tmpBit;

	// right[2] -> right_op[1], right_op[3]
	tmpBit = right_o[1];
	printf("%c goes to position 1 and 3\n", tmpBit);
	right_op[1] = tmpBit;
	right_op[3] = tmpBit;

	// right[1] -> right_op[0]
	tmpBit = right_o[2];
	printf("%c goes to position 0\n", tmpBit);
	right_op[0] = tmpBit;

	// right[0] -> right_op[2], right_op[5]
	tmpBit = right_o[3];
	printf("%c goes to position 2 and 5\n", tmpBit);
	right_op[2] = tmpBit;
	right_op[5] = tmpBit;

	printf("Turned right_op into %s\n", right_op);

	return right_op;
}

char* rotateKey(char* key, int round){
	char* rotatedKey = malloc(8);
	int rotationKey = ((round*2)-1)%4;

	switch (rotationKey){
		case 1:
			rotatedKey[2] = key[0];
			rotatedKey[0] = key[1];
			rotatedKey[1] = key[2];
		
			rotatedKey[6] = key[3];
			rotatedKey[3] = key[4];
			rotatedKey[4] = key[5];
			rotatedKey[5] = key[6];
			break;
		case 3:
			for (int i=0; i<7; i++){
				rotatedKey[i] = key[i];
			}
			break;
		default:
			break;
	}

	return rotatedKey;
}

char* exhibitE(char* key_p){
	char* key_1 = malloc(7);
	// key[0] -> k1[4]
	key_1[4] = key_p[0];
	
	// key[1] -> k1[5]
	key_1[5] = key_p[1];
	
	// key[2] -> the infinite abyss

	// key[3] -> k1[2]
	key_1[2] = key_p[3];

	// key[4] -> k1[1]
	key_1[1] = key_p[4];

	// key[5] -> k1[3]
	key_1[3] = key_p[5];

	// key[6] -> k1[0]
	key_1[0] = key_p[6];

	return key_1;
}

char* exhibitG(char* sipher_p){
	char* sipher_pp = malloc(5);
	printf("TEST: %s\n", sipher_p);
	
	sipher_pp[1] = sipher_p[0];
	sipher_pp[3] = sipher_p[1];
	sipher_pp[0] = sipher_p[2];
	sipher_pp[2] = sipher_p[3];

	return sipher_pp;
}

char* xor_rightop_key1(char* right_op, char* key_1){
	char* sipher_1 = malloc(7);
	for (int i=0; i<6; i++){
		sipher_1[i] = ((right_op[i]-'0') ^ (key_1[i]-'0'))+'0';
	}

	sipher_1[6] = '\0';
		
	return sipher_1;
}

char* xor_sipherpp_left_o(char* sipher_pp, char* left_o){
	char* right_1 = malloc(5);
	for (int i=0; i<4; i++){
		right_1[i] = ((sipher_pp[i]-'0') ^ (left_o[i]-'0'))+'0';
	}
	right_1[4] = '\0';

	return right_1;
}

char* rotate_sipher(char* sipher){
	char* sipher_p = malloc(7);

	sipher_p[0] = sipher[1];
	sipher_p[1] = sipher[2];
	sipher_p[2] = sipher[3];
	sipher_p[3] = sipher[4];
	sipher_p[4] = sipher[5];
	sipher_p[5] = sipher[0];

	sipher_p[6] = '\0';

	return sipher_p;
}

unsigned char backToByte(char* lr_1){
	unsigned char encryptedMessage=0;

	for (int i=0; i<8; i++){
		encryptedMessage <<= 1;

		if (lr_1[i] == '1'){
			encryptedMessage |= 1;
		}
	}

	printf("BYTE: %b\n", encryptedMessage);
	printf("HEX: %x\n", encryptedMessage);

	return encryptedMessage;
}

char* final_permutation(char* lr_1){
	char* final_c = malloc(9);

	final_c[5] = lr_1[0];
	final_c[2] = lr_1[1];
	final_c[6] = lr_1[2];
	final_c[0] = lr_1[3];
	final_c[7] = lr_1[4];
	final_c[1] = lr_1[5];
	final_c[3] = lr_1[6];
	final_c[4] = lr_1[7];

	final_c[8] = '\0';

	printf("Final c: %s\n", final_c);

	return final_c;
}
