/*
邻接矩阵表示的图搜索 
*/ 

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define maxN 100
using namespace std;

struct m_Graph{
	char vex[maxN];		//存储顶点,如{c,a,r,b} 
	int edg[maxN][maxN]; 	//存储边,二维数组 
	int v_num,e_num; 	//图的顶点数和边数 
};

bool visited[maxN]; 	//访问状态

// 找下标 
int GetIndex(const m_Graph& G, char c){
	int i=0;
	for(i=0;i<G.v_num;i++){
		if(G.vex[i]==c)
			return i;
	}
	return -1;
} 

/* 
--------广度优先搜索---------------- 
 1. 初始化队列Q；visited[n]=0；
 2. 访问顶点v；visited[v]=1；顶点v入队列Q；
 3. while（队列Q非空）   
        v=队列Q的对头元素出队；
        w=顶点v的第一个邻接点；
        while（w存在） 
			如果w未访问，则访问顶点w；
			visited[w]=1；
            顶点w入队列Q；
            w=顶点v的下一个邻接点。
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
--------深度优先搜索--------递归--------- 
 1. 访问顶点v；visited[v]=1; 
 2. 对顶点v的未访问邻接节点逐个调用递归 
*/ 
void DFS_1(m_Graph& G, char v0){
	int index = GetIndex(G,v0); 
	visited[index]=1;	
	cout<<v0<<" ";	//访问函数 
	for(int j=0;j<G.v_num;j++){
		if(G.edg[index][j]==1&&!visited[j]){
			DFS_1(G, G.vex[j]);
		}
	}
} 


/* 
----深度优先搜索--非递归--先进后出--stack------- 
 1. 栈S初始化；visited[n]=0；
 2. 访问顶点v；visited[v]=1；顶点v入栈S
 3. while(栈S非空)
        x=栈S的顶元素(不出栈)；
        if(存在并找到未被访问的x的邻接点w)
			访问w；visited[w]=1；
            w进栈;
        else
            x出栈； 
*/ 
void DFS_2(m_Graph& G, char v0){
	stack<char> s;
	s.push(v0);
	int index = GetIndex(G,v0); 
	visited[index]=1;	
	cout<<v0<<" ";	//访问函数 
	while(!s.empty()){
		char c = s.top();
		index = GetIndex(G, c);
		int j=0;
		for(j=0;j<G.v_num;j++){
			if(G.edg[index][j]==1&&!visited[j]){	//找到 
				c = G.vex[j];
				s.push(c);
				visited[j]=1;
				cout<<c<<" ";
				break;
			}
		}
		if(j==G.v_num){		//未找到 
			s.pop(); 
		}		
	}
} 


int main(){
	int n1,n2;
	char v1,v2;
	m_Graph G;
	cin>>G.v_num>>G.e_num;	//顶点数、边数
	for(int i=0;i<G.v_num;i++)
		cin>>G.vex[i];		//顶点{a,b,c,d,e,f} 
	for(int j=0;j<G.e_num;j++){
		cin>>v1>>v2;		//输入边信息：a d
		n1 = GetIndex(G, v1);
		n2 = GetIndex(G, v2);
		G.edg[n1][n2] = G.edg[n2][n1] = 1;
	}
	cout<<"深度优先搜索："; 
	vector<char> res = m_BFS(G, 'b');
	for(int i=0;i<maxN;i++)
		visited[i]=false;
	cout<<endl<<"递归广度优先搜索："; 
	DFS_1(G, 'b');
	for(int i=0;i<maxN;i++)
		visited[i]=false;
	cout<<endl<<"非递归广度优先搜索："; 
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
