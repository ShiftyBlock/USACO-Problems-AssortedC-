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
bool test(int N, string s){
    int a = 0; int b = 0;
    for(int i=0; i<N; i++){
        if(s[i]=='M') b++;
        else a++;
    }
    bool valid = ((2*b)==a);
    return valid;
}
//wow i suck
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        string s; cin>>s;
        int a= 0; int b =0; int c =0;
        bool valid= test(N, s);
        if(!valid) {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0; i<N; i++){
            if(s[i]=='M'){
                b++;
                if(a+c < b) valid=false;
            }
            if(s[i]=='T'){
                if(a>0 && b>0 && c<b) {
                   c++;
                }
                else a++;
            }
        }
        if(a>c)  valid=false;
      //  if()
        if(!valid) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}

