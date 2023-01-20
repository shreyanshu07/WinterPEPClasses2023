/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

/*********************STACK********************************/
/*Applications of Stack : 
    1. Undo Redo Operations
    2. Recursive calls
It is a one ended data structure (First IN First OUT)
To create stack we need 1. An array of abounded space - arr[n]
2. Maintain a top variable

Functions of stack 
    1. void push(int x) => write operations => O(1)
    2. void pop() => write operation => O(1)
    3. int top() => read operation => O(1)
    4. bool isEmpty() => read operation => O(1)
    5. bool isFull() =>read operation => O(1) */

struct stack{
    int arr[1000];
    int top;
}  
struct stack s;
s.top=-1;
void push(int x){
    if(top==n-1){
        cout<<"Overflow"<<endl;
        return;
    }
    s.arr[++s.top]=x;
}
void pop(){
    if(top==-1){
        cout<<"Underflow"<<endl;
        return;
    }
    s.top--;
}
int top(){
    if(s.top==-1){
        cout<<"Underflow"<<endl;
        return -1;
    }
    return s.arr[s.top];
}

//Ques : Implement two stack within one array
// Solution : Brute Force is to divide the array into two parts and use them as two independent stacks.
// Cons: Wastage of memory in case of full of one part while other is empty.
// Solution to this is to fill the elements from both the ends of the array. When they will about to collide print "Overflow"

struct Stack{
    int arr[1000];
    int top1=-1,top2=1000;
}
struct Stack s;
void push1(int x){
    if(top1+1==top2){
        cout<<"Overflow"<<endl;
        return;
    }
    arr[++top1]=x;
}

void push2(int x){
    if(top2-1==top1){
        cout<<"Overflow"<<endl;
        return;
    }
    arr[--top2]=x;
}

void pop1(){
    if(top1==-1){
        cout<<"Underflow"<<endl;
        return;
    }
    top1--;
}

void pop2(){
    if(top2==1000){
        cout<<"Underflow"<<endl;
        return;
    }
    top2++;
}

int top1(){
    if(top1==-1){
        cout<<"Underflow"<<endl;
    }
    return top1;
}

int top2(){
    if(top2==1000){
        cout<<"Underflow"<<endl;
    }
    return top2;
}
//Ques : Implement pushBottom(int x) using stack operations.
// BruteForce : Take an auxiliary stack. On every call , take out all the elements and then first push the new element after that put all the elements one by one.
// Do the above thing recursively

void pushBottom(int x,stack<int>& s){
    if(s.empty()){
        s.push(x);
    }
    int temp=s.top();
    s.pop();
    pushBottom(x,s);
    s.push(temp);
}

// Ques : Given an integer array . Generate next greater element for every element in array.
// Eg : arr : [4,5,2,25]
//      NGE : [5,25,25,-1]

// Solution : BruteForce Using two nested loops and then find it for every element.
// Optimal Solution : Using monotonic Stack || TC : O(n)

vector<int> NGEfunc(int n,vector<int> a){
    stack<int> s;
    vector<int> NGE(n)
    for(int i=0;i<n;i++){
        while(!s.empty() and a[i]>a[s.top()]){
            NGE[s.top()]=a[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        NGE[s.top()]=-1;
        s.pop();
    }
    return NGE;
}

// Ques: Largest Area Rectangle 
// Solution :
vector<int> nextSmallerElement(vector<int> v){
    int n=v.size();
    stack<int> s;
    vector<int> nse(n);
    for(int i=0;i<n;i++){
        while(!s.empty() and v[s.top()]>v[i]){
                nse[s.top()]=i;
                s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        nse[s.top()]=n;
        s.pop();
    }
    return nse;
}
vector<int> prevSmallerElement(vector<int> v){
    int n=v.size();
    stack<int> s;
    vector<int> nse(n);
    for(int i=n-1;i>=0;i--){
        while(!s.empty() and v[s.top()]>v[i]){
                nse[s.top()]=i;
                s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        nse[s.top()]=-1;
        s.pop();
    }
    return nse;
}
int largestRectangleArea(vector<int>& v) {
    int n=v.size();
    vector<int> a=nextSmallerElement(v),b=prevSmallerElement(v);
    int ans=0;
    for(int i=0;i<n;i++){
        int num=(a[i]-b[i]-1)*v[i];
        ans=max(ans,num);
    }
    return ans;
}
