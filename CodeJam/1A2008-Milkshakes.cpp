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
// BAD idea
// satisfy everyone firstly with an unmalted drink
//then for all people who are not satisfied yet
//try to add in the malted drinks
//if there is a contradiction, break

//good idea?? (Still bad actually)
// for each milkshake
//see if you have to do it
// go through an adjacency list for the relevant customers
// or maybe we don't even have to save time, N and M is 2000
// and the sum of T is 3000

// correct solution
// set everything to malted
// look at each customer
// if a customer's preferences have all been made malted then impossible
// if a customer is unhappy and there is a malted required, make it malted, then go back to the first clause
// when done, print the answer

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    int temp=tcs;
    while(tcs-->0){
        int N; cin>>N;
        int M; cin>>M;
        v<int> dp;
        for(int i=0; i<N; i++){
            dp.push_back(-1);
        }
        bool valid=true;
        v<v<pii>> arr(M);
        for(int i=0; i<M; i++){
            int T; cin>>T;
            for(int j=0; j<T; j++){
                int a, b; cin>>a>>b;
                arr[i].push_back(make_pair(a,b));
            }
        }
        //sort arr[i]'s stuff
        for(int i=0; i<M; i++){
            sort(arr[i].begin(), arr[i].end());
        }
        //process
        v<bool> happy;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                for(int k=0; k<arr[j].size(); k++){
                    int a = arr[j][k].first;
                    int b = arr[j][k].second;
                    if(a==i){
                        if(dp[a] == b) {
                            happy[j] =true;
                            break;
                        }
                        if(k==arr[j].size()-1){
                            if(dp[a] == -1){
                                dp[a]=b;
                            }
                            if(dp[a]!=b){
                                happy[j]=false;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(!valid){
            cout<<"Case #"<<temp-tcs<<": "<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"Case #"<<temp-tcs<<": ";
        for(int i=0; i<N; i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

