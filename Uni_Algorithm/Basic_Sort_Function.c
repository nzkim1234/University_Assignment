#include <stdio.h>


void selectionSort(int data[], int n){
	for(int i=0; i<n-1; i++){
		int num=i+1;
		int data_num=data[num];
		for(int j=i+1; j<n; j++){
			if(data_num>data[j]){
				data_num=data[j];
				num=j;
			}
		}
		if(data[i]>data[num]){
			int a=data[i];
			data[i]=data[num];
			data[num]=a;
		}
	}
	for(int k=0; k<n; k++){
		printf("%d ",data[k]);
	}
	printf("\n");
}

void bubbleSort(int data[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(data[i]>data[j]){
				int num=data[i];
				data[i]=data[j];
				data[j]=num;
			}
		}
	}
	for(int k=0; k<n; k++){
		printf("%d ",data[k]);
	}
	printf("\n");
}


void insertionSort(int data[], int n){
	int j,num;
	for(int i=1; i<n; i++){
		num=data[i];
		for(j=i-1; j>=0; j--){
			if(data[j]>num){
				data[j+1]=data[j];
			}
			else
				break;
		}
		data[j+1]=num;
	}
	for(int k=0; k<n; k++){
		printf("%d ",data[k]);
	}
	printf("\n");
}


int main(){
	int data[]={3,31,48,73,8,11,20,29,65,15};
	int data2[]={3,31,48,73,8,11,20,29,65,15};
	int data3[]={3,31,48,73,8,11,20,29,65,15};
	selectionSort(data,10);
	bubbleSort(data2,10);
	insertionSort(data3,10);
}
