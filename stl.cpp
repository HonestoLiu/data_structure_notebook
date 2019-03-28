/*  vector  */ 
vector<int> A;
vector<int> A(10);
vector<int> A(10,1);	//��ʼ��Ϊ��10��Ԫ�أ�����ֵΪ1
vector<int> A(iterator first,iterator last);	//��ʼ��Ϊ���������� [first,last) 
vec.push_back(a);
vec.pop_back();
vec.front() = 100;	//��һ��Ԫ�ص����� 
vec.insert(position,elem)   //��posλ�ò���һ��elem����������������λ�á�
vec.insert(position,n,elem) //��posλ�ò���n��elem���ݣ��޷���ֵ��
vec.insert(position,begin,end)  //��posλ�ò�����[beg,end)��������ݣ��޷���ֵ��
vec.erase(iterator it);		//ɾ��ָ��λ��Ԫ�� 
vec.erase(iterator first, iterator last);
cout << vec[1];		//[]���ʣ�����vector������[]�����Կ�������[]ֱ�ӷ�������Ԫ��
vec.at(1);			//at()�������м���Ƿ�Խ��Ĺ��ܣ����Խ����׳��������԰�ȫ�Ը���[]
vector <int>::iterator it;		//����������
for (it = vec.begin(); it != vec.end(); it++) cout << *it; 
vec.swap(v);	//��ͬ��������v���� 
vec.clear();
if(vec.empty())
int n = vec.size();


/*  list  */
int a[5] = {1,2,3,2,1};
list<int> A(a,a+5);
A.sort();	//�Դ���sort��Ա����
A.remove(2);	//�Ƴ�����2��Ԫ�� 
A.reverse();
A.unique();	//ȥ��
list<int> first;
list<int> second;
first.merge(second);//�ϲ�
void splice (iterator position, list& x, iterator first, iterator last);  
//֧��erase��pop_back, push_back, swap, clear, 
//��֧��[]���� 


/*  map  */
map <int,string> mp;	//������һ����intΪkey��stringΪvalue�ļ�ֵ�ԡ�
map <int,string>::iterator it; 
//���룬ע��ǰ����ֻ����map���޴�Ԫ�ص�ʱ����룬�����һ�ֿ���ʵ�ָ����ٸ�ֵ
mp.insert(make_pair(1, "one"));		//����make_pair���������һ�Թ���������
mp.insert(map<int, string>::value_type(1, "one"));	//����map��value_type����
mp[1] = "one";		//*��������[]���븳ֵ*
mp.at(2) = "two";
//earse(ɾ��)
mp.erase��iterator it);
mp.erase��iterator first��iterator last);
int n = erase(const Key&key);		//ͨ���ؼ���ɾ����ɾ���ɹ�n==1.����==0
mp.find(1);//����key���ڵĵ����������򷵻�end()
//lower_bound(���ҵ�һ�����ڵ���key��ֵ)upper_bound(���ҵ�һ������key��ֵ)
it = mp.lower_bound(1);
it = mp.upper.bound(1);


/*  set  */
int a[5] = {3,4,1,9,2};
set<int> A(a,a+5);
int cnt = A.count(2); 	//ͳ��
set<int>::iterator p1 = A.lower_bound(3);
set<int>::iterator p2 = A.upper_bound(4);
A.erase(iterator it);	//ɾ�� 
pair<set<int>::iterator,bool> result = A.insert(5);	//���������ǲ���ɹ�
set<int>::iterator p = A.find(4);	//���� ���Ҳ�������end() 
//��֧���±�[]���� 


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
/* priority_queue */
struct node{
    int x,y;
    bool operator < (const node & a) const{
        return x<a.x;
    }
};
priority_queue <node>;	//����С�ڣ�������������С�����Զ������ȼ�
priority_queue <int, vector<int>, greater<int> > que2;	//����
priority_queue <int> que;	//����ʵ����Ĭ�Ͻ���
que.push(a);
a = que.top();
que.pop();
bool b = que.empty();
a = que.size();
