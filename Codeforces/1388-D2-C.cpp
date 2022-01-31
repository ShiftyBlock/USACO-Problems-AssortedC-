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
v<int> adj[100000];
long dp[100000];
v<long> people;
v<long> arr;
void dfs(int cur, int par){
    dp[cur]= people[cur];
    for(int next: adj[cur]){
        if(next==par) continue;
        dfs(next, cur);
        dp[cur]+=dp[next];
    }
}
bool enoughpeople(int cur, int par) {
    bool valid = (dp[cur] >= abs(arr[cur]));
    int children = 0;
    for (int next: adj[cur]) {
        if (next == par) continue;
        children++;
        valid &= enoughpeople(next, cur);
    }
    valid &= (dp[cur] % 2 == abs(arr[cur]) % 2);
    return valid;
}
bool negativecheck(int cur, int par){
    bool valid = true;
    long children = 0;
    for (int next: adj[cur]) {
        if (next == par) continue;
        children+=arr[next];
        valid &= negativecheck(next, cur);
    }
    if((adj[cur].size()==1 && adj[cur].back()==par))return true;
    valid&= arr[cur]>= children -people[cur];
    return valid;
}
void reset(int N){
    arr.clear();
    people.clear();
    for(int i=0; i<N; i++){
        adj[i].clear();
        dp[i] = 0;
    }
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N, M; cin>>N>>M;
        for(int i=0; i<N; i++){
            long num; cin>>num; people.push_back(num);
        }
        for(int i=0; i<N; i++){
            long num; cin>>num; arr.push_back(num);
        }
        for(int i=0; i<N-1; i++){
            int a, b; cin>>a>>b; a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0, -1);
        //check for obvious issues
        //too many people, impossible leafs
        bool valid = enoughpeople(0, -1);
        //geniosity check
        bool v2 = negativecheck(0, -1);
        bool yes=valid&v2;
        if(yes){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        reset(N);


    }
    return 0;
}

