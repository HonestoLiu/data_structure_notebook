/*
找出所有和为S的连续正数序列, 100=9-16,18-22
*/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > res;
		vector<int> tmp;
		int plow=1,phigh=2,add=0;
		while(plow<phigh){
			add = (plow+phigh)*(phigh-plow+1)/2;	//求和公式 
			if(add==sum){
				tmp.clear();
				for(int i=plow;i<=phigh;i++)
                    tmp.push_back(i);
                res.push_back(tmp);
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
