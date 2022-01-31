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
bool T[101][200001];
bool subsetSum(v<int>arr, int n, int sum)
{
    // `T[i][j]` stores true if subset with sum `j` can be attained
    // using items up to first `i` items


    // if 0 items in the list and the sum is non-zero
    for (int j = 1; j <= sum; j++) {
        T[0][j] = false;
    }

    // if the sum is zero
    for (int i = 0; i <= n; i++) {
        T[i][0] = true;
    }

    // do for i'th item
    for (int i = 1; i <= n; i++)
    {
        // consider all sum from 1 to sum
        for (int j = 1; j <= sum; j++)
        {
            // don't include the i'th element if `j-arr[i-1]` is negative
            if (arr[i - 1] > j) {
                T[i][j] = T[i - 1][j];
            }
            else {
                // find the subset with sum `j` by excluding or including the i'th item
                T[i][j] = T[i - 1][j] || T[i - 1][j - arr[i - 1]];
            }
        }
    }

    // return maximum value
    return T[n][sum];
}

// Partition problem – Returns true if given array `arr[0…n-1]` can
// be divided into two subsets with equal sum
bool partition(v<int> arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // return true if the sum is even and the array can be divided into
    // two subsets with equal sum
    return !(sum & 1) && subsetSum(arr, n, sum/2);
}
int main() {
    setIO("", 0);
    int N; cin>>N;
    v<int> arr;
    int sum=0;
    for(int i=0; i<N; i++){
        int num; cin>>num; arr.push_back(num);
        sum+=num;
    }
    //our goal is to make sure that the parity is odd
    // or if we can't do that
    // just remove any number
    // and this should work (?)
    if (partition(arr, N)) {
        cout<<1<<endl;
        bool flag=false;
        while(!flag){
            for(int i=0; i<N; i++){
                if(arr[i]%2==1){
                    cout<<i+1<<endl;
                    flag=true;
                    break;
                }
            }
            for(int i=0; i<N; i++){
                arr[i]/=2;
            }
        }
    }
    else {
        cout<<0<<endl;
    }
    return 0;
}

