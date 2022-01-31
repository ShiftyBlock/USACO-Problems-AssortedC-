#include <bits/stdc++.h>
using namespace std;

int n;
int maxgrass[51];


int main(){
    cin>>n;
    char cowdir[n];
    int cowcoord[n][3];
    int ogcoord[n][2];
    for(int i=0;i<n;i++){
        cin>>cowdir[i]>>cowcoord[i][0]>>cowcoord[i][1];
        //cowcoord[n][2] is the one that says if the cow is still moving
        cowcoord[i][2]=1;
    }
    for(int i=0;i<n;i++){
        ogcoord[i][0]=cowcoord[i][0];
        ogcoord[i][1]=cowcoord[i][1];
    }
    //this is the end of the input part////////////////////////////////////////

    //plan
    //find first time that cows intersect
    //fast forward time
    //repeat
    int totalTime=0;
    int rTime=0;
    for(int z=0;z<n;z++){
        //z is just a counter, cows are stopped n times
        int whenInt=1000000001; //whenInt is the first time cows are stopped
        int whichCow=0;
        for(int i=0;i<n;i++){
            //i=cow that is being tested for how much grass it ate
            for(int j=0;j<n;j++){
                //if not same cow and i is alive
                if(j!=i && cowcoord[i][2]==1){
                    //j=cows that are being tested against i
                    if(cowdir[i]=='N'&&cowdir[j]=='E'){
                        //cow being tested is facing north
                        if  (cowcoord[i][0]>=cowcoord[j][0]&&cowcoord[i][1]<cowcoord[j][1]){
                            //cow i is to the right but below cow j
                            if(abs(cowcoord[i][1]-cowcoord[j][1])>abs(cowcoord[i][0]-cowcoord[j][0])){
                                //height dif is greater than x dif
                                if(whenInt>cowcoord[j][1]-cowcoord[i][1]){
                                    whenInt=cowcoord[j][1]-cowcoord[i][1];
                                    whichCow=i;
                                }
                            }
                        }
                    }else if(cowdir[i]=='E'&&cowdir[j]=='N') {
                        //cow being tested is facing east
                        if (cowcoord[i][0] < cowcoord[j][0] && cowcoord[i][1] >= cowcoord[j][1]) {
                            //cow i is to the left but on top of cow j
                            if (abs(cowcoord[i][1] - cowcoord[j][1]) < abs(cowcoord[i][0] - cowcoord[j][0])) {
                                //x dif is greater than height dif
                                if (whenInt > cowcoord[j][0] - cowcoord[i][0]) {
                                    whenInt = cowcoord[j][0] - cowcoord[i][0];
                                    whichCow = i;
                                }
                            }
                        }
                    }
                }
            }
        }
        //whenInt and whichCow are calculated

        if(whenInt==1000000001) break;

        if(whenInt!=1000000001) {
            totalTime = totalTime + whenInt - 1;
            cowcoord[whichCow][2] = 0; //whichcow is stopped
            maxgrass[whichCow] = totalTime + 1;
            //fast forward time
            for (int i = 0; i < n; i++) {
                if (cowdir[i] == 'N') {
                    cowcoord[i][1] = cowcoord[i][1] + whenInt - 1;
                } else {
                    cowcoord[i][0] = cowcoord[i][0] + whenInt - 1;
                }
            }

        }



    }

    //this is the cout part///////////////////////////////////////////////////
    for(int i=0;i<n;i++){
        if(maxgrass[i]==0){
            cout<<"Infinity"<<endl;
        }else{
            cout<<maxgrass[i]<<endl;
        }
    }
}