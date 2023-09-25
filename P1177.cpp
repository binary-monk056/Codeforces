#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<long long>powerof(13,1);
    for(int i=1;i<13;i++) powerof[i]=10*powerof[i-1]; //power of 12 on one based index
    
        long long index;
        cin>>index;
        long long sofar=0;
        long long beforeblock=0;
        int numdigits;
        for(int i=1;i<=12;i++){  //calculate number of digits in the required number
            sofar+=(powerof[i]-powerof[i-1])*i;
            if(index<=sofar){
                numdigits=i;
                break;
            }
            beforeblock+=(powerof[i]-powerof[i-1])*i;
        }
        //perfrom binary search to find digit at the position index
        long long s=powerof[numdigits-1];
        long long e=powerof[numdigits]-1;
        long long best=0;  //our answer
        long long stbest=0; //starting position of our answer
        while(e>=s){
            long long actual=s+(e-s)/2; //the mid value
            long long startactual=beforeblock+1+(actual-powerof[numdigits-1])*numdigits;//starting position of the mid value
            if(startactual<=index){ //if we are at lesser postion than index,we assign our answer and its starting position and try to appraoch toward the index
                if(actual>best){
                    best=actual;
                    stbest=startactual;
                }
                s=actual+1;
            }
            else e=actual-1;
            
        }
        string number=to_string(best);
        cout<<number[index-stbest]<<endl;
    
    return 0;
}
