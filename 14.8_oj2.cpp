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

//链队列操作
void InitQueue(LinkQueue &Q) {
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
}
void EnQueue(LinkQueue &Q,ElemType e) {
	LinkNode *pnew = (LinkNode*)malloc(sizeof(LinkNode));
	pnew->next=NULL;
	pnew->data=e;
	Q.rear->next=pnew;//尾指针的next指向pnew;
	Q.rear=pnew;
}

bool DeQueue(LinkQueue &Q,ElemType &e) {
	if(Q.front==Q.rear) {
		return false;
	}
	LinkNode* q = Q.front->next;//q指向队头第一个节点
	e=q->data;
	Q.front->next = q->next;//让第一个节点断链
	if(Q.rear==q) { //当只存在最后一个结点
		Q.rear = Q.front;//尾巴指向头，即是队列为空了
	}
	free(q);//释放q节点
	return true;
}

bool IsEmpty(LinkQueue &Q) {
	if(Q.front==Q.rear) {
		return true;
	} else
		return false;
}
//中序遍历
void MiddleOrder(BiTree p) {
	if(NULL!=p) {
		MiddleOrder(p->lchild);
		printf("%c",p->c);
		MiddleOrder(p->rchild);
	}
}

//后续遍历
void PostOrder(BiTree p) {
	if(NULL!=p) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%c",p->c);
	}
}

//层次遍历、广度遍历
void LevelOrder(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q,T);
	while(!IsEmpty(Q)) {
		DeQueue(Q,p);//出队当前结点并打印
		putchar(p->c);
		if(p->lchild!=NULL) //入队左孩子
			EnQueue(Q,p->lchild);
		if(p->rchild!=NULL) //入队右孩子
			EnQueue(Q,p->rchild);
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main() {
	BiTree pnew;//用来指向新申请的数节点
	BiTree tree = NULL; //指向树根，代表树
	char c;
	ptag_t phead=NULL,ptail=NULL,listpnew=NULL,pcur;
	//abcdefghij
	while(scanf("%c",&c)) {
		if(c=='\n') {
			break;
		}
		//calloc申请的大小空间为下面两个参数的乘积
		pnew = (BiTree)calloc(1,sizeof(BiTNode));
		pnew->c=c;//数据放进去
		listpnew=(ptag_t)calloc(1,sizeof(tag_t));//给队列结点申请空间
		listpnew->p=pnew;
		if(NULL==tree) {
			tree=pnew;//树的根
			phead=listpnew;//队列头
			ptail=listpnew;//队列尾
			pcur=listpnew;
			continue;
		} else {
			ptail->pnext=listpnew;//新结点放入链表，通过尾插法
			ptail=listpnew;//ptail 指向队列尾部
		}//pcur 始终指向要插入的结点的位置
		if(NULL==pcur->p->lchild) { //如何把新结点放入树
			pcur->p->lchild=pnew;//把新结点放到要插入结点的左边
		} else if(NULL==pcur->p->rchild) {
			pcur->p->rchild=pnew;//把新结点放到要插入结点的右边
			pcur=pcur->pnext;//左右都放了结点后，pcur 指向队列的下一个
		}
	}
//中序遍历
	MiddleOrder(tree);
	printf("\n");
//后续遍历
	PostOrder(tree);
	printf("\n");
//层次遍历
	LevelOrder(tree); 
}
