/*
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> even,res;
        for(int i=0;i<array.size();i++){
            if((array[i]&1)==1)
                res.push_back(array[i]);
            else
                even.push_back(array[i]);
        }
        res.insert(res.end(),even.begin(),even.end());
        array = res;
    }
};
