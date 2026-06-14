#include<iostream>
using namespace std;
string all_name[5]={};
int all_reg[5]={};
int main()
{
string name;
int reg=0;
int n=1;
cout<<"enter name to register";
cin>>name;
reg++;
for(int i=0 ; i<n ; i++){
all_name[i]=name;
all_reg[i]=reg;
}
// for(int i=0 ; i<n ; i++){
//     cout<<"candidate number"<<reg;
//     cout<<"\ncandidate name"<<name;
// }
string tempname;
int tempreg=0;
cout<<"LOGIN...........\n";
cin>>tempname;
cout<<"enter register candidate";
cin>>tempreg;
for(int i=0 ; i<=n ; i++){
    if(all_name[i]==name && all_reg[i]==reg)
    cout << "login successful"<<endl;
}
}