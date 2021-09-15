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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    fo(i, n)
            cin >>
        v[i];
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    int dx[4]={0,-1,1,0};
    int dy[4]={1,0,0,-1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {  if(vis[i][j]==true)
           continue;
            if (v[i][j] == '-')
            {
                vis[i][j] = true;
            }
            else if(v[i][j]=='.')
            {
                q.push({i, j});
                 v[i][j]='B';
                 vis[i][j]=true;
                while (!q.empty())
                {
                    pair<int, int> p = q.front();
                    q.pop();
                    int i = p.first;
                    int j = p.second;
                    
                        
                        for(int k=0;k<4;k++)
                        {
                            int x=i+dx[k];
                            int y=j+dy[k];
                            if(x>=0&&y>=0&&x<n&&y<m&&vis[x][y]==false&&v[x][y]=='.')
                            {
                                if(v[i][j]=='B')
                                {
                                    v[x][y]='W';
                                }
                                else
                                {
                                    v[x][y]='B';
                                }
                                // cout<<x<<" "<<y<<" ";
                                q.push({x,y});
                                vis[x][y]=true;
                            }
                        }
                   
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<endl;
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
