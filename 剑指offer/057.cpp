/*
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        unordered_map<ListNode*,int> M;
        while(pHead){
            if(M[pHead]++==2)
                return pHead;
            pHead = pHead->next;
        }
        return NULL;
    }
};
