#include<bits/stdc++.h>
using namespace std;
int a[200010],a1[200010];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			int b;
			scanf("%d",&b);
			a1[b]=i;
		}
		
		for(int i=1;i<=n;i++)
		{
			if(a1[a[i]]>a1[i])
			{
				cout<<-1<<endl;
				goto u;
			}
		}
		for(int i=1;i<=n;i++)
		cout<<a1[i]-a1[a[i]]<<" ";
		cout<<endl;
		u:;
	}
	return 0;
}