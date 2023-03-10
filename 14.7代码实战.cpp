#include <stdio.h>
#include <stdlib.h>
//二叉树 
typedef int BiElemType;
typedef struct BiTNode {
	BiElemType weight;//c 就是数集上的 data
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode,*BiTree;
//tag 结构体是辅助队列使用的
typedef struct tag {
	BiTree p;//树的某一个结点的地址值
	struct tag *pnext;
} tag_t,*ptag_t;

//int wpl = 0;
//前序遍历
int PreOrder(BiTree p,int deep) {
	static int wpl;//初始化一次 
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
		BiTree pnew;//用来指向新申请的数节点
	BiTree tree = NULL; //指向树根，代表树
	int c;
	ptag_t phead=NULL,ptail=NULL,listpnew=NULL,pcur;
	//abcdefghij
	while(scanf("%d",&c)) {
		if(c==99) {
			break;
		}
		//calloc申请的大小空间为下面两个参数的乘积
		pnew = (BiTree)calloc(1,sizeof(BiTNode));
		pnew->weight=c;//数据放进去
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

	//前序遍历
	printf("------------PreOrder-----------------\n");
	printf("\n");
	//wpl指的是路径 
	printf("wpl为：%d",	PreOrder(tree,0));
	return 0;
} 
