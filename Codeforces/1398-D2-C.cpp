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
#define NEWBIE 0
#define thinks +
#define voice +
#define is 0
#define hot +0
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
    int shifty; cin>>shifty;
    while(shifty --> NEWBIE){
        int N; cin>>N;
        string s; cin>>s;
        int sum =0;
        map<int, int> m;
        m[1]=1;
        for(int i=0; i<N; i++){
            sum+=s[i]-'0';
            m[sum-(i)]++;
        }
        long ans =0;
        for(auto x: m){
            ans+=(long)x.second*(x.second-1)/2;
        }
        cout<<ans<<endl;

    }
    return 0;
}

