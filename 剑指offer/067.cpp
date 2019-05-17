/*
�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·�����ԴӾ����е�����һ�����ӿ�ʼ��
ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ����һ��·�������˾����е�ĳһ�����ӣ���֮�����ٴν���������ӡ�
 ���� a b c e s f c s a d e e ������3 X 4 �����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·������Ϊ�ַ�����
 ��һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�
*/ 

#include <iostream>
using namespace std;
/**
��һ��״̬���鱣��֮ǰ���ʹ����ַ���Ȼ���ٷֱ��ϣ��£����ҵݹ�
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
