/******************************************************************************

Day 3. Engine parts
Given an input file, sum the numbers (adjacent digits always correspond to a single number)
that are beside a symbol other than dot (.). This can be in any direction (up, down, sides and diagonal)

Approach. Store in memory 3 lines at a time. Check for chars that are not digits or dot (.)
that are besides each number

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFF_SIZE 256
#define TRUE 1
#define FALSE 0

FILE *fis;
char buf_up[BUFF_SIZE];
char buf_mid[BUFF_SIZE];
char buf_down[BUFF_SIZE];
int buf_length = 0;
int total; //final total sum

void read_line();
int check_surrounding(int pos);
void sum_if_valid(int isValid, int num);

int main() {
    
    total = 0;
    fis = fopen("input", "r+");
    
    if (fis == NULL) return 1;
    
    buf_down[0] = buf_mid[0] = buf_up[0] = '\0';
    
    fgets(buf_mid, BUFF_SIZE, fis);
    fgets(buf_down, BUFF_SIZE, fis);
    buf_length = strlen(buf_mid);
    
    while (!feof(fis)) {
        
        read_line();
        strcpy(buf_up, buf_mid);
        strcpy(buf_mid, buf_down);
        if (fgets(buf_down, BUFF_SIZE, fis) == NULL) { //includes \n in the array length
            
            buf_down[0]= '\0';
            
        }
    }
    
    read_line(); //read last line with buf_mid and buf_up
    printf("Total: %d\n", total);

    fclose(fis);

    return 0;
    
}


/**
 * Reads the line, looking for numbers. If found, checks with buffers if it is a part number
 **/
 
void read_line() {
    
    char c = '\0';
    char number[5] = {'\0'};
    int integer = 0;
    int isValid = FALSE;
    int current_free = 0;
    
    for (int i = 0; i < buf_length; i++) {
        
        c = buf_mid[i];
        
        if (isdigit(c)) {
            
            number[current_free] = c;
            number[current_free + 1] = '\0';
            current_free++;
            //if not valid, check once more with new position
            if (isValid == FALSE) isValid = check_surrounding(i);
            
        } else if (number[0] != '\0') { //after every number, sum if is valid
            
            integer = atoi(number);
            sum_if_valid(isValid, integer);
            number[0] = '\0';
            current_free = 0;
            isValid = FALSE;
            
        }
        
    }
}


/**
 * Checks for surrounding characters in the passed possition of the mid buffer.
 * If it is surrouned by at least one symbol other than dot (.), returns true. False otherwise
 **/

int check_surrounding(int pos) {
    
    if (pos > 0) {
        
        if (buf_mid[pos - 1] != '.' && !isdigit(buf_mid[pos - 1]) && buf_mid[pos - 1] != '\n')
            return TRUE;
        //check pos - 1 and pos in other lines
        if (buf_up[0] != '\0') {
            
            if (buf_up[pos - 1] != '.' && !isdigit(buf_up[pos - 1]) && buf_up[pos - 1] != '\n')
                return TRUE;
            if (buf_up[pos] != '.' && !isdigit(buf_up[pos]) && buf_up[pos] != '\n')
                return TRUE;
            
        }
        
        if (buf_down[0] != '\0') {
            
            if (buf_down[pos - 1] != '.' && !isdigit(buf_down[pos - 1]) && buf_down[pos - 1] != '\n')
                return TRUE;
            if (buf_down[pos] != '.' && !isdigit(buf_down[pos]) && buf_down[pos] != '\n')
                return TRUE;
            
        }
    }
            
    if (pos < (buf_length - 1)) {
        
        if (buf_mid[pos + 1] != '.' && !isdigit(buf_mid[pos + 1]) && buf_mid[pos + 1] != '\n')
            return TRUE;
        //check pos + 1 in other lines
        if (buf_up[0] != '\0')
            if (buf_up[pos + 1] != '.' && !isdigit(buf_up[pos + 1]) && buf_up[pos + 1] != '\n')
                return TRUE;

        if (buf_down[0] != '\0')
            if (buf_down[pos + 1] != '.' && !isdigit(buf_down[pos + 1]) && buf_down[pos + 1] != '\n')
                return TRUE;
        
    }
    
    return FALSE;
    
}


/**
 * Sums the value of the engine part if valid
 **/
 
void sum_if_valid(int isValid, int num) {
    
    if (isValid) total += num;
    
}


