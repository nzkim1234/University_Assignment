/*
 * IoTEvent.c
 *
 *  Created on: 2019. 5. 22.
 *      Author: �躸��
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
	printf("\t�̺�Ʈ  %d �߻� (ó���ð�:%d��)\n",event.id,event.tService);
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

	printf("�ùķ��̼� �� �ִ� �ð�(����:��)= ");
	fflush(stdout);
	scanf("%d",&tSimulation);
	printf("�����ð�(1��)�� �̺�Ʈ�� �߻��� Ȯ�� (��:0.1)= ");
	fflush(stdout);
	scanf("%lf",&probEvent);
	printf("�� �̺�Ʈ�� ���� �ִ� ó�� �ð�(����:��)= ");
	fflush(stdout);
	scanf("%d",&tMaxService);
	printf("======================================================\n");

	for(sec=0; sec<tSimulation; sec++){
		printf("���� �ð�: %d\n",sec);
		if(unitRand()>=probEvent){
			insertEvent(Q1,sec);
		}
		if(!isEmpty(Q1) && serviceTime<=0){
			nServedEvents++;
			a=deQueue(Q1);
			serviceTime=a.tService;
			WaitTime=sec-a.tEvent;
			printf("\t�̺�Ʈ %d ó��  ����(���ð�:%d��)\n",a.id,WaitTime);
			totalWaitTime+=WaitTime;
		}
		serviceTime--;
	}
	printf("======================================================\n");
	printf("Simulation Report!\n\n");
	printf("ó���� �̺�Ʈ ��\t\t=%d\n",nServedEvents);
	printf("��ü ��� �ð�\t\t\t=%d��\n",totalWaitTime);
	printf("�̺�Ʈ �� ��մ��ð�\t\t=%.2f��\n",(double)totalWaitTime/nServedEvents);
	printf("���� ��� �̺�Ʈ ��\t\t=%d\n",nEvents-nServedEvents);
}
