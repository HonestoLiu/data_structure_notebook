# **vector**  
- 初始化  

        vector<int> A;  
        vector<int> A = {1,2,3,3,4};
        vector<int> A(10);
        vector<int> A(10,1);	//初始化为有10个元素，并赋值为1
        vector<int> A(vec);
        vector<int> A(iterator first,iterator last);	//初始化为其他容器的 [first,last)

- 插入、删除

        vec.insert(pos,elem);       //在pos位置插入一个elem拷贝，传回新数据位置
        vec.insert(pos,n,elem);     //在pos位置插入n个elem数据，无返回值
        vec.insert(pos,begin,end);  //在pos位置插入在[beg,end)区间的数据，无返回值
        vec.erase(iterator it);     //删除指定位置元素 
        vec.erase(iterator first, iterator last);
        vector.assign(iterator first, iterator last);
        vec.assign(n,elem);
        
- 访问

        1.[]        //[]下标访问
        2.vec.at(pos);     //at()函数具有检测是否越界的功能
        3.vector<int>::iterator it;	    //迭代器访问
          for (it = vec.begin(); it != vec.end(); it++) 
          vector<int>::reverse_iterator rit;
          for (rit = vec.rbegin(); rit != vec.rend(); rit++) 
              
              
- 其他

        vec.empty();
        vec.size();
        vec.push_back(elem);    //没有vec.push_front();
        vec.pop_back();         //没有vec.pop_front();
        vec.back();     //返回引用
        vec.front();
        vec.clear();
        vec.reverse(size);  //保留size大小
        vec.resize(size);   //多余元素被删除
        vec.swap(vec_other);    //等价swap(vec,vec_other)
        
# **list双向链表**  
- 初始化

        list<int> A;  
        list<int> A = {1,2,3,3,4};
        list<int> A(10);
        list<int> A(10,1);	//初始化为有10个元素，并赋值为1
        list<int> A(lst);
        list<int> A(iterator first,iterator last);	//初始化为其他容器的 [first,last)

- 插入、删除

        lst.insert(pos,elem);       //在pos位置插入一个elem拷贝，传回新数据位置
        lst.insert(pos,n,elem);     //在pos位置插入n个elem数据，无返回值
        lst.insert(pos,begin,end);  //在pos位置插入在[beg,end)区间的数据，无返回值
        lst.erase(iterator it);     //删除指定位置元素 
        lst.erase(iterator first, iterator last);
        lst.remove(elem);           //移除等于elem的元素
        lst.assign(iterator first, iterator last);
        lst.assign(n,elem);
        
- 访问

        list<int>::iterator it;		//迭代器访问
        for (it = lst.begin(); it != lst.end(); it++)
        
- 其他

        lst.sort();     //自带sort成员函数
        lst.unique();   //unique并不删除，只改变元素位置；等价unique(lst.begin(),lst.end())?
        lst.reverse();  
        lst.push_back(elem) lst.push_front(elem) lst.pop_front() lst.pop_back();
        lst.swap(lst_other);
        lst.clear();
        lst.empty();
        lst.merge(lst_other);
        //在lst位置处拼接lst_other的[first,last)的内容，lst_other会改变大小
        lst.splice(iterator it, list& lst_other, iterator first, iterator last);    


# **string**  
待完成.

# **比特set**  
- 初始化  

        bitset<10> bst;     //bst=0000000000，默认补0
        bitset<4> bst(16);  //16=[... ... ... 00010000],bst=0000,从后往前取
        bitset<4> bst("101111");    //bst=1011,从前往后取
        //需注意，bitset默认[0]在最右边
        
- 操作符  

        ~ ^ & | >> << == != ^= |= &=
        [] //可下标访问
        
- 函数  

        bst.count();    //1的个数
        bst.size();
        (bool) bst.test(pos); //1返回true
        (bool) bst.any();   //有1
        (bool) bst.none();  //无1
        (bool) bst.all();   //全1?
        bst.flip(pos);  //pos位取反，无参时全部取反
        bst.set();      //全部置1
        bst.reset();    //全部置0
        bst.set(pos,1); //bst[pos]=1
        bst.set(pos);   //bst[pos]=1
        bst.reset(pos); //bst[pos]=0

- 类型转换

        string s = bst.to_string();
        unsigned long a = bst.to_ulong();
        unsigned long long a = bst.to_ullong();
        

        
        

# **STL常用算法**  
待完成.
