/*
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x):val(x),next(NULL){
	}
};

class Solution {
public:
	//用stl reverse函数 
	//运行时间：5ms 占用内存：504k
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        ListNode* p = head;
        while(p!=NULL){
            res.push_back(p->val);
            p = p->next;
        }
        reverse(res.begin(),res.end());
        return res;
    }
	
	// 反转链表 
    vector<int> printListFromTailToHead_1(ListNode* head) {
        vector<int> res;
//      ListNode* p = Reverse_1(head);
//		ListNode* p = Reverse_2(head);
		ListNode* p = Reverse_3(head); 
        while(p!=NULL){
            res.push_back(p->val);
            p = p->next;
        }
        return res;
    }
    
    // 方法1：从第2个节点到第N个节点，依次逐节点插入到第1个节点(head节点)之后，(N-1)次这样的操作结束之后,将第1个节点挪到新表的表尾即可
	ListNode* Reverse_1(ListNode* head){
		ListNode* p = head->next;	//2
		ListNode* q;
		while(p->next!=NULL){
			// 1->2->3->4 换成 1->3->2->4 
			q = p->next;	//3
			p->next = q->next;	//2->4
			q->next = head->next;	//3->2
			head->next = q;	//1->3
		} 
		// 1->4->3->2 换成 4->3->2->1,此时p是表尾 
		p->next = head;		//2->1
		head = head->next;	//head->4
		p->next->next = NULL; 	//1->NULL
		return head;
	}
	  
	// 方法2：不断从后面的链剥离一个加入到前链  new_head为前链的头指针（初始当然就为NULL），head为后链的头指针（待剥离的元素）
	// next为剥离后的后链的头指针，我们拆的是head-next这条链
	ListNode* Reverse_2(ListNode* head){
		ListNode* next = NULL;
		ListNode* new_head = NULL;
		while(head!=NULL){
			next = head->next;	//断链，存下后链的头指针
			head->next = new_head;	//断下的元素指向前链的头
			new_head = head;	//前链的头更新了，更新为刚刚插入的元素
			head = next;	//head回归为后链的头指针 
		}
		return new_head; 
	} 
	
	// 方法3：递归--逻辑简单 
	ListNode* Reverse_3(ListNode* head){
		if(head==NULL||head->next==NULL)
			return head;
		ListNode* new_head = Reverse_3(head->next);		//new_head为子链的头指针 
		head->next->next = head;	//head->next->next为子链的尾指针 
		head->next = NULL;
		return new_head;
	}
};

int main(){
	ListNode a(10),b(5),c(9),d(100);
	ListNode* head = &a;
	ListNode* p = head;
	p->next = &b;
	p = p->next;
	p->next = &c;
	p = p->next;
	p->next = &d;
	Solution solu;
//	vector<int> result = solu.printListFromTailToHead(head);
	vector<int> result = solu.printListFromTailToHead_1(head);
	for(auto x:result)
		cout<<x<<endl;
	return 0;
}
