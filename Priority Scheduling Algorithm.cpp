#include<bits/stdc++.h>
using namespace std;
int main(){
    int cpu_time[10],priority[10],tat[10],wt[10],process,i,j,temp[10],p_no[10];
    float atat=0,awt=0;
    cout<<"Enter Number of Process : ";
    cin>>process;
    cout<<"Enter CPU Time : ";
    for(i=0;i<process;i++){
        cin>>cpu_time[i];
    }
    cout<<endl;
    cout<<"Enter priority : ";
    for(i=0;i<process;i++){
        cin>>priority[i];
    }
    cout<<endl;
    for(i=0;i<process-1;i++){
        int me=i;
        for(j=i+1;j<process;j++){
            if(priority[me]>priority[j]){
                me=j;
            }
        }
        if(me!=0){
            swap(priority[me],priority[i]);
            swap(cpu_time[me],cpu_time[i]);
        }

    }
    temp[0]=0;
    for(i=0;i<process;i++){
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+cpu_time[j];

        }
        tat[i]=wt[i]+cpu_time[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        cout<<"Process : "<<i+1<<"\t Waiting Time : "<<wt[i]<<"\t\t"<<"Turnarround Time : "<<tat[i]<<endl;
    }

    awt=awt/process;
    atat=atat/process;
    cout<<"Avarage waiting Time = "<<awt<<endl;
    cout<<"Avarage turn around time = "<<atat<<endl;
    return 0;

}