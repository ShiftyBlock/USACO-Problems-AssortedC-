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

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<pii> arr;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.emplace_back(num, i);
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                if(arr[i].first * arr[j].first > N+ N-1) break;
                if(arr[i].first * arr[j].first == (arr[i].second+1) + (arr[j].second+1)){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

