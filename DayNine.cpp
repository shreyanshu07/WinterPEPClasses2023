/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

/*********************QUEUE***************/
/* Doubly ended data structures ||First In First Out */
/* Real World Application => 
    1. Web server request handling
    2. CPU Scheduling */
    
//Ques : Implement queue using array
 struct Queue{
    int arr[1000];
    int front ,rear;
}
struct Queue q;

bool isEmpty();
void pop();
void push(int x);
int front();
int back();

/*When we try to implement queue in array we need to have circular implementation of array because once the rear pointer reaches end it should go to the start index if it is vacant.
This will save the space and use the array optimally.
overflow condition : front == (rear+1)%N; rear == (front+1)%N;
To distinguish above conditions we need to rely on cnt variable 
if cnt==0 => underflow 
if cnt==1000 => overflow*/

//Ques : Reverse a queue (Well known question)

// BruteForce Approach : Using stack || TC : O(n) SC : O(n)
// Using recursion (This could be the follow up question once you solve with the above approach)

void reverseQueue(queue<int>& q){
    if(q.empty()){
        return;
    }
    int temp=q.front();
    q.pop();
    pushBottom(q);
    q.push(temp);
}

//Ques : Implement Queue using Stack 
// Solution : Using two stacks where push operation can be O(1) and pop operation can be O(n)
class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        this->s1.push(x);
    }
    
    int pop() {
        while(!this->s1.empty()){
            this->s2.push(this->s1.top());
            this->s1.pop();
        }
        int ans=this->s2.top();
        this->s2.pop();
        while(!this->s2.empty()){
            this->s1.push(this->s2.top());
            this->s2.pop();
        }
        return ans;
    }
    
    int peek() {
        while(!this->s1.empty()){
            this->s2.push(this->s1.top());
            this->s1.pop();
        }
        int ans=this->s2.top();
        while(!this->s2.empty()){
            this->s1.push(this->s2.top());
            this->s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return this->s1.empty();
    }
};

//Ques : Implement Stack using queue 
//Solution : 
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

//Ques : Reverse a stack 
// Solution : Both recursive and iterative

void reverseStack(stack<int>& s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    reverseStack(s);
    s.push(temp);
}

//Ques : (IMP) +ve integer n is given. Print "N" +ve numbers whose digits belongs to {1,2,3}
//Eg : N=10 => ans[]={1,2,3,11,12,13,21,22,23,31}
//BruteForce approach is to start from 1 and then check each number if the digits in them belong {1,2,3} then push it otherwise leave it.

//Optimal approach : Using queue data structure
/*  1. Push 0 initially in the queue
    2. Take one element and push it to ans(not the 0) and add 1,2,3 at last of it and push the three into same queue.
    3. After ans has n elements return the ans vector/array */

void solve(int n){
    queue<int> q;
    q.push(0);
    int cnt=0;
    while(cnt<n){
        int x=q.front();
        q.pop();
        if(x!=0){
            cout<<x<<" ";
            cnt++;
        }
        q.push((x*10)+1);
        q.push((x*10)+2);
        q.push((x*10)+3);
    }
}

//Ques : Given an array of n elements. Find the maximum element from every contiguous subarray of size k.
// Eg : Arr[]=5,3,6,4,9,8,7,11,7,15 || k=4 
//        Ans[]={6,9,9,11,11,15}

//Sol: Brute Force approach is use sliding window technique of window size k and then find maximum in every possible window with help of a loop || TC:O(n)
// Note: Simple sliding window is not a possible solution . You can use sliding window with map or set data structure

//Optimal way is to make use of Doubly ended Queue. 

vector<int> solve(vector<int> nums,int k){
    deque<int> q;
    vector<int> v;
    int n=nums.size();
    for(int i=0;i<k;i++){
        while(!q.empty() and q.back()<nums[i]){
            q.pop_back();
        }
        q.push_back(nums[i]);
    }
    v.push_back(q.front());
    for(int i=k;i<n;i++){
        if(nums[i-k]==q.front()) q.pop_front();
        while(!q.empty() and q.back()<nums[i]){
            q.pop_back();
        }
        q.push_back(nums[i]);
        v.push_back(q.front());
    }
    return v;
}

vector<int> solve(vector<int> nums,int k){ //Using hashmaps in sliding window
    map<int,int,greater<int>> mp;
    vector<int> v;
    int n=nums.size();
    for(int i=0;i<k;i++) mp[nums[i]]++;
    auto it=mp.begin();
    v.push_back(it->first);
    for(int i=k;i<n;i++){
        mp[nums[i]]++;
        auto it=mp.find(nums[i-k]);
        it->second--;
        if(it->second==0) mp.erase(nums[i-k]);
        it=mp.begin();
        v.push_back(it->first);
    }
    return v;
}

