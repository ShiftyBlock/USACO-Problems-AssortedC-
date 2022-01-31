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
//solves A = 1, B=2 case
// i think full credit is like strong induction
// if we use the example 2,4
// 4 -> 2
// 5 -> 1, 3
// 6 -> 2 , 4
// 7 -> 3, 5
// 8 -> 4, 6
// 9 -> 5, 7
//you get the point


int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    int temp = tcs;
    while(tcs-->0){
        int N, A,B; cin>>N>>A>>B;
        v<int> arr;
        for(int i=0; i<N; i++){
            int n; cin>>n; arr.push_back(n);
        }
        //observation
        //the number of metals we can make is fib
        v<pii> fib(30);
        fib[0] = make_pair(1,0);
        fib[1] = make_pair(0,1);
        for(int i=2; i<30; i++){
            fib[i] = make_pair(fib[i-1].first + fib[i-2].first,fib[i-1].second + fib[i-2].second);
        }
        pii sum =make_pair(0,0);
        for(int i=0; i<N; i++){
            sum.first+=arr[i] * fib[i].first;
            sum.second+=arr[i] * fib[i].second;
        }
        int ans=-1;
        for(int i=0; i<30; i++){
            if(fib[i].second >=sum.second){
                if(fib[i].first >= sum.first){
                    ans=i+1;
                    break;
                }
                if(fib[i].first < sum.first){
                    if(fib[i].second - sum.second + fib[i].first >= sum.first){
                        ans=i+1;
                        break;
                    }
                }
            }
        }
        cout<<"Case #"<<temp-tcs<<": "<<ans<<endl;
    }
    return 0;
}

