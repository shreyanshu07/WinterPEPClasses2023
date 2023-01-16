/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

/************** SORTING ***************************/
//Comparator : Function that is used with built-in sort function , which returns true if argument1 should appear before argument2 in sorted version of array.

bool myCmp(int a,int b){ //default Comparator
    if(a<b) return true;
    return false;
}

bool myCmp(int a,int b){ //reverse a array
    if(a>b) return true;
    return false;
}

bool myCmp(int a,int b){ //sort the array without considering the sign
    return abs(a)<abs(b)
}

bool myCmp(int a,int b){//sort the array based on odd and even (first even elements will occur and the odd elements)
    return a%2==0;
}

bool myCmp(int a,int b){ //First sort the array based on odd and even and then the even should appear increasing and odd should appear should appear decreasing
    if(a%2==0 and b%2!=0) return true;
    else if(a%2!=0 and b%2==0) return false;
    else if(a%2==0 and b%2==0) return a<b;
    else a>b;
}

bool myCmp(pair<int,int> a,pair<int,int> b){ //sort pair of int , if the first value is same then sort according to the second value
    if(a.first!=b.first) return a.first<b.first;
    return a.second<b.second;
}

/***********BubbleSort***************************************/

//Bubbling means make every adjacent numbers collide with each others

void bubbleSort(int arr[],int n){
    bool done=false;
    while(!done){
        done=true;int i=0;
        while(i<n-1){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                done=false;
            }
            i++;
        }
    }
}

//Google CodeJam Ques : Apply TroubleSort on the array and tell the output without actually appling troubleSort function
//TroubleSort : Iterate the whole array with a window of size 3 and if a[0]>a[2] the swap both of them

void troubleSort(int arr[],int n){
    bool done=false;
    while(!done){
        done=true;int i=0;
        while(i<n-2){
            if(a[i]>a[i+2]){
                swap(a[i],a[i+2]);
                done=false;
            }
            i++;
        }
    }
}

//Note : to get troubleSort we can also sort the elements in odd and even indexes seperately. This will provide is the resultant array after troubleSort without actually applying it in O(nlogn) time.

