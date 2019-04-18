/*
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

// 参考牛客网 
class Solution {
public:
    void push(int value) {
        s1.push(value);
        if(s2.empty()||s2.top()>=value)
            s2.push(value);
    }
    void pop() {
        if(s1.top()==s2.top())
            s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
private:
    stack<int> s1;//顺序存储输入的元素
    stack<int> s2;//辅助存储最小元素
}; 
