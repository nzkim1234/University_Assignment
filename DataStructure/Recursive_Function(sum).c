/*
 * 1.c
 *
 *  Created on: 2019. 3. 5.
 *      Author: ±èº¸À±
 */


#include <stdio.h>

int sum(int n) {
	if(n==1)
		return 1;
	else
		return n+sum(n-1);
}

int main() {
	printf("%d\n",sum(1000));
}
