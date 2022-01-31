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
    v<long> fact;
    fact.push_back(1);
    for(int i=2; i<=10; i++){
        fact.push_back(i*fact.back());
    }
    long x; cin>>x;
    int coins = 0;
    while(x>0){
        if(x<fact.back()) fact.pop_back();
        else{
            x-=fact.back();
            coins++;
        }
    }
    cout<<coins<<endl;
    return 0;
}

