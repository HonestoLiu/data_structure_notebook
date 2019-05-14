/*
圆圈中最后剩下的数 
*/

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n==0||m==0)    return -1;
        list<int> L;
        for(int i=0;i<n;i++)
            L.push_back(i);
        list<int>::iterator it = L.begin();
        while(L.size()>1){
            for(int i=1;i<m;i++){
                it++;
                if(it==L.end())
                    it=L.begin();
            }
            it = L.erase(it);
            if(it==L.end())
                it=L.begin();
        }
        return L.front();
    }
}; 
