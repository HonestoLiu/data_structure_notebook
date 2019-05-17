/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
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
