/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int convert_to_num(char *string);
int word_to_num(char *string);
void assign_to_array(char, char *array);
char substring_eval(char *sub);

FILE *pfile;

//TODO make a function with a double pointer to parse 3, 4 and 5 letter words sequentially. At each step in the while loop
//this is evaluated along with the number characters (i.e. 1, 2, 3, etc), to know precedence in the row

int main()
{
    
    char digits[2] = {'x', 'x'};
    int sum_total = 0;  //the final answer
    char tchar; //temp char while looking for numbers in text
    int num;    //int to store the number of each row
    char words[6];  //stores words for numbers (maximum 5 characters plus de \0)
    
    pfile = fopen("input3", "r+");
    
    if (pfile == 0) {
        
        printf("File could not be loaded.");
        
        return 1;
    }
    
    while (!feof(pfile)) {
        
        tchar = fgetc(pfile);
        
        if (tchar >= '0' && tchar <= '9') {
            
            continue;
            
        } else {    //check if there is a word equal to a number
        
            words[0] = tchar;
            int i = 1;
        
            while (i < 5 && !isspace(tchar)) {
                
                tchar = fgetc(pfile);
                if (tchar == EOF) {break;}
                
                words[i] = tchar;
                i++;
                
            }
            
            words[i] = '\0';
            
            if (tchar != EOF) {
                
                fseek(pfile, -4, SEEK_CUR); //Return 4 characters to the next before storing
                
            }
            //TODO make that it analyzes the last 4 and 3 characters
            
            printf("%s", words);
            
        }
    }
}
