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
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
        }
        int lose = 0;
        int cost = 0;
        for(int i=1; i<N-1; i++){
            if(arr[i-1] > arr[i] && arr[i]< arr[i+1]){
                cost++;
            }
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
                cost++;
            }
            int temp = 0;
            int x = arr[i];
            for(int j=max(1,i-3); j<min(N-1, i+3); j++){
                if(arr[j-1] > arr[j] && arr[j]< arr[j+1]){
                    temp++;
                }
                if(arr[j-1] < arr[j] && arr[j] > arr[j+1]){
                    temp++;
                }
            }
            int t1 = 0;
            arr[i] = arr[i-1];
            for(int j=max(1,i-3); j<min(N-1, i+3); j++){
                if(arr[j-1] > arr[j] && arr[j]< arr[j+1]){
                    t1++;
                }
                if(arr[j-1] < arr[j] && arr[j] > arr[j+1]){
                    t1++;
                }
            }
            int t2 = 0;
            arr[i] = arr[i+1];
            for(int j=max(1,i-3); j<min(N-1, i+3); j++){
                if(arr[j-1] > arr[j] && arr[j]< arr[j+1]){
                    t2++;
                }
                if(arr[j-1] < arr[j] && arr[j] > arr[j+1]){
                    t2++;
                }
            }
            arr[i] = x;
            lose = max(lose, temp - min(t1, t2));
        }
        cout<<cost-lose<<endl;
    }
    return 0;
}

