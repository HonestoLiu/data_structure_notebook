/*
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
*/

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(),numbers.end(),cmp);
        string s="";
        for(int i=0;i<numbers.size();i++)
            s+=to_string(numbers[i]);
        return s;
    }
    static bool cmp(int a, int b) {
    	string s1 = to_string(a);
    	string s2 = to_string(b);
    	return s1+s2<s2+s1;
	}
};

