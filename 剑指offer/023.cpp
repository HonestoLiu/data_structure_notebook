/*
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()==0)
        	return false;
        stack<int> res;
        for(int i=0,j=0;i<pushV.size();){
        	res.push(pushV[i++]);
        	//�������������ж���������ţ�����ϻᱨ����Խ����� 
        	while(j<popV.size() && popV[j]==res.top()){	
        		j++;
        		res.pop();
			}
		}
		return res.empty();
    }
};

int main(){
	int a[]={1,2,3,4,5};
//	int b[]={4,5,3,2,1};
//	int b[]={4,5,3,1,2};
	int b[]={1,2,3,4,5};
	vector<int> A(a,a+5),B(b,b+5);
	Solution S;
	cout<<S.IsPopOrder(A,B)<<endl;
	return 0;
}
