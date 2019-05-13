/*
��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��.
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int len=str.length();
        unordered_map<char,int> M;
        for(int i=0;i<len;i++)
        	M[str[i]]++;
        for(int i=0;i<len;i++)
        	if(M[str[i]]==1)
        	    return i;			
        return -1;
    }
};
