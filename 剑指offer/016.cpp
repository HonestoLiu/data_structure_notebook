/*
����һ����������������е�����k����㡣
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
	// ţ����������  p����k����Ȼ��p��qһ���ߣ���p�ߵ�ĩβ��q���ߵ�����k 
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
