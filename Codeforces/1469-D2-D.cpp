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
//find square root of biggest number
// then find square root of that
//and that
// until you reach 3 or 2
// at 3 you just divide by the 2
// at 2 you are done
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        for(int i=0; i<N; i++){
            arr.emplace_back(i+1);
        }
        v<int> moves;
        set<int> s;
        int big = N;
        while(big!=2){
            int num = ceil(sqrt(big));
            moves.push_back(num);
            s.emplace(num);
            big = num;
        }
        v<pii> ans;
        for(int i=0; i<N-1; i++){
            int num = i+1;
            if(s.find(num)!=s.end()) continue;
            ans.emplace_back(i+1, N);
        }
        for(int i=0; i<moves.size(); i++){
            if(i==0) {
                ans.emplace_back(N, moves[i]);
                ans.emplace_back(N, moves[i]);
            }
            else{
                ans.emplace_back(moves[i-1], moves[i]);
                ans.emplace_back(moves[i-1], moves[i]);
            }
        }
        cout<<ans.size()<<endl;
        for(pii x: ans){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    return 0;
}

