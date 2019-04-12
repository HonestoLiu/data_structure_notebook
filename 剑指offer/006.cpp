/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回
*/

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty())
            return NULL;
        TreeNode* root = new TreeNode(pre[0]);	//指针必须指向对象，故需new 
        vector<int> left_pre, right_pre, left_vin, right_vin;
        int index = 0;
        while(vin[index]!=pre[0])
            index++;
        left_pre.insert(left_pre.begin(),pre.begin()+1,pre.begin()+1+index);
        right_pre.insert(right_pre.begin(),pre.begin()+index+1,pre.end());
        left_vin.insert(left_vin.begin(),vin.begin(),vin.begin()+index);
        right_vin.insert(right_vin.begin(),vin.begin()+index+1,vin.end());
        root->left = reConstructBinaryTree(left_pre,left_vin);
        root->right = reConstructBinaryTree(right_pre,right_vin);
        return root;
    }
};
