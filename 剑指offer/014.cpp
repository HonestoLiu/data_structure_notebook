/*
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
*/


//˼·�� ��n�ö����Ʊ�ʾ�� ��1�ĵط����˷� 
class Solution {
public:
    double Power(double base, int exponent) {
        int n=0;
        double res=1,curr=base;
        if(exponent<0){
            n=-exponent;
            if(base ==0)
                return 0;//����
        }
        else if(exponent==0)
            return 1;
        else
            n=exponent;
        //x^1101 = x^0001*x^0100*x^1000
        while(n!=0){
            if((n&1)==1)
                res*=curr;
            curr*=curr;
            n=n>>1;
        }
        return (exponent>0)?res:1.0/res;
    }
};
