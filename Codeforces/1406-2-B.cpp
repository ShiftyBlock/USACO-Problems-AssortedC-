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
        v<long> arr;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
        int i=0;
        int j=N-1;
        long ans = -1e18;
        ans = max(ans, arr[i]* arr[i+1]* arr[i+2]* arr[i+3]*arr[j]);
        ans = max(ans, arr[i]* arr[i+1] * arr[j] * arr[j-1] * arr[j-2]);
        ans = max(ans, arr[j] * arr[j-1] * arr[j-2] * arr[j-3] * arr[j-4]);
        ans = max(ans, arr[i] * arr[i+1] * arr[i+2] * arr[i+3] * arr[i+4]);
       cout<<ans<<endl;
    }
    return 0;
}

