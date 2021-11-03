#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        string s;
        cin >> s;
        vector<pair<char,int>> b={};
        for (int i=0; i<n; i++) b.push_back({s[i],a[i]});
        sort(b.begin(),b.end());
        int z=0;
        for (int i=0; i<n; i++) if ((b[i].first=='B' && b[i].second<i+1) || (b[i].first=='R' && b[i].second>i+1)) z=1;
        if (z) cout << "NO\n";
        else cout << "YES\n";
    }
}