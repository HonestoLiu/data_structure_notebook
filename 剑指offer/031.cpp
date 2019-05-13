/*
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
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
