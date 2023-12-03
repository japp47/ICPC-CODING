#include <bits/stdc++.h>
using namespace std;

//#define int long long int
#define id long double
#define F first
#define S second
#define inf 1000000007
#define pb push_back
void solve(){
    int n,q;
    cin >> n>> q;
    cout<<fixed<<setprecision(10)<<1.0l*q*(n+q+1)/(q+1)<<endl;
}

int32_t main(){
    //init();
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
        int  t =1;
        cin>>t;
        while(t--){
        solve();
        }
    
}