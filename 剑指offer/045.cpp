/*
����һ���������ַ�����S���������ѭ������Kλ������������
���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����
*/

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if(len==0)
            return str;
        int idx = n % len;
        return str.substr(idx)+str.substr(0,idx);
    }
};
