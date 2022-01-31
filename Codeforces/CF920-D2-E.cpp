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
// idea
// our points of interest are going to be the nodes with edges
// and we want to dfs from an unvisited node that doesnt have an edge with us
// maintain the set of unvisited points
// from this set, add a number to visited iff it doesn't exist in our edge set.
set<int> adj[200001];
//take the set of unvisited verticies
set<int> s;
int bfs(int cur){
    deque<int> dq; dq.push_back(cur);
    s.erase(cur);
    int sum=0;
    //I used to do some weird "component" thing
    // I'm not sure why it doesn't work
    // But this code is cleaner — we try to find the number of points we can go to
    // so we store a global set, starting with everything, and slowly removing 1 by 1.
    while(dq.size()>0) {
        int c = dq.front();
        dq.pop_front();
        sum++;
        v<int> temp;
        for (int num: s) {
            if (adj[c].find(num) == adj[c].end()) {
                temp.push_back(num);
                dq.push_back(num);
            }
        }
        for (int num: temp) {
            s.erase(s.find(num));
        }
    }
    return sum;

}

int main() {
    setIO("", 0);
    int N, M; cin>>N>>M;

    for(int i=0; i<M; i++){
        int a,b; cin>>a>>b;
        a--;b--;
        adj[a].emplace(b);
        adj[b].emplace(a);
    }
    set<int> temp;
    for(int i=0; i<N; i++){
        temp.emplace(i);
    }
    s=temp;
    v<int> results;
    for(int i=0; i<N; i++){
        if(s.find(i)!=s.end()){
            int sum= bfs(i);
            results.push_back(sum);
        }
    }

    sort(results.begin(), results.end());
    cout<<results.size()<<endl;
    for(int num: results) {
        cout << num <<" ";
    }


    return 0;
}

