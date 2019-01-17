/*
Approach 1: Basic 
Make an extra auxillary stack which is going to store  all the value which are smaller than or equal to current top of the 
stack .
When we pop element if minimum is equal to stack top that means current element was helping in the minimum element.
Now minimum element will be second element in minimum stack.

Approach:Using a single variable
Why 2*x-cur_minielement
Whenever current is smaller than previous minimum we do this because 2*x-cur_minielement will always be smaller than x and while
poping element the smaller element than current minimum appears we know this is the which corresponds to the minimum element. 
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
    stack<int> s;
    int mini;
    public:
        KStacks(){}
        void push(int val){
                if(s.empty()){
                    mini=val;
                    s.push(val);
                }
                else{
                    if(s.top()<=val){
                        s.push(val);
                    }
                    else{
                        int x=2*val-mini;
                        s.push(x);
                        mini=val;
                    }
                }
                cout<<"\Element added into the stack";
        }
        void pop(){
            if(s.empty()){
                cout<<"Underflow of the stack";
            }
            else{
                int prev;
                if(s.top()>=mini){
                   prev=s.top();
                   s.pop();     
                }
                else{
                    prev=mini;
                    mini=2*mini-s.top();    
                }
                cout<<"Element deleted is "<<prev<<endl;
            }
        }
        void minimum(){
            if(s.empty())cout<<"\nStack is empty";
            else cout<<"Minimum element is "<<mini<<endl;
        }

};
int main(){
    KStacks ks;
    while(1){
        cout<<"\n1:Push\n2:Pop\n3:Minimum\nChoice:";
        cin>>x;
        if(x==1){
            cout<<"Element:";
            cin>>a;
            ks.push(a);
        }
        else if(x==3){
            ks.minimum();  
        }
        else{
            ks.pop();
        }
    }
    return 0;
   
}
