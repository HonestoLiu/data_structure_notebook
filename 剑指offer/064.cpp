/*
����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣���磬 ��5��3��7��2��4��6��8��    �У��������ֵ��С˳�����С����ֵΪ4��
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        //��������ĵ�k����
        
        if(k<1 || !pRoot)    return NULL;
        TreeNode* p = pRoot;
        stack<TreeNode*> S;
        int cnt=0;
        while(p || !S.empty()){
            if(p){
                S.push(p);
                p=p->left;
            }
            else{
                p = S.top();
                S.pop();
                if(++cnt == k)
                    return p;
                p = p->right;
            }
        }
        return NULL;
    }

    
};
