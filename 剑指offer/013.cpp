/*
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/

//˼·������ʹ1��������ȡn�Ķ�������1�ĸ��� 
class Solution {
public:
     int  NumberOf1(int n) {
         int count=0, flag=1;
         while(flag!=0){
             if((n & flag) != 0)    //!=�����ȼ�����&�Լ�&&
                 count++;
             flag = flag<<1;
         }
         return count;
     }
};
