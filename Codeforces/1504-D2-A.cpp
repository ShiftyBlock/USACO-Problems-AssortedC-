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
bool isP(string s){
    bool valid = true;
    for(int i=0; i<s.length(); i++){
        if(s[i] != s[s.length()-i-1]) valid=false;
    }
    return valid;
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        string s; cin>>s;
        int N = s.length();
        bool allA = true;
        for(int i=0; i<N; i++){
            allA&= (s[i]=='a');
        }
        if(allA){
            cout<<"NO"<<endl;
            continue;
        }
        if(!isP('a' + s)){
            cout<<"YES"<<endl;
            cout<<'a'+s<<endl;
        }
        else if(!isP(s+'a' )){
            cout<<"YES"<<endl;
            cout<<s+'a'<<endl;
        }


    }
    return 0;
}

