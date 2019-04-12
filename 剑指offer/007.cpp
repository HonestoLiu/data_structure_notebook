/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/ 

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
	// 自己当时想的，复杂度较高 
    int pop() {
        int tmp;
        while(!stack2.empty())	//stack2清空 
            stack2.pop();
        while(!stack1.empty()){	//stack1反序存入stack2 
            tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
        int res = stack2.top();	//返回stack2栈顶元素并出栈 
        stack2.pop();
        while(!stack2.empty()){	//恢复出栈后的stack1原来的样子 
            tmp = stack2.top();
            stack2.pop();
            stack1.push(tmp);
        }
        return res;
    }
    
    // 改进  stack2非空就一直可以出栈，出栈后stack1也不用恢复，因为元素存储在stack2中 
	int pop_new(){
		int tmp;
		if(stack2.empty()){	//stack2空，把stack1元素倒序过来;非空，说明可继续出栈 
			while(!stack1.empty()){
				tmp = stack1.top();
				stack2.push(tmp);
				stack1.pop();
			}
		}
		tmp = stack2.top();
		stack2.pop();
		return tmp; 
	} 
	
private:
    stack<int> stack1;
    stack<int> stack2;
};
