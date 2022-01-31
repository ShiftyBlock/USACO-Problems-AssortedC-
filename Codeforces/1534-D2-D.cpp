/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define long long long
#define v vector

long MOD = 1e9+7;


int main() {
    int N; cin>>N;
    cout<<"? 1"<<endl;
    v<int> dist;
    for(int i=0; i<N; i++){
        int num; cin>>num; dist.push_back(num);
    }
    int evens = 0;
    for(int i=0; i<N; i++){
        if(dist[i]%2==0) evens++;
    }
    v<int> proc;
    v<pii> ans;
    if(evens>N/2){
        for(int i=0; i<N; i++){
            if(dist[i]%2==1) proc.push_back(i+1);
        }
    }
    else{
        for(int i=0; i<N; i++){
            if(dist[i]%2==0 && dist[i]>0) proc.push_back(i+1);
        }
        for(int i=0; i<N; i++){
            if(dist[i]==1) ans.emplace_back(1, i+1);
        }
    }
    while(proc.size()>0){
        int cur = proc.back(); proc.pop_back();
        cout<<"? "<<cur<<endl;
        dist.clear();
        for(int i=0; i<N; i++){
            int num; cin>>num; dist.push_back(num);
        }
        for(int i=0; i<N; i++){
            if(dist[i]==1) ans.emplace_back(cur, i+1);
        }
    }
    cout<<"!"<<endl;
    for(pii x: ans){
        cout<<x.first<<" "<<x.second<<endl;
    }

    return 0;
}

