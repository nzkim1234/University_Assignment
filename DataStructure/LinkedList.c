/*
 * LinkedList.c
 *
 *  Created on: 2019. 4. 18.
 *      Author: 김보윤
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct name_card{
	char name[20];
	int id;
	struct name_card* link;
}Namecard;

Namecard *head;

Namecard *make_Namecard(char name[], int id){
	Namecard *newCard = (Namecard*)malloc(sizeof(Namecard));

	strcpy(newCard->name, name);
	newCard->id=id;
	newCard->link=NULL;
	return newCard;
}

void init(){
	head=NULL;
}

int is_empty(){
	if(head!=NULL)
		return 0;
	else
		return 1;
}

int size(){
	int count=0;
	Namecard *p;
	p=head;
	while(p != NULL){
		count++;
		p=p->link;
	}
	return count;
}

Namecard *get_entry(int pos){
	Namecard *p;
	p=head;
	for(int i=0; i<pos; i++){
		p=p->link;
	}
	return p;
}

void insert(int pos, Namecard *item){
	Namecard *p, *pre;
	p=head;
	if(p==NULL){
		head=item;
	}
	else{
		if(pos>size() || pos<0){
			printf("위치오류\n");
		}
		else{
			for(int i=0; i<pos-1; i++)
				p=p->link;
			if(p==NULL){
				p->link=item;
			}
			else{
				if(pos==0){
					pre=head;
					head=item;
					head->link=pre;
				}
				else{
					pre=p->link;
					p->link=item;
					p->link->link=pre;
				}
			}
		}
	}
}

void replace(int pos, Namecard *item){
	Namecard *p, *pre;
	p=head;
	if(pos>size() || pos<0){
		printf("위치오류\n");
	}
	else{
		for(int i=0; i<pos-1; i++){
			p=p->link;
		}
		pre=p->link;
		p->link=item;
		p->link->link=pre->link;
	}
}

void delete(int pos){
	Namecard *p;
	p=head;
	if(pos>size() || pos<0){
		printf("위치오류\n");
	}
	else{
		if(pos==0){
			head=head->link;
		}
		else{
			for(int i=0; i<pos-1; i++){
				p=p->link;
			}

			p->link=p->link->link;
		}
	}
}

int find(Namecard *item){
	Namecard *p;
	p=head;
	for(int i=0; i<size(); i++){
		if(p->id==item->id && strcmp(p->name,item->name)==0)
			return i;
		else
			p=p->link;
	}
	return -1;
}
void print_list(char *msg){
	Namecard *p;
	p=head;
	printf("%s:", msg);
	while(p!=NULL){
		printf("(%s %d)",p->name,p->id);
		p=p->link;
	}
	printf("\n\n");
}

int main(){
	init();
	print_list("Init");

	insert(0, make_Namecard("쟈스민", 21141719));
	insert(0, make_Namecard("백설", 21141713));
	insert(1, make_Namecard("에리얼", 21141708));
	insert(size(), make_Namecard("오로라", 21141741));
	insert(3, make_Namecard("신데렐라", 21141735));
	insert(size(), make_Namecard("벨", 21141731));
	insert(10, make_Namecard("라푼젤", 21141712));
	print_list("Insert");
	replace(size() - 1, make_Namecard("소피아", 21141718));
	replace(4, make_Namecard("엘사", 21141730));
	replace(20, make_Namecard("앨리스", 21141714));

	print_list("Replace");
	delete(3);
	delete(size()-1);
	delete(0);
	delete(30);
	print_list("Delete");
	printf("%s is found at %d\n", "엘사", find(make_Namecard("엘사", 21141730)));
	printf("%s is found at %d\n", "뮬란", find(make_Namecard("뮬란", 21141709)));
}
