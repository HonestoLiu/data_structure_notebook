/*
������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
*/ 

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool *flag=new bool[rows*cols]{false};
        return Help(rows,cols,0,0,threshold,flag);
       
    }
    int Help(int rows,int cols,int r,int c,int threshold,bool *flag){
        if(r>=rows||c>=cols||r<0||c<0||(Sum(c)+Sum(r))>threshold||flag[r*cols+c]==true)
           return 0;
        flag[r*cols+c]=true;
        return Help(rows,cols,r+1,c,threshold,flag)+Help(rows,cols,r-1,c,threshold,flag)+
               Help(rows,cols,r,c+1,threshold,flag)+Help(rows,cols,r,c-1,threshold,flag)+1;
    }
    int Sum(int n)
    {
        int sum=0;
        while(n!=0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
};
