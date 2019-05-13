/*
����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
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
