/*
 * 10.c
 *
 *  Created on: 2019. 5. 22.
 *      Author: IoT-30
 */


#include<stdio.h>
#include<stdlib.h>

typedef char element;

typedef struct DQNode{
	element data;
	struct DQNode *llink;
	struct DQNode *rlink;
}DQNode;

typedef struct{
	DQNode *front, *rear;
}DQueType;

DQueType*createDQue(){
	DQueType *DQ;
	DQ= (DQueType*)malloc(sizeof(DQueType));
	DQ->front=NULL;
	DQ->rear=NULL;
	return DQ;
}


void insertRear(DQueType *DQ, element item){
	DQNode *newNode=(DQNode*)malloc(sizeof(DQNode));
	newNode->data=item;
	if(DQ->rear==NULL){
		DQ->front=newNode;
		DQ->rear=newNode;
		newNode->rlink=NULL;
		newNode->llink=NULL;
	}
	else{
		DQ->rear->rlink=newNode;
		newNode->rlink=NULL;
		newNode->llink=DQ->rear;
		DQ->rear=newNode;
	}
}

int isEmpty(DQueType*DQ){
	if(DQ->front==NULL)
		return 1;
	else
		return 0;
}


element deleteFront(DQueType *DQ)  {
	DQNode *old=DQ->front;
	element item;
	if(isEmpty(DQ))
		return 0;
	else{
		item=old->data;
		if(DQ->front->rlink==NULL){
			DQ->front=NULL;
			DQ->rear=NULL;
		}
		else{
			DQ->front=DQ->front->rlink;
			DQ->front->llink=NULL;
		}
		free(old);
		return item;
	}
}

element deleteRear(DQueType *DQ)  {
	DQNode *old=DQ->rear;
	element item;
	if(isEmpty(DQ))
		return 0;
	else{  item=old->data;
	if(DQ->rear->llink==NULL){
		DQ->front=NULL;
		DQ->rear=NULL;
	}
	else{
		DQ->rear=DQ->rear->llink;
		DQ->rear->rlink=NULL;
	}
	free(old);
	return item;  }
}

int checkPalindrome(DQueType *DQ, char str[]){
	int i=0;
	while(str[i]!='\0'){
		insertRear(DQ,str[i]);
		i++;
	}
	if((i)%2==0){
		while(!isEmpty(DQ)){
			if(deleteFront(DQ)!=deleteRear(DQ))
				return 0;
		}
	}
	else{
		for(int j=0; j<(i)/2; j++){
			if(deleteFront(DQ)!=deleteRear(DQ))
				return 0;
		}
		while(!isEmpty(DQ))
			deleteRear(DQ);
	}
	return 1;
}



int main(){
	DQueType *DQ1= createDQue();
	char str[100];
	int ret;

	while(1){
		printf("문자열을 입력하세요!");
		fflush(stdout);
		scanf("%s",str);
		ret=checkPalindrome(DQ1,str);
		if(ret==1)
			printf("회문입니다\n");
		else{
			printf("회문이 아닙니다!\n");
			while(!isEmpty(DQ1)){
				deleteRear(DQ1);
			}
		}
	}
}
