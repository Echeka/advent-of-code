/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int convert_to_num(char *string);
int word_to_num(char *string);

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
    
    pfile = fopen("input", "r+");
    
    if (pfile == 0) {
        
        printf("File could not be loaded.");
        
        return 1;
    }
    
    while (!feof(pfile)) {
        
        tchar = fgetc(pfile);
        
        if (tchar >= '0' && tchar <= '9') {
            
            if (digits[0] == 'x') {
                
                digits[0] = tchar;
                
            } else {
                
                digits[1] = tchar;
                
            }
        }
        
        if (tchar == '\n') {
            
            num = convert_to_num(digits);
            
            sum_total += num;
            
            //reset the number for new row
            printf("%c y %c \n", digits[0], digits[1]);
            digits[0] = 'x';
            digits[1] = 'x';
            
        }
    }
    
    
    printf("Total sum: %d.\n", sum_total);

    return 0;
}

/***********************************************************************/

int convert_to_num(char *string) {
    
    int number;
    
    if (string[0] == 'x' && string[1] == 'x') {
        
        return 0;
        
    }
    
    if (string[0] == 'x') {
        
        string[0] = string[1];
        
    }
    
    if (string [1] == 'x') {
        
        string[1] = string[0];
        
    }
    
    number = atoi(string);
    
    return (number);
}

/******************************************************************************/

int word_to_num(char *string) {
    
    if (strlen(string) < 3) {   //skip two or less letter words
        
        return (-1);
        
    }
    
    if (!strcmp(string, "one")) {
        
        return 1;
        
    } else if (strcmp(string, "two")) {
        
        return 2;
        
    }   //TODO the rest of the numbers
    
    return -1;
    
}





