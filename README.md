# Nth-Smallest-Element

Aim: To find the nth smallest element in a given sequence of numbers. 
The operation should take an amortized cost of O(n).

Quick Sort's partitioning approach used here. We don not want to do more work than what is required i.e. we don't want to sort 
all the numbers and then return the nth element from sorted list; Instead we approach this problem using the idea of 
partitioning of Quick Sort.

Pivot is randomly generated (randomized quick-sort).

Also, a comparison of the inbuilt nth_element and our custom nth element function is also done, based on the run time of both
for different input sequences and sizes.
