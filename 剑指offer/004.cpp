/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/ 

#include<iostream>
#include<string.h>
using namespace std;

class Solution{
	public:
		// 直接采用string replace函数 
		void replaceSpace(char *str, int length){
			string s(str);	//string s = str; char* 可直接赋值给string
			int index = -1;
			while((index=s.find(' '))!=string::npos)
				s.replace(index,1,"%20");
			strcpy(str, s.c_str()); 
		}
		// 从后往前替换，先计算总的空格数，只用移动一次
		//运行时间：5ms 占用内存：588k
		void replaceSpace_1(char *str, int length){
			int count = 0;
			for(int i=0;i<length;i++){
				if(str[i]==' ')
					count++;
			}
			for(int j=length-1;j>=0;j--){
				if(str[j]!=' ')
					str[j+count*2] = str[j];
				else{
					count--;
					str[j+count*2] = '%';
					str[j+count*2+1] = '2';
					str[j+count*2+2] = '0';
				}
			}
		}
		// 从前往后替换  不止一次替换 
		// 运行时间：4ms 占用内存：408k
		void replaceSpace_2(char *str, int length){
			int i = 0;
			while(str[i]!='\0'){
				if(str[i]==' '){
					for(int j=length-1;j>i;j--)
						str[j+2] = str[j];
					str[i] = '%';
					str[i+1] = '2';
					str[i+2] = '0';
				}
				i++;
			}
		}
}; 


int main(){
	char str[12] = {"a b1b c "};
	Solution solu;
	solu.replaceSpace_2(str, 12);
	cout<<str<<endl;
	return 0;
}
