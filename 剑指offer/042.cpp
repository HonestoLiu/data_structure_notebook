/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
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
