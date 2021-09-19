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
  vi v(8,0);
  
  fo(i,n)
  {
      int x;
      cin>>x;
      if(x==5||x==7)
      {
          cout<<-1<<endl;
          return ;
      }
      v[x]++;
  }
  if(v[1]!=n/3)
  {
      cout<<-1<<endl;
          return ;
  }
  
  int a124=0;
  int a126=0;
  int a136=0;
  if(v[4]!=0)
  {   a124=v[4];
      v[2]-=v[4];
      v[4]=0;
  }
  if(v[2]>0)
  {
      a126=v[2];
      
      v[6]-=v[2];
      v[2]=0;
  }
  if(v[3]>0)
  {
      a136=v[3];
      v[6]-=v[3];
      v[3]=0;
  }
  v[1]-=(a124+a126+a136);
  for(int i=1;i<=7;i++)
  {
      if(v[i]!=0)
      {
          cout<<-1<<endl;
          return ;
      }
  }
// fo(i,7)
// cout<<v[i]<<" ";
// cout<<endl;
  fo(i,a124)
  {
      cout<<1<<" "<<2<<" "<<4<<endl;
  }
   fo(i,a126)
  {
      cout<<1<<" "<<2<<" "<<6<<endl;
  }
   fo(i,a136)
  {
      cout<<1<<" "<<3<<" "<<6<<endl;
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
