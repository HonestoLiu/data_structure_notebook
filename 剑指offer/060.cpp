/*
��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
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
    //�ǵݹ�д��
    bool isSymmetrical(TreeNode* pRoot){
        if(pRoot == NULL) return true;
        stack<TreeNode*> s;
        s.push(pRoot->left);
        s.push(pRoot->right);
        while(!s.empty()) {
            TreeNode* right = s.top();
            s.pop();
            TreeNode* left = s.top();
            s.pop();
            if(left == NULL && right == NULL) continue;
            if(left == NULL || right == NULL) return false;
            if(left->val != right->val) return false;
            s.push(left->left);
            s.push(right->right);
            s.push(left->right);
            s.push(right->left);
        }
        return true;
    }
    //�ݹ�д��
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot) return true;
        return LeftAndRight(pRoot->left,pRoot->right);
    }
    bool LeftAndRight(TreeNode* p1,TreeNode* p2){
        if(p1==NULL)    return p2==NULL;
        if(p2==NULL)    return false;
        if(p1->val != p2->val)    return false;
        return LeftAndRight(p1->left,p2->right) && LeftAndRight(p1->right,p2->left);
    }
};


