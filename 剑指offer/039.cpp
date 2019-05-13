/*
统计一个数字在排序数组中出现的次数。
*/

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()==0)
            return 0;
        int l=0,r=data.size()-1,cnt=0,m;
        bool increase = data[r]>=data[l];
        while(l<r){
            m = (l+r)/2;
            if(data[m]<k){
            	if(increase)
            		l=m+1;
            	else
            		r=m-1;
			}
            else if(data[m]>k){
            	if(increase)
            		r=m-1;
            	else
            		l=m+1;
			}
            else
                break;
        }
        m = (l+r)/2;
        if(data[m]!=k)
            return 0;
        cnt++;
        int idx1=m-1,idx2=m+1;
        while(idx1>=0 && (data[idx1]==k))
            idx1--,cnt++;
        while(idx2<data.size()&& (data[idx2]==k))
            idx2++,cnt++;
        return cnt;
    }
};
