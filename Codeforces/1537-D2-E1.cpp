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
    int N, K; cin>>N>>K;
    string s; cin>>s;

    string temp =to_string(s[0]);
    for(int i=1; i<N; i++){
        if(s[i] < s[0]) temp+=s[i];
        if(s[i] > s[0])  break;
        if(s[0] == s[i]){
            int j=i;

        }
    }
    return 0;
}

