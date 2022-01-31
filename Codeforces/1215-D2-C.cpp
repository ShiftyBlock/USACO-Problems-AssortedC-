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
//wait wtf only 2 letters
//this is so stupid
//by pigeonhole principle
// either the letters are the same
//or they are not
// and therefore you can just replace it with a b
// and by pigeonhole principle there will be always at least 1 bad b
//does this make sense?
int main() {
    setIO("", 0);
    int N; cin>>N;
    string s, t; cin>>s>>t;
    v<int> freq(26);
    for(int i=0; i<N; i++){
        freq[s[i]-'a']++;
    }
    for(int i=0; i<N; i++){
        freq[t[i]-'a']++;
    }
    bool valid = true;
    for(int i=0;i<26; i++){
        if(freq[i]%2==1) valid=false;
    }
    if(!valid) {
        cout<<-1<<endl;
        return 0;
    }
    v<int> a,b;
    for(int i=0; i<N; i++){
        if(s[i]=='a' && t[i]=='b'){
            a.emplace_back(i+1);
        }
        if(s[i]=='b' && t[i]=='a'){
            b.emplace_back(i+1);
        }
    }
    v<pii> ans;
    for(int i=0; i<a.size(); i+=2){
        if(i+1<a.size()) ans.emplace_back(a[i], a[i+1]);
    }
    for(int i=0; i<b.size(); i+=2){
        if(i+1<b.size()) ans.emplace_back(b[i], b[i+1]);
    }
    if(a.size()%2==1 && b.size()%2==1){
        int a1 = a.back();
        int b1 = b.back();
        ans.emplace_back(a1, a1);
        ans.emplace_back(a1, b1);
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }

    return 0;
}

