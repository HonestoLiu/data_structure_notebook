/*
*给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， 
{2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> d;    //存储当前划窗最大元的下标
        if(num.empty() || size == 0 || size > num.size()) {
            return res;
        }
        for(int i=0;i<num.size();i++){
            if(!d.empty()){
                //查看表头元素是否还在在划窗里
                if(i>=d.front()+size){
                    d.pop_front();
                }
                //如果当前数字大于队列尾，则删除队列尾，直到当前数字小于等于队列尾，或者队列空 
                while(!d.empty()&& num[i]>=num[d.back()])
                    d.pop_back();
            }
            d.push_back(i);
            if(i+1>=size)
                res.push_back(num[d.front()]);
        }
        return res;
    }
};
