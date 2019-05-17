/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，
每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的
 第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/ 

#include <iostream>
using namespace std;
/**
用一个状态数组保存之前访问过的字符，然后再分别按上，下，左，右递归
*/
class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str) {
        bool* flag = new bool[rows*cols]();
        int str_len=0;
        while(*(str+str_len)!='\0')
        	str_len++;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (helper(matrix, rows, cols, i, j, str,str_len, 0, flag))
                    return true;
            }
        }
        return false;
    }
private:
	bool helper(char* matrix, int rows, int cols, int i, int j, char* str,int str_len, int k, bool* flag) {
        int index = i * cols + j;
        if (i < 0 || i >= rows || j < 0 || j >= cols || *(matrix+index) != *(str+k) || *(flag+index))
            return false;
        if(k + 1 == str_len) return true; 
        *(flag+index) = 1;
        if (helper(matrix, rows, cols, i - 1, j, str,str_len, k + 1, flag)
                || helper(matrix, rows, cols, i + 1, j, str,str_len, k + 1, flag)
                || helper(matrix, rows, cols, i, j - 1, str,str_len, k + 1, flag)
                || helper(matrix, rows, cols, i, j + 1, str,str_len, k + 1, flag)) {
            return true;
        }
        *(flag+index) = 0;
        return false;
    }
};

int main(){
	char* matrix = "abcesfcsadee";
	char* str = "ese";
	Solution solu;
	cout<<solu.hasPath(matrix,3,4,str);
	return 0;
}
