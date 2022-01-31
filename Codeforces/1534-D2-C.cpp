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
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr1; v<int> arr2(N+1);
        for(int i=0; i<N; i++){
            int num; cin>>num; arr1.push_back(num);
        }
        for(int i=0; i<N; i++){
            int num; cin>>num; arr2[num] = i;
        }
        v<bool> visited(N);
        int count = 0;
        for(int i=0; i<N; i++){
            if(!visited[i]){
                int j=arr2[arr1[i]];
                visited[i] = true;
                while(i!=j){
                    visited[j] = true;
                    j=arr2[arr1[j]];
                }
                count++;
            }
        }
        long ways = 1;
        while(count-->0){
            ways*=2;
            ways%=MOD;
        }
        cout<<ways<<endl;
    }
    return 0;
}

