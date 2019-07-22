#include <iostream>
using namespace std;
void swap(int& n1, int& n2){
	int tmp = n1;
	n1 = n2;
	n2 = tmp;
}

//1.冒泡排序 -- 每次让小元素上浮 
void Bubble_Sort(int* list,int len){
	bool flag = true;
	for(int i=0;i<len-1&&flag;i++){
		flag = False;
		for(int j=len-1;j>i;j--){
			if(list[j]<list[j-1]){	//比较连续两个数的值 
				swap(list[j],list[j-1]);
				flag = true;
			}
		}
	}
}

//2.快速排序 -- 把数组分成两部分 
void Qsort(int* list,int begin,int end){
	if(begin<end){
		int low = begin, high = end;
		int tmp = list[low];	
		while(low<high){
			while(low<high&&list[high]>=tmp)
				high--;
			list[low]=list[high];	//比tmp小，移到左端 
			while(low<high&&list[low]<=tmp)
				low++;
			list[high]=list[low];	//比tmp到，移到右端 
		}
		list[low] = tmp;
		Qsort(list,begin,low-1);	// 递归 
		Qsort(list,low+1,end);		// 递归 
	}
} 


//3.选择排序 -- 每次选择剩余最小的 
void Select_Sort(int* list,int len){
	for(int i=0;i<len;i++){
		int min = i;
		for(int j=i+1;j<len;j++){
			if(list[j]<list[min])
				min = j;
		}
		swap(list[i],list[min]);
	}
} 

//4.插入排序 -- 每次将元素插入到前面有序子列里
void Insert_Sort(int* list,int len){
	for(int i=1;i<len;i++){
		if(list[i]<list[i-1]){	//需插入 
			int tmp = list[i];
			int index=0;
			for(index=i-1;index>=0&&(list[index]>tmp);index--)
				list[index+1]=list[index];
			list[index+1]=tmp; 
		}
	}
} 

int main(){
	int a[]={3,10,5,2,4,9,7,8,0};
//	Bubble_Sort(a,9);
//	Qsort(a,0,8);
//	Select_Sort(a,9);
	Insert_Sort(a,9);
	
	for(int i;i<9;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

