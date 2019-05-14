/*
����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S��
����ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
*/ 

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int s=0,e=array.size()-1;
        vector<int> res;
        while(s<e){
            if(array[s]+array[e]<sum)
                s++;
            else if(array[s]+array[e]>sum)
                e--;
            else{
                res.push_back(array[s]);
                res.push_back(array[e]);
                break;
            }
        }
        return res;
    }
};
