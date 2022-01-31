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
bool vowel(char c){
    return (c=='A')||(c=='E')||(c=='I')||(c=='O')||(c=='U');
}
int main() {
    setIO("test", 1);
    int tcs; cin>>tcs;
    int tcx= tcs;
    while(tcs-->0){
        string s; cin>>s;
        int N = s.length();
        int ans = 1<<30;
        for(char c ='A'; c<='Z'; c++){
            bool t = vowel(c);
            int cur = 0;
            for(int j=0; j<N; j++){

                if(c==s[j]) continue;
                bool tx = vowel(s[j]);
                if(tx==t) cur+=2;
                else cur++;
            }
            ans = min(ans, cur);
        }
        cout<<"Case #"<<tcx-tcs<<": "<<ans<<endl;
    }
    return 0;
}

