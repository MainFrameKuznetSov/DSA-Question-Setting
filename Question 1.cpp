#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n;i>=0;--i)
#define lloop(i,a,b) for(int i=a;i<=b;++i)
#define jloop(i,a,b,k) for(int i=a;i<=b;i+=k)
#define vi vector<int>
#define vll vector<long long>
using namespace std;
int BinarySearch(vi x,int t)
{
    /*
        For descending order,
            replace r & l
    */
    int l=0,r=x.size()-1,mid;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(x[mid]==t)
            return mid;
        if(x[mid]>t)
            r=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
long long exp(int a,int b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b%2==0)
        return exp(a,b/2)*exp(a,b/2);
    else
        return a*exp(a*a,(b-1)/2);
}
ll selfPower(ll x,ll y,ll p) 
{ 
    ll res=1;
    x=x%p;   
    if(x==0) 
        return 0;
    while(y>0) 
    { 
        if(y&1) 
            res=(res*x)%p; 
        y=y>>1;
        x=(x*x)%p; 
    } 
    return res; 
}
void solve()
{
    //Your Code starts here
    int n,k;
    cin>>n>>k;
    vector<int>vect(n);
    map<int,int>fapp,lapp;
    for(int i=0;i<n;++i)
        cin>>vect[i];
    for(int i=0;i<n;++i)
    {
        lapp[vect[i]]=i;
        fapp[vect[n-i-1]]=n-i-1;
    }
    for(int i;i<k;++i)
    {
        int a,b;
        cin>>a>>b;
        if(fapp.find(a)==fapp.end() || lapp.find(b)==lapp.end())
        {
            cout<<"NO\n";
            continue;
        }
        int l=fapp[a],r=lapp[b];
        //cout<<l<<","<<r;
        l<r?cout<<"YES\n":cout<<"NO\n"; 
    }
}
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	   solve();
	return 0;
}