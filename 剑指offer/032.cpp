/*
{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//自己 
    int FindGreatestSumOfSubArray(vector<int> array) {
        int p=0,sum=0,res=array[0];		//res是最大和 
        while(p<array.size()){
            sum+=array[p];
            if(sum>res)		//sum记录i-j的和，若比res大,换 
                res=sum;
            if(sum<0)	//sum<0，丢弃i-j的和 
                sum=0;
            p++;
        }
        return res;
    }
    
    //牛客 F(i)=以array[i]为末尾元素的子数组的和的最大值
    //转移方程：F(i) = max( F(i-1)+array[i], arrray[i] )
	// resturn max( F(i) ) 
    int FindGreatestSumOfSubArray_1(vector<int> array) {
        int f = array[0]; //记录当前所有子数组的和的最大值
        int res=array[0];   //包含array[i]的连续数组最大值
        for (int i = 1; i < array.size(); i++) {
            f=max(f+array[i], array[i]);
            res=max(f, res);
        }
        return res;
    } 
};

int main(){
	vector<int> A = {-1,-2,-3,4,-6,7,-2,9};
	Solution solu;
	cout<<solu.FindGreatestSumOfSubArray_1(A)<<endl;
	return 0;
}
 
