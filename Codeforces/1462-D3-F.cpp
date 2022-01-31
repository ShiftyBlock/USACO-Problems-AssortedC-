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
bool sortLeft(pii x, pii y){
    return x.second < y.second;
}
bool sortRight(pii x, pii y){
    return x.first < y.first;
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<pii> arr;
        for(int i=0; i<N; i++){
            int a,b; cin>>a>>b;
            arr.emplace_back(a,b);
        }
        v<pii> left = arr;
        sort(left.begin(), left.end(), sortLeft);
        for(int i=0; i<left.size(); i++){
            int temp= left[i].first;
            left[i].first = left[i].second;
            left[i].second = temp;
        }
        v<pii> right = arr;
        sort(right.begin(), right.end(), sortRight);
        int ans = 1<<30;
        for(int i=0; i<N; i++){
            pii x = arr[i];
            int below = lower_bound(left.begin(), left.end(), make_pair(x.first, (long) -1e9)) - left.begin();
            int above = right.end() - upper_bound(right.begin(), right.end(), make_pair(x.second, (long) 1e9));
           ans = min(ans, below+above);
        }
        cout<<ans<<endl;

    }
    return 0;
}

