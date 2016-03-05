#include <stdio.h>
#include <stdlib.h>
#include"LinkQueue.h"
/*
文件名称：链队列的基本操作
时间：2015-1-26 23:45
说明：链队列的基本操作，在链队列的结点结构中，头指针front相当于单链表的头结点，尾指针rear指向整个单链表中最后一个元素 
*/

int main(int argc, char *argv[]) 
{
	LinkQueue Q;
	int i=0;
	QElemType a;
	
	LinkQueueInit(&Q);
	printf("\n当前链队列的长度为:%d\n",LinkQueueLength(Q));
	printf("\n遍历当前链队列的结果为:\n"); 
	LinkQueueTraverse(Q);
	
	for(i=0;i<10;i++)
		LinkQueueEnQueue(&Q,i);

	printf("\n当前链队列的长度为:%d\n",LinkQueueLength(Q));
	printf("\n遍历当前链队列的结果为:\n"); 
	LinkQueueTraverse(Q);
	
	LinkQueueDelQueue(&Q,&a);
	printf("a=%d\n",a);
	printf("\n当前链队列的长度为:%d\n",LinkQueueLength(Q));
	printf("\n遍历当前链队列的结果为:\n"); 
	LinkQueueTraverse(Q);
	
	LinkQueueGetHead(Q,&a);	
	printf("a=%d\n",a);
	printf("\n当前链队列的长度为:%d\n",LinkQueueLength(Q));
	printf("\n遍历当前链队列的结果为:\n"); 
	LinkQueueTraverse(Q);
	
	LinkQueueClear(&Q);
	printf("\n当前链队列的长度为:%d\n",LinkQueueLength(Q));
	printf("\n遍历当前链队列的结果为:\n"); 
	LinkQueueTraverse(Q);	
	
	LinkQueueDestroy(&Q);
	printf("\n当前链队列的长度为:%d\n",LinkQueueLength(Q));
			
	return 0;
}
