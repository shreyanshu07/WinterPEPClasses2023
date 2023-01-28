/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

/*********************************Questions on Binary Trees************************************/
//Ques: Count complete tree nodes
//SOl : BruteForce
int count(Node* root){
    if(!root) return ;
    return 1+count(root->left)+count(root->right);
    
}

//But in the above approach we are not making use of the complete binary tree 
//Follow Up: Can we improve the time complexity from O(n)?

//Try to use binary search to get the last filled node of the tree. Rest work can be done in O(1). We can calculate the number of nodes in a tree with complete with given number of levels
//Number of nodes in the tree of n levels =(2^n) - 1
//Number of nodes in the nth level = 2^(n-1)

bool isNull(int x,int l,int h,Tree* root) { // Function to find the xth node in last level is null or not.
    Node* temp=root;
    while(l<h){
        int m=l+((h-l)/2);
        if(x<=m){
            temp=temp->left;
            h=m;
        }
        else{
            temp=temp->right;
            l=m+1;
        }
        
    }
    if(!tmp) return true;
    return false;
} 

int findNullNode(int h,Tree* root){ //Finds the position of last node with value in the tree traversing levelwise 
    int l=1,r=2^(n-1),llcnt=2^(n-1);
    while(l<=r){
        int m=(l+r)/2;
        if(isNull(M,1,llcnt,root)) r=m-1;
        else if(M==llcnt or isNull(M+1,1,llcnt,root)) return m;
        else l=m+1;
    }
    return 0;
}// Uses binary Search to locate 

int getHeight(Tree *root){ //Returns height of the tree 
    if(!root) return 0;
    return 1+getHeight(root->left);
}

int countNode(Tree *root){ // The main function
    int height=getHeight(root);
    int ans=2^(height-1) -1;
    ans+=findNullNode(root);
    return ans;
}

// Time complexity of the above code is O(logn*logn)

// Follow up: Can we do still better ?
//Both left and right tree can't be imperfect when whole tree is gaurenteed to be complete binary tree 
pair<bool,int> isPerfect(Tree* root){ // returns two value 1. whether tree is perfect or not 2. height of left side
    Tree* temp=root;
    int lh=0;
    while(temp){
        lh++;
        temp=temp->left;
    }
    temp=root;
    int rh=0;
    while(temp){
        rl++;
        temp=temp->right;
    }
    return {lh==rh,lh};
}
int countNodes(TreeNode* root){
    if(!root) return 0;
    int cnt=1;
    pair<bool,int> pleft=isPerfect(root->left);
    pair<bool,int> pright=isPerfect(root->right);
    if(pleft.first){ //if left side is perfect then simply use formula to cal number of nodes
        cnt+=pow(2,pleft.second)-1;
    }
    else{  //else go to the left subtree
        cnt+=countNodes(root->left);
    }
    if(pright.first){ //if right side is perfect then simply use formula to cal number of nodes 
        cnt+=pow(2,pright.second)-1;
    }
    else{
        cnt+=countNodes(root->right);
    }
    return cnt;
}

