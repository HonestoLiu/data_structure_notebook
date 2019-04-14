/*
字节跳动3:跳跃问题
编号为0-n的建筑，高度为H[0]=0,H[i]>=0待输入；
初始能量为E,在第k个建筑上能量为p[k]，若H[k+1]>p[k]（建筑高度大于当前能力值），则能量值减少（ H[k+1]>p[k]）；
反之，则增加（p[k]-H[k+1]）。现要求在每个建筑上 能量值都非负，求最小的初始能量值E。
输入：总的建筑数以及高度
输出：最小初始能量 
*/ 

/*
分析：转移方程：p[k+1]=p[k]+(p[k]-H[k+1])
设p[0]=x,则：
p[1]=2*p[0]-H[1];
p[2]=2*p[1]-H[2]=2^2p[0]-2H[1]-H[2];
p[3]=2*p[2]-H[3]=2^3p[0]-2^2H[1]-2H[2]-H[3];
……
n个不等式（p[i]>=0),只有最后一个有用，即：
p[0]> H[1]/2 + H[2]/2^2 + H[3]/2^3 + ... + H[n]/2^(n+1) 
 
*/ 

#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	double p=0,h=0;
	for(int i=0;i<n;i++){
		cin>>h;
		for(int j=0;j<=i;j++)
			h=h/2;
		p=p+h;
	}
	cout<<(int)p +1;
	return 0;
} 
