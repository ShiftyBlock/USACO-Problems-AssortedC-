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

void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    else{

    }

}
int dp[102][102];
int result[102][102];
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N, M; cin>>N>>M;
        v<int> arr;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                int num; cin>>num;
                dp[i][j] = num;
                arr.push_back(num);
            }
        }
        sort(arr.begin(), arr.end());
        map<int, int> m;
        //find m smallest
        for(int i=0; i<M; i++){
            if(m.find(arr[i])==m.end()) m.emplace(arr[i], 0);
            m[arr[i]]++;
        }
        int pointer=0;
        for(int i=0; i<N; i++){
            v<int> temp;
            for(int j=0; j<M; j++){
                temp.push_back(dp[i][j]);
            }
            sort(temp.begin(), temp.end());
            for(int j=0; j<M; j++){
                if(m.find(temp[j])!=m.end()){
                    result[i][pointer] = temp[j];
                    m[temp[j]]--;
                    if(m[temp[j]]==0) m.erase(temp[j]);
                    pointer++;
                }
            }
        }
        for(int i=0; i<N; i++){
            v<int> temp;
            for(int j=0; j<M; j++){
                temp.push_back(dp[i][j]);
            }
            for(int j=0; j<M; j++){
                if(result[i][j]!=0){
                    temp.erase(find(temp.begin(), temp.end(), result[i][j]));
                }
            }
            for(int j=0; j<M; j++){
                if(result[i][j]==0){
                    result[i][j] = temp.back();
                    temp.pop_back();
                }
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }

        for(int i=0; i<N+1; i++){
            for(int j=0; j<M+1; j++){
                result[i][j] =0;
                dp[i][j] = 0;
            }
        }

    }
    return 0;
}

