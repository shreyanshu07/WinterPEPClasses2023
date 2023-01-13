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
