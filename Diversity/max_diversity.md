2 2 3 3 3 5 5 5 5 6
=>max ops need to make all elements of array a of size n to make it distinct = n-1(all elements are equal)
N-size(set(A))(no of distinct elements in A) 

Not want to change any unique element to any other element in array A bcoz that will not lead to any increment in diversity array

k = 2
Objective: To find optimium set of elements to change |set|<= k
 
2 2 
3 3 3
5 5 5 5 
6

If we change 3 to 10 then diversity does not changes from its group to another group but within the group diversity changes by 2
we would like to change occurence of that element whuch has max frequency M,M-1 new pairs, maximum increase in diversity with one operation.


k>n: if all elements are distinct, nC2
if k<=n: 
    5 4   / change 5 with freq 4
    5 3   / now 5 with freq 3 
    rand() unique element with freq 1

n can be upto 10^5
k can be 10^5

DS where we can fetch max element and push another element
f
f-1
1 unique
f-1
1

can use set also and maxheap