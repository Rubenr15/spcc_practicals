#include <bits/stdc++.h>
using namespace std;

class symbol {
public:
    unordered_map<char,int> hashmap;
    int address=1000;
   
    void createTable(string temp){
        for(int i=0;i<temp.length();i++){
            address += 1;
            hashmap[temp[i]] = address;
        }
        cout<<"Table created"<<"\n";
    }
   
    void viewTable() {
        cout<<"Symbol Table"<<"\n";
        for(auto i : hashmap){
            string type = isalpha(i.first) ? "identifier" : "operator";
            cout<<"Symbol:"<<i.first<<"  Address:"<<i.second<<" Type:"<<type<<"\n";
        }
    }
   
    void removeSymbol(char sym){
        if(hashmap.find(sym) != hashmap.end()){
            hashmap.erase(sym);
            cout<<"Symbol removed"<<"\n";
        }
        else{
            cout<<"Symbol does not exist"<<"\n";
        }
    }
   
    void enterSymbol(char sym){
        if(hashmap.find(sym) != hashmap.end()){
            cout<<"Symbol already exist"<<"\n";
        }
        else{
            address += 1;
            hashmap[sym] = address;
            cout<<"Symbol inserted"<<"\n";
        }
    }
   
    void searchSymbol(char sym){
        if(hashmap.find(sym) != hashmap.end()){
            cout<<"Symbol "<<sym<<" exists at address:"<<hashmap[sym]<<"\n";
        }
        else{
            cout<<"Symbol does not exists"<<"\n";
        }
    }
   
};

int main() {

    bool flag=true;
    symbol ob;
    char sym;
    string temp;
    int n;
    while(flag){
        cout<<"\n1. Create table 2. Search symbol 3. Enter symbol 4. Remove symbol 5. View table 6. Exit"<<"\n";
        cout<<"Enter your choice:";
        cin>>n;
       
        switch(n){
            case 1:
            cout<<"Enter the expression:";
            cin>>temp;
            ob.createTable(temp);
            break;
           
            case 2:
            cout<<"Enter the symbol you want to search:";
            cin>>sym;
            ob.searchSymbol(sym);
            break;
           
            case 3:
            cout<<"Enter the symbol you want to add:";
            cin>>sym;
            ob.enterSymbol(sym);
            break;
           
            case 4:
            cout<<"Enter the symbol you want to remove:";
            cin>>sym;
            ob.removeSymbol(sym);
            break;
           
            case 5:
            ob.viewTable();
            break;
           
            case 6:
            flag = false;
            break;
        }
       
    }
   
    cout<<"program exited";

    return 0;
}