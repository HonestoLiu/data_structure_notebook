/*
Dijkstra �㷨 ��

  1. ��ʼ��;
  2. ѭ��n��
    	3.����С����Ϊtrue;
		4.����dist 
  
*/
//�ڽӾ����д�� 
int n, e[maxv][maxv];
int dis[maxv], pre[maxv];	// pre������ע��ǰ����ǰһ�����
bool vis[maxv] = {false};	//��ʼδ������ 
void Dijkstra(int s) {
  fill(dis, dis + maxv, inf);	//��ʼ����Ϊ�� 
  dis[s] = 0;
  for(int i = 0; i < n; i++) pre[i] = i; //��ʼ״̬��ÿ�����ǰ��Ϊ����
  for(int i = 0; i < n; i++) {	//ѭ��n�� 
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
        pre[v] = u; // pre������ע��ǰ����ǰһ�����
      }
    }
  }
}

/*
�ж������·��ʱ��ѡcost���ٵ� 
for(int v = 0; v < n; v++) { //��дv��forѭ��
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
�ж������·��ʱ��ѡ��Ȩ���� 
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
�����·�������� 
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
�����·�������ϣ�����ӵڶ���ߵıȽϣ��������ȴ������·��Ȼ��ʹ��dfs����
1. �洢--���·��������ʹ��vector<int> pre[maxv]; 
if(dis[u] + e[u][v] < dis[v]) {
  dis[v] = dis[u] + e[u][v];
  pre[v].clear();
  pre[v].push_back(u);
} else if(dis[i] + e[u] == dis[v]) {
  pre[v].push_back(u);
}
2. ��������ӡ·��
int optvalue;
vector<int> pre[maxv];
vector<int> path, temppath;
void dfs(int v) { // vΪ��ǰ���ʽ��
  if(v == start) {
    temppath.push_back(v);
    int value = ·��temppath�ϵ�valueֵ;
    if(value ���� optvalue) {
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
//�ڽӱ��д��
struct node {
  int v, dis;	//��š����� 
}
vector<node> e[maxv];	//ÿ����洢���ڽڵ���Ϣ 
int n;
int dis[maxv], pre[maxv];	// pre������ע��ǰ����ǰһ�����
bool visit[maxv] = {false};
for(int i = 0; i < n; i++) pre[i] = i; //��ʼ״̬��ÿ�����ǰ��Ϊ����
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


// Floyd�㷨 // 
/* 
1. ����D��¼��������С·�� 	����D[0][3]= 10��˵������0 �� 3 �����·��Ϊ10��
2. ����P��¼�������С·���е���ת��  	����P[0][3]= 1 ˵����0 �� 3�����·���켣Ϊ��0 -> 1 -> 3
*/
//�����Ǹ��������㷨�ĺ��Ĳ��� 
    for(k = 0; k < G.vexnum; k++){	//kΪ�м��
        for(v = 0 ; v < G.vexnum; v++){	//vΪ���
            for(w =0; w < G.vexnum; w++){	//wΪ�յ� 
                if(D[v][w] > (D[v][k] + D[k][w])){
                    D[v][w] = D[v][k] + D[k][w];//������С·�� 
                    P[v][w] = P[v][k];//������С·���м䶥�� 
                }
            }
        }
    }

// Bellman-Ford //
/*
����һ����������������Ż��Ķ��㣬�Ż�ʱÿ��ȡ�����׶��� u�������� u �㵱ǰ�����·������ֵdis[u]���� u ���ڽӵĶ��� v �����ɳڲ�����
��� v ������·������ֵdis[v]���Ը�С���� v �㲻�ڵ�ǰ�Ķ����У��ͽ� v ������β���������ϴӶ�����ȡ�������������ɳڲ�����ֱ�����п�Ϊֹ��
*/
int matrix[100][100];  //�ڽӾ���
bool visited[100];     //�������
int dist[100];         //Դ�㵽����i����̾���
int path[100];         //��¼���·��·��
int enqueue_num[100];  //��¼��Ӵ���
int vertex_num;        //������
int edge_num;          //����
int source;            //Դ��
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
            if (matrix[u][v] != INT_MAX)  //u��vֱ���ڽ�
            {
                if (dist[u] + matrix[u][v] < dist[v])
                {
                    dist[v] = dist[u] + matrix[u][v];
                    path[v] = u;
                    if (!visited[v])
                    {
                        Q.push(v);
                        enqueue_num[v]++;
                        if (enqueue_num[v] >= vertex_num)	//�ж��Ƿ���ڸ��� 
                            return false;
                        visited[v] = 1;
                    }
                }
            }
        }
    }
    return true;
} 

