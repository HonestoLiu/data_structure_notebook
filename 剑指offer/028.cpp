/*
����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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
