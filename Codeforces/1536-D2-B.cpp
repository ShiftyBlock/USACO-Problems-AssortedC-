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
bool check(string s, string t){
    for(int i=0; i<s.length(); i++){
        string temp = s.substr(i, t.length());
        if(temp==t) return true;
    }
    return false;
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;

    LOOP:while(tcs-->0){
        int N; cin>>N;
        string s; cin>>s;
        bool valid = false;
        for(char i='a'; i<='z'; i++){
            string t=""; t+=i;
            if(!check(s, t)){
                cout<<i<<endl;
                valid=true;
                goto LOOP;
            }
        }
        if(valid) continue;
        for(char i='a'; i<='z'; i++){
            for(char j='a'; j<='z'; j++){
                string t=""; t+=i; t+=j;
                if(!check(s, t)){
                    cout<<i<<j<<endl;
                    valid=true;
                    goto LOOP;
                }
            }
        }
        if(valid) continue;
        for(char i='a'; i<='z'; i++){
            for(char j='a'; j<='z'; j++){
                for(char k='a'; k<='z'; k++){
                    string t=""; t+=i; t+=j; t+=k;
                    if(!check(s, t)){
                        cout<<i<<j<<k<<endl;
                        valid=true;
                        goto LOOP;
                    }
                }
            }
        }
        if(valid) continue;
        for(char i='a'; i<='z'; i++){
            for(char j='a'; j<='z'; j++){
                for(char k='a'; k<='z'; k++){
                    for(char l='a'; l<='z'; l++){
                        string t=""; t+=i; t+=j; t+=k; t+=l;
                        if(!check(s, t)){
                            cout<<i<<j<<k<<l<<endl;
                            valid=true;
                            goto LOOP;
                        }
                    }
                }
            }
        }

    }
    return 0;
}

