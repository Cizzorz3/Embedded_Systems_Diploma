/*
 * ex_1.c
 *
 *  Created on: Jan 21, 2022
 *      Author: midoe
 */


#include <stdio.h>

void main(){
	int x;
	printf("Enter an integer you want to check: ");
	fflush(stdin),fflush(stdout);
	scanf("%d",&x);
	if(x%2==0){
		printf("%d is even \n",x);
	}
	else{
		printf("%d is odd \n",x);
	}





}
