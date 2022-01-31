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
int matrix1[1001][1001];
int matrix2[1001][1001];
struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool merge(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};
int main() {
    setIO("", 0);
    int N, M1, M2; cin>>N>>M1>>M2;
    DSU d1 = DSU(N);
    DSU d2 = DSU(N);
    for(int i=0; i<M1; i++){
        int a, b; cin>>a>>b; a--; b--;
        matrix1[a][b] = 1;
        d1.merge(a,b);
    }
    for(int i=0; i<M2; i++){
        int a, b; cin>>a>>b; a--; b--;
        matrix2[a][b] = 1;
        d2.merge(a,b);
    }
    int ans = 0;
    v<pii> print;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(matrix1[i][j]==1 || matrix2[i][j]==1) continue;
            if(d1.get(i)==d1.get(j)) continue;
            if(d2.get(i)==d2.get(j)) continue;
            d1.merge(i,j);
            d2.merge(i,j);
            ans++;
            print.emplace_back(i,j);
        }
    }
    cout<<ans<<endl;
    for(pii x: print){
        cout<<x.first+1<<" "<<x.second+1<<endl;
    }



    return 0;
}

