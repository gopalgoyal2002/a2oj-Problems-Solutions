#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
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
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>             vi;
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
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];



void solve() {
   string a,b;
   cin>>a>>b;
   int po=0,ne=0;
   int po2=0,ne2=0;
   int q=0;
   int m=0;
   fo(i,a.length())
   {
       if(a[i]=='+')
       po++;
       else
       ne++;


       if(b[i]=='+')
       po2++;
       else if(b[i]=='-')
       ne2++;
       else
       {
       q++;
       if(a[i]=='+')
         m++;
         else
         m--;
       }
   }

  int n=a.length();
  if(po==po2&&ne==ne2)
  {
      cout<<double(1)<<endl;
      return ;
  }
   if(po<po2)
   {
        cout<<double(0)<<endl;
        return ;
   }
   else if(ne<ne2)
   {
       cout<<double(0)<<endl;
        return ;
   }
   long double deno=mpow(2,q);
   long double neo=0;
   for(int mask=0;mask<1<<q;mask++)
   {
     int j=mask;
     int z=0;
   
     for(int k=0;k<q;k++)
     {   
         if(mask>>k&1)
         {
               z++;
         }
         else{
             z--;
         }
     }
     
     if(z==m)
     {
         neo++;
     }
   }
   cout<<m<<endl;
   cout<<neo<<endl;
   long double ans=neo/deno;
   printf("%0.9f\n",(double)ans);


}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    
      solve();
    

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
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}
