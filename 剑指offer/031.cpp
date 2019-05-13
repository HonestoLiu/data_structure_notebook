/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len = input.size();
        vector<int> res;
        if (len == 0 || k < 1 || k > len) {
            return res;
        }
        priority_queue<int,vector<int>,less<int> > p;
        for(int i=0;i<len;i++){
            if(p.size()<k)
                p.push(input[i]);
            else if(input[i]<p.top()){
                p.pop();
                p.push(input[i]);
            }
        }
        while(!p.empty()){
            res.push_back(p.top());
            p.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
