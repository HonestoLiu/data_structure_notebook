/*
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead)    return NULL;
        ListNode* tmp = new ListNode(0);
        tmp->next = pHead;
        ListNode* p = tmp;
        ListNode* q = p;
        while(p->next){
            q = p->next;
            if(q->next!=NULL && q->next->val==q->val){
                while(q->next!=NULL && q->next->val==q->val){
                    q = q->next;
                    p->next = q->next;
                }
            }
            else p = p->next;
        }
        return tmp->next;
    }
};
