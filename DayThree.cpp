/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

/************** BINARY SEARCH ***************************/

int binarySearch(int l,int h,int arr[],int key){ // Basic Binary Search Template TC :O(log n) 
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]>key) h=mid-1;
        else if (arr[mid]<key) l=mid+1;
        else return mid;
    }
    return -1;
}

int binarySearchFirstOccurence(int l,int h,int arr[],int key){ //To find firstOccurence
    while(l<=h){
        int mid=l+((h-l)/2);
        if(arr[mid]>key) h=mid-1;
        else if(arr[mid]<key) l=mid+1;
        else{
            if(mid==0) return mid;
            else if(arr[mid]>arr[mid-1]) return mid;
            else h=mid-1;
        }
    }
    return -1;
}

int binarySearchLastOccurence(int l,int h,int arr[],int key,int n){ //To find lastOccurence
    while(l<=h){
        int mid=l+((h-l)/2);
        if(arr[mid]>key) h=mid-1;
        else if(arr[mid]<key) l=mid+1;
        else{
            if(mid==n-1) return mid;
            else if(arr[mid]>arr[mid-1]) return mid;
            else l=mid+1;
        }
    }
    return -1;
}

int frequencyOfKey(int l,int h,int arr[],int key,int n){ // To count frequency of particular element
    if(binarySearchFirstOccurence(l,h,arr,key)!=-1){
        return (binarySearchFirstOccurence(l,h,arr,key)- binarySearchLastOccurence(l,h,arr,key,n) + 1);
    }
    else{
        return -1;
    }
}

/*Note : Important points to consider for binary Search
        1. You should have a sorted search space.
        2. All elements in the search space should have some unique property (exclusiveness) in them , then only we can use it.
           Eg : Given a array which has at first occurence of number of multiple of 3 and then numbers that are multiple of 5.
                Now we are asked to search last element which is multiple of 3. We can't apply binary Search here even if the array is sorted.
                Because there can be elements that is multiplte of both 3 and 5. (3 6 9 12 5 10 15 20)
                Here there is mutual exclusion
        3. You can apply binary Search over answers if they belong to a group of elements that are sorted and you know highest and lowest points.
*/

//Ques : Given a rotated sorted array ,find a key element from that array using binary search.
//Solution : If pivot is found then we can have binary search in the two segment seperately.
//           So this question boils down to finding pivot in a rotated sorted array.

int pivotElement(int l,int h,int arr[],int n){
    int m=l+(h-l)/2;
    if(a[m]<=a[n-1]) h=m-1;
    else{
        if(m==n-1 and a[m]>a[m+1]) return m;
        else l=m+1;
    }
    return -1;
}

//Ques : Apply sqrt(int n) using binary search
int sqrtBinarySearch(int n){
    int l=1,h=n;
    while(l<=h){
        int m=l+(h-l)/2;
        if((m*m)>n) h=m-1;
        else{
            if((m+1)*(m+1)>n) return m;
            else l=m+1;
        }
    }
    return -1;
}

//Binary Search can be applied on monotonious functions only Eg : sqrt() is parabola


/********************PRACTICE QUESTIONS*********************************/
/*

1. Order agnostic Binary Search
2. 1st and last occurence of an Element
3. Count of elements in a sorted array
4. Number of Times the array is rotated
5. Find an element in rotated array
6. Searching in nearly sorted array
7. Floor/Ceil of an Element
8. Next Letter
9. Index of last 1 int sorted array
10. Find the position of an element in a sorted array
11. Minimum difference element in a sorted array
12. Bitonic array max element
13. Search in bitonic array
14. Search in rowWise + colWise sorted matrix
15. Find element in sortedArray that appears only once
16. Allocate minimum number of pages


*/
int binarySearchOrderNotKnown(int arr[],int n,int key) // Order agnostic Binary Search
{
	if(arr[0]<arr[n-1])
	{
		int start=0;
		int end=n-1;
		
		while(start<=end)
		{
			int mid=start+(end-start)/2;
			
			if(arr[mid]==key)
			{
				return mid;
			}
			else if(arr[mid]>key)
			{
				end=mid-1;
			}
			else if(arr[mid]<key)
			{
				start=mid+1;
			}
		}
         }
         
    else 
	{
		int start=0;
		int end=n-1;
		
		while(start<=end)
		{
			int mid=start+(end-start)/2;
			
			if(arr[mid]==key)
			{
				return mid;
			}
			else if(arr[mid]>key)
			{
                start=mid+1;
			}
			else if(arr[mid]<key)
			{
				end=mid-1;
			}
		}
         }
         return -1;	
}

