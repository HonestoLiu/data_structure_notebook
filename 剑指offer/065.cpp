/*
*����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ�����磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3��
��ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� �������{2,3,4,2,6,2,5,1}�Ļ�������������6���� 
{[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� 
{2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
*/

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> d;    //�洢��ǰ�������Ԫ���±�
        if(num.empty() || size == 0 || size > num.size()) {
            return res;
        }
        for(int i=0;i<num.size();i++){
            if(!d.empty()){
                //�鿴��ͷԪ���Ƿ����ڻ�����
                if(i>=d.front()+size){
                    d.pop_front();
                }
                //�����ǰ���ִ��ڶ���β����ɾ������β��ֱ����ǰ����С�ڵ��ڶ���β�����߶��п� 
                while(!d.empty()&& num[i]>=num[d.back()])
                    d.pop_back();
            }
            d.push_back(i);
            if(i+1>=size)
                res.push_back(num[d.front()]);
        }
        return res;
    }
};
