#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"1.Assignment 2.Arithmetic 3.Relation\n";
    cout<<"Enter your choice:";
    int ch;
    cin>>ch;

    string s;
    cout<<"Enter the expression:";
    cin>>s;

    string temp;
    int pos;
    char op;

    switch (ch){
        case 1:
            pos = s.find('=');
            temp = s.substr(pos+1);
            cout<<"temp="<<temp<<"\n";
            cout<<s.substr(0,pos)<<"=temp\n";
            break;
        case 2:
            cout<<"Enter the operator:";
            cin>>op;
            pos = s.find(op);
            temp = s.substr(0,pos);
            cout<<"temp="<<temp<<"\n";
            cout<<"temp1="<<"temp"<<op<<s.substr(pos+1)<<"\n";
            break;
        case 3:
            int adr = 100;
            cout<<adr<<" if "<<s<<" goto "<<adr+3<<"\n";
            adr++;
            cout<<adr<<" T=0\n";
            adr++;
            cout<<adr<<" goto "<<adr+2<<"\n";
            adr++;
            cout<<adr<<" T=1\n";
            adr++;
            cout<<adr<<" next\n";
            break;
    }


    return 0;
}