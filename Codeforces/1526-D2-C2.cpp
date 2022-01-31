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
struct segtree{
    int N;
    v<long> operations;
    v<long> mins;
    segtree(int n){
        N= 1;
        while(N<n) N*=2;
        operations.assign(2*N, 0);
        mins.assign(2*N, 0);
    }
    void add(int l, int r, long x){
        add(l,r,x, 0, 0, N);
    }
    void add (int l, int r, long x, int cur, int lx, int rx){
        if(lx>=r || l>=rx) return;
        if(lx>=l && rx<=r) {
            operations[cur]+=x;
            mins[cur]+=x;
            return;
        }
        int m = (lx+rx)/2;
        add(l,r,x, 2*cur+1, lx, m);
        add(l,r,x, 2*cur+2, m, rx);
        mins[cur] = min(mins[2*cur+1], mins[2*cur+2])+operations[cur];
    }
    long query(int l, int r){
        return query(l,r,0,0, N);
    }
    long query(int l, int r, int cur, int lx, int rx){
        if(lx>=r || l>=rx) return 1e15;
        if(lx>=l && rx<=r) return mins[cur];
        int m = (lx+rx)/2;
        long m1 = query(l,r,2*cur+1, lx, m);
        long m2 = query(l,r,2*cur+2, m, rx);
        return min(m1, m2) + operations[cur];
    }
};
int main() {
    setIO("", 0);
    int N; cin>>N;
    v<long> arr;
    for(int i=0; i<N; i++){
        int num; cin>>num;
        arr.push_back(num);
    }
    v<long> pos(N);
    v<pii> neg;
    int ans = 0;
    for(int i=0; i<N; i++){
        if(arr[i]>=0) {
            pos[i]+=arr[i];
            ans++;
        }
        if(i!=0) pos[i]+=pos[i-1];
        if(arr[i]<0) neg.emplace_back(-arr[i], i);
    }
    segtree st(N);
    for(int i=0; i<N; i++){
        st.add(i, i+1, pos[i]);
    }
    sort(neg.begin(), neg.end());
    for(int i=0; i<neg.size(); i++){
        long mp = st.query(neg[i].second, N);
        if(neg[i].first <= mp){
            st.add(neg[i].second,N, -neg[i].first);
            ans++;
        }
    }
    cout<<ans<<endl;


    return 0;
}

