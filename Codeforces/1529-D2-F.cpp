/*
I need to beat moo (moo.)
 and since he solved all of the hard problems in 2 hours
 I will solve in 2 minutes
 just to beat him
 moo anti orz
 shifty super orz
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
int N, M;
int matrix[600][600];
void dijisktra(int start){
    v<long> cost; cost.assign(N, 1e18);
    v<bool> marked; marked.assign(N, false);
    for(int j=0; j<N; j++){
        if(cost[j] > matrix[start][j]) cost[j] = matrix[start][j];
    }
    while(true){
        int cur = -1;
        for(int j=0; j<N; j++){
            if(cur==-1){
                if(!marked[j]) cur=j;
            }
            else{
                if(!marked[j] && cost[cur] > cost[j]) cur=j;
            }
        }
        if(cur==-1) break;
        marked[cur] = true;
        for(int j=0; j<N; j++){
            if(cost[(cur+j)%N] > cost[cur] + j){
                cost[(cur+j)%N] = cost[cur]+j;
            }
        }
        for(int j=0; j<N; j++){
            int price = matrix[cur][j];
            if(cost[cur] + price < cost[((j + cost[cur]))%N]){
                cost[((j + cost[cur]))%N] = cost[cur] + price;
            }
        }
    }
    for(int i=0; i<N; i++){
        if(i==start) cout<<0<<" ";
        else cout<<cost[i]<<" ";
    }
    cout<<endl;
}
int main() {
    setIO("", 0);
     cin>>N>>M;
     for(int i=0; i<600; i++){
         for(int j=0; j<600; j++){
             matrix[i][j] = 1<<30;
         }
     }
     for(int i=0; i<M; i++) {
         int a, b, c;
         cin >> a >> b >> c;
         matrix[a][b] = c;
     }
    for(int i=0; i<N; i++){
        dijisktra(i);
    }
    //run dijisktra on each node
    //the new question
    return 0;
}

