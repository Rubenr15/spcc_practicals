#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char label[10],opcode[10],operand[10];
    int mdtc = 1,mntc = 1;
    FILE *copyfile,*input,*mdt,*mnt;

    input = fopen("input.txt","r");
    mdt = fopen("mdt.txt","w");
    mnt = fopen("mnt.txt","w");
    copyfile = fopen("Copyfile.txt","w");

    fscanf(input,"%s %s %s",label,opcode,operand);

    while(strcmp(opcode,"END") != 0){
        if(strcmp(opcode,"MACRO") == 0){
            fscanf(input,"%s %s %s",label,opcode,operand);
            fprintf(mnt,"%d %s %d\n",mntc,opcode,mdtc);
            mntc++;
            while(strcmp(opcode,"MEND") != 0){
                fprintf(mdt,"%d %s %s %s\n",mdtc,label,opcode,operand);
                mdtc++;
                fscanf(input,"%s %s %s",label,opcode,operand);
            }
            fprintf(mdt,"%d %s %s %s\n",mdtc,label,opcode,operand);
            mdtc++;
        }
        else{
            fprintf(copyfile,"%s %s %s\n",label,opcode,operand);
        }
        fscanf(input,"%s %s %s",label,opcode,operand); 
    }
    fprintf(copyfile,"%s %s %s\n",label,opcode,operand);

    fclose(input);
    fclose(mdt);
    fclose(mnt);
    fclose(copyfile);
    return 0;
}
