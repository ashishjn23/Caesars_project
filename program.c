#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    FILE *op;
    int i,x=0,num;
    char buff[255],word[2];
    fp = fopen("input.txt", "r");
    op = fopen("output.txt", "w");
    while(fscanf(fp,"%s",buff) != EOF){
        for(i=0 ; buff[i] != '\0' ; i++){
            if(buff[i] != '-'){
                word[x] = buff[i];
                x = x + 1;
            }
            else if(buff[i] == '-'){
                //printf("%s_",word);
                num = atoi(word);
                if(num <= 13){
                    fprintf(op,"%c",num + 77);
                }
                else{
                    fprintf(op,"%c",num + 51);
                }
                x = 0;
                word[0] = '\0';
                word[1] = '\0';
            }
        }
        //printf("%s_",word);
        num = atoi(word);
        if(num <= 13){
            fprintf(op,"%c",num + 77);
        }
        else{
            fprintf(op,"%c",num + 51);
            
        }
        x = 0;
        word[0] = '\0';
        word[1] = '\0';
        fprintf(op," ");
    }
    
    fclose(fp);
    fclose(op);
    return 0;
}