/*
����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����
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
