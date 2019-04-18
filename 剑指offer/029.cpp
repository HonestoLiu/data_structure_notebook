/*
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��
*/ 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
class Solution {
public:
    vector<string> Permutation(string str) {
        int len = str.length();
        vector<string> res;
        if(len==1){
            res.push_back(str);
            return res;
        }
        for(int i=0;i<len;i++){
            swap(str[0],str[i]);
            vector<string> Sub = Permutation(str.substr(1));
            for(int j=0;j<Sub.size();j++){
                string s = str[0]+Sub[j];
                res.push_back(s);
            }
            swap(str[i],str[0]);
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());	//ȥ�� 
        return res;
    }
};
int main(){
	string s="dbaa";
	Solution Solu;
	vector<string> r = Solu.Permutation(s);
	cout<<r.size()<<endl;
	for(int i=0;i<r.size();i++)
		cout<<r[i]<<endl;
	return 0;
}
