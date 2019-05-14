/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector<int> res(n,1);
        for(int i=1;i<n;i++)
            res[i]=res[i-1]*A[i-1];
        int tmp = 1;
        for(int j=n-2;j>=0;j--){
            tmp*=A[j+1];
            res[j]*=tmp;
        }
        return res;
    }
};
