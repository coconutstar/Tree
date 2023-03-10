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

//前序遍历
void PreOrder(BiTree p) {
	if(NULL!=p) {
		printf("%c",p->c);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
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
//前序遍历
	PreOrder(tree);
}
