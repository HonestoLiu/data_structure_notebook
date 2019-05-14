/*
在一个长度为n的数组里的所有数字都在0到n-1的范围内,请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2
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
