/*
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ��,���ҳ�����������һ���ظ������֡� 
���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        bool res = false;
        int* p = new int[length];
        for(int i=0;i<length;i++)
            p[i] = 0;
        for(int i=0;i<length;i++){
            p[numbers[i]]++;
            if(p[numbers[i]]==2){
                res = true;
                *duplication = numbers[i];
                break;
            }
        }
        return res;
    }
};
