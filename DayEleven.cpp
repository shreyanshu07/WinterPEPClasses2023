/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

/**************Questions on LinkedList**************************/

//Ques: Copy List with Random Pointer (Google Interview Question)

//Solution: 
//BruteForce Approach is to first create a copy of linkedList and then for each node find the random pointer's distance from starting node. 
//After knowing the distance traverse till same distance in copied Linkedlist and then declare that as random pointer of that node.
//Do this step for each node || TC: O(n^2) and SC : O(1)

//Optimal Approach is to use a hashMap and then store {Node,CopyNode} key,value pair so that we can convert the random address of old linkedList.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

Node* copyRandomList(Node* head) {
    Node* head2=nullptr;
    Node* ptr=head;
    Node* ptr2;
    while(ptr){
        if(!head2){
            Node* temp=new Node(ptr->val);
            temp->val=ptr->val;
            temp->next=NULL;
            temp->random=NULL;
            head2=temp;
            ptr2=temp;
            ptr=ptr->next;
        }
        else{
            Node* temp=new Node(ptr->val);
            temp->val=ptr->val;
            temp->next=NULL;
            temp->random=NULL;
            ptr2->next=temp;
            ptr2=ptr2->next;
            ptr=ptr->next;
        }
    }
    map<Node*,Node*> mp;
    ptr=head;
    ptr2=head2;
    while(ptr){
        mp.insert({ptr,ptr2});
        ptr2=ptr2->next;
        ptr=ptr->next;
    }
    ptr=head;
    ptr2=head2;
    while(ptr){
        ptr2->random=mp[ptr->random];
        ptr2=ptr2->next;
        ptr=ptr->next;
    }
    return head2;
}

//Best Approach : Without using extra space 

Node* copyRandomList(Node* head) {
    Node* ptr=head;
    while(ptr){
        Node* temp=new Node(ptr->val);
        temp->next=ptr->next;
        ptr->next=temp;
        ptr=ptr->next->next;
    }
    ptr=head;
    while(ptr){
        if(ptr->random)
            ptr->next->random=ptr->random->next;
        else
            ptr->next->random=NULL;
        ptr=ptr->next->next;
    }
    ptr=head->next;
    while(ptr->next){
        ptr->next=ptr->next->next;
        ptr=ptr->next;
    }
    head=head->next;
    ptr=head;
    while(ptr){
        cout<<ptr->val<<" .";
        if(ptr->random) cout<<ptr->random->val<<" ";
        else cout<<"NULL ";
        ptr=ptr->next;
    }
    return head;
}

//Merge two sorted linkedList 
//Brute approach is to use a extra space and create a seperate linkedList .

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* list3=nullptr;
    ListNode* ptr1=list1;
    ListNode* ptr2=list2;
    ListNode* ptr3=nullptr;
    while(ptr1 and ptr2){
        if(ptr1->val<=ptr2->val){
            struct ListNode* temp=new ListNode();
            temp->val=ptr1->val;
            temp->next=nullptr;
            if(!list3){
                ptr3=temp;
                list3=temp;
            }
            else{
                ptr3->next=temp;
                ptr3=ptr3->next;
            }
            ptr1=ptr1->next;
        }
        else{
            struct ListNode* temp=new ListNode();
            temp->val=ptr2->val;
            temp->next=nullptr;
            if(!list3){
                ptr3=temp;
                list3=temp;
            }
            else{
                ptr3->next=temp;
                ptr3=ptr3->next;
            }
            ptr2=ptr2->next;
        }
    }
    while(ptr1){
        struct ListNode* temp=new ListNode();
        temp->val=ptr1->val;
        temp->next=nullptr;
        if(!list3){
            ptr3=temp;
            list3=temp;
        }
        else{
            ptr3->next=temp;
            ptr3=ptr3->next;
        }
        ptr1=ptr1->next;
    }
    while(ptr2){
        struct ListNode* temp=new ListNode();
        temp->val=ptr2->val;
        temp->next=nullptr;
        if(!list3){
            ptr3=temp;
            list3=temp;
        }
        else{
            ptr3->next=temp;
            ptr3=ptr3->next;
        }
        ptr2=ptr2->next;
    }
    return list3;
}

//Optimal Approach : By changing the linkes(next pointer) of the linkedList

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *a=list1,*b=list2,*list3=nullptr,*tailptr=nullptr;
    if((!a)) return b;
    if(!b) return a;
    if(a->val<=b->val){
        list3=a;
    }
    else{
        list3=b;
    }
    while(a and b){
        if(a->val<=b->val){
            if(!tailptr){
                tailptr=a;
                a=a->next;
            }
            else{
                tailptr->next=a;
                tailptr=tailptr->next;
                a=a->next;
            }
        }
        else{
            if(!tailptr){
                tailptr=b;
                b=b->next;
            }
            else{
                tailptr->next=b;
                tailptr=tailptr->next;
                b=b->next;
            }
        }
    }
    if(a){
        tailptr->next=a;
    }
    if(b){
        tailptr->next=b;
    }
    return list3;
}

//Follow Up Question is to do the above using recursion
void merge(ListNode* a,ListNode* b,ListNode* tailptr){
    if(!a and !b) return;
    if(a and !b){
        tailptr->next=a;
        return;
    }
    if(!a and b){
        tailptr->next=b;
        return;
    }
    if(a->val<=b->val){
        if(!tailptr){
            tailptr=a;
            a=a->next;
        }
        else{
            tailptr->next=a;
            tailptr=tailptr->next;
            a=a->next;
        }
    }
    else{
        if(!tailptr){
            tailptr=b;
            b=b->next;
        }
        else{
            tailptr->next=b;
            tailptr=tailptr->next;
            b=b->next;
        }
    }
    merge(a,b,tailptr);
    return;
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *a=list1,*b=list2,*list3=nullptr,*tailptr=nullptr;
    if((!a)) return b;
    if(!b) return a;

    if(a->val<=b->val){
        list3=a;
    }
    else{
        list3=b;
    }
    merge(a,b,tailptr);
    return list3;
}

//Ques: Flatten a sortedLinkedList in single LinkedList 
//Sol: It can be done using merge function implemented above.
