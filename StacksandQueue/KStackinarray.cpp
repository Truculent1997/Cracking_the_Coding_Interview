/*
Approach1:
For the K=3
One stack from the begining and one stack from the end and third one in the middle somewhere for third stack shifting 
is always is required each time stack becomes full from one side.
Space complexity is good but facing problems in the time complexity.

Approach2:
Divide by K for each segment 

Approach3:
Multiplying by 3*i+sno
for getting the required element index.
Approach 2 is better than the Approach 3 due to cache in the array processing time in latter version array elements from the same
stack are far apart from each other.


Apporach 4:
It is useful stack of  big data structure since we are going to take extra space.
We are just forming the linked list of free spaces actually where head element of that list contains current free space 
whenever free space is equal -1 that means no free space is remaining 
*/
/*
 	“When you’re not practicing, somebody else is. And the day you meet them, you will lose.”
 */
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int lu;
long n,x,y,t,a,b,c;
set<long> m1;
bitset<500005> vis;
class KStacks{
    int *arr;
    int *top;
    int *next;
    int n,k;
    int overtop;
    public:
        KStacks(int n1,int k1){
            n=n1;k=k1;
            overtop=0;
            arr=new int[n1];
            top=new int[k1];
            next=new int[n1];
            for(int i=0;i<k1;i++){
                  top[i]=-1;  
            }
            for(int i=0;i<n1-1;i++){
                next[i]=i+1;
            }
            next[n1-1]=-1;
        }
        void push(int sno,int val){
            if(overtop==-1){
                  cout<<"Overflow()\n";
                  return ;  
            }
            else{
                arr[overtop]=val;
                int i=next[overtop];
                next[overtop]=top[sno];
                top[sno]=overtop;
                overtop=i;
                cout<<"\Element added into the stack";
            }
        }
        void pop(int sno){
            if(top[sno]==-1){
                cout<<"Underflow of the stack";
            }
            else{
                int prev=top[sno];
                top[sno]=next[prev];
                next[prev]=overtop;
                overtop=prev;
                cout<<"Element deleted is "<<arr[prev]<<endl;
            }
        }

};
int main(){
    int k=3;
    cout<<"N:";
    cin>>n;
    KStacks ks(n,k);
    while(1){
        cout<<"\n1:Push\n2:Pop\nChoice:";
        cin>>x;
        if(x==1){
            cin>>a>>b;
            ks.push(a-1,b);
        }
        else{
            cin>>a;
            ks.pop(a-1);
        }
    }
    return 0;
   
}
