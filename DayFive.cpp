/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

//Insertion sort : O(n*n)
void insertionSort(int n,int arr[]){
    int i=1;
    while(i<n){
        int j=i;
        while(j){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
            j--;
        }
        i++;
    }
}
              
//Ques : Merge two sorted arrays into one.

vector<int> mergeSortedArrays(int n,int m,int arr1[],int arr2[]){
    int i=0,j=0,k=0;
    vector<int> ans(n+m);
    while(i<n and j<m){
        if(arr1[i]<arr2[j]){
            ans[k++]=arr1[i++];
        }
        else{
            ans[k++]=arr2[j++];
        }
    }
    while(i<n){
        ans[k++]=arr1[i++];
    }
    while(j<m){
        ans[k++]=arr2[j++];
    }
    return ans;
}

void merge(long long arr1[], long long arr2[], int n, int m) //Sort without extra space
{ 
    // code here 
    int i=0,j=0,k=n-1;
    while(i<n and j<m){
        if(arr1[i]>arr2[j]){
            swap(arr1[k--],arr2[j++]);
        }
        else i++;
    }
    sort(arr2,arr2+m);
    sort(arr1,arr1+n);
} 


//Ques : Given an array which contains both positive and negative numbers in sorted order. Now, sort the square of elements of array.
//BruteForce approach is to first generate all the squares in same array and then sort it with O(nlogn) complexity.
//Optimized version : Graph of square is parabolic and is curved from 0. So we can divide the array from 0 into both positive and negative and then merge two divided parts after generating squares.

vector<int> sortSquareArray(int n,int arr[]){
    int x,y;
    for(int i=0;i<n;i++){
        if(arr[i]<0) x=i;
        arr[i]=arr[i]*arr[i];
    }
    y=x+1;
    int k=0;
    vector<int> ans(n);
    while(x>=0 and y<n){
        if(arr1[i]<arr2[j]){
            ans[k++]=arr1[x--];
        }
        else{
            ans[k++]=arr2[j++];
        }
    }
    while(x>=0){
        ans[k++]=arr1[x--];
    }
    while(j<n){
        ans[k++]=arr2[j++];
    }
    return ans;
    
}

/*Ques : Given a sorted array and three integers A,B,C. Sort the array after applying the following equation :
        a[i]=A*(a[i]*a[i]) + B*(a[i]) + C 
    Sol : Find the pivot in the array by iterating through the array and then merging the two sorted part using above algorithm
          Second way is to find slope of the equation which would provide us the point from where the graph of the equation is rebounding and then we can merge two sorted part on that point */

/*MergeSort : It can be seen as optimization in insertion sort. In insertion sort , we insert an element in the sorted array. 
              But this increases the time complexity since we are inserting only one element . 
              We can optimize it as to divide to array into two equal halves instead of dividing it in n-1 and 1 elements. 
              In merge Sort, we insert half of the array to the other when they become sorted.*/

void merge(int arr[],int s1,int s2,int e1,int e2,int n){
    int i=s1,j=s2,k=s1;
    int ans[n];
    while(i<=e1 and j<=e2){
        if(arr[i]<arr[j]){
            ans[k++]=arr[i++];
        }
        else{
            ans[k++]=arr[j++];
        }
    }
    while(i<=e1){
        ans[k++]=arr[i++];
    }
    while(j<=e2){
        ans[k++]=arr[j++];
    }
    for(int x=s1;x<=e2;x++){
        arr[x]=ans[x];
    }
}
void MS(int arr[],int i,int j,int n){
    if(i==j) return;
    int m=(i+j)/2;
    MS(i,m);
    MS(m+1,j);
    merge(arr,i,m,m+1,j,n);
}

//Ques : Given an array of size N. Find number of pair(i,j) such that i<j and arr[i]>arr[j]. (Inversion Count)
// Solution : Basically , we need to update the mergeSort function and we have to add a part of code which adds the number of intra (i,j) pairs within two divided arrays to the answer.

