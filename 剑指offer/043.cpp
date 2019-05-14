/*
找出所有和为S的连续正数序列, 100=9-16,18-22
*/

class Solution {
public:
	//自己，设序列为{x+1,x+2,...,x+len}，求解满足条件的整数x>=0
	//从长度len=2验证 
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        vector<int> tmp;
        int add=3,len=2;
        while(add<=sum){
            if((sum-add)%len==0){
                tmp.clear();
                int beg=(sum-add)/len;
                for(int j=1;j<=len;j++)
                    tmp.push_back(beg+j);
                res.insert(res.begin(),tmp);
            }
            len++;
            add+=len;
        }
        return res;
    }
    
    //牛客网 --滑动指针的做法
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > res;
		vector<int> tmp;
		int plow=1,phigh=2,add=0;
		while(plow<phigh){
			add = (plow+phigh)(phigh-plow+1)/2;	//求和公式 
			if(add==sum){
				tmp.clear();
				for(int i=plow;i<=phigh;i++)
                    tmp.push_back(i);
                res.push_back[tmp];
                plow++;
			}
			else if(add<sum)
				phigh++;
			else
				plow++;
		}
		return res;
	}
	 
};
