/*
IMPLEMENTATION OF LINEAR SEARCH

--------------HEADER FILES---------------
iostream:  I/O
-----------------------------------------

----------------TIME COMPLEXITY---------------
O(n);	searching through the whole array(1->n)
-----------------------------------------

-------------SPACE COMPLEXITY-----------
					O(n)
----------------------------------------

*/
#include<iostream>
using namespace std;

int lsearch(int* arr, int low, int high, int ele)
{
	int i;
	for(i=low; i<=high; ++i)
		if(arr[i]==ele)
			return i;
	return -1;
}

//------------------DRIVER PROGRAM-----------------
int main()
{
	int key, A[]={1,3,7,12,18,20,55,98,101,150};	
	cout<<lsearch(A,0,9,12)<<endl;
	cout<<lsearch(A,0,9,55)<<endl;
	cout<<lsearch(A,0,9,19)<<endl;
	cout<<lsearch(A,0,9,101)<<endl;
	cout<<lsearch(A,0,9,98)<<endl;
	return 0;
}