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
//idea
//figure out the min and the max bound for each dice
// so we can either have a reallybig dice and be cut off like that
// or we can have a really really big sum and we must use big numbers on our dice
// which cuts off the smaller numbers


int main() {
    setIO("", 0);
    long N, A; cin>>N>>A;
    v<int> arr;
    long total=0;
    for(int i=0; i<N; i++){
        int n; cin>>n;
        arr.push_back(n);
        total+=n;
    }
    for(int i=0; i<N; i++){
        long ans=0;
        total-= arr[i];
        //for cutting off the smaller numbers
        ans+= max(0LL, (A-total-1));
        total+=arr[i];
        ans+=max(0LL, arr[i] - (A-(N-1)));
        cout<<ans<<" ";
    }

    return 0;
}

