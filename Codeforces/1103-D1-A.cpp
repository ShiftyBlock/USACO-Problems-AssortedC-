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
    string s; cin>>s;
    bool usedver = false;
    int hor=0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '0'){
            if(!usedver){
                cout<<1<<" "<<1<<endl;
                usedver = true;
            }
            else if(usedver){
                cout<<3<<" "<<1<<endl;
                usedver=false;
            }
        }
        if(s[i] == '1'){
            cout<<hor+1<<" "<<3<<endl;
            hor++;
            hor%=4;
        }
    }
    return 0;
}

