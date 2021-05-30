/*
 * Singly_Linked_List(Deletion_Search).c
 *
 *  Created on: 2019. 4. 16.
 *      Author: 김보윤
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
	char data[4];
	struct ListNode* link;
}listNode;

typedef struct {
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(void){
	linkedList_h* L;
	L=(linkedList_h*)malloc(sizeof(linkedList_h));
	L->head=NULL;
	return L;
}

void freeLinkedList_h(linkedList_h *L){
	listNode* p;
	while(L->head != NULL){
		p=L->head;
		L->head=L->head->link;
		free(p);
		p=NULL;
	}
}

void printList(linkedList_h* L){
	listNode* p;
	printf("L=(");
	p=L->head;
	while(p!=NULL){
		printf("%s", p->data);
		p=p->link;
		if(p!=NULL) printf(", ");
	}
	printf(")\n");
}

void insertFirstNode(linkedList_h *L, char *x){
	listNode *newNode;
	newNode=(listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data,x);
	newNode->link=L->head;
	L->head=newNode;
}

void insertMiddleNode(linkedList_h *L, listNode *pre, char *x){
	listNode *newNode;
	newNode=(listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data,x);
	if(L->head==NULL){
		newNode->link=NULL;
		L->head=newNode;
	}
	else if(pre==NULL){
		newNode->link=L->head;
		L->head=newNode;
	}
	else{
		newNode->link=pre->link;
	pre->link=newNode;
	}
}

void insertLastNode(linkedList_h* L, char* x){
	listNode* newNode;
	listNode* temp;
	newNode=(listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data,x);
	newNode->link=NULL;
	if(L->head==NULL){
		L->head=newNode;
		return;
	}
	temp=L->head;
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=newNode;
}

void deleteFirstNode(linkedList_h* L){
	listNode *old;
	if(L->head==NULL)
		return ;
	old =L->head;
	L->head=old->link;
	free(old);
}
void deleteNode(linkedList_h* L, listNode* pre){
	listNode* old;
	if(L->head==NULL)
		return;
	if(pre==NULL)
		return;
	old=pre->link;
	pre->link=old->link;
	free(old);
}
listNode* searchNode(linkedList_h* L, char* x){
	listNode *temp;
	temp=L->head;
	while(temp!=NULL){
		if(strcmp(temp->data,x)==0)
			return temp;
		else temp=temp->link;
	}
}
listNode* searchPreNode(linkedList_h* L, listNode* p) {
	listNode *temp, *pre;
	temp=L->head;
	pre=NULL;
	while(temp!=NULL){
		if(temp==p)
			return pre;
		pre=temp;
		temp=temp->link;
	}
	return pre;
}
	void reverse(linkedList_h* L){
		listNode* p;
		listNode* q;
		listNode* r;
		p=L->head;
		q=NULL;
		r=NULL;
		while(p!=NULL){
			r=q;
			q=p;
			p=p->link;
			q->link=r;
		}
		L->head=q;
	}
int main(){
	linkedList_h* L;
	listNode *p, *pre;
	L=createLinkedList_h();

	printf("(1) 리스트에 [월],[수],[일] 노드 삽입하기!\n");
	insertLastNode(L,"월");
	insertLastNode(L,"수");
	insertLastNode(L,"일");
	printList(L);

	printf("(2) 리스트에서 [화] 노드 탐색하기!\n");
	p=searchNode(L,"화");
	if(p==NULL){
		printf("찾는 데이터가 없습니다.\n\n");
	}
	else
		printf("[%s]를 찾았습니다.\n\n",p->data);
	printf("(3) 리스트에서 [수] 노드 탐색하기!\n");
	p=searchNode(L,"수");
	if(p==NULL){
		printf("찾는 데이터가 없습니다.\n\n");
	}
	else
		printf("[%s]를 찾았습니다.\n\n",p->data);

	printf("(4) 리스트의 [수] 뒤에 [금] 노드 삽입하기!\n");
	insertMiddleNode(L,p,"금");
	printList(L);
	printf("(5) 리스트에서 [월] 노드 삭제하기!\n");
	p=searchNode(L,"월");
	if(p==NULL){
		printf("찾는 데이터가 없습니다.\n");
	}
	else{
		printf("[%s]를 찾았습니다.\n",p->data);
		pre=searchPreNode(L,p);
		if(pre==NULL)
			deleteFirstNode(L);
		else
			deleteNode(L,pre);
		printList(L);
	}
	printf("(6) 리스트 순서를 역순으로 바꾸기!\n");
	reverse(L);
	printList(L);
	freeLinkedList_h(L);
}

