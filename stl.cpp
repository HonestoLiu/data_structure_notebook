/*  vector  */ 
vector<int> A;
vector<int> A(10);
vector<int> A(10,1);	//初始化为有10个元素，并赋值为1
vector<int> A(iterator first,iterator last);	//初始化为其他容器的 [first,last) 
vec.push_back(a);
vec.pop_back();
vec.front() = 100;	//第一个元素的引用 
vec.insert(position,elem)   //在pos位置插入一个elem拷贝，传回新数据位置。
vec.insert(position,n,elem) //在pos位置插入n个elem数据，无返回值。
vec.insert(position,begin,end)  //在pos位置插入在[beg,end)区间的数据，无返回值。
vec.erase(iterator it);		//删除指定位置元素 
vec.erase(iterator first, iterator last);
cout << vec[1];		//[]访问，由于vector重载了[]，所以可以利用[]直接访问已有元素
vec.at(1);			//at()函数具有检测是否越界的功能，如果越界会抛出错误，所以安全性高于[]
vector <int>::iterator it;		//迭代器访问
for (it = vec.begin(); it != vec.end(); it++) cout << *it; 
vec.swap(v);	//与同类型容器v互换 
vec.clear();
if(vec.empty())
int n = vec.size();


/*  list  */
int a[5] = {1,2,3,2,1};
list<int> A(a,a+5);
A.sort();	//自带的sort成员函数
A.remove(2);	//移除等于2的元素 
A.reverse();
A.unique();	//去重
list<int> first;
list<int> second;
first.merge(second);//合并
void splice (iterator position, list& x, iterator first, iterator last);  
//支持erase，pop_back, push_back, swap, clear, 
//不支持[]访问 


/*  map  */
map <int,string> mp;	//创建了一个以int为key，string为value的键值对。
map <int,string>::iterator it; 
//插入，注意前两种只能在map内无此元素的时候插入，而最后一种可以实现覆盖再赋值
mp.insert(make_pair(1, "one"));		//利用make_pair函数构造出一对关联量插入
mp.insert(map<int, string>::value_type(1, "one"));	//插入map的value_type数据
mp[1] = "one";		//*利用重载[]输入赋值*
mp.at(2) = "two";
//earse(删除)
mp.erase（iterator it);
mp.erase（iterator first，iterator last);
int n = erase(const Key&key);		//通过关键字删除，删除成功n==1.否则==0
mp.find(1);//返回key所在的迭代器，否则返回end()
//lower_bound(查找第一个大于等于key的值)upper_bound(查找第一个大于key的值)
it = mp.lower_bound(1);
it = mp.upper.bound(1);


/*  set  */
int a[5] = {3,4,1,9,2};
set<int> A(a,a+5);
int cnt = A.count(2); 	//统计
set<int>::iterator p1 = A.lower_bound(3);
set<int>::iterator p2 = A.upper_bound(4);
A.erase(iterator it);	//删除 
pair<set<int>::iterator,bool> result = A.insert(5);	//并不能总是插入成功
set<int>::iterator p = A.find(4);	//查找 ，找不到返回end() 
//不支持下标[]访问 


/* Stack */
stack<int> st;
st.push(12);
st.pop();
int a = st.top();
int a = st.size();
bool b = st.empty();

/* Queue */
queue<int> que;
que.push(a);
a = que.front();
a = que.back();
que.pop();
bool b = que.empty();
a = que.size();


/* deque */
deque<int> deq;
deq.push_back(a);
deq.pop_back();
deq.push_front();
deq.pop_front();
deq.erase(position);
deq.insert(position,ele);
bool b = deq.empty();
a = deq.size();
a = deq.front();
a = deq.back();

/* priority_queue */
struct node{
    int x,y;
    bool operator < (const node & a) const{
        return x<a.x;
    }
};
priority_queue <node>;	//重载小于，可以利用重载小于来自定义优先级
priority_queue <int, vector<int>, greater<int> > que2;	//升序
priority_queue <int> que;	//创建实例，默认降序
que.push(a);
a = que.top();
que.pop();
bool b = que.empty();
a = que.size();
