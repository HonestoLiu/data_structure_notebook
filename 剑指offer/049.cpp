/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/ 

class Solution {
public:
	//牛客网 --递归 
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1)); //&&逻辑判断 
        return ans;
    }
    // 自己（不会） 
    int Sum_Solution(int n) {
        return ((int)pow(n,2)+n)>>1;
    }
};

