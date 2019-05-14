/*
�������з�ת ��student. a am I��-> ��I am a student.�� 
*/ 

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	//�Լ� --�ݹ� 
    string ReverseSentence(string str) {
        int idx=0;
        if((idx=str.find(" "))!=string::npos)
            return ReverseSentence(str.substr(idx+1))+" "+str.substr(0,idx);
        return str;
    }
    
	// ţ���� ����ַ����� 
    string ReverseSentence_1(string str) {
        string res = "", tmp = "";
        for(unsigned int i = 0; i < str.size(); ++i){
            if(str[i] == ' ') res = " " + tmp + res, tmp = "";
            else tmp += str[i];
        }
        if(tmp.size()) res = tmp + res;	//���һ������ 
        return res;
    }
    
    //ţ���� ʱ��O(n),�ռ�O(1)�����η�ת����һ�����巭ת���ڶ���ÿ�������ٷ�ת
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
