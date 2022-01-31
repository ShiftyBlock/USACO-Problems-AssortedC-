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
v<int> adj[200001];
int main() {
    setIO("", 0);
    int N, M; cin>>N>>M;
    for(int i=0; i<M; i++){
        int a, b; cin>>a>>b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    v<int> arr(N);
    for(int i=0; i<N; i++){
        for(int x: adj[i]){
            if(i>x) {
                arr[x]++;
            }
        }
    }
    int ans = 0;
    for(int x: arr){
        if(x==0) ans++;
    }
    int Q; cin>>Q;
    while(Q-->0){
        int op; cin>>op;
        if(op==1){
            int a, b; cin>>a>>b; a--; b--;
            if(a<b) swap(a,b);
            arr[b]++;
            if(arr[b]==1) ans--;
        }
        if(op==2){
            int a, b; cin>>a>>b; a--; b--;
            if(a<b) swap(a,b);
            arr[b]--;
            if(arr[b]==0) ans++;

        }
        if(op==3){
            cout<<ans<<endl;
        }
    }

    return 0;
}

