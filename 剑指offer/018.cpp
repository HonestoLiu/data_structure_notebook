/*
���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* q = new ListNode(0);	//�½���ͷ 
        ListNode* res =q;
        while(pHead1 || pHead2){
            if(pHead1&&pHead2){
                if(pHead1->val<pHead2->val){
                    q->next = pHead1;
                    pHead1=pHead1->next;
                }
                else{
                    q->next = pHead2;
                    pHead2 = pHead2->next;
                }
                q = q->next;
            }
            else if(pHead1){
                q->next = pHead1;
                break;
            }
            else{
                q->next = pHead2;
                break;
            }
        }
        return res->next;
    }
};
