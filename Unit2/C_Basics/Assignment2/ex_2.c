/*
 * ex_2.C
 *
 *  Created on: Jan 21, 2022
 *      Author: mohamed adel
 */
#include<stdio.h>
void main(){

	char c;
	printf("Enter an alphaebt:");
	fflush(stdout),fflush(stdin);
	scanf("%c",&c);
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
		printf("%c is a vowel",c);
	}
	else{
		printf("%c is a consonant",c);
	}



}
