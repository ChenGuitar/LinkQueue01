#include <stdio.h>
#include <stdlib.h>
#include"LinkQueue.h"
/*
�ļ����ƣ������еĻ�������
ʱ�䣺2015-1-26 23:45
˵���������еĻ����������������еĽ��ṹ�У�ͷָ��front�൱�ڵ������ͷ��㣬βָ��rearָ�����������������һ��Ԫ�� 
*/

int main(int argc, char *argv[]) 
{
	LinkQueue Q;
	int i=0;
	QElemType a;
	
	LinkQueueInit(&Q);
	printf("\n��ǰ�����еĳ���Ϊ:%d\n",LinkQueueLength(Q));
	printf("\n������ǰ�����еĽ��Ϊ:\n"); 
	LinkQueueTraverse(Q);
	
	for(i=0;i<10;i++)
		LinkQueueEnQueue(&Q,i);

	printf("\n��ǰ�����еĳ���Ϊ:%d\n",LinkQueueLength(Q));
	printf("\n������ǰ�����еĽ��Ϊ:\n"); 
	LinkQueueTraverse(Q);
	
	LinkQueueDelQueue(&Q,&a);
	printf("a=%d\n",a);
	printf("\n��ǰ�����еĳ���Ϊ:%d\n",LinkQueueLength(Q));
	printf("\n������ǰ�����еĽ��Ϊ:\n"); 
	LinkQueueTraverse(Q);
	
	LinkQueueGetHead(Q,&a);	
	printf("a=%d\n",a);
	printf("\n��ǰ�����еĳ���Ϊ:%d\n",LinkQueueLength(Q));
	printf("\n������ǰ�����еĽ��Ϊ:\n"); 
	LinkQueueTraverse(Q);
	
	LinkQueueClear(&Q);
	printf("\n��ǰ�����еĳ���Ϊ:%d\n",LinkQueueLength(Q));
	printf("\n������ǰ�����еĽ��Ϊ:\n"); 
	LinkQueueTraverse(Q);	
	
	LinkQueueDestroy(&Q);
	printf("\n��ǰ�����еĳ���Ϊ:%d\n",LinkQueueLength(Q));
			
	return 0;
}
