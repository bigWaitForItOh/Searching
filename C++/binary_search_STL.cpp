/*
IMPLEMENTATION OF BINARY SEARCH: USING STL & INBUILT FUNCTIONS

--------------HEADER FILES---------------
iostream:  I/O
vector:	   vector container class
algorithm: binary_search & sort functions
-----------------------------------------

-----------------SYNTAX------------------
binary_search(lower_bound_vector, upper_bound_vector, element)
sort(lower_bound_vector, upper_bound_vector)
-----------------------------------------

-----------------TIME COMPLEXITY----------------
	binary search:	O(logn);	T(N)=T(N/2)+O(1)
	sorting: 		O(nlogn)
	Overall:		O(nlogn)
------------------------------------------------

-------------SPACE COMPLEXITY-----------
				O(n)
----------------------------------------

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//------------------DRIVER PROGRAM-----------------S
int main()
{
	int A[]={3,101,7,19,150,12,20,55,98,1};		//unsorted array
	vector <int> Av(A,A+9);
	sort(Av.begin(),Av.end());
	
	if(binary_search(Av.begin(),Av.end(), 20))
		cout<<"Element found!"<<endl;
	else
		cout<<"Element not found!"<<endl;
		
	return 0;
}