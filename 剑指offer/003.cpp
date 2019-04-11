/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，
输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

//思路：左下角或者右上角开始，动态规划 
#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
		bool Find(int target, vector<vector<int> > array){
			int len1 = array.size();	//行
			int len2 = array[0].size();	//列
			int row = len1-1, col = 0;
			while(row>=0 && col<len2){
				if(array[row][col] == target)
					return true;
				else if(array[row][col]>target)
					row--;
				else
					col++;
			}
			return false;
		}
};
int main(){
	vector<vector <int> > A = {{1,2,3,4},{4,6,7,9},{5,8,9,10}};
	Solution solu;
	if(solu.Find(12,A))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
