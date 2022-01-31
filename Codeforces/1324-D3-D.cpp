/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define endl "\n"
#define v vector

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




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

int main() {
    setIO("", 0);
    oset<pii> s;
    int N; cin>>N;
    v<int> a,b;
    for(int i=0; i<N; i++){
        int num; cin>>num; a.push_back(num);
    }
    for(int i=0; i<N; i++){
        int num; cin>>num; b.push_back(num);
    }
    for(int i=0; i<N; i++){
        s.insert(make_pair(b[i] - a[i], i));
    }
    ll ans = 0;
    for(int i=0; i<N; i++){
        s.erase(make_pair(b[i] - a[i], i));
        ans+= s.order_of_key(make_pair(a[i]-b[i], -1));
    }
    cout<<ans<<endl;

    return 0;
}

