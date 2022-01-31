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
    //if you can change 1 neighbor
    //or there exists a subsegment of ks >1
    //then its always valid
    while(tcs-->0) {
        int N, M; cin>>N>>M;
        v<int> arr;
        bool container = false;
        for(int i=0; i<N; i++){
            int num; cin>>num;
            arr.push_back(num);
            if(num==M) container =true;
        }
        if(N==1 && arr[0] ==M) {
            cout<<"yes"<<endl;
            continue;
        }
        if(!container){
            cout<<"NO"<<endl;
            continue;
        }
        bool valid = false;

        for(int i=0; i<N;i++ ){
            if(arr[i] >= M){
                if(i>0 && arr[i]<= arr[i-1]){
                    valid=true;
                }
                if(i>1 && arr[i] <= arr[i-2]){
                    valid=true;
                }
                if(i<N-1 && arr[i]<=arr[i+1]){
                    valid=true;
                }
                if(i<N-2 && arr[i] <= arr[i+2]){
                    valid=true;
                }
            }
        }
        if(valid) {
            cout<<"yes"<<endl;
            continue;
        }
        else{
            cout<<"no"<<endl;
        }


    }
    return 0;
}

