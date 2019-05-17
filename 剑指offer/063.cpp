/*
请实现两个函数，分别用来序列化和反序列化二叉树
*/ 

//遇到空节点标记'#'，遇到数字'value,' 

class Solution {  
public:
    char* Serialize(TreeNode *root) {
       if(root == NULL)
           return NULL;
        string str;
        Serialize(root, str);
        int len = str.length();
        char *ret = new char[len + 1];
        for(int i = 0; i < len; i++)
            ret[i] = str[i];
        ret[len] = '\0';
        return ret;
    }
    void Serialize(TreeNode *root, string& str){//引用 
        if(root == NULL){
            str += '#';
            return ;
        }
        string r = to_string(root->val);
        str += r+',';
        Serialize(root->left, str);
        Serialize(root->right, str);
    }
     
    TreeNode* Deserialize(char *str) {
        if(str == NULL)
            return NULL;
        return Deserialize(&str);
    }
    
    TreeNode* Deserialize(char* &str){//对str做++操作，传引用 
        if(*str == '#'){  
            ++str;         
            return NULL;
        }
        int num = 0;
        while(*str != '\0' && *str != ','){
            num = num*10 + (*str - '0');
            ++str;
        }
        TreeNode *root = new TreeNode(num);
        if(*str == '\0')
            return root;
        else
            str++;
        root->right = Deserialize(str);
        return root;
    }
};
