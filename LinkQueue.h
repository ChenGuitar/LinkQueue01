#ifndef _LinkQueue_H
#define _LinkQueue_H

#define Bool int 
#define OK (1)
#define Error (0)
#define True (1)
#define False (0) 

typedef int QElemType;
/*������н������*/ 
typedef struct QueueNode 
{
	QElemType data;
	struct QueueNode *next;	
}QueueNode,*QueuePtr;

typedef struct LinkQueue
{
	QueuePtr front,rear;/*������������ͷָ�롢βָ��*/
	int length;	
}LinkQueue;

/*����һ���ն���*/
Bool LinkQueueInit(LinkQueue *Q);
/*����һ��������*/
void LinkQueueDestroy(LinkQueue *Q);
/*���һ��������*/
Bool LinkQueueClear(LinkQueue *Q);
/*�ж�һ���������Ƿ�Ϊ��*/
Bool LinkQueueIsEmpty(LinkQueue Q);
/*��ȡ�����еĳ���*/
int LinkQueueLength(LinkQueue Q);
/*��ȡ������ͷ���Ԫ��*/
void LinkQueueGetHead(LinkQueue Q,QElemType *e);
/*��������,��������Ϊe�Ľ����뵽����ĩβ*/
void LinkQueueEnQueue(LinkQueue *Q,QElemType e);
/*�������У��������е�һ��������������ɾ��������������ָ��e����*/
void LinkQueueDelQueue(LinkQueue*Q,QElemType *e);
/*��������������*/
void LinkQueueTraverse(LinkQueue Q);

 
#endif
