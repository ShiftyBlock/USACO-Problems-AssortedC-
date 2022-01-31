/*
ID: davidzh8
PROG: subset
LANG: C++
 i want 10 solves today orz
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
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        for(int i=0; i<N; i++){
            int n; cin>>n; arr.push_back(n);
        }
        sort(arr.begin(), arr.end());
        set<double> s;
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                double dist = arr[j] - arr[i];
                double h = 1;
                if((dist*h)/2 > 0) s.emplace((dist*h)/2);
            }
        }
        cout<<s.size()<<endl;
    }
    return 0;
}

