#include <bits/stdc++.h>
using namespace std;
#define id long double
#define F first
#define S second
#define inf 1000000007
#define pb push_back
#define rep(i,a,b) for(int i = a;i<b;i++)

int n,k,J,s[100005], tableIndex[100005];
int cnt[100005][3];
vector<int> tables;
int ceil(int a, int b){
    return (a+b-1)/b;
}
bool check(int S){
 
    int total_load = 0;
    for(auto table:tables){
        int final_count=0;
        int sized_events = S/2;
        int num_files_reqd = ceil(cnt[table][2],sized_events);
        int empty_space=0;
        if(cnt[table][2] % sized_events > 0){
            empty_space += 2*(sized_events - cnt[table][2] % sized_events);
        }
        if(S%2) empty_space += num_files_reqd;
        if(cnt[table][1]<=empty_space){
            final_count=num_files_reqd;
        }
        else{
            int remaining_one = cnt[table][1] - empty_space;
            final_count = num_files_reqd + ceil(remaining_one,S);
        }
        int load_jobs_reqd = ceil(final_count,k);
        total_load += load_jobs_reqd;

    }
    if(total_load <= J) return true;
    else return false;

}
void solve(){
    cin>>n>>k>>J;
    rep(i,0,n) cin>>tableIndex[i]>>s[i];
    bool flag=false;
    rep(i,0,n){
        cnt[tableIndex[i]][s[i]]++;
        tables.pb(tableIndex[i]);
        if(s[i] == 2)  flag = true;
    }
    if (flag == false && n<=J*k) {
        cout << 1 <<endl;
         for(auto table: tables) cnt[table][1] = cnt[table][2] = 0;
         tables.clear();
        return;
    }
    
    sort(tables.begin(), tables.end());
    tables.resize(unique(tables.begin(), tables.end())- tables.begin());
    int lo = 1, hi = 200005;
    while(hi - lo > 1){
        int mid = (lo + hi)/2;
        if(check(mid)) hi = mid; //good value
        else lo = mid;
    }
    cout<<hi<<endl; // 0 1 
    if(check(hi) == false){
        cout<<"WA";
    }
    for(auto table: tables) { cnt[table][1] = cnt[table][2] = 0;}
    tables.clear();
    
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
    return 0;
}