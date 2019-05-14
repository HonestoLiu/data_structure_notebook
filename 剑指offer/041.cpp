/*
����һ�ö��������жϸö������Ƿ���ƽ���������
*/

//�Լ���ÿ���ڵ�����˶�Σ����Ӷȸ� 
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot)    return true;
        int left_d = Depth(pRoot->right);
        int right_d = Depth(pRoot->left);
        bool legal_depth = (abs(left_d-right_d)<=1);
        return legal_depth && IsBalanced_Solution(pRoot->right) && IsBalanced_Solution(pRoot->left);
    }
    int Depth(TreeNode* pRoot){
        if(!pRoot)    return 0;
        return 1 + max(Depth(pRoot->right),Depth(pRoot->left));
    }
};
//ţ�������ݹ�д��
public class Solution {
    public boolean IsBalanced_Solution(TreeNode root) {
        return getDepth(root) != -1;
    }
     
    private int getDepth(TreeNode root) {
        if (root == null) return 0;
        int left = getDepth(root.left);
        if (left == -1) return -1;
        int right = getDepth(root.right);
        if (right == -1) return -1;
        return Math.abs(left - right) > 1 ? -1 : 1 + Math.max(left, right);
    }
} 
