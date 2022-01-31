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


}
// dp[row][col][numbers taken in col][cursum%k] = cursum
int dp[71][71];
int matrix[71][71];
int row[71][71][71];
int br[71][71];
// make a best row array
// row[r][taken][cursum%k] = cursum
// then finally our answer is going to be
//
int main() {
    setIO("", 0);
    int N, M, K;
    cin>>N>>M>>K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M;j++){
            cin>>matrix[i][j];
        }
    }
    // set everything here to impossible except when you take nothing
    for(int i=0; i<71; i++){
        for(int j=0; j<71; j++){
            for(int k=0; k<71; k++){
                row[i][j][k] = -1;
                if(j==0 && k==0) row[i][j][k] =0;
            }
            br[i][j]=-1;
            dp[i][j]= -1;
        }
    }
    //dp[0] = using null
    // dp[anything][0] = null
    //1 indexing
    // get best row
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=M/2-1; k>=0; k--){
                for(int l=0; l<K; l++){
                    if(row[i][k][l] >=0){
                        row[i][k+1][(l+matrix[i][j])%K] = max( row[i][k+1][(l+matrix[i][j])%K], row[i][k][l] + matrix[i][j]);
                    }
                }
            }
        }
        //get best dp sum
        for(int j=0; j<M; j++){
            for(int k=0; k<K; k++){
                br[i][k]= max(br[i][k], row[i][j][k]);
               //cout<<row[i][j][k]<<" ";
            }
          //  cout<<endl;
        }
      //cout<<endl;

    }
    for(int i=0; i<1; i++){
        for(int j=0; j<K; j++){
            dp[i][j]= br[i][j];
        }
    }

    //issue with the dp
    // you can knapsack but there might not be anything there

    for(int i=1; i<N; i++){

        for(int j=0; j<K; j++){
            for(int k=0; k<K; k++){
                //fixed with this check
                if(dp[i-1][j]>=0 && br[i][k] >=0) {
                    dp[i][(j + br[i][k]) % K] = max(dp[i][(j + br[i][k]) % K], dp[i - 1][j] + br[i][k]);
                }
            }
        }
        /*for(int j=0; j<K; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";*/
    }
    /*
    cout<<"BEST ROW SECTION"<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            cout<<br[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"BEST DP SECTION"<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
     */

    cout<<dp[N-1][0]<<endl;


    return 0;
}

