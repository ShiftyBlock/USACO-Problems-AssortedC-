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
//exploding freeze orz
//https://codeforces.com/contest/1537/submission/119871715 credits
int main() {
    setIO("", 0);
    int N, K; cin>>N>>K;
    string s; cin>>s;
    int j= 0;
    string ans =""; ans+=s[0];
    string cur = "";
    for(int i=1; i<N; i++){
        cur+=s[i];
        if(s[i] > s[j]) break;
        if(s[i] < s[j]) {
            ans+=cur;
            j=0;
            cur="";
        }
        else j++;
    }
    while(ans.length()<K){
        ans= ans+ans;
    }
    while(ans.length()>K){
        ans.pop_back();
    }
    cout<<ans<<endl;
    return 0;
}

