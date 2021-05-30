/*
 * List.c
 *
 *  Created on: 2019. 4. 7.
 *      Author: 김보윤
 */

#include <stdio.h>
#include <string.h>
#define MAX_IOT_LIST_SIZE 45


int length;

typedef struct {
	char name[20];
	int id;
}Namecard;

Namecard iot_list[MAX_IOT_LIST_SIZE];

Namecard make_Namecard(char name[], int id) {
	Namecard newCard;

	strcpy(newCard.name, name);
	newCard.id = id;

	return newCard;
}

void init(void){
	length = 0;
}

void insert(int pos, Namecard item){
	if((0 <= pos) && (pos < MAX_IOT_LIST_SIZE) &&  pos < length+1 ){
		if(pos <= length){
			for(int i=length; pos <= i; i--)
				iot_list[i+1] = iot_list[i];
			iot_list[pos] = item;
			length++;
		}
	}else
		printf("포화상태 오류 또는 삽입 위치 오류\n");


}

void delete(int pos){
	if((pos < 0) || (length == 0) ||pos >= length){
		printf("공백상태 오류 또는 삭제 위치 오류\n");

		return ;
	}

	for(int i = pos ; i < length-1 ; i++){
		iot_list[i] = iot_list[i+1];
	}
	length--;

}

Namecard get_entry(int pos){
	return iot_list[pos];
}

int is_empty(void){

	if(length == 0){
		return 1;
	}
	return 0;
}

int is_full(void){
	if(length == (MAX_IOT_LIST_SIZE-1) )
		return 1;
	return 0;
}

int find(Namecard item){
	for(int i = 0; i < MAX_IOT_LIST_SIZE; i++ ){
		if((iot_list[i].id == item.id) && !strcmp(item.name, iot_list[i].name)){
			return i;
		}
	}
	return -1;
}

void replace(int pos, Namecard item){

	if((0 <= pos) && (pos < MAX_IOT_LIST_SIZE) && (pos < length)){
		iot_list[pos].id = item.id;
		strcpy(iot_list[pos].name, item.name);
	}else{
		printf("교체 위치 오류\n");
	}
}

int size(void){
	return length;
}

void sort_list(void) {
	Namecard minCard = make_Namecard("name", 0);


	Namecard tempCard = make_Namecard("name", 0);


	int i = 0;

	if (is_empty() == 0) {
		for (int j = 0; j < length; j++) {
			minCard = iot_list[j];
			i = 0;
			for (int k = j; i < length - j; i++) {
				if (minCard.id > iot_list[k].id) {
					tempCard = minCard;
					minCard = iot_list[k];
					iot_list[k] = tempCard;
				}
				k++;
			}
			iot_list[j] = minCard;
		}
	}
	else {
		printf("정렬 오류\n");
	}
}

void print_list(char *msg){
	printf("%s:", msg);
	for(int i=0; i< length; i++){
		printf("(%s, %d) ",iot_list[i].name, iot_list[i].id);
	}
	printf("\n");
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
	sort_list();
	print_list("Sort");
	printf("%s is found at %d\n", "엘사", find(make_Namecard("엘사", 21141730)));
	printf("%s is found at %d\n", "뮬란", find(make_Namecard("뮬란", 21141709)));
}

