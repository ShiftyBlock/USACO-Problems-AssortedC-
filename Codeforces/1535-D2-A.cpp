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
        int a,b,c,d; cin>>a>>b>>c>>d;
        int better = max(a,b);
        int better2= max(c,d);
        v<int> arr;
        arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);
        arr.push_back(d);
        sort(arr.begin(), arr.end());
        bool valid = false;
        if(arr[2]== better && arr[3] == better2) valid =true;
        if(arr[3]== better && arr[2] == better2) valid =true;
        if(valid) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}

