/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namspace std;

/****************LINKED LIST***********************/
struct Node{
    int data;
    struct Node* next;
}
struct Node a;//This is static allocation of a node but most of the times the allocation is dynamic in case of linkedLists

Dynamic allocation => ptr=(struct Node*)malloc(sizeof(struct Node));

//Ques : Traverse a linkedLists and print all the values.

void print(struct Node* head){
    struct Node* temp=head;
    while(temp){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
// Never use the head pointer of a linkedlist , instead make your own temp pointer variable.

//Follow up Ques: Print the linkedList recursively

void print(struct Node* head){
    if(!head) return;
    cout<<head->data<<endl;
    print(head->next);
}

//Ques: Implement linkedList using array. 
//OPerations on linkedList: 1. insert operation 2. delete operation.

//Ques: Print the middle node in a linkedList . 
//BruteForce : Using two pass algorithm. First traverse to determine the length and then traverse length/2 to reach middle node.
//Optimal Approach: Using Slow and fast pointer (One-pass algo)

void printMiddle(struct Node* head){
    struct Node* fast=head;
    struct Node* fast=slow;
    while(fast and fast->next){
        s=s->next;
        fast=fast->next->next;
    }
    cout<<s->data<<endl;
}

//Ques: Given a linkedList , and an integer k. Print the (L/k)th node of the linkedList from beginning.
// Brute Force Approach using two pass algorithm
int fractional_node(struct Node *head, int k)
{
    // your code here
    int n=0;
    Node *ptr = head;
    while(ptr!=NULL){
        n++;
        ptr=ptr->next;
    }
    int num=ceil((n*1.0)/(k*1.0));
    ptr=head;
    
    while(--num){
        ptr=ptr->next;
    }
    return ptr->data;
}
//Optimal Approach : One pass 
int fractional_node(struct Node *head, int k)
{
    // your code here
    struct Node *fast=head;
    struct Node *slow=head;
    while(fast){
        int x=k;
        while(x-- and fast){
            fast=fast->next;
        }
        if(!fast) return slow->data;
        slow=slow->next;
    }
}

//Ques: Reverse a linkedList.
//Brute Optimal Approach: Using stack and two pass algorithm || First store all the elements in the stack and then pop one by by and create node.
//NOTE : It's better not to tamper with the values of linkedList instead try to change the links of the linkedList.

//Optimal Approach:

void reverseLL(struct Node* head){
    struct Node* prev=NULL;
    struct Node* curr=head;
    while(curr){
        struct Node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head= prev;
}

//Follow up : Solve the above code recursively

void recur(struct Node* prev,struct Node* curr){
    if(!curr) return;
    struct Node* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
    recur(prev,curr);
}
void recurReverseLL(struct Node* head){
    struct Node* prev=NULL;
    struct Node* curr=head;
    recur(prev,curr);
    head=prev;
}

//Ques : Check if the linkedList is palindrome or not 
//Sol : BruteForce - Using Stack (Push elements into the stack and then compare values one by one, if all the values are in same order , return true else false;)

//Optimal Approach is to reverse half of LinkedList and then compare two halfs (Note: Take care of ODD and EVEN lengths)

bool isPalindrome(ListNode* head) {
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast!=nullptr and fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }
    ListNode* prev=nullptr;
    ListNode* curr=slow;
    while(curr){
        ListNode* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    fast=head;
    slow=prev;
    while(fast and slow){
        if(fast->val != slow->val) return false;
        fast=fast->next;
        slow=slow->next;
    }
    return true;
}

// Amazon Interview Question : Flatten an LinkedList
// Solution to this is traverse the linkedlist till last . Now start traversing the list again . when you find a branch , add that branch to the last ptr and the move last ptr to last of list and repeat the process.

