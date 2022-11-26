// JAY SWAMINARAYAN //
// DIGANT SHELADIYA //

/////////////////////////////////////////
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
//////////////////////////////////////////

#include<iostream>
#include<stdio.h>
#include <sstream>
#include <cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <numeric>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
#define test int t; cin>>t; while(t--)
#define pi (3.141592653589)
#define ll long long int
#define of(i, x, n) for (ll i = x; i >= n; i--)
#define f(i, x, n) for (ll i = x; i < n; i++)
#define fr(i, m) for (auto i : m)
#define vl vector<long long>
#define vs vector<string>
#define sl set<ll>
#define ss set<string>
#define sc set<char>
#define mll map<ll,ll>
#define mcl map<char,ll>
#define msi map<string,int>
#define msl map<string,ll>
#define pb push_back
#define pp pop_back
#define float double
#define all(v) (v).begin(), (v).end()
#define bll(v) (v).begin(), (v).end(),greater<int>()
#define fi first
#define se second
#define maxi *max_element
#define mini *min_element
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define M 1000000007
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define rtn return
ll gcd(ll a, ll b)
{if (b == 0){rtn a;}rtn gcd(b, a % b);}
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll binpow(ll x,ll y)
{
    x%=M;
    ll ans=1;
    while(y>0)
    {
        if(y&1)ans=ans*x%M;
        x=x*x%M;
        y>>=1;
    }
    return ans%M;
}
bool perfectsq(double x)
{
    if (x>=0)
    {ll sr = sqrt(x); rtn (sr*sr==x);}
    rtn false;
}
bool isprime(ll number)
{
    if (number <= 1)
        rtn false;
    if (number == 2)
        rtn true;
    if (number % 2 == 0)
        rtn false;
    ll boundary = (ll)floor(sqrt(number));
    for (ll i = 3; i <= boundary; i += 2)
        if (number % i == 0)
            rtn false;
    rtn true;
}
vl prime;
void primeFactors(ll n)
{
    ll c=2;
    while(n>1){if(n%c==0){prime.pb(c); n/=c;} else c++;}
}
// !(n&(n-1)) --> n==2^x n&(n-1) --> n!=2^x
void solve()
{
    mll m;
    ll n;
    cin>>n;
    vl v(n);
    f(i,0,n)cin>>v[i],m[v[i]]++;
//    ll vis[101];
    char s[100000];
    ll ct=0;
    fr(it,m)if(it.se==1)ct++;
    ll tmp=0;
    if(ct&1){
        fr(it,m){
            if(it.se>2){
                tmp=it.fi;
                break;
            }
        }
    }
    bool f=0,f1=0;
    ll taken=0;
    ll cta=0,ctb=0;
    f(i,0,n){
        //if(vis[v[i]])continue;
      //  vis[v[i]]=1;
    
        if(ct&1){
            if(m[v[i]]==1 && !f1){
                s[i]='B';
                f1=1;
                ctb++;
            }
            else if(m[v[i]]==1 && f1){
                s[i]='A';
                f1=0;
                cta++;
            }
            else if(v[i]==tmp && cta<ctb && taken==0){
                s[i]='A';
                f1=0;
                taken=1;
                cta++;
            }
            else if(v[i]==tmp && ctb<=cta && taken==0){
                s[i]='B';
                f1=1;
                taken =2;
                ctb++;
            }
            else{
                if(v[i]==tmp){
                    if(taken==2)s[i]='A';
                    else s[i]='B';
                }
                else s[i]='A';
                
            }
            
        }
        else{
            if(m[v[i]]==1 && !f){
                s[i]='B';
                f=1;
            }
            else if(m[v[i]]==1 && f){
                s[i]='A';
                f=0;
            }
            else{
                s[i]='A';
            }
        }
        
    }
    if(ct&1 && tmp==0){
        cout<<"NO"<<endl; rtn;
    }
    cout<<"YES"<<endl;
    f(i,0,n)cout<<(char)s[i];
    
}
int main()
{
    fast;
//    test
    solve();
    rtn 0;
}
