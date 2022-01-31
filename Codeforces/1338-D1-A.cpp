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
        v<int> arr;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
        }
        v<int> res;
        res.push_back(arr[0]);
        long ans = 0;
        for(int i=1; i<N; i++){
            long m = max(arr[i], res[i-1]);
            long x = m-arr[i];
            long p2 =1;
            long moves =0;
            while(x>=p2){
                moves++;
                p2*=2;
            }
            ans = max(ans, moves);
            res.push_back(m);
        }
        cout<<ans<<endl;
    }
    return 0;
}

