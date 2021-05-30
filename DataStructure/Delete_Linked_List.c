/*
 * 20.C
 *
 *  Created on: 2019. 4. 10.
 *      Author: IoT-13
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
	char name[20];
	int id;
	struct node *link;
}Node;

Node *head;

void print_list();

Node *search_list_by_name(char *name);
Node *search_list_by_id(int id);

void insert(Node *pre, char *name, int id);

void delete(char *name, int id);

int main(){
	Node *pre;
	insert(NULL,"엘리스",1000);
	print_list();
	insert(NULL,"엘사",2000);
	print_list();
	pre =search_list_by_name("엘리스");
	insert(pre,"신데렐라",3000);
	print_list();
	pre=search_list_by_id(1000);
	insert(pre,"쟈스민",4000);
	print_list();
	printf("Delete\n");
	delete("엘사",2000);
	print_list();
	delete("쟈스민",4000);
	print_list();
	delete("신데렐라",3000);
	print_list();
	delete("엘리스",1000);
	print_list();
	delete("신데렐라",3000);
	print_list();
}

void print_list(){
	Node *p;
	p=head;
	while(p!=NULL){
		printf("(%s, %d) ",p->name, p->id);
		p=p->link;
	}
	printf("\n");
}
Node *search_list_by_name(char *name){
	Node *p;
	p=head;
	while(p!=NULL){
		if(strcmp(p->name,name)==0){
			return p;
		}
		else
			p=p->link;
	}
	return p;
}


Node *search_list_by_id(int id){
	Node *p;
	p=head;
	while(p!=NULL){
		if(p->id==id)
			return p;
		else
			p=p->link;
	}
	return p;
}

void insert(Node *pre, char *name, int id) {
	Node *new;
	new=(Node*)malloc(sizeof(Node));
	new->id=id;
	strcpy(new->name,name);

	if(head==NULL){
		head=new;
		new->link=NULL;
	}
	else if(pre==NULL){
		new->link=head;
		head=new;
	}
	else{
		new->link=pre->link;
		pre->link=new;
	}
}

void delete(char *name, int id){
	Node *pre;
	Node *del;

	if(head==NULL){
		printf("List is empty!!!\n");
		return ;
	}

	if(id==head->id && strcmp(head->name,name)==0){
		del=head;
		head=head->link;
		free(del);
	}
	else{
		pre=head;
		while(pre->link!=NULL){
			if(pre->link->id==id && strcmp(pre->link->name,name)==0){
				del=pre->link;
				pre->link=pre->link->link;
			}
			else
				pre=pre->link;
		}
	}
}
