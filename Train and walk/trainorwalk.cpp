#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define id long double
#define F first
#define S second
#define inf 1000000007
#define pb push_back
int n,A,B,C,D,P,Q,Y;
int x[303];
void solve(){
    cin>>n>>A>>B>>C>>D>>P>>Q>>Y;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    int time1 = P*abs(x[A] - x[B]);
    int time2 = P*abs(x[C] - x[A]) + Q*abs(x[C] - x[D])+P*abs(x[D] - x[B]); 
    int timeAC = P*abs(x[C] - x[A]);
    if(timeAC>Y)
    time2 = inf;
    else{
        int waiting_time = Y - timeAC;
        time2+= waiting_time;
    }
    int res = min(time1, time2);
    cout<<res<<endl;


}
///void init(){
    // ios_base:: sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
//#ifndef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
//#endif
//}
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