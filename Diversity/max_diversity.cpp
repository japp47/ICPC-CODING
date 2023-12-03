#include <bits/stdc++.h>
using namespace std;
#define int long long
#define id long double
#define F first
#define S second
#define random_element 1000000007
#define pb push_back
#define rep(i,a,b) for(int i = a;i<b;i++)
int n, k , a[100005];
void solve() {
    cin >> n>> k;
    rep(i,0,n) cin>>a[i];
    if(k>=n) cout<<n*(n-1)/2<<endl;
    else{
        map<int,int> freq;
        rep(i,0,n) freq[a[i]]++;
        priority_queue<pair<int, int>> pq;
        for(auto val:freq){
            int element = val.F;
            int count = val.S;
            pq.push({count, element});
        }
        rep(i,0,k){ 
          pair<int,int> max_freq_element = pq.top();
          pq.pop();
          int element = max_freq_element.S;
          int frequency= max_freq_element.F;
          if(frequency == 1){
            break;
          }
          else{
            pq.push({frequency-1,element});
            pq.push({1,random_element});
          }
        }
        //total no of pairs - pairs with a[i]=a[j]
        int res = n*(n-1)/2;
        while(!pq.empty()){
          pair<int,int> max_freq_element = pq.top();
          pq.pop();
          int element = max_freq_element.S;
          int frequency= max_freq_element.F;
          res-=frequency*(frequency-1)/2;
            
        }
        cout<<res<<endl;
    }
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