/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define endl "\n"
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
struct dsu{
    int N; v<int> arr;
    dsu(int n){
        N=n;
        arr.resize(N);
        for(int i=0; i<N; i++){
            arr[i]=i;
        }
    }
    int find(int x){
        if(x==arr[x]) return x;
        int par = find(arr[x]);
        arr[x] = par;
        return par;
    }
    bool merge(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x==y) return false;
        arr[x] = y;
        return true;
    }
};
v<pii> val;
struct cmp{
    bool operator()(int a, int b){

    }
};
int main() {
    setIO("", 0);
    int N; cin>>N;
    v<pii> arr;
    for(int i=0; i<N; i++){
        int a, b; cin>>a>>b;
        val.emplace_back(a,b);
        arr.emplace_back(a, i);
        arr.emplace_back(b, i);
    }
    sort(arr.begin(), arr.end());
    dsu dj(N);
    auto cmp = [] (int a, int b){
        return val[a].first < val[b].first;
    };
    set<int, decltype(cmp)> s(cmp);
    bool valid = true;
    for(auto x: arr){
        if(s.find(x.second)!=s.end()){
            s.erase(s.find(x.second));
            auto idx = s.lower_bound(x.second);
            for(; idx !=s.end(); idx++){
                int num = *idx;
                if(num != x.second && val[num].first > val[x.second].first){
                    if(!dj.merge(num, x.second)){
                        valid=false;
                        break;
                    }
                }
            }

        }
        else s.insert(x.second);
    }
    for(int i=0; i<N; i++){
        dj.find(i);
    }
    sort(dj.arr.begin(), dj.arr.end());
    valid &= (dj.arr[0] == dj.arr.back());
    if(valid){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}