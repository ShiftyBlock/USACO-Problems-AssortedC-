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
v<int> adj[300001];
int main() {
    setIO("", 0);
    int N, M, K; cin>>N>>M>>K;
    for(int i=0; i<M; i++){
        int a, b;
        cin>>a>>b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    double low =0.0;
    double high = 1.0;
    while(high - .0000001> low){
        double mid = (low+high)/2;
        if(valid(mid)){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    return 0;
}

