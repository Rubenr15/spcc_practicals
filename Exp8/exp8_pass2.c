#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char label[10],opcode[10],operand[10],mntc[10],macroname[10],mdtc[10],mdtmdtc[10],ignore[10],mdtlabel[10],mdtvalue[10];
    int flag = 0;
    
    FILE *input,*mnt_table,*mdt_table,*output;
    input = fopen("Copyfile.txt","r");  
    mnt_table = fopen("MNT.txt","r");
    mdt_table = fopen("MDT.txt","r");
    output = fopen("Expanded_Source.txt","w");
    
    fscanf(input,"%s %s %s",label,opcode,operand);
    
    while(strcmp(opcode,"END")!=0){
        if(strcmp(opcode,"START")==0 || strcmp(opcode,"USING")==0 || strcmp(opcode,"DC")==0 || strcmp(opcode,"DS")==0 ){
            fprintf(output,"%s %s %s\n",label,opcode,operand);
        }
        else{
            flag = 0;
            while(fscanf(mnt_table,"%s %s %s",mntc,macroname,mdtc) != EOF){
                if(strcmp(opcode,macroname)==0){
                    flag = 1;
                    break;
                }
            }
            if(flag==1){
                fscanf(mdt_table,"%s %s %s %s",mdtmdtc,ignore,mdtlabel,mdtvalue);
                while(strcmp(mdtc,mdtmdtc)!=0){
                    fscanf(mdt_table,"%s %s %s %s",mdtmdtc,ignore,mdtlabel,mdtvalue);
                }
                fscanf(mdt_table,"%s %s %s %s",mdtmdtc,ignore,mdtlabel,mdtvalue);
                while(strcmp(mdtlabel,"MEND")!=0){
                    fprintf(output,"%s %s %s\n",ignore,mdtlabel,mdtvalue);
                    fscanf(mdt_table,"%s %s %s %s",mdtmdtc,ignore,mdtlabel,mdtvalue);
                }
                rewind(mdt_table);
            }
            else{
                fprintf(output,"%s %s %s\n",label,opcode,operand);
            }
            rewind(mnt_table);
        }
        fscanf(input,"%s %s %s",label,opcode,operand);
    }
    
    fprintf(output,"%s %s %s\n",label,opcode,operand);
    
    fclose(input);
    fclose(mnt_table);
    fclose(mdt_table);
    fclose(output);
    
    
    return 0;
}
