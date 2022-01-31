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
// given ABCDE
//you can either compare ABCDE
// or cyclic shift starting from
// AEDCB
// BAEDC
// CBAED
// DCBAE
// EDCBA
// AEDCB (cycled)

//every time you move, you're cyclic shifting
//the string to the right
//
int main() {
    setIO("", 0);
    string s; cin>>s;
    v<int> arr;
    int N = s.length();
    for(int i=0; i<N; i++){
        if(s[i]=='b')arr.push_back(0);
        else arr.push_back(1);
    }
    int best = 0;
    for(int i=0; i<N; ){
        int temp = i;
        int j=i+1;
        while(j<N){
            if((arr[i]+1)%2 == arr[j]){
                j++;
                i++;
            }
            else break;
        }
        i=j;
        best = max(best, j-temp);
    }
    if(best ==N){
        cout<<best<<endl;
        return 0;
    }
    int low =1; int high =N-1;
    while(low<high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] =temp;
        low++;
        high--;
    }
    int dp0=0;
    for(int i=0; i<N; ){
        int temp = i;
        int j=i+1;
        while(j<N){
            if((arr[i]+1)%2 == arr[j]){
                j++;
                i++;
            }
            else break;
        }
        int tempans=j-temp;
        if(temp==0){
            dp0 = tempans;
        }
        if(j==N){
            if((arr[N-1]+1)%2 == arr[0]){
                tempans+=dp0;
            }
        }
        best = max(best, tempans);
        i=j;
    }
    cout<< best<<endl;

    return 0;
}

