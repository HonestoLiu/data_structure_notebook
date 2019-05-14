/*
单词序列反转 “student. a am I”-> “I am a student.” 
*/ 

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	//自己 --递归 
    string ReverseSentence(string str) {
        int idx=0;
        if((idx=str.find(" "))!=string::npos)
            return ReverseSentence(str.substr(idx+1))+" "+str.substr(0,idx);
        return str;
    }
    
	// 牛客网 逐个字符处理 
    string ReverseSentence_1(string str) {
        string res = "", tmp = "";
        for(unsigned int i = 0; i < str.size(); ++i){
            if(str[i] == ' ') res = " " + tmp + res, tmp = "";
            else tmp += str[i];
        }
        if(tmp.size()) res = tmp + res;	//最后一个单词 
        return res;
    }
    
    //牛客网 时间O(n),空间O(1)。两次翻转，第一次整体翻转，第二次每个单词再翻转
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        string::size_type s = 0, e;       
        while((e=str.find(' ', s)) != string::npos){
            reverse(str.begin()+s, str.begin()+e);
            s = e + 1;
        }
        reverse(str.begin()+s, str.end());
        return str;
    }
    
};

int main(){
	string s=" A";
	Solution solu;
	cout<<solu.ReverseSentence(s)<<endl;
	return 0;
}
