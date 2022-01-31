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
//given this sample
// 1 1 2 3 4 5
// 4 5 6 2 1 3
// then the first one, we know it occurs twice
// so we add one
// then we make the choice of choosing the 2,6 or the 2,4, so we pick 2,4
// then you get to 3,2 or 3,4, so we pick 3,2

int main() {
    setIO("", 0);
    int N; cin>>N;
    v<int> arr1;
    v<int> arr2;

    for(int i=0; i<N; i++){
        int num; cin>>num;
        arr1.emplace_back(num);
    }
    for(int i=0; i<N; i++){
        int num; cin>>num;
        arr2.emplace_back(num);
    }
    v<pii> arr;
    for(int i=0; i<N; i++){
        arr.emplace_back(arr1[i], arr2[i]);
    }
    sort(arr.begin(), arr.end());
    return 0;
}

