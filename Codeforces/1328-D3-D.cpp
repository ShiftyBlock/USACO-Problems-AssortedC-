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
        set<int> c;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
            c.emplace(num);
        }
        if(c.size()==1){
            cout<<1<<endl;
            for(int i=0; i<N; i++){
                cout<<1<<" ";
            }
            cout<<endl;
            continue;
        }
        if(c.size()==2){
            cout<<2<<endl;
            int cc  =1;
            for(int i=0; i<N; ){
                int j=i;
                while(j<N){
                    if(arr[j] == arr[i]) j++;
                    else break;
                }
                int sz= j-i;
                while(i<j){
                    cout<<cc<<" ";
                    i++;
                }
                cc++; if(cc==3) cc=1;
            }
            cout<<endl;
            continue;
        }
        if(N%2==0){
            cout<<2<<endl;
            int cc  =1;
            for(int i=0; i<N;i++ ){
                cout<<cc<<" ";
                cc++; if(cc==3) cc=1;
            }
            cout<<endl;
            continue;
        }
        int cc=1;
        v<int> color(N);
        bool flag = false;
        for(int i=0; i<N; i++){
            if(!flag && arr[i]==arr[(i+1)%N]){
                color[i] = cc;
                color[(i+1)%N] = cc;
                i++;
                flag = true;
            }
            else color[i] = cc;
            cc++; if(cc==3) cc=1;
        }
        if(!flag) {
            color[N-1] = 3;
            cout<<"3"<<endl;
        }
        else cout<<"2"<<endl;
        for(int i=0; i<N; i++){
            cout<<color[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}

