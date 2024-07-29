#include<bits/stdc++.h>
using namespace std;
int main(){
    int process;
    cin>>process;
    int bursTime[process],arrivalTime[process];
    float Avg1=0,Avg2=0;
    for(int i=0;i<process;i++){
        cin>>bursTime[i];
    }
    for(int i=0;i<process;i++){
        cin>>arrivalTime[i];
    }

    for(int i=0;i<process-1;i++){
            for(int j=0;j<process-i-1;j++){
                if(arrivalTime[j]>arrivalTime[j+1]){
                    int temp1=arrivalTime[j];
                    int temp2=bursTime[j];
                    arrivalTime[j]=arrivalTime[j+1];
                    bursTime[j]=bursTime[j+1];
                    arrivalTime[j+1]=temp1;
                    bursTime[j+1]=temp2;
                }
            }
    }

    int waitingTime[process],TurArroundTime[process];
    waitingTime[0]=0;
    for(int i=1;i<process;i++){
        waitingTime[i]=bursTime[i-1]+waitingTime[i-1]-arrivalTime[i]+arrivalTime[i-1];


    }
    for(int i=0;i<process;i++){

        cout<<"Waiting Time : "<<waitingTime[i]<<endl;
        Avg1+=waitingTime[i];


    }

    for(int i=0;i<process;i++){

        TurArroundTime[i]=waitingTime[i]+bursTime[i];
        Avg2+=TurArroundTime[i];


    }
        for(int i=0;i<process;i++){

        cout<<"Turn Arround Time : "<<TurArroundTime[i]<<endl;

    }
    cout<<"Average Waiting Time : "<<Avg1/3<<endl;
    cout<<"Turn Arround Time : "<<Avg1/3<<endl;




}
