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
v<int> adj[200001];
int degree[200001];
//this is completely wrong. An H case needs only 1
// O   O
// |   |
// O - O
// |   |
// O   O

//my dumb algo uses 2, but you only need to move the middle line to the bottom.
//alogirhtm
// dfs down
// and maintain a "current leaf" node
// so when you hit the bottom
// and then you recurse into your children
// we know that any node with >1 child is a bad bamboo
// so we will remove that edge starting from the bottom up
// then attach it to the "current leaf"
//you could also attach the node to your current branch chidl but its the same
//amount of operations so im going to do it my way
int curLeaf = -1;
void countDegree(int cur, int par){
    if(par!=-1) degree[cur]++;
    for(int next: adj[cur]){
        if(next==par) continue;
        degree[cur]++;
        countDegree(next, cur);
    }
    if(degree[cur]==1 && curLeaf == -1){
        curLeaf = cur;
    }
}
v<string> operations;

void dfs(int cur, int par){
    int child = 0;
    for(int next: adj[cur]){
        if(next==par) continue;
        child++;
        dfs(next, cur);
        if((child>1 && par!=-1 ) || (child>2 && par==-1)){
            operations.emplace_back(to_string(cur+1)+" "+to_string(next+1)+" "+to_string(next+1)+" "+to_string(curLeaf+1));
            curLeaf = next;
            degree[cur]--;
        }
    }
}
int main(){
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;

        for(int i=0; i<N-1; i++){
            int a, b; cin>>a>>b; a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        countDegree(0, -1);
        dfs(0, -1);
        cout<<operations.size()<<endl;
        for(string s: operations){
            cout<<s<<endl;
        }
        for(int i=0; i<N; i++){
            adj[i].clear();
            degree[i] = 0;
        }
        operations.clear();
    }
    return 0;
}

