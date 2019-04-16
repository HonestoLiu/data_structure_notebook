/*
Dijkstra 算法 ：

  1. 初始化;
  2. 循环n次
    	3.找最小，记为true;
		4.更新dist 
  
*/
//邻接矩阵的写法 
int n, e[maxv][maxv];
int dis[maxv], pre[maxv];	// pre用来标注当前结点的前一个结点
bool vis[maxv] = {false};	//初始未被访问 
void Dijkstra(int s) {
  fill(dis, dis + maxv, inf);	//初始距离为∞ 
  dis[s] = 0;
  for(int i = 0; i < n; i++) pre[i] = i; //初始状态设每个点的前驱为自身
  for(int i = 0; i < n; i++) {	//循环n次 
    int u = -1, minn = inf;
    for(int j = 0; j < n; j++) {
      if(visit[j] == false && dis[j] < minn) {
        u = j;
        minn = dis[j];
      }
    }
    if(u == -1) return;
    visit[u] = true;
    for(int v = 0; v < n; v++) {
      if(visit[v] == false && e[u][v] != inf && dis[u] + e[u][v] < dis[v]) {
        dis[v] = dis[u] + e[u][v];
        pre[v] = u; // pre用来标注当前结点的前一个结点
      }
    }
  }
}

/*
有多条最短路径时，选cost最少的 
for(int v = 0; v < n; v++) { //重写v的for循环
  if(visit[v] == false && e[u][v] != inf) {
    if(dis[u] + e[u][v] < dis[v]) {
      dis[v] = dis[u] + e[u][v];
      c[v] = c[u] + cost[u][v];
    }else if(dis[u] + e[u][v] == dis[v] && c[u] + cost[u][v] < c[v]) {
      c[v] = c[u] + cost[u][v];
    }
  }
}
*/ 

/*
有多条最短路径时，选点权最大的 
for(int v = 0; v < n; v++) {
  if(visit[v] == false && e[u][v] != inf) {
    if(dis[u] + e[u][v] < dis[v]) {
      dis[v] = dis[u] + e[u][v];
      w[v] = w[u] + weight[v];
    }else if(dis[u] + e[u][v] == dis[v] && w[u] + weight[v] > w[v]) {
      w[v] = w[u] + weight[v];
    }
  }
}
*/ 

/*
求最短路径的数量 
for(int v = 0; v < n; v++) {
  if(visit[v] == false && e[u][v] != inf) {
    if(dis[u] + e[u][v] < dis[v]) {
      dis[v] = dis[u] + e[u][v];
      num[u] = num[v];
    }else if(dis[u] + e[u][v] == dis[v]) {
      num[v] = num[v] + num[u];
    }
  }
}
*/

/*
在最短路径基础上，若添加第二标尺的比较，还可以先存下最短路径然后使用dfs搜索
1. 存储--最短路径多条，使用vector<int> pre[maxv]; 
if(dis[u] + e[u][v] < dis[v]) {
  dis[v] = dis[u] + e[u][v];
  pre[v].clear();
  pre[v].push_back(u);
} else if(dis[i] + e[u] == dis[v]) {
  pre[v].push_back(u);
}
2. 搜索并打印路径
int optvalue;
vector<int> pre[maxv];
vector<int> path, temppath;
void dfs(int v) { // v为当前访问结点
  if(v == start) {
    temppath.push_back(v);
    int value = 路径temppath上的value值;
    if(value 优于 optvalue) {
      optvalue = value;
      path = temppath;
    }
    temppath.pop_back();
    return ;
  }
  temppath.push_back(v);
  for(int i = 0; i < pre[v].size(); i++)
    dfs(pre[v][i]);
  temppath.pop_back();
} 

*/ 
//邻接表的写法
struct node {
  int v, dis;	//编号、距离 
}
vector<node> e[maxv];	//每个点存储相邻节点信息 
int n;
int dis[maxv], pre[maxv];	// pre用来标注当前结点的前一个结点
bool visit[maxv] = {false};
for(int i = 0; i < n; i++) pre[i] = i; //初始状态设每个点的前驱为自身
void Dijkstra(int s) {
  fill(dis, dis + maxv, inf);
  dis[s] = 0;
  for(int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for(int j = 0; j < n; j++) {
      if(visit[j] == false && dis[j] < minn) {
        u = j;
        minn = dis[j];
      }
    }
    if(u == -1) return ;
    visit[u] = true;
    for(int j = 0; j < e[u].size(); j++) {
      int v = e[u][j].v;
      if(visit[v] == false && dis[u] + e[u][j].dis < dis[v]) {
        dis[v] = dis[u] + e[u][j].dis;
        pre[v] = u;
      }
    }
  }
} 


// Floyd算法 // 
/* 
1. 矩阵D记录顶点间的最小路径 	例如D[0][3]= 10，说明顶点0 到 3 的最短路径为10；
2. 矩阵P记录顶点间最小路径中的中转点  	例如P[0][3]= 1 说明，0 到 3的最短路径轨迹为：0 -> 1 -> 3
*/
//这里是弗洛伊德算法的核心部分 
    for(k = 0; k < G.vexnum; k++){	//k为中间点
        for(v = 0 ; v < G.vexnum; v++){	//v为起点
            for(w =0; w < G.vexnum; w++){	//w为终点 
                if(D[v][w] > (D[v][k] + D[k][w])){
                    D[v][w] = D[v][k] + D[k][w];//更新最小路径 
                    P[v][w] = P[v][k];//更新最小路径中间顶点 
                }
            }
        }
    }

// Bellman-Ford //
/*
设立一个队列用来保存待优化的顶点，优化时每次取出队首顶点 u，并且用 u 点当前的最短路径估计值dis[u]对与 u 点邻接的顶点 v 进行松弛操作，
如果 v 点的最短路径估计值dis[v]可以更小，且 v 点不在当前的队列中，就将 v 点放入队尾。这样不断从队列中取出顶点来进行松弛操作，直至队列空为止。
*/
int matrix[100][100];  //邻接矩阵
bool visited[100];     //标记数组
int dist[100];         //源点到顶点i的最短距离
int path[100];         //记录最短路的路径
int enqueue_num[100];  //记录入队次数
int vertex_num;        //顶点数
int edge_num;          //边数
int source;            //源点
bool SPFA()
{
    memset(visited, 0, sizeof(visited));
    memset(enqueue_num, 0, sizeof(enqueue_num));
    for (int i = 0; i < vertex_num; i++)
    {
        dist[i] = INT_MAX;
        path[i] = source;
    }
 
    queue<int> Q;
    Q.push(source);
    dist[source] = 0;
    visited[source] = 1;
    enqueue_num[source]++;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        visited[u] = 0;
        for (int v = 0; v < vertex_num; v++)
        {
            if (matrix[u][v] != INT_MAX)  //u与v直接邻接
            {
                if (dist[u] + matrix[u][v] < dist[v])
                {
                    dist[v] = dist[u] + matrix[u][v];
                    path[v] = u;
                    if (!visited[v])
                    {
                        Q.push(v);
                        enqueue_num[v]++;
                        if (enqueue_num[v] >= vertex_num)	//判断是否存在负环 
                            return false;
                        visited[v] = 1;
                    }
                }
            }
        }
    }
    return true;
} 

