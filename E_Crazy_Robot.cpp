#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int n;
    cin>>n;
    ll int sum=0;
    vector<vector<int>>v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
            sum+=v[i][j];
        }
    }
    // for(int i=0;i<n;i++)
    //     for(int j=0;j<n;j++)
    //         cout<<v[i][j];
    // cout<<sum;
    ll int val=(n-1)*(n-1);
    ll int x=sum/val;
    // cout<<x;
    for(int i=0;i<n;i++){
        ll int y=0;
        for(int j=0;j<n;j++){
            y+=v[i][j];
        }
		// cout<<y;
         ll int ans=(y-x)/(n-2);
         cout<<ans<<" ";
    }
	
    return 0;
}