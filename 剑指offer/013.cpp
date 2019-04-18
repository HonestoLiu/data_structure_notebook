/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

//思路：不断使1右移来获取n的二进制中1的个数 
class Solution {
public:
     int  NumberOf1(int n) {
         int count=0, flag=1;
         while(flag!=0){
             if((n & flag) != 0)    //!=的优先级高于&以及&&
                 count++;
             flag = flag<<1;
         }
         return count;
     }
};
