#include <stdio.h>
#include <string.h>

int main(){
    char label[10],opcode[10],operand[10],mnemonic[10],location_cnt[10],sym[10],symlabel[10],mlabel[10];
    FILE *mot,*input,*st,*output,*base;
    mot = fopen("MOT.txt","r");
    input = fopen("out.txt","r");
    st = fopen("st.txt","r");
    base = fopen("base.txt","w");
    output = fopen("out_2.txt","w");

    fscanf(input,"%s %s %s",label,opcode,operand);
    fscanf(input,"%s %s %s %s",location_cnt,label,opcode,operand);

    fprintf(base,"Y %c%c 00 00 00",operand[2],operand[3]);

    fscanf(input,"%s %s %s %s",location_cnt,label,opcode,operand);

    while(strcmp(opcode,"END") != 0){
        if(strcmp(opcode,"DC") == 0){
            fprintf(output,"%s %c\n",location_cnt,operand[2]);
        }
        else if(strcmp(opcode,"DS") == 0){
            fprintf(output,"%s _\n",location_cnt);
        }
        else{
            fscanf(mot,"%s %s",mnemonic,mlabel);
            while(strcmp(mnemonic,"END") != 0){
                if(strcmp(mnemonic,opcode) == 0){
                    char temp[10]="";
                    int j =0;
                    int flag = 0;
                    for(int i = 0;i<strlen(operand);i++){
                        if(flag == 1){
                            temp[j] = operand[i];
                            j++;
                        }
                        if(operand[i] == ','){
                            flag = 1;
                        }
                    }
                    while(fscanf(st,"%s %s",sym,symlabel) != EOF){
                        if(strcmp(temp,sym) == 0){
                            fprintf(output,"%s %c%c%s\n",mlabel,operand[0],operand[1],symlabel);
                        }
                    }
                    rewind(st);
                    break;
                }
                fscanf(mot,"%s %s",mnemonic,mlabel);  
            }
            rewind(mot);
        }
        fscanf(input,"%s %s %s %s",location_cnt,label,opcode,operand);

    }

    return 0;
}