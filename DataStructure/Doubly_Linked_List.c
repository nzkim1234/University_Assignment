/*
 * Doubly_Linked_List.c
 *
 *  Created on: 2019. 4. 30.
 *      Author: 김보윤
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
	char data[4];
	struct ListNode *llink;
	struct ListNode *rlink;
}listNode;

typedef struct{
	listNode *head;
}linkedList_h;

linkedList_h *createLinkedList_h(){
	linkedList_h *DL;
	DL=(linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head=NULL;
	return DL;
}

void insertNode(linkedList_h *DL, listNode *pre, char *x){
	listNode *newNode;
	newNode=(listNode *)malloc(sizeof(listNode));
	strcpy(newNode->data,x);

	if(DL->head==NULL){
		DL->head=newNode;
		newNode->llink=NULL;
		newNode->rlink=NULL;
	}
	else if(pre==NULL){
		newNode->rlink=DL->head;
		DL->head=newNode;
		newNode->llink=NULL;
		newNode->rlink->llink=newNode;
	}
	else{
		newNode->rlink=pre->rlink;
		pre->rlink=newNode;
		newNode->llink=pre;
		if(newNode->rlink!=NULL)
			newNode->rlink->llink=newNode;
	}
}

void deleteNode(linkedList_h *DL, listNode *old){
	if(DL->head==NULL)
		return ;
	else if(old==NULL)
		return ;
	else if(DL->head==old){
		DL->head=old->rlink;
		if(old->rlink!=NULL)
			old->rlink->llink=NULL;
		free(old);
	}
	else{
		old->llink->rlink=old->rlink;
		if(old->rlink!=NULL)
			old->rlink->llink=old->llink;
		free(old);
	}
}

void printList(linkedList_h *DL){
	listNode *temp;
	printf("DL=(");
	temp=DL->head;

	while(temp!= NULL){
		printf("%s",temp->data);
		temp=temp->rlink;
		if(temp!=NULL)
			printf(", ");
	}
	printf(") \n\n");
}

listNode *searchNode(linkedList_h *DL, char *x){
	listNode *temp;
	temp= DL->head;
	while(temp!= NULL){
		if(strcmp(temp->data,x)==0)
			return temp;

		temp=temp->rlink;
	}
	return temp;
}

int main(){
	linkedList_h *DL;
	listNode *p;
	DL= createLinkedList_h();
	printf("(1) 이중 연결 리스트 생성하기!\n");
	printList(DL);
	printf("(2) 이중 연결 리스트에 [월] 노드 삽입하기!\n");
	insertNode(DL,NULL,"월");
	printList(DL);
	printf("(3) 이중 연결 리스트의 제일 앞에 [목] 노드 삽입하기!\n");
	insertNode(DL,NULL,"목");
	printList(DL);
	printf("(4) 이중 연결 리스트의 [월] 노드 뒤에 [수] 삽입하기!\n");
	p=searchNode(DL,"월");
	insertNode(DL,p,"수");
	printList(DL);
	printf("(5) 이중 연결 리스트에서 [월] 노드 삭제하기!\n");
	deleteNode(DL,p);
	printList(DL);
	printf("(6) 이중 연결 리스트에서 [목] 노드 삭제하기!\n");
	p=searchNode(DL,"목");
	deleteNode(DL,p);
	printList(DL);

}

