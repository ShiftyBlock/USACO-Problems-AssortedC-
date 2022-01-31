/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
#define long long long
#define v vector

long MOD = 1e9+7;

void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }

}
//neko cow and field super antiorz
// answer for pair i,j is min(xi + yj, xj + yi)
// with wlog we can say xi + yj <= xj + yi, rearrange to get xi - xj <= yi-yj
// which means first person is better at first activity and second person is better at second activity
// so take a suffix sum of max and walk through from prefix
bool cmp(pair<pii, int> x, pair<pii, int> y){
    return x.first.first - x.first.second < y.first.first - y.first.second;
}
int main() {
    setIO("", 0);
    int N, M; cin>>N>>M;
    v<pair<pii, int>> arr;
    for(int i=0; i<N; i++){
        long a, b; cin>>a>>b;
        arr.emplace_back(make_pair(a,b), i);
    }
    sort(arr.begin(), arr.end(), cmp);
    v<long> suffix(N);
    for(int i=N-1; i>=0; i--){
        if(i==N-1){
            suffix[i] = arr[i].first.second;
        }
        else{
            suffix[i] = arr[i].first.second + suffix[i+1];
        }
    }
    v<long> prefix(N);
    for(int i=0; i<N; i++){
        if(i==0){
            prefix[i] = arr[i].first.first;
        }
        else prefix[i] = arr[i].first.first + prefix[i-1];
    }
    long sum = 0;
    v<long> ans(N);
    for(int i=0; i<N; i++){
        if(i<N-1) ans[i] = (N-1-i) * arr[i].first.first + suffix[i+1];
        if(i>0) ans[i]+=prefix[i-1] + i*arr[i].first.second;
    }
    v<int> invert(N);
    for(int i=0; i<N; i++){
        invert[arr[i].second] = i;
    }
    /*
    for(int i=0; i<N; i++){
        cout<<invert[i]<<" ";
    }
    cout<<endl;
    for( auto x: ans){
        cout<<x<<" ";
    }
    cout<<endl;*/
    for(int i=0; i<M; i++){
        int a, b; cin>>a>>b;
        a--; b--;
        int j = invert[a];
        int k = invert[b];
        long cost = min(arr[j].first.first + arr[k].first.second, arr[k].first.first + arr[j].first.second);
        ans[j]-=cost;
        ans[k]-=cost;
    }
    for(int i=0; i<N; i++){
        int j = invert[i];
        cout<<ans[j]<<" ";
    }
    cout<<endl;
    return 0;
}

