#include <iostream>
#include <stack>
#include <queue>
using namespace std;
 
//��������� binary tree node 
typedef struct BiTNode{
	char data;		//����
	struct BiTNode *lchild,*rchild;		//���Һ���ָ��
}BiTNode,*BiTree;
 
//���������д���������
int CreateBiTree(BiTree &T){	//��Ҫ�޸ĵ�ַ��ָ�򣬹�ʹ�õ�ַ������ 
	char data;	//�������������������н���ֵ��һ���ַ�������#����ʾ����
	scanf("%c",&data);
	if(data == '#')
		T = NULL;
	else{
		T = (BiTree)malloc(sizeof(BiTNode));	//���ɸ����
		T->data = data;
		CreateBiTree(T->lchild);	//����������
		CreateBiTree(T->rchild);	//����������
	}
	return 0;
}

//���ʺ���--��� 
void Visit(BiTree T){
	if(T->data != '#')
		printf("%c ",T->data);
}

//1.�������
void PreOrder(BiTree T){
	if(T != NULL){
		Visit(T);				//���ʸ��ڵ�
		PreOrder(T->lchild);	//�������ӽ��
		PreOrder(T->rchild);	//�������ӽ��
	}
}

//2.�������  
void InOrder(BiTree T){  
    if(T != NULL){  
        InOrder(T->lchild);		//�������ӽ�� 
        Visit(T);   			//���ʸ��ڵ�    
        InOrder(T->rchild);		//�������ӽ��
    }  
}  

//3.�������
void PostOrder(BiTree T){
	if(T != NULL){
		PostOrder(T->lchild);	//�������ӽ��
		PostOrder(T->rchild);	//�������ӽ��
		Visit(T);				//���ʸ��ڵ�
	}
}

/* 1.�������(�ǵݹ�)
   ˼·������T->data�󣬽�T��ջ������������������������������ʱ��ջ��Ԫ��ӦΪT����ջ�����������T����������
*/
void PreOrder2(BiTree T){
	stack<BiTree> stack;
	BiTree p = T;	//p�Ǳ���ָ��
	while(p || !stack.empty()){		//ջ���ջ���p����ʱѭ��
		if(p != NULL){	//�ǿգ�����ջ�У��������������� 
			stack.push(p);
			printf("%c ",p->data);
			p = p->lchild;
		}
		else{	//�գ������ϲ㣬��ջ 
			p = stack.top();
			stack.pop();
			p = p->rchild;	//����������
		}
	}//while
}

/* 2.�������(�ǵݹ�)
   ˼·��T��Ҫ�������ĸ�ָ�룬�������Ҫ���ڱ������������󣬷��ʸ����ٱ�����������
         �Ƚ�T��ջ������������������������������ʱ��ջ��Ԫ��ӦΪT����ջ������T->data�����������T����������
*/
void InOrder2(BiTree T){
	stack<BiTree> stack;
	BiTree p = T;	//p�Ǳ���ָ��
	while(p || !stack.empty()){		//ջ���ջ���p����ʱѭ��
		if(p != NULL){	//�ǿգ�����ջ�У��������������� 
			stack.push(p);
			p = p->lchild;
		}
		else{	//�գ����ʸ��ڵ㣬��ջ�������ҽڵ� 
			p = stack.top();
			printf("%c ",p->data);
			stack.pop();
			p = p->rchild;
		}
	}//while
}
 
//�������(�ǵݹ�)
typedef struct BiTNodePost{
	BiTree biTree;
	char tag;
}BiTNodePost,*BiTreePost;
 
void PostOrder2(BiTree T){
	stack<BiTreePost> stack;
	BiTree p = T;	//p�Ǳ���ָ��
	BiTreePost BT;
	//ջ���ջ���p����ʱѭ��
	while(p != NULL || !stack.empty()){
		//����������
		while(p != NULL){
			BT = (BiTreePost)malloc(sizeof(BiTNodePost));
			BT->biTree = p;
			//���ʹ�������
			BT->tag = 'L';
			stack.push(BT);
			p = p->lchild;
		}
		//��������������Ϸ��ʸ��ڵ�
		while(!stack.empty() && (stack.top())->tag == 'R'){
			BT = stack.top();
			//��ջ
			stack.pop();
			printf("%c ",BT->biTree->data);
		}
		//����������
		if(!stack.empty()){
			BT = stack.top();
			//���ʹ�������
			BT->tag = 'R';
			p = BT->biTree;
			p = p->rchild;
		}
	}//while
}

//��α���
void LevelOrder(BiTree T){
	queue<BiTree> queue;
	BiTree p = T;	//����ָ�� 
	queue.push(p);	//���ڵ����
	while(!queue.empty()){	//���в���ѭ��
		p = queue.front();
		printf("%c ",p->data);		//����pָ��Ľ��
		queue.pop();				//�˳�����
		if(p->lchild != NULL)		//���������գ������������
			queue.push(p->lchild);
		if(p->rchild != NULL)		//���������գ������������
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

