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
//nastya and array thing
//i have no clue on wtf this problem is

// if you do max(min(N-1, arr[i]), min(N, arr[i+1])) and
// max(min(N-1, arr[i]), min(N, arr[i+2]))
// and lets say our permutation is 5 3 4 2 1 and i=0
// then we get 5 for the first query
// 5 for the second query
// so we know that the first element is going to be 5
//

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr(N);
        for(int i=0; i<N; i++){
            int T1;
            cout<<"? 1 "<<i+1<<" "<<i+2<<" "<<1<<endl;
            cin>>T1;
            int T2;
            cout<<"? 1 "<<i+2<<" "<<i+3<<" "<<1<<endl;
            cin>>T2;
            int T3;
            cout<<"? 2 "<<i+1<<" "<<i+2<<" "<<N-1<<endl;
            cin>>T3;
            int T4;
            cout<<"? 2 "<<i+2<<" "<<i+3<<" "<<N-1<<endl;
            cin>>T4;

            map<int, int> freq;
            freq[T1]++; freq[T2]++; freq[T3]++; freq[T4]++;
            for(auto key: freq){
                if(key.second ==2){
                    arr[i+1] = key.first;
                }
            }


        }
    }

    return 0;
}

