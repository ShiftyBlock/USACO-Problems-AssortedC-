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
struct segtree{
    int n; v<int> arr;
    segtree(int K){
        n=K;
        arr.resize(4*n);
    }
    void update(int i, int val){
        update(i, val, 0, 0, n);
    }
    void update(int i, int val, int cur, int lx, int rx){
        if(rx-lx==1) {
            arr[cur] = val;
            return;
        }
        int mid = (lx+rx)/2;
        if(mid>i){
            update(i,val, 2*cur+1, lx, mid);
        }
        else{
            update(i,val, 2*cur+2, mid, rx);
        }
        arr[cur]= arr[2*cur+1]+arr[2*cur+2];
    }
    int query(int l, int r){
        return query(l,r, 0, 0, n);
    }
    int query(int l, int r, int cur, int lx, int rx){
        if(lx>=r || rx<=l) return 0;
        if(lx>=l && rx<=r) return arr[cur];
        int mid = (lx+rx)/2;
        return query(l,r,2*cur+1, lx, mid) + query(l,r,2*cur+2, mid, rx);
    }
    void reset(int K){
        arr= v<int>(4*K);
        n=K;
    }
};
v<int> treeA[300001];
v<int> treeB[300001];
int t = 0;
int tin[300001];
int tout[300001];
int anc[30][300001];
int N;
segtree st1(300001);
segtree st2(300001);
map<int, int> rollback;
void euler(int cur, int par){
    tin[cur] = t++;
    anc[0][cur] = par;
    for(int i=1; i<30; i++){
        if(anc[i-1][cur]==-1) continue;
        anc[i][cur] = anc[i-1][anc[i-1][cur]];
    }
    for(int next: treeB[cur]){
        if(next==par)continue;
        euler(next, cur);
    }
    tout[cur] = t++;
}
int ans =0;
int m = 0;
void dfs(int cur, int par){
    int path = st1.query(tin[0], tin[cur]+1);
    int subtree = st2.query(tin[cur], tout[cur]);
    if(path==0 && subtree==0){
        st1.update(tin[cur], 1);
        st1.update(tout[cur], -1);
        st2.update(tin[cur], 1);
        ans++;
    }
    if(path==1 && subtree==0){
        //change the path thing to 0
        int u = cur;
        for(int i=29; i>=0; i--){
            if(anc[i][u]!=-1){
                if(st1.query(0,1+ tin[anc[i][u]]) >0) {
                    // cout<<u<<" "<<anc[i][u]<<endl;
                    u = anc[i][u];
                }
            }
        }
        st1.update(tin[u], 0);
        st1.update(tout[u], 0);
        st2.update(tin[u], 0);
        st1.update(tin[cur], 1);
        st1.update(tout[cur], -1);
        st2.update(tin[cur], 1);
        rollback.emplace(cur, u);
    }
    if(path==0 && subtree==1){
        //do nothing
    }
    m = max(m, ans);
    for(int next: treeA[cur]){
        if(next==par) continue;
        dfs(next, cur);
    }
    ans-= st1.query(tin[cur], tin[cur]+1);
    st1.update(tin[cur], 0);
    st1.update(tout[cur], 0);
    st2.update(tin[cur], 0);
    if(rollback.find(cur)!=rollback.end()){
        int l = rollback[cur];
        path = st1.query(tin[0], tin[l]+1);
        if(path==0){
            st1.update(tin[l], 1);
            st1.update(tout[l], -1);
            st2.update(tin[l], 1);
            ans++;
        }
    }
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        cin>>N;
        for(int i=0; i<30; i++){
            for(int j=0; j<N; j++){
                anc[i][j] = -1;
            }
        }
        for(int i=1; i<=N-1; i++){
            int par; cin>>par;
            par--;
            treeA[i].push_back(par);
            treeA[par].push_back(i);

        }
        for(int i=1; i<=N-1; i++){
            int par; cin>>par;
            par--;
            treeB[i].push_back(par);
            treeB[par].push_back(i);
        }
        euler(0, -1);
        st1.reset(2*N);
        st2.reset(2*N);
        dfs(0, -1);
        cout<<m<<endl;
        for(int i=0; i<30; i++) {
            for (int j = 0; j < N; j++) {
                anc[i][j] = -1;
            }
        }
        m=0;
        ans=0;
        t=0;
        for(int i=0; i<N; i++){
            treeA[i].clear();
            treeB[i].clear();
            tin[i] = 0;
            tout[i] = 0;
        }
        rollback.clear();
    }
    return 0;
}

