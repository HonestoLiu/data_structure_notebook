/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int cnt=0,len=numbers.size();
        unordered_map<int,int> M;
        for(int i=0;i<len;i++){
            M[numbers[i]]++;
            if(M[numbers[i]]>cnt){
                cnt=M[numbers[i]];
                if(cnt>len/2)
                    return numbers[i];
            }
        }
        return 0;
    }
};
