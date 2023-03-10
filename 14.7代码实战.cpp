#include <stdio.h>
#include <stdlib.h>
//������ 
typedef int BiElemType;
typedef struct BiTNode {
	BiElemType weight;//c ���������ϵ� data
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode,*BiTree;
//tag �ṹ���Ǹ�������ʹ�õ�
typedef struct tag {
	BiTree p;//����ĳһ�����ĵ�ֵַ
	struct tag *pnext;
} tag_t,*ptag_t;

//int wpl = 0;
//ǰ�����
int PreOrder(BiTree p,int deep) {
	static int wpl;//��ʼ��һ�� 
	if(NULL!=p) {
//		printf("%d,deep:%d\n",p->weight,deep);
        if(p->lchild==NULL&&p->rchild==NULL){
        	wpl = wpl+p->weight*deep;
		}
		PreOrder(p->lchild,deep+1);
		PreOrder(p->rchild,deep+1);
	}
	return wpl;
}

int main(){
		BiTree pnew;//����ָ������������ڵ�
	BiTree tree = NULL; //ָ��������������
	int c;
	ptag_t phead=NULL,ptail=NULL,listpnew=NULL,pcur;
	//abcdefghij
	while(scanf("%d",&c)) {
		if(c==99) {
			break;
		}
		//calloc����Ĵ�С�ռ�Ϊ�������������ĳ˻�
		pnew = (BiTree)calloc(1,sizeof(BiTNode));
		pnew->weight=c;//���ݷŽ�ȥ
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
	printf("------------PreOrder-----------------\n");
	printf("\n");
	//wplָ����·�� 
	printf("wplΪ��%d",	PreOrder(tree,0));
	return 0;
} 
