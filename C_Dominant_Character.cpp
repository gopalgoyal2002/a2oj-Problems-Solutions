
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
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

//==================================BINARY INDEX TREE===============================
// void update(vl & bt,int a,int val){
    
//      for(int i=a;i<bt.size();i+=i&(-i)){
//          bt[i]+=val;
//      }
//     //  if(a==1)
//     //  return ;
    
// }
// int read(vl & bt,int x){
//     int sum=0;
//     while(x>0){
//         sum+=bt[x];
//         x-=(x&-x);
//     }
//     return sum;
// }
//==================================BINARY INDEX TREE===============================

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    //  cout<<s;
    // int n=s.length();
      int ans=INT_MAX;
    int a=0,b=0,c=0;


    int i=0,j=0;
    while(i<n&&j<n){
        if(s[i]=='a')
        {
            a++;
        }
        if(s[i]=='c'){
            c++;
        }
        if(s[i]=='b')
        b++;

        if(a>b&&a>c&&i-j>1){
            ans=min(ans,i-j+1);
        }
        while(a<b||a<c&&j<=i){
             if(s[j]=='a')
        {
            a--;
        }
        if(s[j]=='c'){
            c--;
        }
        if(s[j]=='b')
            b--;
        
        j++;
        if(a>b&&a>c&&i-j>1){
            ans=min(ans,i-j+1);
        }
        }
        i++;
    }
    
    
    if(ans!=INT_MAX){
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
int main(){
    int t;
	cin>>t;
	
	while(t--){
		int n,i;
		cin>>n;
		string s,ans[7]={"aa","aba","aca","abca","acba","abbacca","accabba"};
		cin>>s;
		int res=-1;
		for(int i=0;i<7;i++){
			if(s.find(ans[i])!=-1){
				res=ans[i].length();
				break;
			}
		}		
	cout<<res<<endl;
	}
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
