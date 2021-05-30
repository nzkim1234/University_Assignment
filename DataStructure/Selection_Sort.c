/*
 * 1.c
 *
 *  Created on: 2019. 3. 5.
 *      Author: ±èº¸À±
 */


#include <stdio.h>

void selectionSort(int a[], int n){
	int min, num, rem=0;
	for(int i=0; i<n; i++){
		min=a[i];
		for(int j=i+1; j<n; j++){
			if(min>a[j]){
				min=a[j];
				rem=j;
			}
		}
		num=a[i];
		a[i]=a[rem];
		a[rem]=num;
	}
}
int main(){
	int a[10]={1,10,34,2,7,95,100,745,3,56};
	selectionSort(a,10);
	for(int i=0; i<10; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
