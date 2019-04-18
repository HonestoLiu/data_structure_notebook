/*
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root!=NULL)
            q.push(root);
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            res.push_back(p->val);
            if(p->left!=NULL)
                q.push(p->left);
            if(p->right!=NULL)
                q.push(p->right);
        }
        return res;
    }
};
