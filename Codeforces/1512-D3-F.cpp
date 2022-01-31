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
        int N, C;
        cin>>N>>C;
       // try buying each course
       v<int> arr1, arr2;
       for(int i=0; i<N; i++){
           int num; cin>>num;
           arr1.push_back(num);
       }
       for (int i = 0; i < N-1; ++i) {
            int num; cin>>num;
            arr2.push_back(num);
       }
       long ans = 1<<30;
       long days = 0;
       long tugrik=0;
       for(int i=0; i< N; i++){
           long profit = arr1[i];
           long daysUntilDone = (C-tugrik)/profit;
           long realTugrik = daysUntilDone * profit;
           if(realTugrik +tugrik < C){
               realTugrik += profit;
               daysUntilDone++;
           }
           ans = min(ans, days+daysUntilDone);
           //try buy course
           if(tugrik >= arr2[i]){
               days++;
               tugrik -= arr2[i];
               continue;
           }
           long td = (arr2[i] - tugrik)/profit;
           long realt = td * profit;
           if(realt + tugrik < arr2[i]){
               realt+=profit;
               td++;
           }
           days+= td;
           tugrik +=  realt;
           tugrik-=arr2[i];
           days++;
       }
       cout<<ans<<endl;
    }
    return 0;
}

