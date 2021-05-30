/*
 * Circular_Linked_List.c
 *
 *  Created on: 2019. 4. 20.
 *      Author: �躸��
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
	printf("(1) ���� ���� ����Ʈ �����ϱ�!\n");
	printList(CL);
	printf("(2) ���� ���� ����Ʈ�� [��] ��� �����ϱ�!\n");
	insertFirstNode(CL,"��");
	printList(CL);
	printf("(3) ���� ���� ����Ʈ�� [��] ��� �ڿ�  [��] ��� �����ϱ�!\n");
	p=searchNode(CL,"��");
	insertMiddleNode(CL,p,"��");
	printList(CL);
	printf("(4) ���� ���� ����Ʈ�� [��] ��� �ڿ�  [��] ��� �����ϱ�!\n");
	p=searchNode(CL,"��");
	insertMiddleNode(CL,p,"��");
	printList(CL);
	printf("(5) ���� ���� ����Ʈ���� [��] ��� �����ϱ�!\n");
	pre=searchPreNode(CL,p);
	deleteNode(CL,pre);
	printList(CL);

}
