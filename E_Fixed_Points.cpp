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

// TO CREATING SEIEVE>>>>>>
// vl se(1e6+2,1);
// void seive()
// {
//     for(int i=2;i*i<1e6+2;i++)
//     {    if(se[i]==1)
//     { 
//         for(int j=i*i;j<1e6+2;j=j+i)
//         {
//             se[j]=0;
//         }
//     }
//     }
//     // for(int i=0;i<10;i++)
//     // cout<<se[i]<<" ";
//     // cout<<endl;
//     // cout<<se[1e6];
// }
// vector<int>parent(200,-1);
// vector<int>emp(200);
// int find2(int u)
// {
//     if(emp[u]==u)
//     {
//         return u;
//     }
//     emp[u]=find2(emp[u]);
//     return emp[u];
// }
// int find(int u)
// {
//     if(parent[u]==u)
//     {
//         return u;
//     }
//     parent[u]=find(parent[u]);
//     return parent[u];
// }
// void uni(int x,int y)
// {
//     int x_rep=find(x);
//     int y_rep=find(y);
//     if(x_rep==y_rep)
//     return ;
//     else
//     x_rep=y_rep;

// }
int find(vector<pair<int,int>>&v,int val)
{
    int low=0;
    int high=v.size()-1;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(v[mid].first==val&&(mid==0||v[mid-1]!=val))
        {
            return mid;
        }
        else if(v[mid].first<=val)
        {
            low=mid+1;    
        }
        else{
            high=mid-1;
        }
    }
}

void solve()
{
  int n,k;
  cin>>n>>k;
  vpii v(n);
  int mval=INT_MIN;
  fo(i,n)
  {
     int x;
     cin>>x;
     v[i]={x,i};
     mval=max(mval,x);
  }
  sort(v.begin(),v.end());
  vector<int>vv;
  for(int i=1;i<n;i++)
  {
       int ind=find(v,i);
      
      if(v[ind].first==i)
      {
          vv.push_back(i);
      }
      else
      break;

  }
  for(int i=0;i<vv.size();i++)
  cout<<vv[i]<<" ";

}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
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
