#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Num:";
    cin>>n;
    cout<<(((0xAAAAA&n)>>1)|((0x55555&n)<<1))<<endl;
    return 0;
}
/*
https://stackoverflow.com/questions/4788799/swap-every-pair-of-bits-in-byte
*/
