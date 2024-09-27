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
void assign_to_array(char, char *array);
char substring_eval();

FILE *pfile;

//TODO make a function with a double pointer to parse 3, 4 and 5 letter words sequentially. At each step in the while loop
//this is evaluated along with the number characters (i.e. 1, 2, 3, etc), to know precedence in the row

int main()
{
    
    char digits[2] = {'x', 'x'};
    int sum_total = 0;  //the final answer
    char tchar, ctemp; //temp char while looking for numbers in text
    int num;    //int to store the number of each row
    char words[6];  //stores words for numbers (maximum 5 characters plus de \0)
    
    
    pfile = fopen("input2", "r+");
    
    if (pfile == 0) {
        
        printf("File could not be loaded.");
        
        return 1;
    }
    
    while (!feof(pfile)) {
        
        tchar = fgetc(pfile);
        
        if (tchar >= '0' && tchar <= '9') {
            
            assign_to_array(tchar, digits);
            
        } else {    //check if there is a word equal to a number
        //TODO NOT WORKING THE WORD ASSIGNMENT
        
            ctemp = substring_eval();
            
            if (ctemp != 'x' && ctemp != '\n') {
                
                assign_to_array(ctemp, digits);
                
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

char word_to_numchar(char *string) {
    
    if (strlen(string) < 3) {   //skip two or less letter words
        
        return 'x';
        
    }
    
    if (!strcmp(string, "one")) {
        
        return '1';
        
    } else if (!strcmp(string, "two")) {
        
        return '2';
        
    } else if (!strcmp(string, "three")) {
        
        return '3';
        
    } else if (!strcmp(string, "four")) {
        
        return '4';
        
    } else if (!strcmp(string, "five")) {
        
        return '5';
        
    } else if (!strcmp(string, "six")) {
        
        return '6';
        
    } else if (!strcmp(string, "seven")) {
        
        return '7';
        
    } else if (!strcmp(string, "eight")) {
        
        return '8';
        
    } else if (!strcmp(string, "nine")) {
        
        return '9';
        
    }
    
    return 'x';
}

/******************************************************************************/

void assign_to_array(char c, char *array) {
    
    if (array[0] == 'x') {
                
        array[0] = c;
                
    } else {
                
        array[1] = c;
                
    }
}

/******************************************************************************/

char substring_eval() {
    
    char eval_char, tchar;
    char word[6];
    int counter = 0;    //counts the number of words before an EOF or \n
    int i = 0;
    
    //Evaluate substring up to 5 characters long to see if the word corresponds to a number
    while (i < 5) {
                
        tchar = fgetc(pfile);
        counter++;
        if (tchar == EOF || tchar == '\n') {break;}
        
        word[i] = tchar;
        i++;
                
    }
            
    word[i] = '\0';
            
    if (tchar != EOF) {
                
        fseek(pfile, (counter * -1), SEEK_CUR); //Return the characters moved before EOF or \n
                
    }
    
    eval_char = word_to_numchar(word);
    
    return (eval_char);
}





