/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<pair<pii, int>> arr;
        for(int i=0; i<N; i++){
            int a, b; cin>>a>>b;
            if(a<b) swap(a,b);
            arr.emplace_back(make_pair(a,b), i);
        }
        sort(arr.begin(), arr.end());
        v<int> ans(N);
        set<pair<pii, int>> s;
        oset<pii> orz;
        for(int i=0; i<N;){
            int j=i;
            while(j<N){
                if(arr[i].first.first == arr[j].first.first) j++;
                else break;
            }
            int pi =i;
            while(i<j){
                auto x = orz.order_of_key(make_pair(arr[i].first.second, -1));
                if(x==0) ans[arr[i].second] = -2;
                else ans[arr[i].second] = orz.find_by_order(0) -> second;
                i++;
            }
            while(pi<i){
                orz.insert(make_pair(arr[pi].first.second, arr[pi].second));
                pi++;
            }
        }
        for(int i=0; i<N; i++){
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}

