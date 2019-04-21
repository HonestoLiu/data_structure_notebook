/*
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
���ؽ��Ϊ���ƺ��������head����ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
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
	// �Լ�д�����Ƚ�ԭ����random��ָ�Ľڵ��index��������Ȼ����������ָ���ڵ��random 
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
 	// ţ����д�� 
    /*
        1������ÿ���ڵ㣬�磺���ƽڵ�A�õ�A1����A1����ڵ�A����
        2����������A1->random = A->random->next;
        3���������ֳ�ԭ����͸��ƺ������
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
        //���
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
