/*
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ�� 
����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
*/ 

class Solution {
public:
    bool isNumeric(char* string)
    {
        if(!string)	return false;
        std::string str(string);
        std::string s1,s2;
        int n1 = str.find_first_of("eE");//���ҵ�һ�γ��֡�e�����ߡ�E����λ��
        if(n1!=string::npos){
            s1=str.substr(0,n1);
            s2=str.substr(n1+1);
            return isDouble(s1)&&isInteger(s2);//�С�eE�����г������֣�s1����������s2����������
        }
        return isDouble(str);//û��'Ee'���������
    }
    
    //�ж��ַ����ǲ���һ������ 
    bool isInteger(string s){
        if(s.empty()||s=="-"||s=="+")	return false;
        if(s[0]=='-' || s[0]=='+')	s=s.substr(1);
        for(int i=0;i<s.length();i++){
            if(s[i] <'0' || s[i] > '9')
                return false;
        }
        return true;
    }
    
    //�ж��ַ����ǲ���һ����
    bool isDouble(string s){
        if(s.empty()||s=="-"||s=="+")	return false;
        if(s[0]=='-' || s[0]=='+')	s=s.substr(1);
        if(count(s.begin(),s.end(),'.')>1) return false;
        for(int i=0;i<s.length();i++){
            if((s[i] <'0' || s[i] > '9') && s[i]!='.')
                return false;
        }
        return true;
    }
};
