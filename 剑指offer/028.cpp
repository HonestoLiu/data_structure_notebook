/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree)    return NULL;
        vector<TreeNode*> V;
        stack<TreeNode*> S;
        TreeNode* p = pRootOfTree;
        while(p || !S.empty()){
            if(p){
                S.push(p);
                p=p->left;
            }
            else{
                p=S.top();
                V.push_back(p);
                S.pop();
                p=p->right;
            }
        }
        for(int i=0;i<V.size();i++){
            V[i]->left = (i==0)?NULL:V[i-1];
            V[i]->right = (i==V.size()-1)?NULL:V[i+1];
        }
        return V[0];
    }
};
