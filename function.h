#include <stdio.h>
#include <stdlib.h>
//������ 
typedef char BiElemType;
typedef struct BiTNode {
	BiElemType c;//c ���������ϵ� data
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode,*BiTree;
//tag �ṹ���Ǹ�������ʹ�õ�
typedef struct tag {
	BiTree p;//����ĳһ�����ĵ�ֵַ
	struct tag *pnext;
} tag_t,*ptag_t;

//������ 
typedef BiTree ElemType;

typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkNode;

typedef struct {
	LinkNode *front,*rear;//����ͷ������β 
}LinkQueue;
