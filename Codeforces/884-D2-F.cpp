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
    int N; cin>>N;
    string s; cin>>s;
    v<int> freq;
    for(int i=0; i<N; i++){
        freq[s[i]-'a']++;
    }
    v<pii> arr;
    for(int i=0; i<N; i++){
        int num; cin>>num; arr.emplace_back(num, i);
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    //idea is
    //that we sort positions by decreasing weight
    // and we have 2 cases
    // if the complement isnt the same we can continue without doing anything
    //if the complement is the same
    // take the cheapest element that isnt the same char
    // and then swap

    return 0;
}

