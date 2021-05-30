/*
 * IoTEvent.c
 *
 *  Created on: 2019. 5. 22.
 *      Author: 김보윤
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define cQ_SIZE 100

typedef struct{
	int id;
	int tEvent;
	int tService;
}Event;

typedef Event element;

typedef struct{
	element queue[cQ_SIZE];
	int front, rear;
}QueueType;

int tSimulation;
double probEvent;
int tMaxService;
int totalWaitTime;
int nEvents;
int nServedEvents;

double unitRand(){
	return (rand()/(double)RAND_MAX);
}

QueueType *createQueue(){
	QueueType *cQ;
	cQ=(QueueType*)malloc(sizeof(QueueType));
	cQ->front=0;
	cQ->rear=0;
	return cQ;
}

int isEmpty(QueueType *cQ){
	if(cQ->front==cQ->rear)
		return 1;
	else
		return 0;
}

int isFull(QueueType *cQ){
	if(((cQ->rear+1)%cQ_SIZE)==cQ->front%cQ_SIZE)
		return 1;
	else
		return 0;
}

void enQueue(QueueType *cQ, element item){
	if(isFull(cQ)){
		printf("Queue is Full!!!\n");
		exit(1);
	}
	else{
		cQ->rear=(cQ->rear+1)%cQ_SIZE;
		cQ->queue[cQ->rear]=item;
	}
}

element deQueue(QueueType *cQ){
	if(isEmpty(cQ))
		exit(1);
	else{
		cQ->front=(cQ->front+1)%cQ_SIZE;
		return cQ->queue[cQ->front];
	}
}


void insertEvent(QueueType *cQ, int eventTime){
	nEvents++;
	Event event;
	event.id=nEvents;
	event.tEvent=eventTime;
	event.tService=rand()%tMaxService+1;
	enQueue(cQ,event);
	printf("\t이벤트  %d 발생 (처리시간:%d초)\n",event.id,event.tService);
}

int main(){
	QueueType *Q1= createQueue();
	Event a;
	int serviceTime=0;
	int sec;

	srand((unsigned int)time(NULL));

	int WaitTime=0;
	totalWaitTime=0;
	nEvents=0;
	nServedEvents=0;

	printf("시뮬레이션 할 최대 시간(단위:초)= ");
	fflush(stdout);
	scanf("%d",&tSimulation);
	printf("단위시간(1초)에 이벤트가 발생할 확률 (예:0.1)= ");
	fflush(stdout);
	scanf("%lf",&probEvent);
	printf("한 이벤트에 대한 최대 처리 시간(단위:초)= ");
	fflush(stdout);
	scanf("%d",&tMaxService);
	printf("======================================================\n");

	for(sec=0; sec<tSimulation; sec++){
		printf("현재 시간: %d\n",sec);
		if(unitRand()>=probEvent){
			insertEvent(Q1,sec);
		}
		if(!isEmpty(Q1) && serviceTime<=0){
			nServedEvents++;
			a=deQueue(Q1);
			serviceTime=a.tService;
			WaitTime=sec-a.tEvent;
			printf("\t이벤트 %d 처리  시작(대기시간:%d초)\n",a.id,WaitTime);
			totalWaitTime+=WaitTime;
		}
		serviceTime--;
	}
	printf("======================================================\n");
	printf("Simulation Report!\n\n");
	printf("처리된 이벤트 수\t\t=%d\n",nServedEvents);
	printf("전체 대기 시간\t\t\t=%d초\n",totalWaitTime);
	printf("이벤트 당 평균대기시간\t\t=%.2f초\n",(double)totalWaitTime/nServedEvents);
	printf("현재 대기 이벤트 수\t\t=%d\n",nEvents-nServedEvents);
}
