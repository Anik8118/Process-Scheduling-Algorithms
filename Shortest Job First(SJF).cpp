#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t,p[10],bt[10],wt[10],tat[10],minimum;
    float awt=0,atat=0;
    cout<<"Enter the Number of Process : ";
    cin>>n;
    cout<<"Input the cpu time : ";
    for(int i=0;i<n;i++)
        cin>>bt[i];
    cout<<"Enter the Arrive Time : ";
    for(int i=0;i<n;i++)
        cin>>p[i];
    for(int i=0;i<n-1;i++){
        minimum=i;
        for(int j=i+1;j<n;j++){
            if(bt[minimum]>bt[j])
                minimum=j;
        }
        if(minimum!=i){
            swap(bt[minimum],bt[i]);
            swap(p[minimum],p[i]);
        }
    }

    for(int i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(int j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        cout<<"\tWaiting Time : "<<wt[i]<<"\t\t"<<"Turnaround Time : "<<tat[i]<<endl;
    }
    awt=awt/n;
    atat=atat/n;
    cout<<"Avarage waiting Time = "<<awt<<endl;
    cout<<"Avarage turn around time = "<<atat<<endl;
    return 0;
}