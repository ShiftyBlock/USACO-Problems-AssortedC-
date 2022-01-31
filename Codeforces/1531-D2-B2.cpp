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
    map<pii, int> arr;
    map<int, int> height;
    long ans=0;
    for(int i=0; i<N; i++){
        int a, b; cin>>a>>b;
        if(a==b){
            ans+=height[a];
            height[a]++;
        }
        if(a!=b){
            ans-=arr[make_pair(min(a,b), max(a,b))];
            ans+=height[a];
            ans+=height[b];
            height[a]++;
            height[b]++;
            arr[make_pair(min(a,b), max(a,b))]++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

