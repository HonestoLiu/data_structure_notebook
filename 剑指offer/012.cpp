/*
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

class Solution {
public:
	//递推公式为 p(n)=p(n-1)+p(n-2) 
    int rectCover(int number) {
        if(number<1)
            return 0;
        int f=0,g=1;
        while(number-->0){
            g += f;
            f=g-f;
        }
        return g;
    }
};
 
