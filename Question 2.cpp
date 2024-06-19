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
    int n;
    cin>>n;
    vector<int>vect(n),ans(6,INT_MAX);
    unordered_map<int,int>map;
    for(int i=0;i<n;++i)
    {
        cin>>vect[i];
        if(map.find(vect[i])==map.end())
            map[vect[i]]=i;
        else
        {
            ans[vect[i]-1]=min(ans[vect[i]-1],i-map[vect[i]]);
            map[vect[i]]=i;
        }
    }
    int res=0;
    for(int i=0;i<6;++i)
    {
        //cout<<i+1<<"->"<<ans[i]<<"\n";
        res+=ans[i];
    }
    cout<<res<<"\n";
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