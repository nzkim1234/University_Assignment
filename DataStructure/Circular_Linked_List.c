/*
 * Circular_Linked_List.c
 *
 *  Created on: 2019. 4. 20.
 *      Author: 김보윤
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
	char data[4];
	struct ListNode* link;
}listNode;

typedef struct{
	listNode *head;
}linkedList_h;

linkedList_h *createLinkedList_h(){
	linkedList_h *CL;
	CL=(linkedList_h*)malloc(sizeof(linkedList_h));
	CL->head=NULL;
	return CL;
}

void insertFirstNode(linkedList_h *CL, char *x){
	listNode *newNode, *temp;
	newNode=(listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data,x);
	if(CL->head==NULL){
		CL->head=newNode;
		newNode->link=newNode;
	}
	else{
		temp=CL->head;
		while(temp->link!=CL->head)
			temp=temp->link;
		newNode->link=temp->link;
		temp->link=newNode;
		CL->head=newNode;
	}
}

void insertMiddleNode(linkedList_h *CL, listNode *pre, char *x){
	listNode *newNode, *temp;
	newNode=(listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data,x);
	if(CL->head==NULL){
		CL->head=newNode;
		newNode->link=newNode;
	}
	else if(pre==NULL){
		temp =CL->head;
		while(temp->link != CL->head)
			temp=temp->link;
		newNode->link=temp->link;
		temp->link=newNode;
		CL->head=newNode;
	}
	else{
		newNode->link=pre->link;
		pre->link=newNode;
	}
}

void deleteNode(linkedList_h *CL, listNode *pre){
	listNode *old;
	if(CL->head==NULL) return ;
	else if (pre==NULL) return ;
	else{
		old=pre->link;
		pre->link=old->link;
		if(old == CL->head)
			CL->head= old->link;
		free(old);
	}
}

void printList(linkedList_h *CL){
	listNode *p;
	printf("CL =(");
	p=CL->head;
	if(p!=NULL){
		do{
			printf("%s",p->data);
			p=p->link;
			if(p!=CL->head) printf(", ");
		}while(p!=CL->head);
	}
	printf(")\n");
}

listNode *searchNode(linkedList_h *CL, char *x){
	listNode *temp;
	if(CL->head==NULL){
		return NULL;
	}
	else{
		temp=CL->head;
		do{
			if(strcmp(temp->data,x)==0)
				return temp;
			temp=temp->link;
		}while(temp!=CL->head);
		return NULL;
	}
}

listNode *searchPreNode(linkedList_h *CL, listNode *p){
	listNode *temp, *pre;
	if(CL->head==NULL)
		return NULL;
	else{
		temp=CL->head;
		pre=NULL;
		do{
			if(temp==p)
				return pre;
			pre=temp;
			temp=temp->link;
		}while(temp!= CL->head);
		return NULL;
	}
}

int main(){
	linkedList_h* CL;
	listNode *p, *pre;
	CL=createLinkedList_h();
	printf("(1) 원형 연결 리스트 생성하기!\n");
	printList(CL);
	printf("(2) 원형 연결 리스트에 [월] 노드 삽입하기!\n");
	insertFirstNode(CL,"월");
	printList(CL);
	printf("(3) 원형 연결 리스트에 [월] 노드 뒤에  [수] 노드 삽입하기!\n");
	p=searchNode(CL,"월");
	insertMiddleNode(CL,p,"수");
	printList(CL);
	printf("(4) 원형 연결 리스트에 [수] 노드 뒤에  [금] 노드 삽입하기!\n");
	p=searchNode(CL,"수");
	insertMiddleNode(CL,p,"금");
	printList(CL);
	printf("(5) 원형 연결 리스트에서 [수] 노드 삭제하기!\n");
	pre=searchPreNode(CL,p);
	deleteNode(CL,pre);
	printList(CL);

}
