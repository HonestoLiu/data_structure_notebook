/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。n<=39
*/

class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)
            return 0;
        int a=1,b=1,c=1;
        for(int i=2;i<n;i++){
            c=a;
            a = a+b;
            b = c;
        }
        return a;
    }
    // 简洁写法 
    int Fibonacci_1(int n) {
		int f=0,g=1;
		while(n-->0){
			g=g+f;
			f=g-f;
		}
		return g;
    }
};
 
