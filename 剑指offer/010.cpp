/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

class Solution {
public:
    int jumpFloor(int number) {
        if(number==1)
            return 1;
        if(number==2)
            return 2;
        return jumpFloor(number-1)+jumpFloor(number-2);
    }
	//递归关系为斐波那契数列
    int jumpFloor_1(int number) {
    	int f=1,g=1;
    	while(--number>0){
    		g=g+f;
    		f=g-f;
	}
	return g;
    }
};
 
