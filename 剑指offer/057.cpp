/*
��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null
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
