#include <stdio.h>
#include <stdlib.h>
//二叉树 
typedef char BiElemType;
typedef struct BiTNode {
	BiElemType c;//c 就是数集上的 data
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode,*BiTree;
//tag 结构体是辅助队列使用的
typedef struct tag {
	BiTree p;//树的某一个结点的地址值
	struct tag *pnext;
} tag_t,*ptag_t;

//链队列 
typedef BiTree ElemType;

typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkNode;

typedef struct {
	LinkNode *front,*rear;//链表头、链表尾 
}LinkQueue;
