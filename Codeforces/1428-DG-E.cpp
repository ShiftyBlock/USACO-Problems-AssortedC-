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
long cost(pii a){
    long next = a.second;
    long sizeA = a.first/next;
    long useA = a.first - next*sizeA;
    long costA = (sizeA+1)*(sizeA+1)*useA + (sizeA)*(sizeA)*(next - useA);
    return costA;
}
struct cmp{
    bool operator()(pii a, pii b){
        long costa = cost(make_pair(a.first, a.second));
        long costA = cost(make_pair(a.first, a.second+1));
        long costb = cost(make_pair(b.first, b.second));
        long costB = cost(make_pair(b.first, b.second+1));
        return costa-costA<costb-costB;
    }
};

int main() {
    setIO("", 0);
    int N, K; cin>>N>>K;
    priority_queue<pii,vector<pii>, cmp> arr;
    for(int i=0; i<N; i++){
        int num; cin>>num;
        arr.emplace(num, 1);
    }
    while(arr.size()<K){
        pii cur = arr.top(); arr.pop();
        arr.emplace(cur.first, cur.second+1);
        K--;
    }
    long ans =0;
    while(arr.size()>0){
        long num = cost(arr.top());
        ans+= num;
        arr.pop();
    }
    cout<<ans<<endl;

    return 0;
}

