/*
 * 3.c
 *
 *  Created on: 2019. 5. 1.
 *      Author: IoT-30
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char a;
	struct node* link;
}Node;

Node *A= NULL, *B=NULL, *C=NULL;

void AlternateMerge(){
	Node *p, *q, *r;
	Node* newNode;

	p=A;
	q=B;
	r=C;

	while(p!=NULL || q!=NULL){
		if(p!=NULL){
			newNode=(Node*)malloc(sizeof(Node));
			newNode->a=p->a;
			if(r==NULL){
				Node* t;
					t=(Node*)malloc(sizeof(Node));
					t->a=newNode->a;
					t->link=NULL;
					C=t;
					r=C;
			}
			else{
				Node* t;
					t=(Node*)malloc(sizeof(Node));
					t->a=newNode->a;
					t->link=NULL;
					r->link=t;
					r=r->link;
			}
			p=p->link;
		}
		if(q!=NULL){
			newNode=(Node*)malloc(sizeof(Node));
			newNode->a=q->a;
			if(r==NULL){
				Node* t;
					t=(Node*)malloc(sizeof(Node));
					t->a=newNode->a;
					t->link=NULL;
					C=t;
					r=C;
			}
			else{
				Node* t;
					t=(Node*)malloc(sizeof(Node));
					t->a=newNode->a;
					t->link=NULL;
					r->link=t;
					r=r->link;
			}
			q=q->link;
		}
	}
}


int main(){
	Node* p, *temp;
	p=(Node*)malloc(sizeof(Node));
	p->a='I';
	p->link=NULL;
	A=p;

	p=(Node*)malloc(sizeof(Node));
	p->a='o';
	p->link=NULL;
	temp=A;
	temp->link=p;

	p=(Node*)malloc(sizeof(Node));
	p->a='T';
	p->link=NULL;
	temp=temp->link;
	temp->link=p;

	p=(Node*)malloc(sizeof(Node));
	p->a='H';
	p->link=NULL;
	B=p;

	p=(Node*)malloc(sizeof(Node));
	p->a='e';
	p->link=NULL;
	temp=B;
	temp->link=p;

	p=(Node*)malloc(sizeof(Node));
	p->a='l';
	p->link=NULL;
	temp=temp->link;
	temp->link=p;

	p=(Node*)malloc(sizeof(Node));
	p->a='l';
	p->link=NULL;
	temp=temp->link;
	temp->link=p;

	p=(Node*)malloc(sizeof(Node));
	p->a='o';
	p->link=NULL;
	temp=temp->link;
	temp->link=p;

	AlternateMerge();
	p=C;
	while(p!=NULL){
		printf("%c ",p->a);
		p=p->link;
	}
}
