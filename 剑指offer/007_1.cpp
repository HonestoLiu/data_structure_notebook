/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/ 

class Solution
{
public:
    void push(int node) {
        queue1.push(node);
    }
    int pop(){
    	int tmp, len=queue1.size();
		for(int i=0;i<len-1;i++){	//queue1元素依次存入queue2
			tmp = queue1.front();
			queue1.pop();
			queue2.push(tmp);
		}
		int res = queue1.front();	//pop最后一个元素 
		queue1.pop();
		while(!queue2.empty()){		//queue2元素出队存入queue1 
			tmp = queue2.front();
			queue2.top();
			queue1.push(tmp);
		}
		return res;	
	}
private:
    queue<int> queue1;
    queue<int> queue2;
};
