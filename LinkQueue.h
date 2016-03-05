#ifndef _LinkQueue_H
#define _LinkQueue_H

#define Bool int 
#define OK (1)
#define Error (0)
#define True (1)
#define False (0) 

typedef int QElemType;
/*构造队列结点类型*/ 
typedef struct QueueNode 
{
	QElemType data;
	struct QueueNode *next;	
}QueueNode,*QueuePtr;

typedef struct LinkQueue
{
	QueuePtr front,rear;/*定义队列链表的头指针、尾指针*/
	int length;	
}LinkQueue;

/*构造一个空队列*/
Bool LinkQueueInit(LinkQueue *Q);
/*销毁一个链队列*/
void LinkQueueDestroy(LinkQueue *Q);
/*清除一个链队列*/
Bool LinkQueueClear(LinkQueue *Q);
/*判断一个链队列是否为空*/
Bool LinkQueueIsEmpty(LinkQueue Q);
/*获取链队列的长度*/
int LinkQueueLength(LinkQueue Q);
/*获取链队列头结点元素*/
void LinkQueueGetHead(LinkQueue Q,QElemType *e);
/*入链队列,将数据域为e的结点插入到队列末尾*/
void LinkQueueEnQueue(LinkQueue *Q,QElemType e);
/*出链队列，将队列中第一个结点从链队列中删除并将数据域用指针e返回*/
void LinkQueueDelQueue(LinkQueue*Q,QElemType *e);
/*遍历整个链队列*/
void LinkQueueTraverse(LinkQueue Q);

 
#endif
