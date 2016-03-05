#include<stdio.h>
#include<malloc.h>
#include"LinkQueue.h"

/*
typedef int QElemType;

typedef struct QueueNode 
{
	QElemType data;
	struct QueueNode *next;	
}QueueNode,*QueuePtr;

typedef struct LinkQueue
{
	QueuePtr front,rear;
	int length;	
}LinkQueue;
*/

/*
�������ƣ�LinkQueueInit(LinkQueue *Q)
����������Q------ָ����е�ָ��
˵���� ����һ���ն��У�������һ����������Ա���������һ������ĵ�����
�ڶ��н��ṹ��Q->frontָ�������ͷ��㣬Q->rearָ�����������һ����� 
*/
Bool LinkQueueInit(LinkQueue *Q)
{	
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QueuePtr));
	if(!Q->front)
	{
		printf("\n�����д���ʧ��!\n");
		return Error;	
	}
	Q->front->next=NULL;/*��ʼ��������Ķ����ÿ�*/
	Q->length=0;
	return OK;
}
/*����һ��������*/
void LinkQueueDestroy(LinkQueue *Q)
{
	while(Q->front)
	{
		Q->rear=Q->front->next;/*ע��whileѭ����ͷָ���βָ�붼�ڲ���������β�������ƶ�*/
		free(Q->front);
		Q->front=Q->rear;	
	}
}
/*���һ��������*/
Bool LinkQueueClear(LinkQueue *Q)
{
	QueuePtr ptarget,pnext;
	pnext=Q->front->next;
	
	Q->rear=Q->front;
	Q->front->next=NULL;
	
	while(pnext)
	{
		ptarget=pnext;
		pnext=pnext->next;
		free(ptarget);
		Q->length--;	
	}
	if(!Q->length)
	{
		return OK;	
	}
	else
	{
		printf("\n�����л�δ������!\n");
		return Error;	
	}	
}

/*�ж�һ���������Ƿ�Ϊ��*/
Bool LinkQueueIsEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
		return True;
	else
		return False;
}
/*��ȡ�����еĳ���*/
int LinkQueueLength(LinkQueue Q)
{
	int length=0;
	QueuePtr p=Q.front;/*��������Ϊ��ʱQ.front==Q.rear*/
	while(p!=Q.rear)
	{
		length++;
		p=p->next;	
	}
	return length;
	//return Q.length;	
}
/*��ȡ������ͷ���Ԫ��*/
void LinkQueueGetHead(LinkQueue Q,QElemType *e)
{
	QueuePtr p;
	if(Q.front==Q.rear)/*�Ϸ��Լ�飬������Ϊ��ʱ*/
	{
		printf("\n����Ϊ�գ��޷���ȡ\n");
		return;	
	}
	else
	{
		p=Q.front->next;
		*e=p->data;			
	}	
}

/*��������,��������Ϊe�Ľ����뵽����ĩβ*/
void LinkQueueEnQueue(LinkQueue *Q,QElemType e)
{
	QueuePtr node=(QueuePtr)malloc(sizeof(QueuePtr));
	if(!node)
		return;
	/*��ʼ�����ɵ��½��*/	 
	node->data=e;
	node->next=NULL;
	
	Q->rear->next=node;
	Q->rear=node;
	Q->length++;	
} 
/*�������У��������е�һ��������������ɾ��������������ָ��e����*/
void LinkQueueDelQueue(LinkQueue*Q,QElemType *e)
{
	QueuePtr p; 
	if(Q->front==Q->rear)/*�Ϸ��Լ�飬������Ϊ��ʱ*/
	{
		printf("\n������Ϊ�գ��޷�����!\n");
		return;	
	}
	p=Q->front->next;/* ����ɾ���Ķ�ͷ����ݴ��p*/
	Q->front->next=Q->front->next->next;/*������ͷָ��ָ�������е�2�����*/
	*e=p->data;
	
	if(p==Q->rear)/*����������ֻ��һ����㼴ͷָ����βָ��ָ��ͬһ��Ԫ��ʱ��βָ��ָ��ͷָ��*/ 
	{
		Q->rear=Q->front;
	} 
	free(p);
	Q->length--;	 
} 
/*��������������*/
void LinkQueueTraverse(LinkQueue Q)
{
	QueuePtr p;
	if(Q.front==Q.rear)/*�Ϸ��Լ��*/ 
	{
		printf("\n��ǰ������Ϊ�գ��޷���������������!\n");
		return;
	} 
	p=Q.front->next;
	while(p)
	{
		printf("%d,",p->data);
		p=p->next;	
	}
	printf("\n");
	
}
