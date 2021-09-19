#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

void solve()
{
    int n;
    cin>>n;
    vpii v(n);
    map<int,vector<int>>mp;
    fo(i,n)
    {
        int c;
        cin>>c;
        
        mp[c].push_back(i);
    }
    vector<pair<int,int>>ans;
    // for(auto x:mp)
    // {   cout<<x.first<<endl;
    //     for(auto y:x.second)
    //     cout<<y<<" ";
    //     cout<<endl;
    // }
   for(auto x:mp)
   {
       if(x.second.size()==1)
       {
           ans.push_back({x.first,0});
       }
       else{
           int diff=x.second[1]-x.second[0];
           bool flag=true;
           for(int i=0;i<x.second.size()-1;i++)
           {
                 if(x.second[i+1]-x.second[i]!=diff)
                 {
                    flag=false;
                 }
           }
           if(flag==true)
           {
               ans.push_back({x.first,diff});
           }

       }

   }
   cout<<ans.size()<<endl;
   for(int i=0;i<ans.size();i++)
   {
       cout<<ans[i].first<<" "<<ans[i].second<<endl;
   }

}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    solve();
    return 0;
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(int n, int m)
{
    int i, u, v;
    while (m--)
    {
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(int u, int par)
{
    for (int v : g[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
    }
}