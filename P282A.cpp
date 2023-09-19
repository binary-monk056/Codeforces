#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int res=0;
    string s;
    while(n--){
        cin>>s;
        if(s=="X++" or s=="++X") res++;
        else res--;
    }
    cout<<res<<endl;
    return 0;
}