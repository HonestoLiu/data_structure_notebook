/*
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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
    //递归 
    int TreeDepth(TreeNode* pRoot){
        if(pRoot==NULL)
            return 0;
        return 1 + max(TreeDepth(pRoot->left),TreeDepth(pRoot->right));
    }
    //非递归
    int TreeDepth(TreeNode* pRoot)
    {
		if(!pRoot)	return 0;
		queue<TreeNode*> q;
		q.push(pRoot);
		int depth = 0;
		while(!q.empty()){
			int size = q.size();
			depth++;
			while(size--){
				TreeNode* p = q.front();
				q.pop();
				if(p->left)	q.push(p->left);
				if(p->right) q.push(p->right);
			}
		}
		return depth;
    }
};
