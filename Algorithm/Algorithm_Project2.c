#include <stdio.h>
#pragma warning(disable:4996)
int N=0;
int cost = 0;

void merge(int a[], int p, int q, int r) {
	int B[10000];
	int first = p;
	int mid = q+1;
	int last = r;
	int n = 0;
	while (first <= q && mid <= r) {
		if (a[first] <= a[mid])
			B[n++] = a[first++];
		else
			B[n++] = a[mid++];
	}
	while(mid<=r)
			B[n++] = a[mid++];
	while (first <= q)
			B[n++] = a[first++];
	n = 0;
	for (int i = p; i <= r; i++) {
		a[i] = B[n++];
	}
}

void mergeSort(int a[], int p, int r) {
	if (p < r) {
		int i = (p+r) / 2;
		mergeSort(a, p, i);
		mergeSort(a, i + 1, r);
		merge(a, p, i, r);
	}
}

void makeGroup(int a[],int N) {
	cost = 0;

	int i = N-1;
	while(i>=0) {
		int group[3] = { 0,0,0 };
		for (int j = 0; j < 3; j++) {
			if (i >= 0) {
				group[j] = a[i--];
			}
		}
		int min = group[0];
		int min_index = 0;
		for (int k = 1; k < 3; k++) {
			if (min > group[k]) {
				min = group[k];
				min_index = k;
			}
		}
		group[min_index] = 0;
		cost = cost + group[0] + group[1] + group[2];
	}
}

int main() {
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		int *A = (int*)malloc(sizeof(int)*N);
		for (int j = 0; j < N; j++) { 
			scanf("%d", &A[j]);
		}
		mergeSort(A, 0, N-1);
		makeGroup(A,N);
		printf("%d\n", cost);
		free(A);
	}

}