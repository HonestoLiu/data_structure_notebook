/*
���������Ķ�����������任ΪԴ�������ľ���

�������ľ����壺Դ������ 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	���������
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
	//�ݹ� 
    void Mirror(TreeNode *pRoot) {
        if(pRoot!=NULL){
            TreeNode* p = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = p;
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
    //�ǵݹ�--���Ĳ�α��������ʺ����ǽ����������� 
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
