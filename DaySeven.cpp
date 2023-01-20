/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;

/*************************** HASHMAP *************************/

//Ques: Store the frequency of all the elements of an array.
//Brute Force : Sort the array and then count numbers of element in array. O(n logn)
// More Optimal approach is to declare an array of size(max element in array) and initially initialize it with 0's.
//              then increment the frequency by one once you encounter the element.
// One of the biggest demerit of the above algo is when it contains really large elements (10^18) , we will encounter space limit exceed error most of the times.
// So to solve the above problem we use map/hashmap to count frequency of elements

/* Hashing is a smart strategy to maintain a large range of data in limited space.
    HashFunction : It takes key as input and then allocates slot for the given input. A good hash function ensures uniform distribution.
    Key Should always be unique and value can be duplicate.
Here , comes concept of collision when pairs have same key and different values. then we will use a linked list to keep a track of values that map to same key.

Functions of maps : 1. void put(k,v);
                    2. int get(k);
                    
Time Complexities of both functions :

Insertions are normally proportional to Log2N as well--but there's a special provision made for when you're inserting a number of items that are already in order1. 
In this case, you can specify a "hint" for where an insertion is going to take place. 
When that hint is correct, each insertion is (amortized) O(1) instead of O(Log N), so inserting a range of items in sorted order is linear instead of N log(N). 
The hint you specify is an iterator to the position just after the item to be inserted.

Hence average time complexity of put(k,v) and get(k) is almost O(1). But worst time complexity of both the function is O(n)

One thing to note is that when we storing string in the map it would take a little more time ie O(size of largest string as key)*/

//Ques : Given an unsorted array , check if there exists a pair such that it sums equal to "k".

//Solution: One solution is to sort the array and then apply two pointer approach to find || TC :O(n logn)
//Another optimized approach is to to store all the elements in a map and the check if k-a[i] is present or not.

bool checkSum(int arr[],int n){
    map<int,int> mp;
    for(int i=0;i<n;i++) mp[arr[i]]++;
    for(int i=0;i<n;i++){
        if(mp.find(k-a[i])!=mp.end()) return true;
    }
    return false;
}

//Ques: Given an unsorted array of integers. Check if there is a subarray whose sum is 0.

//Solution: BruteForce Approach is to use three for loops and find sum of every possible subarray and the check for it. //TC:O(n^3)
// More optimal way is to create a prefix sum array and then have two for loops to find sum of every possible subarray and check for it. || TC:O(n^2)
// Most optimal way is to first create a prefix sum array and then store all the element of prefix sum array one by one into the map. If the element has already been occured then we get assurance that there is a subarray with sum 0.

bool checkSubarraySum(int arr[],int n){
    map<int,int> mp;
    mp[0]++;
    int prefixSum=0;
    for(int i=0;i<n;i++){
        prefixSum+=arr[i];
        if(mp.find(prefixSum)!=mp.end()){
            return true;
        }
        else mp[prefixSum]++;
    }
    return false;
}

//Ques: Given an unsorted array of integers. Return the length of longest subarray whose sum is equal to 0

int lengthSubarraySum(int arr[],int n){
    int prefixSum=0,maxi=0;
    map<int,int> mp;
    mp[prefixSum]++;
    for(int i=0;i<n;i++){
        prefixSum+=arr[i];
        if(mp.find(prefixSum)!=mp.end()){
            maxi=max(maxi,(i-mp[prefixSum]));
        }
        else{
            mp[prefixSum]=i;
        }
    }
    return maxi;
}

/* We got N Queries => There are 3 types of queries 
    1. '+' integer => adds an number to the bag 
    2. '-' integer => remove one occurence of the number from bag 
    3. '?' binaryString => Return all the integers with 01 pattern where 0 means even and 1 means odd*/
    
long long convert(string s){
    int n=s.size();
    long long a=1,ans=0;
    while(n--){
        if(s[n-1]){
            ans+=a;
        }
        a*=2;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            char c;cin>>c;
            if(c=='+'){
                string s="";
                int num;cin>>n;
                while(n){
                    if((n%10)%2==0){
                        s+="0";
                    }
                    else s+="1";
                    n/=10;
                }
                reverse(s.begin(),s.end());
                long long a=convert(s);
                mp[a]++;
            }
            else if(c=='-'){
                string s="";
                int num;cin>>n;
                while(n){
                    if((n%10)%2==0){
                        s+="0";
                    }
                    else s+="1";
                    n/=10;
                }
                reverse(s.begin(),s.end());
                long long a=convert(s);
                mp[a]--;
            }
            else{
                string s;cin>>s;
                long long a=convert(s);
                if(mp.find(s)!=mp.end()){
                    cout<<mp[s]<<endl;
                }
                else cout<<0<<endl;
            }
        }
    }
}
