/*
��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ��
�����а��մ����ҵ�˳���ӡ���������Դ����ơ�
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
            int size = 0,depth=0;
            TreeNode* p = pRoot;
            while(!Q.empty()){
                size=Q.size();
                depth++;
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
                //if(depth%2==0) reverse(tmp.begin(),tmp.end());
                if((depth&1)==0) reverse(tmp.begin(),tmp.end());
                Res.push_back(tmp);
            }
            return Res;
    }
    
};
