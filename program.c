#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main(){
    FILE *fp;               //file pointer for input
    FILE *op;               //file pointer for output
    int i,x=0,num;
    char buff[255],word[2];
    fp = fopen("input.txt", "r");
    op = fopen("output.txt", "w");
    while(fscanf(fp,"%s",buff) != EOF){             //fscanf reads from input.txt till it finds a space or EOF, now it takes first word into the variable 'buff'
        for(i=0 ; buff[i] != '\0' ; i++){           //a for loop for iterating each charachter stored in the variable buff
            if(buff[i] != '-'){                     //if the charachter in buff is a number then we save it in the temporary variable
                word[x] = buff[i];                  //here 'x' variable is used for counting the number of characters saved in the temp variable "word"
                x = x + 1;
            }
            else if(buff[i] == '-'){                //if the charachter in buff is a '-' then we have a number ready to be converted into letter using ascii conversion
                num = atoi(word);                   //convert the number in char format to its exact number in int format
                if(num <= 13){                      //a check for ROT13 conversion
                    fprintf(op,"%c",num + 64 + 13);      //if the number is less than 13 then add 64 for converting it to an ASCII and then add 13 for ROT13 conversion.
                }                                       //and the command fprintf writed the number after converting the ASCII to character into the output file
                else{
                    fprintf(op,"%c",num + 64 - 13);     //if the number is less than 13 then add 64 for converting it to an ASCII add then subtract 13 for ROT13 conversion.
                }
                x = 0;                                  //as the work of the variable word is done for the current number it is flushed again to zero.
                word[0] = '\0';                         //similarly the variable 'word' is also flushed so that new numbers can be saved in the variable.
                word[1] = '\0';
            }
        }
        num = atoi(word);                               //if the characters in the variable 'buff' are finished then it means that the last letter stored in the variable 'word' has to be inserted
        if(num <= 13){                                  //that is taken care of here before doing the fscanf for next word.
            fprintf(op,"%c",num + 77);
        }
        else{
            fprintf(op,"%c",num + 51);
        }
        x = 0;
        word[0] = '\0';                                 // similarly flushing the variable 'word' same as earlier
        word[1] = '\0';
        fprintf(op," ");                                //printing a space after each word of our encrypted sentence, as after this a new word is going to be started.
    }
    fclose(fp);
    fclose(op);
    return 0;
}