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
        int N;
        cin>>N;
        v<int> arr;
        v<int> freq(N);
        for(int i=0; i<N; i++){
            int num; cin>>num; num--;
            arr.push_back(num);
            freq[arr[i]]++;
        }
        bool valid = false;
        for(int i=0; i<N; i++){
            if(freq[i] ==1){
                valid=true;
                for(int j=0; j<N; j++){
                    if(arr[j] == i) {
                        cout<<j+1<<endl;
                    }
                }
                break;
            }
        }
        if(!valid) cout<<-1<<endl;
    }
    return 0;
}

