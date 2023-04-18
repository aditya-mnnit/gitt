#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
typedef long long int ll;
using namespace std;
vector<vector<int>>adj;
vector<int>vis;
vector<int>depth;
vector<int>height;
vector<int>par,ch;
vector<ll>factdp;
// set<ll>s;
ll ct=0;
ll cyc=0;
ll mod=1e9+7;
vector<bool>prime;
ll chil=0;
void seive(int n)
{
    prime.assign(n+1,true);
    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        {
            //cout<<i<<" ";//here i is prime
            for(int j=i*i;j<=n;j+=i)
            prime[j]=false;
        }
    }

}
ll factorial(ll n)
{
    if(factdp.size()==0)
    factdp.push_back(1);
    for(int i=factdp.size();i<=n;i++)
    {
        factdp.push_back((factdp[i-1]*(i%mod))%mod);
    }
    return factdp[n];
}
ll binpow(ll a,ll b)
{
    a%=mod;
    ll res=1;
    while(b>0)
    {
        if(b&1)
        res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res%mod;
}
ll inversemod(ll n)
{
return binpow(n,mod-2);
}


ll ncr(ll n, ll r)
{
    if (n < r)  return 0; if (r == 0) return 1;
    return ((factorial(n))%mod*inversemod(factorial(r))%mod*inversemod(factorial(n-r))%mod)%mod;
}
void dfs(int node,int parent)
{

    vis[node]=1;
    depth[node]=depth[parent]+1;
    ct++;
par[node]=parent;
    for(auto i:adj[node])
    {
        if(vis[i]!=1)
        {
            dfs(i,node);
             chil=1;
    ch[node]+=(ch[i]+1);
        }
    }
    if(chil==0)
    ch[node]=chil;
    chil=0;
}

vector<int> path(int n)
{
    vector<int>ans;
    while(n!=0)
    {
        ans.push_back(n);
        n=par[n];

    }
    return ans;
}
vector<int>cp;
int lsb(ll n)
{
 
    // To find the position
    // of the most significant
    // set bit
    int k = (int)(log2(n));
 
    // To return the the value
    // of the number with set
    // bit at k-th position
    return k;
}

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
  
    ll a,b;
     cin>>a>>b;
     cout<<a+b<<"\n";
     cout<<"hi"<<"\n";

     
   

 
 

}
   
     
      
   
