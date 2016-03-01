# Searching
Three common methods of searching-

Linear Search O(n): Check every element from index 0 to n-1.

Binary Search O(logn): Necessary to sort at least once, by any of the O(nlogn) methods.
		Three conditions are checked-
		-If element is equal to mid element, found.
		-Else if element is greater than mid element, it may lie in second-half.
		-Else it may lie in first-half.

Hashing O(1): A suitable hash function has to be found first, which highly varies according to scenario & may not be feasible in some.
	      Collision & load factor has to be considered.
	      Useful technique with constant time complexity.