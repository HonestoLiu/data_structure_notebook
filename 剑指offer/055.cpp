/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/ 

class Solution {
public:
    bool isNumeric(char* string)
    {
        if(!string)	return false;
        std::string str(string);
        std::string s1,s2;
        int n1 = str.find_first_of("eE");//查找第一次出现‘e’或者‘E’的位置
        if(n1!=string::npos){
            s1=str.substr(0,n1);
            s2=str.substr(n1+1);
            return isDouble(s1)&&isInteger(s2);//有‘eE’则切成两部分，s1必须是数，s2必须是整数
        }
        return isDouble(str);//没有'Ee'则必须是数
    }
    
    //判断字符串是不是一个整数 
    bool isInteger(string s){
        if(s.empty()||s=="-"||s=="+")	return false;
        if(s[0]=='-' || s[0]=='+')	s=s.substr(1);
        for(int i=0;i<s.length();i++){
            if(s[i] <'0' || s[i] > '9')
                return false;
        }
        return true;
    }
    
    //判断字符串是不是一个数
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
