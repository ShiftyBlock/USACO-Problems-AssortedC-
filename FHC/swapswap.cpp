#include <bits/stdc++.h>
using namespace std;

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

int main(){
    setIO("swap",1);
    int n;
    int k;
    int a1,a2,b1,b2;
    cin>>n>>k>>a1>>a2>>b1>>b2;
    int cows[n];
    for(int i=0;i<n;i++){
        cows[i]=i;
        //cow #1 is 0
    }
    for(int i=0;i<k;i++){
        //repeat steps 1 and 2 k times
        int temp1,temp2;
        for(int j=0;j<=(a2-a1)/2;j++){
            temp1=cows[a1+j-1];
            temp2=cows[a2-j-1];
            cows[a1+j-1]=temp2;
            cows[a2-j-1]=temp1;
        }
        //repeat for step 2

        for(int j=0;j<=(b2-b1)/2;j++){
            temp1=cows[b1+j-1];
            temp2=cows[b2-j-1];
            cows[b1+j-1]=temp2;
            cows[b2-j-1]=temp1;
        }
    }

    for(int i=0;i<n;i++){
        cout<<cows[i]+1<<endl;
    }
}