/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/ 
#include <iostream>
#include <vector>
using namespace std; 

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
	// 自己写法，先将原链的random所指的节点的index存下来，然后在新链中指定节点的random 
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
        vector<RandomListNode*> Node;
        vector<RandomListNode*> c_Node;
        vector<int> Index;
        RandomListNode* c_Head = new RandomListNode(pHead->label);
        RandomListNode* p = pHead;
        RandomListNode* c_p = c_Head;
        while(p->next!=NULL){
            Node.push_back(p);
            p = p->next;
            c_p->next = new RandomListNode(p->label);
            c_Node.push_back(c_p);
            c_p = c_p->next;
        }
        Node.push_back(p);
        c_Node.push_back(c_p);
        p = pHead,c_p = c_Head;
        while(p!=NULL){
            if(p->random==NULL)
                Index.push_back(-1);
            else{
                for(int i=0;i<Node.size();i++){
                    if(p->random==Node[i])
                        Index.push_back(i);
                }
            }
            p = p->next;
        }
        for(int j =0;j<Index.size();j++){
            if(Index[j]==-1)
                c_p->random=NULL;
            else
                c_p->random = c_Node[Index[j]];
            c_p = c_p->next;
        }
        return c_Head;
    }
 	// 牛客网写法 
    /*
        1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
        2、遍历链表，A1->random = A->random->next;
        3、将链表拆分成原链表和复制后的链表
    */
     
    RandomListNode* Clone_1(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        RandomListNode *currNode = pHead;
        while(currNode){
            RandomListNode *node = new RandomListNode(currNode->label);
            node->next = currNode->next;
            currNode->next = node;
            currNode = node->next;
        }
        currNode = pHead;
        while(currNode){
            RandomListNode *node = currNode->next;
            if(currNode->random){               
                node->random = currNode->random->next;
            }
            currNode = node->next;
        }
        //拆分
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *tmp;
        currNode = pHead;
        while(currNode->next){
            tmp = currNode->next;
            currNode->next =tmp->next;
            currNode = tmp;
        }
        return pCloneHead;
    }   
};

int main(){
	RandomListNode a(1);
	RandomListNode b(2);
	RandomListNode c(3);
	a.next = &b;
	b.next = &c;
	a.random = &a;
	b.random = &c;
	c.random = &b;
	RandomListNode* p = &a;
	Solution solu;
	RandomListNode* c_p = solu.Clone(p);
	while(c_p!=NULL){
		cout<<c_p->random->label<<" ";
		c_p = c_p->next;
	}

	return 0;
}
