#include <stdio.h>
#include <stdlib.h>

struct stackNode
{
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode STACKNODE;
typedef struct stackNode *STACKNODEPTR;

void push(STACKNODEPTR *, int);
int pop(STACKNODEPTR *);
int isEmpty(STACKNODEPTR);
void printStack(STACKNODEPTR);
void instructions(void);

int main(void)
{
	STACKNODEPTR stackPtr = NULL; /* 指向堆栈顶 */
	int choice, value;
	
	instructions();
	printf("?");
	scanf("%d", &choice);
	
	while(choice != 3)      /* 不定数循环 */
	{
		switch(choice)
		{
			case 1: /* 压入堆栈 */
				printf("输入一个整数：");
				scanf("%d", &value);
				push(&stackPtr, value);
				printStack(stackPtr);
				break;
			case 2: /* 弹出堆栈 */
				if(!isEmpty(stackPtr))
					printf("被弹出的值是：%d 。\n", pop(&stackPtr));
			
				printStack(stackPtr);
				break;
			default:
				printf("无效的选择！\n\n");
				instructions();
				break;
		}
		
		printf("?");
		scanf("%d", &choice);
	}
	
	printf("结束运行。\n");
	return 0;
}

/* 打印菜单指令 */
void instructions(void)
{
	printf(
		"输入你的选择：\n
	        1 将一个值推入堆栈；\n
	        2 将一个值弹出堆栈；\n
	        3 结束程序。\n"
	       );
}

void push(STACKNODEPTR *topPtr, int info)
{
	STACKNODEPTR newPtr;
	
	if((newPtr = malloc(sizeof(STACKNODE))) == NULL)
		fprintf(stderr, "%d 没有插入，因为没有可用的内存！", info);
	
	newPtr->data = info;
	newPtr->nextPtr = *topPtr;
	*topPtr = newPtr;
}

int pop(STACKNODEPTR *topPtr)
{
	STACKNODEPTR tempPtr;
	int popValue;
	
	tempPtr = *topPtr;
	popValue = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
	return popValue;
}

void printStack(STACKNODEPTR currentPtr)
{
	if(currentPtr == NULL)
		printf("堆栈为空！\n\n");
	else
	{
		printf("堆栈为：\n");
		while(currentPtr != NULL)
		{
			printf("%d -->",currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL\n\n");
	}
}

/* 堆栈为空? */
int isEmpty(STACKNODEPTR topPtr)
{
	return topPtr == NULL;
}
