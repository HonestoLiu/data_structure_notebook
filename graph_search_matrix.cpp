/*
�ڽӾ����ʾ��ͼ���� 
*/ 

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define maxN 100
using namespace std;

struct m_Graph{
	char vex[maxN];		//�洢����,��{c,a,r,b} 
	int edg[maxN][maxN]; 	//�洢��,��ά���� 
	int v_num,e_num; 	//ͼ�Ķ������ͱ��� 
};

bool visited[maxN]; 	//����״̬

// ���±� 
int GetIndex(const m_Graph& G, char c){
	int i=0;
	for(i=0;i<G.v_num;i++){
		if(G.vex[i]==c)
			return i;
	}
	return -1;
} 

/* 
--------�����������---------------- 
 1. ��ʼ������Q��visited[n]=0��
 2. ���ʶ���v��visited[v]=1������v�����Q��
 3. while������Q�ǿգ�   
        v=����Q�Ķ�ͷԪ�س��ӣ�
        w=����v�ĵ�һ���ڽӵ㣻
        while��w���ڣ� 
			���wδ���ʣ�����ʶ���w��
			visited[w]=1��
            ����w�����Q��
            w=����v����һ���ڽӵ㡣
*/  
vector<char> m_BFS(const m_Graph& G, char v0){
	vector<char> res;
	queue<char> q;
	char c;
	int index;
	
	index = GetIndex(G, v0);
	res.push_back(v0);
	cout<<v0<<" ";
	q.push(v0);
	visited[index]=1;
	while(!q.empty()){
		c=q.front();
		index = GetIndex(G, c);
		q.pop();
		for(int j=0;j<G.v_num;j++){
			if(G.edg[index][j]==1&&!visited[j]){
				c = G.vex[j];
				cout<<c<<" ";
				q.push(c);
				res.push_back(c);
				visited[j]=1;	
			}
		}
	}
	return res;
}

/* 
--------�����������--------�ݹ�--------- 
 1. ���ʶ���v��visited[v]=1; 
 2. �Զ���v��δ�����ڽӽڵ�������õݹ� 
*/ 
void DFS_1(m_Graph& G, char v0){
	int index = GetIndex(G,v0); 
	visited[index]=1;	
	cout<<v0<<" ";	//���ʺ��� 
	for(int j=0;j<G.v_num;j++){
		if(G.edg[index][j]==1&&!visited[j]){
			DFS_1(G, G.vex[j]);
		}
	}
} 


/* 
----�����������--�ǵݹ�--�Ƚ����--stack------- 
 1. ջS��ʼ����visited[n]=0��
 2. ���ʶ���v��visited[v]=1������v��ջS
 3. while(ջS�ǿ�)
        x=ջS�Ķ�Ԫ��(����ջ)��
        if(���ڲ��ҵ�δ�����ʵ�x���ڽӵ�w)
			����w��visited[w]=1��
            w��ջ;
        else
            x��ջ�� 
*/ 
void DFS_2(m_Graph& G, char v0){
	stack<char> s;
	s.push(v0);
	int index = GetIndex(G,v0); 
	visited[index]=1;	
	cout<<v0<<" ";	//���ʺ��� 
	while(!s.empty()){
		char c = s.top();
		index = GetIndex(G, c);
		int j=0;
		for(j=0;j<G.v_num;j++){
			if(G.edg[index][j]==1&&!visited[j]){	//�ҵ� 
				c = G.vex[j];
				s.push(c);
				visited[j]=1;
				cout<<c<<" ";
				break;
			}
		}
		if(j==G.v_num){		//δ�ҵ� 
			s.pop(); 
		}		
	}
} 


int main(){
	int n1,n2;
	char v1,v2;
	m_Graph G;
	cin>>G.v_num>>G.e_num;	//������������
	for(int i=0;i<G.v_num;i++)
		cin>>G.vex[i];		//����{a,b,c,d,e,f} 
	for(int j=0;j<G.e_num;j++){
		cin>>v1>>v2;		//�������Ϣ��a d
		n1 = GetIndex(G, v1);
		n2 = GetIndex(G, v2);
		G.edg[n1][n2] = G.edg[n2][n1] = 1;
	}
	cout<<"�������������"; 
	vector<char> res = m_BFS(G, 'b');
	for(int i=0;i<maxN;i++)
		visited[i]=false;
	cout<<endl<<"�ݹ�������������"; 
	DFS_1(G, 'b');
	for(int i=0;i<maxN;i++)
		visited[i]=false;
	cout<<endl<<"�ǵݹ�������������"; 
		DFS_2(G, 'b');	
//7 9
//a b c d e f g
//a b
//a c
//a d
//b e
//c e
//c f
//e g
//f g
//d f
//b a e c d g f
	return 0;	
} 
