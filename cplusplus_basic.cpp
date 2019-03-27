/* 读取一行字符串 */
//	 1. gets()方法，参数是字符数组名,不会跳过空格，遇到enter停止 
	char s[1005];
	gets(s);
	cout << s << endl;
	
//	 2. cin.getline()方法，第1个参数字符数组名，第2个参数是字符个数，默认结束符为'\n' 
	char s[2000];
	cin.getline(s,1005);
	cout << s << endl;

//	 3. string + getline()
	string str;
	getline(cin,str);
	cout << str << endl;


/* c方式输入输出 */
	int a[2][2];
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			scanf("%d",&a[i][j]);
	printf("%.3d\n",a[1][1]);	//.n表示补齐n位


/* 结构体 */
//	c版本
	define struct BiTNode{
		char s;
		struct BiTNode *lchild, *rchild;
	}BiTNode, *BiTree;	//BiTNode=struct BiTNode, BiTree = struct BiTNode *

// c++版本
	struct Student{
		string ID;
		int Grade;
	}s1;	//s1是一个Student型的变量


/* c++小数点控制输出 */
	#include <iomanip>
	cout<<fixed<<setprecision(2)<<result;	//保留小数点两位 


/* string-int的相互转换 */
	string str="123.45";
	int a = atoi(str.c_str());
	float b = atof(str.c_str());
	long c = atol(str.c_str());

	int num = 101;
	string str = to_string(num);