int searchInNearlySortedArray(int n,int arr[],int l,int h,int key){
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==key) return mid;
        if((mid==0 or mid==n-1)) return -1;
        if(arr[mid-1]==key) return mid-1;
        if(arr[mid+1]==key) return mid+1;
        if(arr[mid]<key) l=mid+1;
        else if(arr[mid]>key) h=mid-1;
    }
    return -1;
}

int floorValueOfKey(int n,int arr[],int key){ // In this function element is returned instead of element index;
    int l=0,h=n-1,res=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key){
            res=arr[mid];
            l=mid+1;
        }
        else h=mid-1;
    }
    return res;
}

int ceilValueOfKey(int n,int arr[],int key){ // In this function element is returned instead of element index;
    int l=0,h=n-1,res=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key){
            l=mid+1;
        }
        else{
            
            res=arr[mid];
            h=mid-1;
        }
    }
    return res;
}

/*QUES : Suppose you have a sorted array of infinite numbers, how would you search an element in the array?

Since array is sorted, the first thing clicks into mind is binary search, but the problem here is that we don’t know size of array.
If the array is infinite, that means we don’t have proper bounds to apply binary search. So in order to find position of key, first we find bounds and then apply binary search algorithm.

Let low be pointing to 1st element and high pointing to 2nd element of array, Now compare key with high index element,
-if it is greater than high index element then copy high index in low index and double the high index.
-if it is smaller, then apply binary search on high and low indices found.*/

int binarySearchInInfiniteArray(int arr[],int key){
    int l=0,h=1;
    while(arr[h]<key){
        h*=2;
    }
    if(arr[h]==key) return mid;
    return binarySearch(l,h,arr[],key);
}

int findPeakElement(vector<int> v){ //Finding the peak element
    int n=v.size();
    int l=0,r=n-1;
    if(n==1) return 0;
    if(n==2){
        if(v[0]<v[1]) return 1;
        else return 0;
    }
    if(v[0]>v[1]) return 0;
    if(v[n-1]>v[n-2]) return n-1;
    while(l<=r){
        int mid=l+((r-l)/2);
        cout<<mid<<" ";
        if((mid==0 and v[mid]>v[mid+1]) or (mid==(n-1) and v[mid]>v[mid-1])) return mid;
        else if(v[mid]>v[mid-1] and v[mid]>v[mid+1]) return mid;
        else if(v[mid]<v[mid-1]) r=mid;
        else if(v[mid]>v[mid-1]) l=mid;
        
    }
    return -1;
}

/*
ALLOCATE MINIMUM NUMBER OF PAGES:

Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Example :

Input : pages[] = {12, 34, 67, 90}
        m = 2
Output : 113
Explanation:
There are 2 number of students. Books can be distributed 
in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 
      2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student
      2 with 67 + 90 = 157 pages 
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 
      1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113. 
*/

int isPossible(int A[],int n,long long sum,long long tot){
    long long res=0,i=0,ans=0;
    while(i<n){
        res=0;
        while(i<n and (A[i]+res<=sum)){
            res+=A[i];
            i++;
        }
        ans++;
    }
    return ans;
}
int findPages(int a[], int n, int M) 
{
    //code here
    int mini=INT_MAX;long long sum=0;
    for(int i=0;i<n;i++) {mini=min(mini,a[i]);sum+=a[i];}
    long long l=mini,h=sum-mini,ans=0;
    while(l<=h){
        long long m=l+((h-l)/2);
        int num=isPossible(a,n,m,sum);
        if(num>M) l=m+1;
        else if(num<=M) {h=m-1;ans=m;}
        
    }
    return ans;
}
