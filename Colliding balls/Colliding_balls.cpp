#include <bits/stdc++.h>
using namespace std;

#define id long double
#define F first
#define S second
#define pb push_back
#define rep(i,a,b) for(int i = a;i<b;i++)
int n,m, x[100005], vx[100005], y[100005], vy[100005];
long long valx[10000005],valy[10000005];
void solve(){
    cin >>n>>m;
    rep(i,1,n+1) cin>>x[i]>>vx[i];
    rep(i,1,m+1) cin>>y[i]>>vy[i];
    rep(i,1,n+1){
        valx[i] = x[i] * vx[i];
    }
     rep(i,1,m+1){
        valy[i] = y[i] * vy[i];
    }  
    map<int,int> freq_x,freq_y;
    rep(i,1,n+1) freq_x[valx[i]]++;
    rep(i,1,m+1) freq_y[valy[i]]++;
    vector<int> values;
    rep(i,1,n+1) values.pb(valx[i]);
    rep(i,1,m+1) values.pb(valy[i]);
    sort(values.begin(), values.end());
    values.resize(unique(values.begin(), values.end())-values.begin());
    int res = 0;
    for(auto val:values){
        res+=min(freq_x[val],freq_y[val]);
    }
    cout<<res<<endl;
}


void init(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
int32_t main(){
    init();
    {
        solve();
    }
}