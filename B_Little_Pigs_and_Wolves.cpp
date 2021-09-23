#include<iostream>
using namespace std;
int ans,i,a,l,b;
int main()
{
	string x[100];
	cin>>a>>b;
	for(i=1;i<=a;i++)
	cin>>x[i];
	for(i=1;i<=a;i++)
	for(l=0;l<b;l++)
	if(x[i][l]=='W'&&(x[i+1][l]=='P'||x[i-1][l]=='P'||x[i][l-1]=='P'||x[i][l+1]=='P'))ans++;
	cout<<ans;
}