/*
字节跳动5：过河问题
n个人过河，只有一条船；为安全起见，每次船上只能坐2-3人（不能单独一人坐船）；
每个人过河时间不一样，取每次过河的人里耗时最多的作为一次过河的时间。
输入：总人数，每个人单独过河的时间
输出：总的最短过河时间 
*/ 

/*
分析：
以{2,3,3,4,6,8}为例，若8最后过河，则耗时为{2,3,3,4,6}+{2,3}+{2,3,8}；
若8不是最后过河，则耗时为{8,min_1, min_2}+{min_1,min_2}+{2,3,3,4,6}；
显然最佳的过河方法是：每次挑选剩余耗时最多的人和耗时最少的两个人过河，耗时最少的两个人返回。 
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,t,sum=0;	//默认 n>1 
	vector<int> T;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		sum+=t;
		T.push_back(t);
	}
	if(n<=3)
		cout<<sum;
	else{
		sort(T.begin(),T.end());
		cout<<sum-T[0]+(n-4)*T[1];
	}
	return 0;
} 
