#include<bits/stdc++.h>
using namespace std;
#define int long long
int l,r,s; set<int> S;
void f(int x){S.insert(x); if(x < r)f(x*10+4),f(x*10+7);}
int32_t main()
{
    cin >> l >> r;
    for(f(0);l <= r;)
    {
        auto it = S.lower_bound(l);
        s+=(min(r,*it) - l + 1)**it;
        l=*it+1;
    }
    cout << s;
}