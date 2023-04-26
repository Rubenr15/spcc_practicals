#include <stdio.h>
#include <string.h>

int main(){
    char label[10],opcode[10],operand[10],mnemonic[10],code[10];
    int location_cnt = 0,flag=0,length,start;

    FILE *input,*mot,*st,*output;

    input = fopen("input_1.txt","r");
    mot = fopen("MOT.txt","r");
    st = fopen("st.txt","w");
    output = fopen("out.txt","w");

    fscanf(input,"%s %s %s",label,opcode,operand);
    if(strcmp(opcode,"START") == 0){
        fprintf(output,"%s %s %s\n",label,opcode,operand);
        fscanf(input,"%s %s %s",label,opcode,operand);

    }
    else{
        location_cnt = 0;
    }

    while(strcmp(opcode,"END") != 0){
        fprintf(output,"%d ",location_cnt);
        if(strcmp(label,"**") != 0){
            fprintf(st,"%s %d\n",label,location_cnt);
        }

        fscanf(mot,"%s",mnemonic);

        if(strcmp(opcode,"DC") == 0){
            location_cnt += 4;
        }
        else if(strcmp(opcode,"DS") == 0){
            location_cnt += 4;
        }
        else if(strcmp(opcode,"USING") == 0){
            location_cnt += 0;
        }
        else{
            while(strcmp(mnemonic,"END") != 0){
                if(strcmp(mnemonic,opcode) == 0){
                    location_cnt += 4;
                }
                fscanf(mot,"%s",mnemonic);
            }
        }

        fprintf(output,"%s %s %s\n",label,opcode,operand);
        fscanf(input,"%s %s %s",label,opcode,operand);
        rewind(mot);
    }
    fprintf(output,"** %s %s %s\n",label,opcode,operand);
    fclose(input);
    fclose(mot);
    fclose(st);
    fclose(output);




    return 0;
}