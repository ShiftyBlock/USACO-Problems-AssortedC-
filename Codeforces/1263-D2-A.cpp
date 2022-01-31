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
        int a,b,c; cin>>a>>b>>c;
        v<int> arr; arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);
        sort(arr.begin(), arr.end());
        long ans = min(arr[0], arr[2] - arr[1]);
        arr[0] -= ans; arr[2]-=ans;
        if(arr[0]>0){
            long temp = min(arr[0]/2, min(arr[1], arr[2]));
            arr[0] -= 2*temp;
            arr[1] -=temp;
            arr[2]-=temp;
            ans+=2*temp;
        }
        ans+=min(arr[1], arr[2]);
        cout<<ans<<endl;
    }
    return 0;
}

