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
//sort hint array
// if we take an arbitrary index
// and let mystery number = x
// then there will be (j)/2 pairs such that you add 2*x
// and any number above it contributes 2*thatmysterynumber
// so if we start from the back
// and calculate one at a time
// you can then just add the remaining sum
// and check if possible
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        N*=2;
        v<long> arr;
        for (int i = 0; i < N; ++i) {
            long num; cin>>num; arr.emplace_back(num);
        }
        sort(arr.begin(), arr.end());
        bool valid = true;
        map<long, int> freq;
        for(int i=0; i<N; i++){
            freq[arr[i]]++;
        }
        for(auto x: freq){
            if(x.second != 2) valid = false;
        }
        if(!valid){
            cout<<"NO"<<endl;
            continue;
        }
        v<int> ans;
        long cursum = 0;
       /* for(int i=0; i<N; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout.flush();*/

        for(int i=N-1; i>=0; i-=2){
            //below, pairs, +2 for self
            int below = i/2*2 +2;
            //no zeros allowed oops
            if(arr[i] <= cursum) valid = false;
            long x= arr[i] - cursum;
            if(x%below!=0){
                valid =false;
            }
            long num = x/below;
            ans.push_back(num);
            ans.push_back(-num);
            cursum+=2*num;
        }
        /*reverse(ans.begin(), ans.end());
        for(int num: ans){
            cout<<num<<" ";
        }
        cout<<endl;*/
        if(valid) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
       // cout<<endl;
    }
    return 0;
}

