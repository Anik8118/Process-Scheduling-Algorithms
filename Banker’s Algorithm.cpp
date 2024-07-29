#include <bits/stdc++.h>
using namespace std;
int main(){
    int process,resource;
    cout<<"Enter the number of processes: ";
    cin>>process;
    cout<<"Enter the number of resources: ";
    cin>>resource;

    int maximum[process][resource],allocated[process][resource],need[process][resource],total_value[resource],available[resource],work[resource],safeSequence[process];
    bool finish[process];

    for(int i=0;i<process;i++){
        cout<<"Process "<<i+1<<endl;
        for (int j=0;j<resource;j++){
            cout<<"Maximum value for resource "<<j+1<< ": ";
            cin>>maximum[i][j];
        }
        for (int j=0;j<resource;j++){
            cout<<"Allocated for resource "<<j+1<<": ";
            cin>>allocated[i][j];
        }
    }

    for (int i=0;i<process;i++){
        for (int j=0;j<resource;j++){
            need[i][j]=maximum[i][j]-allocated[i][j];
        }
    }

    // Input total available resources
    for (int i=0;i<resource;i++){
        cout<<"Enter total value of resource "<<i + 1<< ": ";
        cin>>total_value[i];
    }

    // Calculate the available resources
    for (int i=0;i<resource;i++){
        int sum=0;
        for (int j=0;j<process;j++){
            sum+=allocated[j][i];
        }
        available[i]=total_value[i]-sum;
    }

    // Initialize work array to available resources
    for (int i=0;i<resource;i++){
        work[i]=available[i];
    }

    // Initialize finish array to false
    for (int i=0;i<process;i++){
        finish[i]=false;
    }

    // Safety algorithm
    int count=0;
    while(count<process) {
        bool found=false;
        for(int i=0;i<process;i++){
            if(!finish[i]){
                bool canAllocate=true;
                for(int j=0;j<resource;j++){
                    if(need[i][j]>work[j]){
                        canAllocate=false;
                        break;
                    }
                }
                if (canAllocate){
                    for (int j=0;j<resource;j++){
                        work[j]+=allocated[i][j];
                    }
                    safeSequence[count++]=i;
                    finish[i]=true;
                    found=true;
                }
            }
        }
        if(!found){
            cout<<"The system is not currently in a safe state."<<endl;
            return 0;
        }
    }

    cout<<"The system is currently in a safe state and <";
    for(int i=0;i<process;i++){
        cout<<"P"<<safeSequence[i]+1;
        if(i!=process- 1){
            cout << "    ";
        }

    }
    cout<<"> is the safe sequence"<<endl;

    return 0;
}