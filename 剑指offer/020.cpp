/*
操作给定的二叉树，将其变换为源二叉树的镜像。

二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot!=NULL){
            TreeNode* p = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = p;
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
    //非递归--树的层次遍历，访问函数是交换左右子树 
	void Mirror(TreeNode *pRoot) {
		queue<TreeNode*> q;
		if(pRoot!=NULL)
			q.push(pRoot);
		while(!q.empty()){
			TreeNode* p = q.front();
			TreeNode* tmp = p->left;
			p->left = p->right;
			p->right = tmp;
			q.pop();
			if(p->left!=NULL)
				q.push(p->left);
			if(p->right!=NULL)
				q.push(p->right);	
		}
	}
};
