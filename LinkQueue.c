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
函数名称：LinkQueueInit(LinkQueue *Q)
函数参数：Q------指向队列的指针
说明： 构造一个空队列，队列是一种特殊的线性表，链队列是一种特殊的单链表，
在队列结点结构中Q->front指向单链表的头结点，Q->rear指向单链表中最后一个结点 
*/
Bool LinkQueueInit(LinkQueue *Q)
{	
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QueueNode));
	if(!Q->front)
	{
		printf("\n链队列创建失败!\n");
		return Error;	
	}
	Q->front->next=NULL;/*初始化将构造的队列置空*/
	Q->length=0;
	return OK;
}
/*销毁一个链队列*/
void LinkQueueDestroy(LinkQueue *Q)
{
	while(Q->front)
	{
		Q->rear=Q->front->next;/*注意while循环中头指针和尾指针都在不断向单链表尾部方向移动*/
		free(Q->front);
		Q->front=Q->rear;	
	}
}
/*清除一个链队列*/
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
		printf("\n链队列还未清除完毕!\n");
		return Error;	
	}	
}

/*判断一个链队列是否为空*/
Bool LinkQueueIsEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
		return True;
	else
		return False;
}
/*获取链队列的长度*/
int LinkQueueLength(LinkQueue Q)
{
	int length=0;
	QueuePtr p=Q.front;/*当链队列为空时Q.front==Q.rear*/
	while(p!=Q.rear)
	{
		length++;
		p=p->next;	
	}
	return length;
	//return Q.length;	
}
/*获取链队列头结点元素*/
void LinkQueueGetHead(LinkQueue Q,QElemType *e)
{
	QueuePtr p;
	if(Q.front==Q.rear)/*合法性检查，当队列为空时*/
	{
		printf("\n队列为空，无法获取\n");
		return;	
	}
	else
	{
		p=Q.front->next;
		*e=p->data;			
	}	
}

/*入链队列,将数据域为e的结点插入到队列末尾*/
void LinkQueueEnQueue(LinkQueue *Q,QElemType e)
{
	QueuePtr node=(QueuePtr)malloc(sizeof(QueueNode));
	if(!node)
		return;
	/*初始化生成的新结点*/	 
	node->data=e;
	node->next=NULL;
	
	Q->rear->next=node;
	Q->rear=node;
	Q->length++;	
} 
/*出链队列，将队列中第一个结点从链队列中删除并将数据域用指针e返回*/
void LinkQueueDelQueue(LinkQueue*Q,QElemType *e)
{
	QueuePtr p; 
	if(Q->front==Q->rear)/*合法性检查，当队列为空时*/
	{
		printf("\n链队列为空，无法出队!\n");
		return;	
	}
	p=Q->front->next;/* 将欲删除的队头结点暂存给p*/
	Q->front->next=Q->front->next->next;/*链队列头指针指向链队列第2个结点*/
	*e=p->data;
	
	if(p==Q->rear)/*当链队列中只有一个结点即头指针与尾指针指向同一个元素时让尾指针指向头指针*/ 
	{
		Q->rear=Q->front;
	} 
	free(p);
	Q->length--;	 
} 
/*遍历整个链队列*/
void LinkQueueTraverse(LinkQueue Q)
{
	QueuePtr p;
	if(Q.front==Q.rear)/*合法性检查*/ 
	{
		printf("\n当前链队列为空，无法遍历整个链队列!\n");
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
