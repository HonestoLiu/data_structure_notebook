/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
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
        res.erase(unique(res.begin(),res.end()),res.end());	//去重 
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
