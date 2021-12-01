#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin>>T;
	while(T--)
	{
		ll k,x,S; cin>>k>>x,S=k*k;
		ll l=1,r=2*k-1,ans=0;
		while(l<=r)
		{
			ll mid=l+r>>1,s,p;
			if(mid<=k) s=mid*(mid+1)/2;
			else p=2*k-1-mid,s=S-p*(p+1)/2;
			if(s<x) ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%lld\n",min(ans+1,2*k-1));
	}
	return 0;
}