/*
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        sort(data.begin(),data.end());
        int cnt=0;
        for(int i=0;i<data.size();i++){
            if(i+1==data.size()||data[i]!=data[i+1]){
                cnt++;
                if(cnt==2){
                    *num2 = data[i];
                    break;
                }
                *num1=data[i];
            }
            else
                i++;
        }
    }
};
