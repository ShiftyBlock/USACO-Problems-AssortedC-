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
v<int> adj[100001];
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<pii> temp;
        //pair ij contributes (i+1) *(N-j)
        for(int i=0; i<N; i++){
            int num; cin>>num; temp.emplace_back(num, i);
        }
        sort(temp.begin(), temp.end());
        v<int> compress(N);
        for(int i=0; i<N;){
            int j=i;
            while(j<N && temp[j].first == temp[i].first){
                j++;
            }
            int k = i;
            while(i<j){
                compress[temp[i].second] = k;
                i++;
            }
        }
        for(int i=0; i<N; i++){
            adj[compress[i]].push_back(i);
        }
        for(int i=0; i<N; i++){
            sort(adj[i].begin(), adj[i].end());
        }
        long sum =0;
        for(int i=0; i<N; i++){
            if(adj[i].size()<=1) continue;
            long suffix =0;
            for(int j=1; j<adj[i].size(); j++){
                suffix+=(N-adj[i][j]);
            }
            sum+=(adj[i][0]+1) * suffix;
            for(int j=1; j<adj[i].size(); j++){
                suffix-=(N-adj[i][j]);
                sum+=(adj[i][j]+1)*suffix;
            }
        }
        cout<<sum<<endl;
        for(int i=0; i<N; i++){
            adj[i].clear();
        }
    }
    return 0;
}

