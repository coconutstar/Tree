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

//�����в���
void InitQueue(LinkQueue &Q) {
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
}
void EnQueue(LinkQueue &Q,ElemType e) {
	LinkNode *pnew = (LinkNode*)malloc(sizeof(LinkNode));
	pnew->next=NULL;
	pnew->data=e;
	Q.rear->next=pnew;//βָ���nextָ��pnew;
	Q.rear=pnew;
}

bool DeQueue(LinkQueue &Q,ElemType &e) {
	if(Q.front==Q.rear) {
		return false;
	}
	LinkNode* q = Q.front->next;//qָ���ͷ��һ���ڵ�
	e=q->data;
	Q.front->next = q->next;//�õ�һ���ڵ����
	if(Q.rear==q) { //��ֻ�������һ�����
		Q.rear = Q.front;//β��ָ��ͷ�����Ƕ���Ϊ����
	}
	free(q);//�ͷ�q�ڵ�
	return true;
}

bool IsEmpty(LinkQueue &Q) {
	if(Q.front==Q.rear) {
		return true;
	} else
		return false;
}
//�������
void MiddleOrder(BiTree p) {
	if(NULL!=p) {
		MiddleOrder(p->lchild);
		printf("%c",p->c);
		MiddleOrder(p->rchild);
	}
}

//��������
void PostOrder(BiTree p) {
	if(NULL!=p) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%c",p->c);
	}
}

//��α�������ȱ���
void LevelOrder(BiTree T) {
	LinkQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q,T);
	while(!IsEmpty(Q)) {
		DeQueue(Q,p);//���ӵ�ǰ��㲢��ӡ
		putchar(p->c);
		if(p->lchild!=NULL) //�������
			EnQueue(Q,p->lchild);
		if(p->rchild!=NULL) //����Һ���
			EnQueue(Q,p->rchild);
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main() {
	BiTree pnew;//����ָ������������ڵ�
	BiTree tree = NULL; //ָ��������������
	char c;
	ptag_t phead=NULL,ptail=NULL,listpnew=NULL,pcur;
	//abcdefghij
	while(scanf("%c",&c)) {
		if(c=='\n') {
			break;
		}
		//calloc����Ĵ�С�ռ�Ϊ�������������ĳ˻�
		pnew = (BiTree)calloc(1,sizeof(BiTNode));
		pnew->c=c;//���ݷŽ�ȥ
		listpnew=(ptag_t)calloc(1,sizeof(tag_t));//�����н������ռ�
		listpnew->p=pnew;
		if(NULL==tree) {
			tree=pnew;//���ĸ�
			phead=listpnew;//����ͷ
			ptail=listpnew;//����β
			pcur=listpnew;
			continue;
		} else {
			ptail->pnext=listpnew;//�½���������ͨ��β�巨
			ptail=listpnew;//ptail ָ�����β��
		}//pcur ʼ��ָ��Ҫ����Ľ���λ��
		if(NULL==pcur->p->lchild) { //��ΰ��½�������
			pcur->p->lchild=pnew;//���½��ŵ�Ҫ����������
		} else if(NULL==pcur->p->rchild) {
			pcur->p->rchild=pnew;//���½��ŵ�Ҫ��������ұ�
			pcur=pcur->pnext;//���Ҷ����˽���pcur ָ����е���һ��
		}
	}
//�������
	MiddleOrder(tree);
	printf("\n");
//��������
	PostOrder(tree);
	printf("\n");
//��α���
	LevelOrder(tree); 
}
