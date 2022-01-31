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
    int A,B,C,D; cin>>A>>B>>C>>D;
    int N = 2e6;
    v<int> arr1(N);
    v<int> psum(N);
    //0 illegal anyways
    for(int i=1; i<N; i++){
        if(i>=A && i<=B) arr1[i] = 1;
        psum[i] = psum[i-1] + arr1[i];
    }
    v<int> arr2(N);
    for(int i=1; i<N; i++){
        int b = 0;
        int c = 0;
        if(i>=B) b = psum[i-B];
        if(i>=C+1) c= psum[i-(C+1)];
        arr2[i] = b-c;
    }
    //match up 3rd side
    long ans =0;
    for(int i=1; i<N; i++){
        //for a given a+b>c sum
        // we need a c such that c>=C and c<=D
        // where c is smaller than a+b
        ans+=arr2[i] * (long) max(0, min(i-C,D-C+1));
    }
    cout<<ans<<endl;

    return 0;
}

