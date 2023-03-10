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

//ǰ�����
void PreOrder(BiTree p) {
	if(NULL!=p) {
		printf("%c",p->c);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
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
//ǰ�����
	PreOrder(tree);
}
