/******************************************************************************

BACKTRACKING and PRUNNING IN BACKTRACKING
*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

/*Note : Pass by value leads to higher Space Complexity because on each call it creates a seperate data structure
         Hence , to avoid this we use Pass by reference in recursion and backtracking
         Backtracking is all about three steps
         1. Do Change
         2. Call the function
         3. Undo the Change*/
         
void generateAllSubsets(int i,vector<int>& v){ // generate all the subsets of a given vector
    int N=v.size();
    if(i==N){
        print(v);
        return;
    }
    v.push_back(a[i]); //do Change
    generateAllSubsets(i+1,v); // call function
    v.pop_back(); // undo Change
    generateAllSubsets(i+1,v);
}

void generateAllPermutation(int i,string s){ //Given a string and we need to print all the permutation of a string
    if(i==n-1){
        print(s);
        return;
    }
    for(int x=i;x<n;x++){
        swap(s[i],s[x]);
        generateAllPermutation(i+1,s);
        swap(s[i],s[x]);
    }
}

// Now what if the question is twisted to print all the permutations in a lexicographical order.
// It is noticed that when we swap , the sort property of the string is disturbed and hence we can't get string in lexicographical order
// The solution to this is we can rotate the substring part instead of swap it and then unrotate the same substring to bring back it in original state.

void generateAllPermutationV1(int i,string s){ //Given a string and we need to print all the permutation of a string
    if(i==n-1){
        print(s);
        return;
    }
    for(int x=i;x<n;x++){
        rotate(s[i],s[x]);
        generateAllPermutationV1(i+1,s);
        rotate(s[i],s[x]);
    }
}

// Now lets have one more twist on the question , what if the string given contains repeated characters
// If we use the above two methods it will generate repeated permuations which is obviously not accepted
// The solution for this is to use a bool array and mark the already visited characters , to avoid repeated answers

void generateAllPermutationV2(int i,string s){ //Given a string and we need to print all the permutation of a string
    if(i==n-1){
        print(s);
        return;
    }
    for(int x=i;x<n;x++){
        if(!vis[s[x]]){
            swap(s[i],s[x]);
            generateAllPermutationV2(i+1,s);
            swap(s[i],s[x]);
            vis[s[x]]=true;
        }
    }
}

/* N-Queens Problem
    Given a n*n matrix(chess) , you need to place n queens so that any of the queen can't attack other from that position*/
    
void NQueensFunc(int r,int n, int[][] arr){
    if(r==n){
        print(arr);
        return;
    }
    for(int j=r;j<n;i++){
        if(isSafe(r,j,arr)){
            arr[r][j]=1;
            nQ(r+1,n,arr);
            arr[i][j]=0;
        }
    }
}

//isSafe() is function which checks the condition that the placed queens can't attack the other from their positions.
