#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//自己写的 
    vector<int> printMatrix(vector<vector<int> > matrix) {
    	int h = matrix.size();
		int w = matrix[0].size();
		bool** p = new bool*[h+2];
		for(int i=0;i<h+2;i++)
			p[i] = new bool[w+2];
		for(int i=0;i<h+2;i++)
			for(int j=0;j<w+2;j++){
				if(i==0||i==h+1||j==0||j==w+1)
					p[i][j]=true;
				else
					p[i][j]=false;
			}
        vector<int> res;
        char c='r';
        int i=1,j=1;
        while(!p[i][j]){
        	res.push_back(matrix[i-1][j-1]);
        	p[i][j]=true;
        	switch(c){
        		case 'r':
        			if(!p[i][j+1])
        				j=j+1;
					else
						i=i+1,c='d';
					break;
				case 'd':
        			if(!p[i+1][j])
        				i=i+1;
					else
						j=j-1,c='l';
					break;
				case 'l':
        			if(!p[i][j-1])
        				j=j-1;
					else
						i=i-1,c='u';
					break;
				case 'u':
        			if(!p[i-1][j])
        				i=i-1;
					else
						j=j+1,c='r';
					break;
			}
		}
		return res;
    }
    
    // 牛客网参考1
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int>res;
        res.clear();
        int row=matrix.size();//行数
        int collor=matrix[0].size();//列数
        //计算打印的圈数
        int circle=((row<collor?row:collor)-1)/2+1;//圈数
        for(int i=0;i<circle;i++){
            //从左向右打印
            for(int j=i;j<collor-i;j++)
                res.push_back(matrix[i][j]);         
            //从上往下的每一列数据
            for(int k=i+1;k<row-i;k++)
                res.push_back(matrix[k][collor-1-i]);
            //判断是否会重复打印(从右向左的每行数据)
            for(int m=collor-i-2;(m>=i)&&(row-i-1!=i);m--)
                res.push_back(matrix[row-i-1][m]);
            //判断是否会重复打印(从下往上的每一列数据)
            for(int n=row-i-2;(n>i)&&(collor-i-1!=i);n--)
                res.push_back(matrix[n][i]);}
        return res;
    }
        
    // 牛客网参考2
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;
        // 输入的二维数组非法，返回空的数组
        if (row == 0 || col == 0)  return res;
        // 定义四个关键变量，表示左上和右下的打印范围
        int left = 0, top = 0, right = col - 1, bottom = row - 1;
        while (left <= right && top <= bottom)
        {
            // left to right
            for (int i = left; i <= right; ++i)  res.push_back(matrix[top][i]);
            // top to bottom
            for (int i = top + 1; i <= bottom; ++i)  res.push_back(matrix[i][right]);
            // right to left
            if (top != bottom)
            	for (int i = right - 1; i >= left; --i)  res.push_back(matrix[bottom][i]);
            // bottom to top
            if (left != right)
            	for (int i = bottom - 1; i > top; --i)  res.push_back(matrix[i][left]);
            left++,top++,right--,bottom--;
        }
        return res;
    } 
};

int main(){
	vector<vector<int> > A={{1,2,3,4},{2,3,4,5},{3,4,5,6}};
	Solution s;
	vector<int> B = s.printMatrix(A);
	for(int i=0;i<B.size();i++)
		cout<<B[i]<<" ";
	return 0;
}
