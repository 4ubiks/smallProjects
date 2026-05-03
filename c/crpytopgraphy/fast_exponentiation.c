/****************************************************************************** 

                      Online C Compiler. 
           Code, Compile, Run and Debug C program online. 
 

Write your code in this editor and press "Run" button to compile and execute it. 

/author: Jack Harris /date: 21 April 2026 /course: CSCN463-001 
compilation method: `gcc -o fast fast_exponentiation.c`
*******************************************************************************/ 

#include <stdio.h> 

int main() {  
int a;  

printf("Enter a value for a (decimal): ");  

scanf("%d", &a); 

char binary_b[65]; 
int binary_length=0; 
int b=0; 
printf("Enter a value for b (binary limit 16 bits: "); 
scanf("%64s", binary_b); 
 
for (int bit = 0; binary_b[bit] != '\0'; bit++) { 

    if (binary_b[bit] != '0' && binary_b[bit] != '1'){ 
       printf("The value %c you entered is not in binary form. Please try again.", binary_b[bit]); 
       return 0; 
   } 
   b = b * 2 + (binary_b[bit] - '0'); 
   binary_length++; 
} 
 
int n=0; 
printf("Enter a value for n (decimal): "); 
scanf("%d", &n); 
 
 
int c_array[binary_length]; 
int f_array[binary_length]; 
 
// perform exponentiation 
int c=0; 
int base_a = a; 
int f_compute=1; 
for (int i=0; i<binary_length; i++){ 
   f_compute = (f_compute*f_compute)%n; 
   c *= 2; 
    
   if (binary_b[i] == '1'){ 
       c+=1; 
       f_compute = (f_compute*base_a)%n; 
   } 
    
   f_array[i] = f_compute; 
   c_array[i] = c; 
} 
 
printf("i     "); 
for (int bit=0; bit<binary_length; bit++){ 
   printf("%d    ", (binary_length-bit)-1); 
} 
 
printf("\nBi    "); 
for (int bit=0; bit<binary_length; bit++){ 
   printf("%c    ", binary_b[bit]); 
} 
 
printf("\nc     "); 
for (int bit=0; bit<binary_length; bit++){ 
   printf("%d    ", c_array[bit]); 
} 
 
printf("\nf     "); 
for (int bit=0; bit<binary_length; bit++){ 
   printf("%d    ", f_array[bit]); 
} 
 

} 
