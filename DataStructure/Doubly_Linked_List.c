/*
 * Doubly_Linked_List.c
 *
 *  Created on: 2019. 4. 30.
 *      Author: �躸��
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
	printf("(1) ���� ���� ����Ʈ �����ϱ�!\n");
	printList(DL);
	printf("(2) ���� ���� ����Ʈ�� [��] ��� �����ϱ�!\n");
	insertNode(DL,NULL,"��");
	printList(DL);
	printf("(3) ���� ���� ����Ʈ�� ���� �տ� [��] ��� �����ϱ�!\n");
	insertNode(DL,NULL,"��");
	printList(DL);
	printf("(4) ���� ���� ����Ʈ�� [��] ��� �ڿ� [��] �����ϱ�!\n");
	p=searchNode(DL,"��");
	insertNode(DL,p,"��");
	printList(DL);
	printf("(5) ���� ���� ����Ʈ���� [��] ��� �����ϱ�!\n");
	deleteNode(DL,p);
	printList(DL);
	printf("(6) ���� ���� ����Ʈ���� [��] ��� �����ϱ�!\n");
	p=searchNode(DL,"��");
	deleteNode(DL,p);
	printList(DL);

}

