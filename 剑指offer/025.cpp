/*
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//�ݹ� 
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if(len==0)
            return false;
        int l = 0,r=len-1;
        bool left=true,right=true;
        while(sequence[l]<sequence.back())
            l++;
        while(r>=0&&sequence[r]>=sequence.back())
            r--;
        vector<int> L(sequence.begin(),sequence.begin()+l);
        vector<int> R(sequence.begin()+r+1,sequence.end()-1);
        if(l!=0)
        	left = VerifySquenceOfBST(L);
        if(r+1!=len-1)
        	right = VerifySquenceOfBST(R);
        return (l==r+1) && left && right;
    }
}; 

int main(){
	Solution solu;
	int a[] = {5,7,6,9,11,10,8};
	vector<int> A(a,a+7);
//	vector<int> A;
	cout<<solu.VerifySquenceOfBST(A);
	return 0;	
}
