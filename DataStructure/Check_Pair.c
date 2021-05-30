/*
 * 7.c
 *
 *  Created on: 2019. 5. 8.
 *      Author: IoT-30
 */


/*
 * 6.c
 *
 *  Created on: 2019. 5. 8.
 *      Author: IoT-30
 */


#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef char element;

element stack[STACK_SIZE];
int top=-1;

int isEmpty(){
	if(top==-1)
		return 1;
	else return 0;
}

int isFull(){
	if(top==STACK_SIZE -1)
		return 1;
	else
		return 0;
}

void push(element item){
	if(isFull()){
		printf("\n\n stack is FULL!\n");
		return ;
	}
	else
		stack[++top]=item;
}

element pop(){
	if(isEmpty()){
		printf("\n\n stack is Empty!!\n");
		return 0;
	}
	else
		return stack[top--];
}

element peek(){
	if(isEmpty()){
		printf("\n\n stack is Empty!!\n");
		return 0;
	}
	else
		return stack[top];
}

int testPair(char filename[]){
	char symbol, open_pair;
	int mQuote=0;
	FILE *fp = fopen(filename,"r");
	if(fp==NULL)
		printf("Error: 파일이 존재하지 않습니다!\n");
	top=-1;
	while((symbol=fgetc(fp))!=EOF){
		if(symbol==34||symbol==39){
			if(mQuote==0)
				mQuote=1;
			else
				mQuote=0;
		}
		if(mQuote==1){
			continue;
		}
		switch(symbol){
		case'(':
		case'[':
		case'{':
			push(symbol);
			break;
		case')':
		case']':
		case'}':
			if(top==-1)
				return 0;
			else{
				open_pair=pop();
				if((open_pair=='('&&symbol!=')')||(open_pair=='['&&symbol!=']')||(open_pair=='{'&&symbol!='}'))
					return 0;
				else
					break;
			}
		}
	}
	fclose(fp);
	if(top==-1)
		return 1;
	else
		return 0;
}

int main(){
	int ret;
	ret=testPair("5.c");
	(ret==1) ? printf("5.c 괄호 정상\n") : printf("5.c 괄호 비정상\n");
	ret=testPair("7.c");
	(ret==1) ? printf("7.c 괄호 정상\n") : printf("7.c 괄호 비정상\n");

}
