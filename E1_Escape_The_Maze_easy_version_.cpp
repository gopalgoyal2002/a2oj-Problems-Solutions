#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
// void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================


int a[N];

void solve() {
    int n,k;
    cin>>n>>k;
    vi g[n];
    vi f(k);
    fo(i,k){
    cin>>f[i];
    f[i]--;
    }

    fo(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vi t(n,INT_MAX);
    queue<pair<int,int>>q;
    vector<bool>vis(n,false);
    fo(i,k){
        q.push({f[i],0});
        vis[f[i]]=true;
        // cout<<f[i];
    }
    while(!q.empty()){
        pair<int,int>p=q.front();
        q.pop();
        int u=p.first;
        int time=p.second;
         t[u]=time;
        for(auto v:g[u]){
            if(vis[v]==false){
                q.push({v,time+1});
                vis[v]=true;
               
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<t[i]<<" ";
    // }
    // cout<<endl;
    q.push({0,0});
    vis=vector<bool>(n,false);
    vis[0]=true;
    while(!q.empty()){
        int u=q.front().first;
        int tt=q.front().second;
        q.pop();
        if(t[u]>tt){ 
            int count=0;
            if(g[u].size()==1&&vis[g[u][0]]==true)
            {
                cout<<"YES"<<endl;
                 return ;
            }
            for(auto v:g[u]){
                if(v!=u&&vis[v]==false)
                {
                
                if(t[v]>tt+1){
                  q.push({v,tt+1});
                  vis[v]=true;
                }
                }
                
            }
        }
    }
    cout<<"NO"<<endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		// g[u].pb(v);
		// g[v].pb(u);
	}
}

// void dfs(int u, int par){
// 	for(int v:g[u]){
// 		if (v == par) continue;
// 		dfs(v, u);
// 	}
// }
