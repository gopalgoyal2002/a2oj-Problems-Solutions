#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int n,i,t;
int main()
{
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		int ans = a[0];
		for(i=0;i<n-1;i++){
			ans = max(ans,a[i+1]-a[i]);
		}
		cout<<ans<<endl; 
	}
	return 0;
}