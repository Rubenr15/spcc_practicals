#include<bits/stdc++.h>
using namespace std;

class code{
public:
    vector<string> result;
    vector<string> arg1;
    vector<string> arg2;
    vector<string> op1;
    vector<string> reg;

    void splitString(string input){
        stringstream ss(input);
        string word,type;
        int i = 0;
        while(ss >> word){
            if(i == 0){
                result.push_back(word);
            }
            else if(i == 2){
                arg1.push_back(word);
            }
            else if(i == 3){
                op1.push_back(word);
            }
            else if(i == 4){
                arg2.push_back(word);
            }
            i++;
        }
    }

    int findReg(string args){
        if(reg.empty()){
            return -1;

        }
        else{
            for(int i =0;i<reg.size();i++){
                if(args == reg[i]){
                    return i;
                }
            }
        }
        return -1;
    }

    int genReg(string args){
        reg.push_back(args);
        int i = 0;
        while(i < reg.size()){
            if(reg[i] == args){
                break;
            }
            i++;
        }
        return i;
    }
};

int main(){

    vector<string> codes;
    unordered_map<string,string>instruction = { {"+","ADD"},{"-","SUB"},{"*","MUL"},{"/","DIV"}};
    int n;
    cout<<"Enter the no of lines in code:";
    cin>>n;
    code ob;
    string input;
    ifstream myfile("code.txt");
    cout<<"Code:\n";
    if(myfile.is_open()){
        while(getline(myfile,input)){
            cout<<input<<"\n";
            ob.splitString(input);
        }
        myfile.close();
    }
    else{
        cout<<"unable to open file";
    }
    

    for(int i = 0;i<n;i++){
        if(i >= ob.arg2.size()){
            int temp1 = ob.findReg(ob.arg1[i]);

            if(temp1 != -1){
                codes.push_back("MOV R" + to_string(temp1) + "," + ob.result[i]);
            }
            else{
                codes.push_back("MOV " + ob.arg1[i] + "," + ob.result[i]);
            }
        }
        int tempreg;
        // cout<<ob.arg1[i]<<" "<<ob.arg2[i]<<endl;
        int temp1 = ob.findReg(ob.arg1[i]);
        int temp2 = ob.findReg(ob.arg2[i]);
        // cout<<temp1<<" "<<temp2<<"\n";

        if(temp1 == -1 and temp2 == -1){
            tempreg = ob.genReg(ob.arg1[i]);
            codes.push_back("MOV " + ob.arg1[i] + ",R" + to_string(tempreg));
            codes.push_back(instruction[ob.op1[i]] + " " + ob.arg2[i] + ",R" + to_string(tempreg));
            ob.reg[tempreg] = ob.result[i];
        }
        else if(temp1 != -1 and temp2 != -1){
            codes.push_back(instruction[ob.op1[i]] + " " + "R" + to_string(temp1) + ",R" + to_string(temp2));
            ob.reg[temp2] = ob.result[i];
        }
    }

    cout<<"Target code generated is:\n";

    for(auto i : codes){
        cout<<i<<"\n";
    }


    
    return 0;
}