/*
扑克牌的顺序，判断是否是顺子 
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
    	sort(numbers.begin(),numbers.end());
    	int cnt = 0,res=0;
    	while(numbers[cnt]==0)
    		cnt++;
    	for(int i=cnt;i<numbers.size()-1;i++){
    		if(numbers[i+1]-numbers[i]==0)
    			return false;
    		res+=numbers[i+1]-numbers[i]-1;
		}
    	return res<=cnt?true:false; 
    }
};

int main(){
	vector<int> A ={1,3,4,0,0,9};
	Solution solu;
	cout<<solu.IsContinuous(A)<<endl;
	return 0;
}
