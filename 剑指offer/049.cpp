/*
��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
*/ 

class Solution {
public:
	//ţ���� --�ݹ� 
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1)); //&&�߼��ж� 
        return ans;
    }
    // �Լ������ᣩ 
    int Sum_Solution(int n) {
        return ((int)pow(n,2)+n)>>1;
    }
};

