#include <iostream>
#include <stack>
#include <queue>
using namespace std;
 
//二叉树结点 binary tree node 
typedef struct BiTNode{
	char data;		//数据
	struct BiTNode *lchild,*rchild;		//左右孩子指针
}BiTNode,*BiTree;
 
//按先序序列创建二叉树
int CreateBiTree(BiTree &T){	//需要修改地址的指向，故使用地址的引用 
	char data;	//按先序次序输入二叉树中结点的值（一个字符），‘#’表示空树
	scanf("%c",&data);
	if(data == '#')
		T = NULL;
	else{
		T = (BiTree)malloc(sizeof(BiTNode));	//生成根结点
		T->data = data;
		CreateBiTree(T->lchild);	//构造左子树
		CreateBiTree(T->rchild);	//构造右子树
	}
	return 0;
}

//访问函数--输出 
void Visit(BiTree T){
	if(T->data != '#')
		printf("%c ",T->data);
}

//1.先序遍历
void PreOrder(BiTree T){
	if(T != NULL){
		Visit(T);				//访问根节点
		PreOrder(T->lchild);	//访问左子结点
		PreOrder(T->rchild);	//访问右子结点
	}
}

//2.中序遍历  
void InOrder(BiTree T){  
    if(T != NULL){  
        InOrder(T->lchild);		//访问左子结点 
        Visit(T);   			//访问根节点    
        InOrder(T->rchild);		//访问右子结点
    }  
}  

//3.后序遍历
void PostOrder(BiTree T){
	if(T != NULL){
		PostOrder(T->lchild);	//访问左子结点
		PostOrder(T->rchild);	//访问右子结点
		Visit(T);				//访问根节点
	}
}

/* 1.先序遍历(非递归)
   思路：访问T->data后，将T入栈，遍历左子树；遍历完左子树返回时，栈顶元素应为T，出栈，再先序遍历T的右子树。
*/
void PreOrder2(BiTree T){
	stack<BiTree> stack;
	BiTree p = T;	//p是遍历指针
	while(p || !stack.empty()){		//栈不空或者p不空时循环
		if(p != NULL){	//非空，存入栈中，继续遍历左子树 
			stack.push(p);
			printf("%c ",p->data);
			p = p->lchild;
		}
		else{	//空，退至上层，出栈 
			p = stack.top();
			stack.pop();
			p = p->rchild;	//访问右子树
		}
	}//while
}

/* 2.中序遍历(非递归)
   思路：T是要遍历树的根指针，中序遍历要求在遍历完左子树后，访问根，再遍历右子树。
         先将T入栈，遍历左子树；遍历完左子树返回时，栈顶元素应为T，出栈，访问T->data，再中序遍历T的右子树。
*/
void InOrder2(BiTree T){
	stack<BiTree> stack;
	BiTree p = T;	//p是遍历指针
	while(p || !stack.empty()){		//栈不空或者p不空时循环
		if(p != NULL){	//非空，存入栈中，继续遍历左子树 
			stack.push(p);
			p = p->lchild;
		}
		else{	//空，访问根节点，退栈，访问右节点 
			p = stack.top();
			printf("%c ",p->data);
			stack.pop();
			p = p->rchild;
		}
	}//while
}
 
//后序遍历(非递归)
typedef struct BiTNodePost{
	BiTree biTree;
	char tag;
}BiTNodePost,*BiTreePost;
 
void PostOrder2(BiTree T){
	stack<BiTreePost> stack;
	BiTree p = T;	//p是遍历指针
	BiTreePost BT;
	//栈不空或者p不空时循环
	while(p != NULL || !stack.empty()){
		//遍历左子树
		while(p != NULL){
			BT = (BiTreePost)malloc(sizeof(BiTNodePost));
			BT->biTree = p;
			//访问过左子树
			BT->tag = 'L';
			stack.push(BT);
			p = p->lchild;
		}
		//左右子树访问完毕访问根节点
		while(!stack.empty() && (stack.top())->tag == 'R'){
			BT = stack.top();
			//退栈
			stack.pop();
			printf("%c ",BT->biTree->data);
		}
		//遍历右子树
		if(!stack.empty()){
			BT = stack.top();
			//访问过右子树
			BT->tag = 'R';
			p = BT->biTree;
			p = p->rchild;
		}
	}//while
}

//层次遍历
void LevelOrder(BiTree T){
	queue<BiTree> queue;
	BiTree p = T;	//遍历指针 
	queue.push(p);	//根节点入队
	while(!queue.empty()){	//队列不空循环
		p = queue.front();
		printf("%c ",p->data);		//访问p指向的结点
		queue.pop();				//退出队列
		if(p->lchild != NULL)		//左子树不空，将左子树入队
			queue.push(p->lchild);
		if(p->rchild != NULL)		//右子树不空，将右子树入队
			queue.push(p->rchild);
	}
}

int main()
{
	BiTree T;
	CreateBiTree(T);
	
	printf("PreOrder traversal: \n");
	PreOrder(T);
	printf("\n");
	printf("PreOrder traversal(Non-recursive): \n");
	PreOrder2(T);
	printf("\n");
	printf("InOrder traversal: \n");
	InOrder(T);
	printf("\n");
	printf("InOrder traversal(Non-recursive): \n");
	InOrder2(T);
	printf("\n");
	printf("PostOrder traversal: \n");
	PostOrder(T);
	printf("\n");
	printf("PostOrder traversal(Non-recursive): \n");
	PostOrder2(T);
	printf("\n");
	printf("Level traversal: \n");
	LevelOrder(T);
	printf("\n");
    return 0;
}

