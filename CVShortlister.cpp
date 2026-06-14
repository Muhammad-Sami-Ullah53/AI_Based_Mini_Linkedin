#include<iostream>
using namespace std;

string all_name[5]={};
int all_reg[5]={};


int main(){
string name;
int reg=0;
int n=1;
cout<<"Enter Candidate Name to Register: ";
cin>>name;  
reg++;
for (int i=0; i<n; i++){
    all_name[i]=name;
    all_reg[i]=reg;
}
for(int i=0; i<n; i++){
    cout<<"Candidate Number: "<<reg;
    cout<<"\nCandidate Name: "<<name;
}

}