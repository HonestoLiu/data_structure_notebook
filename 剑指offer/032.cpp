/*
{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
��һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)
*/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int p=0,sum=0,res=array[0];
        while(p<array.size()){
            sum+=array[p];
            if(sum>res)
                res=sum;
            if(sum<0)
                sum=0;
            p++;
        }
        return res;
    }
};
