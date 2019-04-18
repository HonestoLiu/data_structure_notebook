/*
输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        int len=0;
        ListNode* p = pListHead;
        while(p){
            len++;
            p=p->next;
        }
        if(k==0||k>len)
            return NULL;
        int count=len-k;
        p = pListHead;
        while(count--)
            p = p->next;
        return p;
    }
	// 牛客网简洁代码  p先走k步，然后p、q一起走，当p走到末尾，q就走到倒数k 
	public ListNode FindKthToTail(ListNode head,unsigned int k) {
        ListNode p, q;
        p = q = head;
        int i = 0;
        for (; p != NULL; i++) {
            if (i >= k)
                q = q.next;
            p = p.next;
        }
        return i < k ? null : q;
    }
};
