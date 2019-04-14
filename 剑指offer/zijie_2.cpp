/*
�ֽ�����2:��������
ÿ����������(x,y)  ,���������������ֵĸ������������Ĳ��Դ���1�У�5����1��2��3�������֣�1,2)������Ϊ3 
������
2		//���Դ��� 
5		//ʱ������ͼƬ
3 1 2 3 4 3 2		//ͼƬ����3������(x1,y1) (x2,y2) (x3,y3)
4 1 2 4 3 2 3 3 3
2 1 2 1 3
3 2 3 4 3 4 4
2 1 2 3 2		//ͼƬ����3������(x1,y1) (x2,y2)
2		//ʱ������ͼƬ
2 1 1 2 2
2 1 1
*/ 

/*
struct����id 
*/ 

#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;
struct Feature{
	int id,x,y;
	Feature(int index,int i,int j):id(index),x(i),y(j){
	}
	bool operator< (const Feature& A) const{
		if(x==A.x&&y==A.y)
			return id<A.id;
		if(x!=A.x)
			return x<A.x;
		return y<A.y;
	}
};
int main(){
	int TA,n,k,x,y;
	vector<Feature> F;
	vector<int> R;
	cin>>TA;
	while(TA--){
		F.clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>x>>y;
				Feature f(i,x,y);
				F.push_back(f);
			}
		}
		sort(F.begin(),F.end());
		int res =1,count=1;
		for(int i=1;i<=F.size();i++){
			if(F[i].x==F[i-1].x&&F[i].y==F[i-1].y&&F[i].id==F[i-1].id+1)
				count++;
			else
				count=1;
			res=max(res,count);
		}
//		cout<<res<<endl;
		R.push_back(res);
	}
	for(int i=0;i<R.size();i++)
		cout<<R[i]<<endl;
	return 0;
} 
