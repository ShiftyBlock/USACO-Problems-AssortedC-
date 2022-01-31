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
        v<int> pos(101);
        for(int i=0; i<N; i++){
            int num; cin>>num;
            arr.push_back(num);
            pos[num] = i;
        }
        sort(arr.begin(), arr.end());
        int ans = 1<<30;
        int a = pos[arr[0]];
        int b = pos[arr[arr.size()-1]];
        ans = min(ans, max(a,b)+1);
        ans = min(ans, min(a,b)+1 + N-max(a,b));
        ans = min(ans, N-min(a,b));
        cout<<ans<<endl;


    }
    return 0;
}

