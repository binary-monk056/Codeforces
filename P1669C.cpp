#define el                   endl
#define pb                   push_back
#define ll                   long long int
#define vl                   vector<long long int>
#define vb					 vector<bool>
#define vi					 vector<int>
#define vd					 vector<double>
#define pii                  pair<int,int>
#define mii                  map<int,int>
 
 
#include<bits/stdc++.h>
using namespace std;
 
int MOD = 1000000007;
 
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
 
        vector<ll>a(n);
        map<ll,ll>mp;
 
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]]=i;
        }
 
        ll mn = mp[0],mx = mp[0];
        ll ans=1;
 
        for(int i=1;i<n;i++)
        {
            if(mp[i]>mx)
            {
                mx=mp[i];
            }
            else if(mp[i]<mn)
            {
                mn=mp[i];
            }
            else
            {
                ans=ans * (mx-mn+1-i);
                ans = ans%MOD;
            }
        }
        ans = (ans+MOD)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
 
