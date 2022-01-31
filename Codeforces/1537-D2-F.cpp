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
v<int> adj[200000];
void init(int N){
    for(int i=0; i<N; i++){
        adj[i].clear();
    }
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N, M; cin>>N>>M;
        init(N);
        v<int> arr, target;
        long sum1 =0; long sum2=0;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
            sum1+=num;
        }
        for(int i=0; i<N; i++){
            int num; cin>>num; target.push_back(num);
            sum2+=num;
        }
        for(int i=0; i<M; i++){
            int a, b; cin>>a>>b; a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        sum1+=1e16; sum2+=1e16;
        if(sum1%2!=sum2%2){
            cout<<"NO"<<endl;
            continue;
        }
        queue<int> q;
        v<int> dp(N);
        dp.assign(N, -1);
        dp[0] = 0;
        q.push(0);
        bool valid = true;
        while(q.size()>0){
            int cur = q.front(); q.pop();
            for(int next: adj[cur]){
                if(dp[next] == -1){
                    dp[next] = (dp[cur]+1)%2;
                    q.push(next);
                }
                else if (dp[next] == (dp[cur]+1)%2){
                    //do nothing
                }
                else {
                    valid=false;
                    break;
                }
            }
        }
        if(!valid){
            cout<<"YES"<<endl;
            continue;
        }
        sum1=0; sum2=0;
        for(int i=0; i<N; i++){
            if(dp[i] ==0) sum1+= target[i] -arr[i];
            else sum2+=target[i] - arr[i];
        }
        if(sum1==sum2) {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;


    }
    return 0;
}

