/*
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行
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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > Res;
            vector<int> tmp;
            if(!pRoot)    return Res;
            queue<TreeNode*> Q;
            Q.push(pRoot);
            int size = 0;
            TreeNode* p = pRoot;
            while(!Q.empty()){
                size=Q.size();
                tmp.clear();
                while(size--){
                    p = Q.front();
                    tmp.push_back(p->val);
                    if(p->left)
                        Q.push(p->left);
                    if(p->right)
                        Q.push(p->right);
                    Q.pop();
                }
                Res.push_back(tmp);
            }
            return Res;
        }
    
};
