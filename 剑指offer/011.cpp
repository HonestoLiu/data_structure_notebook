/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

class Solution {
public:
    int jumpFloorII(int number) {
        if(number<1)
            return 0;
        int count=1;
        while(--number>0)
            count=count*2;
        return count;
    }
};
 
