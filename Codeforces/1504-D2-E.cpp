/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long, long>
#define long long long
#define endl "\n"
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
struct cmp{
    bool operator()(pii x, pii y){
        return x.first > y.first;
    }
};
// rewrite max(𝑐𝑖,𝑎𝑗−𝑎𝑖)=𝑐𝑖+max(0,𝑎𝑗−𝑎𝑖−𝑐𝑖).
//ignore the ci term
//minimize max(0,𝑎𝑗−𝑎𝑖−𝑐𝑖)
//run dijisktra on the modified graph
// note that going back is now free :)
long dp[100001];
int main() {
    setIO("", 0);
    int N; cin>>N;
    v<long> arr, cost;
    v<pii> temp;
    for(int i=0; i<N; i++){
        int a, b; cin>>a>>b; temp.emplace_back(a,b);
    }
    sort(temp.begin(), temp.end());
    for(int i=0; i<N; i++){
        arr.push_back(temp[i].first);
        cost.push_back(temp[i].second);
    }
    for(int i=0; i<N; i++){
        dp[i] = 1e18;
    }
    //cost, node
    priority_queue<pii,v<pii>, cmp> pq;
    pq.emplace(0,0);
    dp[0] = 0;
    while(pq.size()>0){
        // minimize max(0,𝑎𝑗−𝑎𝑖−𝑐𝑖)
        pii node = pq.top(); pq.pop();
        int cur = node.second;
        int dist = node.first;
        //free because bigger-> smaller is 0
        if(cur>0){
            if(dp[cur-1] > dist){
                dp[cur-1]=dist;
                pq.emplace(dp[cur-1], cur-1);
            }
        }
        //find the largest index such that max(0,𝑎𝑗−𝑎𝑖−𝑐𝑖) = 0
        // upper bound for ai+ci
        int idx = upper_bound(arr.begin(), arr.end(), cost[cur] + arr[cur]) - arr.begin()-1;
        if(dp[idx] > dist){
            dp[idx] = dist;
            pq.emplace(dp[idx], idx);
        }
        //or we can go to idx+1
        if(idx+1<N){
            if(dp[idx+1] > dist + arr[idx+1] - cost[cur] - arr[cur]){
                dp[idx+1] = dist + arr[idx+1] - cost[cur] - arr[cur];
                pq.emplace(dp[idx+1], idx+1);
            }
        }
    }
    long ans =0;
    for(int num: cost){
        ans+=num;
    }
    cout<<dp[N-1] + ans<<endl;

    return 0;
}

