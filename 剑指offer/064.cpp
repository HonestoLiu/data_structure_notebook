/*
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
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
        //先序遍历的第k个数
        
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
