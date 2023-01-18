/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

/*********TWO POINTERS**************/

/*Ques: Given an sorted array of size N , check if there is a pair with sum==k (Two Sum Problem)
 Brute Force : Using two nested for loops check the sum of every possible pairs and then return true if found else false. O(N*N)
 Optimized Approach : Make use of sorted array and for each element do BinarySearch of (key-a[i]) and then return true if found else false. O(NlogN)
 More Optimized Approach : Two pointer approach.
    Initialize first pointer at starting and second pointer at the last element.if sum of both pointed elements is less, move starting pointer towards end.
    if sum of both pointed elements is more ,move ending pointer towards starting end. else return true in case we got sum==key */
bool twoSum(int arr[],int n,int key){
    int i=0,j=n-1;
    while(i<j){
        int curr=arr[i]+arr[j];
        if(curr==key) return true;
        else if(curr<key) i++;
        else j--;
    }
    return false;
}

/*Somethings to figure out before solving pointer problems
    1. How many pointers are needed ?
    2. Initial position of the pointers ?
    3. How to move these pointers ? (In which direction) */

/*Ques : Given an sorted array of size N , return number of distinct pairs which can sum to key. Array can contain duplicate elements*/

/*Ques : Given an sorted array of size N, check if there is a pair such that a[i]-a[j]==k where k is a number >=0.

approach 1 : Brute Force => Check for every possible pairs using two for loops. O(N*N);
approach 2 : Using BinarySearch (explained above)
approach 3 : Using Two pointers.

Next version of ques : Can contain duplicate elements. */

/*Ques : Given an array of size N which is sorted and don't contain duplicates. Find number of rectangles with distinct configuration that can be formed using array elements as dimensions whose area is less than B.
 Eq : arr[]={2,3,5} ; B=15
        ans : 4 */

int uniqueRectangles(int arr[],int n,int d){
    int i=0,j=n-1,ans=0;
    while(i<=j){
        area=a[i]*a[j];
        if(area>=d) j--;
        else{
            ans+=(((j-i+1)*2)-1);
            i++;
        }
    }
    return ans;
}

/*Ques : Given three sorted arrays A,B,C of size N. Minimize the following equation : max(A[i],B[j],C[k])-min(A[i],B[j],C[k]).
        Find i,j,k such that equation value is minimum.*/
