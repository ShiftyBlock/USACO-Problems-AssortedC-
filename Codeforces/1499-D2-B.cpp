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
        string s;cin>>s; int N = s.length();
        v<int> arr;
        for(int i=0; i<N; i++){
            arr.emplace_back(s[i]-'0');
        }
        if(is_sorted(arr.begin(), arr.end())) {
            cout<<"YES"<<endl;
            continue;
        }
        int first = -1;
        for(int i=0; i<N-1; i++){
            if(arr[i]==1 && arr[i+1]==1) {
                first=i; break;
            }
        }
        int second = -1;
        for(int i=N-2; i>=0; i--){
            if(arr[i]==0 && arr[i+1]==0) {
                second=i; break;
            }
        }
        if(first>-1 && second>-1 && first<second) cout<<"no"<<endl;
        else cout<<"YEs"<<endl;
    }
    return 0;
}

