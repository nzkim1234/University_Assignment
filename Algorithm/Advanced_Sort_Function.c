/*
 * test.c
 *
 *  Created on: 2019. 10. 11.
 *      Author: ±èº¸À±
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int A[], int p, int q, int r){
	int B[100000];
	int i=p;
	int j=q+1;
	int t=0;
	while(i<=q && j<=r){
		if(A[i]<=A[j])
			B[t++]=A[i++];
		else
			B[t++]=A[j++];
	}
	while(i<=q){
		B[t++]=A[i++];
	}
	while(j<=r){
		B[t++]=A[j++];
	}
	i=p;
	t=0;
	while(i<=r){
		A[i++]=B[t++];
	}
}

void mergeSort(int A[], int p, int r){
	if(p<r){
		int q=(p+r)/2;
		mergeSort(A,p,q);
		mergeSort(A,q+1,r);
		merge(A,p,q,r);
	}
}

int partition(int A[], int p, int r){
	int x=A[r];
	int i=p-1;
	int tmp;
	for(int j=p; j<=r-1; j++){
		if(A[j]<x){
			i++;
			tmp=A[i];
			A[i]=A[j];
			A[j]=tmp;
		}
	}
	tmp=A[i+1];
	A[i+1]=A[r];
	A[r]=tmp;
	return i+1;
}

void quickSort(int A[], int p, int r){
	if(p<r){
		int q=partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int main(){
	int mergeInput[100000],quickInput[100000];
	for(int i=0; i<10; i++){
		mergeInput[i]=quickInput[i]=rand();
	}
	mergeSort(mergeInput,0,9);
	quickSort(quickInput,0,9);
	printf("Merge Sort: ");
	for(int i=0; i<10; i++){
		printf("%d ",mergeInput[i]);
	}
	printf("\n");
	printf("Quick Sort: ");
	for(int i=0; i<10; i++){
		printf("%d ",quickInput[i]);
	}
	printf("\n");
	srand((unsigned)time(NULL));
	clock_t start,end,start2,end2;
	for(int k=0; k<5; k++){
	for(int i=0; i<100000; i++){
		mergeInput[i]=quickInput[i]=rand();
	}
	start=clock();
	mergeSort(mergeInput,0,99999);
	end=start2=clock();
	quickSort(quickInput,0,99999);
	end2=clock();
	printf("Merge Sort: %f QuickSort: %f\n",(double)(end-start)/CLOCKS_PER_SEC,(double)(end2-start2)/CLOCKS_PER_SEC);
	}
}
