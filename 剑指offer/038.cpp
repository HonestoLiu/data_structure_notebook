/*
输入两个链表，找出它们的第一个公共结点。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1 || !pHead2)    return NULL;
        stack<ListNode*> s1,s2;
        ListNode *p1=pHead1,*p2=pHead2;
        while(p1){
            s1.push(p1);
            p1=p1->next;
        }
        while(p2){
            s2.push(p2);
            p2=p2->next;
        }
        while(!s1.empty()&&!s2.empty()){
            if(s1.top()!=s2.top())
                return s1.top()->next;
            s1.pop();
            s2.pop();
        }
        if(!s1.empty())    return s1.top()->next;
        if(!s2.empty())    return s2.top()->next;
        return pHead1;
    }
};
