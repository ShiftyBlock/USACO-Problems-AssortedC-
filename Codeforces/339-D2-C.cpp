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
//moves, sum, last
struct state{
    int k,a,b;
    state(int i, int j, int l){
        k=i; a=j; b=l;
    };
};
int dp[1001][21][11];
int OFFSET= 10;
int main() {
    setIO("", 0);
    v<int> arr(11);
    for(int i=0; i<10; i++){
        char c; cin>>c;
        arr[i+1] =  c-'0';
    }
    int M; cin>>M;
    queue<state> q;
    q.emplace(0,OFFSET,0);
    dp[0][OFFSET][0] = 1;
    while(q.size()>0){
        state cur = q.front(); q.pop();
        int k = cur.k;
        if(k==M) continue;
        int a = cur.a;
        int b = cur.b;
        int turn = 1;
        if(k%2==1) turn =-1;
        for(int i=1; i<=10; i++){
            if(arr[i]==1){
                if(b!=i && a+turn*i<=10+OFFSET && a+turn*i>=0 && abs(a-OFFSET) < i && dp[k+1][a+turn*i][i]==0){
                    q.emplace(k+1, a+turn*i,i);
                    dp[k+1][a+turn*i][i] = 1;
                }
            }
        }
    }
    state best={-1,-1,-1};
    for(int j=0; j<21; j++){
        for(int k=0; k<11; k++){
            if(dp[M][j][k]){
                best = {M, j, k};
                break;
            }
        }
    }
    if(best.k==-1) {
        cout<<"NO"<<endl;
    }
    else{
        q.emplace(best);
        v<int> moves;
        while(q.size()>0){
            auto cur = q.front(); q.pop();
            int k = cur.k;
            if(k==0) break;
            int a = cur.a;
            int b = cur.b;
            moves.push_back(b);
            int turn = 1;
            if((k-1)%2==1) turn = -1;
            int prev = a - turn*b;
            for(int last=0; last<11; last++){
                if(dp[k-1][prev][last] && last!=b){
                    q.push({k-1, prev, last});
                    break;
                }
            }
        }
        cout<<"YES"<<endl;
        reverse(moves.begin(), moves.end());
        for(int x: moves){
            cout<<x<<" ";
        }
    }

    return 0;
}

