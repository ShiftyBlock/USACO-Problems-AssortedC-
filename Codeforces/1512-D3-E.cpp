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
        int N, L, R, X; cin>>N>>L>>R>>X;
        int minB = 0;
        for(int i=1; i<=R-L+1; i++){
            minB+=i;
        }
        int maxB = 0;
        for(int i=N; i>N-(R-L+1); i--){
            maxB +=i;
        }
        if(X> maxB || X<minB){
            cout<<-1<<endl;
            continue;
        }
        int j=0;
        int curNum=N;
        v<int> arr;
        int sum=0;
        for(int i=1; i<=R-L+1; i++){
            arr.push_back(i);
          //  cout<<i<<endl;
            sum+=i;
        }
        while(j<arr.size()){
            if((sum+curNum-arr[j]) == X){
                sum+=curNum - arr[j];
                arr[j] = curNum;
                break;
            }

            if(sum+curNum - arr[j] > X){
                if(curNum == arr.size()+1){
                    j++;
                    continue;
                }
                curNum--;
                continue;
            }
            if(sum+curNum - arr[j] < X){
                sum+=curNum;
                sum-= arr[j];
                arr[j] = curNum;
                curNum--;
                j++;
            }
        }
        v<int> notUsed;
        for(int i=1; i<=N; i++){
            bool con = false;
            for(int k=0; k<arr.size(); k++){
                if(arr[k] == i) con=true;
            }
            if(!con) notUsed.push_back(i);
        }
        j=0;
        L--;
        R--;
        for(int i=0; i<N; i++){
            if(i>= L && i<=R){
                cout<<arr[i-L]<<" ";
            }
            else{
                cout<<notUsed[j]<<" ";
                j++;
            }
        }
        cout<<endl;


    }
    return 0;
}

