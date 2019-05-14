#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	
	// ������Ӵ����Ӵ�Ҫ����ԭ�ַ��������� 
	// ��F[i][j]��ʾ��x[i] y[j]��β��������Ӵ��ĳ���
	// ת�Ʒ��̣�F[i][j]= (x[i]==y[j])?(F[i-1][j-1]+1):0; 
	int longestSubstring(string x, string y) {
   		vector<vector<int> > f(x.size() + 1, vector<int>(y.size() + 1, 0));
   		int res = -1;
   		for (int i = 1; i <= x.size(); i++) {
       		for (int j = 1; j <= y.size(); j++) {
       			f[i][j] = x[i]==y[j]?(f[i-1][j-1]+1):0;
           		res = max(res,f[i][j]);
       		}
		}
    	return res;
	}
	
	// ����������У�������Ҫ�������˳��һ�£�����Ҫ������ 
	// ��F[i][j]��ʾx[i]-y[j]ǰ������������еĳ���
	// ת�Ʒ��̣�F[i][j]= (x[i]==y[j])? (F[i-1][j-1]+1): max( F[i-1][j], F[i][j-1]); 
	int longestSubsequence(string x, string y) {
		vector<vector<int> > f(x.size() + 1, vector<int>(y.size() + 1, 0));
    	for (int i = 1; i <= x.size(); i++) {
        	for (int j = 1; j <= y.size(); j++) {
            	if (x[i] == y[j])
                	f[i][j] = f[i-1][j-1]+1;
            	else 
                	f[i][j] = max(f[i-1][j], f[i][j-1]);
        	}
    	}
    	return f[x.size()][y.size()];
	}
};

int main(){
	string s1 = "avfrdaaaf abc";
	string s2 = "a frad abcaaaa";
	Solution solu;
	cout<<solu.longestSubstring(s1,s2)<<endl;
	cout<<solu.longestSubsequence(s1,s2)<<endl;
	return 0;
}
 
