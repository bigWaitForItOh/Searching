/*
IMPLEMENTATION OF BINARY SEARCH

--------------HEADER FILES---------------
iostream:  I/O
-----------------------------------------

-----------TIME COMPLEXITY---------------
		O(logn);	T(N)=T(N/2)+O(1)
-----------------------------------------

-------------SPACE COMPLEXITY-----------
				O(n)
----------------------------------------

*/
#include<iostream>
using namespace std;

int bsearch(int* arr, int low, int high, int ele)
{
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(ele==arr[mid])							//mid ele is equal to key element
			return mid;							
		else if(ele>arr[mid])						//key element may lie in the second half
			return bsearch(arr,mid+1,high,ele);
		else										//key element may lie in the first half
			return bsearch(arr,low,mid-1,ele);
	}
	return -1;
}

//------------------DRIVER PROGRAM-----------------
int main()
{
	int A[10]={1,3,7,12,18,20,55,98,101,150};		//sorted array
	cout<<bsearch(A,0,9,12)<<endl;
	cout<<bsearch(A,0,9,55)<<endl;
	cout<<bsearch(A,0,9,19)<<endl;
	cout<<bsearch(A,0,9,101)<<endl;
	cout<<bsearch(A,0,9,98)<<endl;
	return 0;
}