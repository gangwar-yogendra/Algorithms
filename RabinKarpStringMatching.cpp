/* 	Rabin Karp String Matching Algorithm
	String: S0S1S2S3S4S5S6SkSk+1....Sn, Pattern: S5S6SkSk+1
	Calculate the Hash Value of Pattern and then start from index 0 in given String and sift by
	one if Hash match then check each char of pattern and string
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PRIME_NUMBER 619

int hashFunction(char *str) {
	int value = 0;
	int hashValue=0;
	int m = strlen(str);
	
	for(int i = 0; i < strlen(str)-1; i++) {
		//value = value + (int)str[i];
		value = value + (int)str[i] * pow(10, m-i-1);
		
		// if m = 3 then its make as str[i] * x^2 + str[i+1] * x^1 + str[i+2] * x^0;  {where x = 10 }
	}
	
	hashValue = value % PRIME_NUMBER;
	
	return hashValue;
}

void substring(char *text, char *substr, int position, int len ) {
	int c = 0;
	
	while(c < len) {
		substr[c] = text[position + c - 1];
		c++;
	}
	substr[c] = '\0';
}

int search(char *text, char *pattern) {
	/* length of text string */
	int n = strlen(text);
	/* length of pattern */ 
	int m = strlen(pattern);
	
	int hashPattern = hashFunction(pattern);
	
	
	for(int i = 1; i <= n-m+1; i++) 
	{
		// Get the substring equal to pattern string length and sifting by 1 index using for loop
		char substr[m];
		substring(text, substr, i, m);
				
		// Get hash value of substring
		int hashsubstr = hashFunction(substr);
		
		// compare hash value of pattern and substring 
		if(hashsubstr == hashPattern)
		{
			for(int j = 0; j<m; j++) 
			{
				if(text[i+j-1] != pattern[j]) {
					break;
				}
				
				if(j == m-1) {
					std::cout<<"Pattern found at index: "<< i-1 <<std::endl;
				}
			}
		}
	}
}

int main(int argc, char **argv) 
{
	char text[] = "ababcdaddabbbcccadddd";
	char pattern[] = "dabbbc";
	
	//char text[] = "abbcca";
	//char pattern[] = "ca";
	
	search(text, pattern);
	
	return 0;
}