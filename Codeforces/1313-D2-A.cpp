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
int check(int a, int b, int c, v<v<int>> &arr){
    v<int> ct={a,b,c};
    int ans = 0;
    for(int i=0; i<7; i++){
        bool check= true;
        for(auto x: arr[i]){
            if(ct[x]<=0) check = false;
        }
        if(check){
            ans++;
            for(auto x: arr[i]){
                ct[x]--;
            }
        }
    }
    return ans;

}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int a, b, c; cin>>a>>b>>c;
        v<v<int>> arr;
        arr.push_back({0});
        arr.push_back({1});
        arr.push_back({2});
        arr.push_back({0,1});
        arr.push_back({0,2});
        arr.push_back({1,2});
        arr.push_back({0,1,2});
        sort(arr.begin(), arr.end());
        int ans =0 ;
        while(next_permutation(arr.begin(), arr.end())){
            ans = max(ans, check(a,b,c, arr));
        }
        cout<<ans<<endl;
    }
    return 0;
}

