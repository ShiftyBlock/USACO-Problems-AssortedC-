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

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N, M; cin>>N>>M;
        v<int> arr(N);
        int sum =0;
        for(int i=0; i<N; i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        if(M==sum) {
            cout<<"NO"<<endl;
            continue;
        }
        int cur = 0;
        cout<<"YES"<<endl;
        while(arr.size()>0){
            if(cur+arr.back() ==M){
                arr.emplace(arr.begin(), arr.back());
                arr.pop_back();
            }
            else{
                cout<<arr.back()<<" ";
                cur+=arr.back();
                arr.pop_back();

            }
        }
        cout<<endl;
    }
    return 0;
}

