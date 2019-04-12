/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// 顺序查找 O(n) 
    int minNumberInRotateArray(vector<int> rotateArray) {
        int len = rotateArray.size();
        if(rotateArray.empty())
            return 0;
        if(len == 1)
            return rotateArray[1];
        int index = 1;
        while(index<len){
            if(rotateArray[index]<rotateArray[index-1])
                break;
            index++;
        }
        return rotateArray[index];
    }
    // 二分查找 O(logn)
	int minNumberInRotateArray_1(vector<int> rotateArray) {
		int low = 0, high = rotateArray.size()-1;
		while(low<high){
			int mid = (low+high)/2;
			if(rotateArray[mid]<rotateArray[low])	
				high = mid;
			else if(rotateArray[mid] == rotateArray[low])	//[1,0,1,1,1] 或者[1,1,1,0,1],
				low++;
			else
				low = mid; 	
		}
		return rotateArray[low];
	}
};
int main(){
	vector<int> A={4,5,7,8,1,1,1,2};
	Solution solu;
	cout<<solu.minNumberInRotateArray(A)<<endl;
	cout<<solu.minNumberInRotateArray_1(A)<<endl;
	return 0;
}

