/*
ID: davidzh8
PROG: nocows
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
#define long long long
#define v vector
#define MOD 9901

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
//dp[height][nodes] = number of ways to build with height and nodes
//prefix[height][nodes] = sumOf(dp[height][nodes] + dp[height-1][nodes] + dp[height-2][nodes] ...)
// this transition is WRONG
// transition is dp[height-1][nodes-2] + dp[height][nodes-2]

//correct transition
// we can always merge 2 smaller subtrees, add a root node on top, and voila!
// therefore if there are j nodes and x nodes in left subtree, there are j-x-1 (-1 for root)
// we now have 3 cases to deal with
// both left and right subtrees have height i-1.
// dp[i][j] += dp[i-1][x] * dp[i-1][j-x-1]
// only the left subtree has height i-1
// dp[i][j] += dp[i-1][x] * prefix[i-2][j-x-1] ( we take i-2 to make sure we don't double count the first case)
// only the right subtree has height i-1
// dp[i][j] += prefix[i-2][x] * dp[i-1][j-x-1]

// also if x != j-x-1 you can just switch left and right trees so multiply by 2
int dp[101][201];
int prefix[101][201];
int main() {
    setIO("nocows", 1);
    int N, K; cin>>N>>K;
    dp[1][1] =1;
    for(int i=2; i<=K; i++){
        for(int j=1; j<=N; j+=2){
            for(int x=1; x<j; x+=2){
                int sum=0;
                sum+= dp[i-1][x] * dp[i-1][j-x-1];
                sum += dp[i-1][x] * prefix[i-2][j-x-1];
                sum += prefix[i-2][x] * dp[i-1][j-x-1];
                dp[i][j] +=sum;
                dp[i][j] %=MOD;
            }

        }
        for(int x=0; x<=N; x++){
            prefix[i-1][x] += prefix[i-2][x] + dp[i-1][x];
            prefix[i-1][x] %=MOD;
        }
    }
    cout<<dp[K][N]%MOD<<endl;
    return 0;
}

