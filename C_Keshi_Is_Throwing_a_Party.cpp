#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,t,a[200004],b[200004];
int B(int x,int z)
{
	if(x<z)
	{
		int s=0,y=x+z+1>>1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=y-s-1&&b[i]>=s)s++;
		}
		if(s<y)return B(x,y-1);
		else return B(y,z);
	}
	return x;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(cin>>t;t--;)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
		cout<<B(1,n)<<endl;
	}
}
