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
int total; //final total sum
const char DIGITS[] = "0123456789";

void read_line();
int check_surrounding(int pos);

int main() {
    
    total = 0;
    fis = fopen("input", "r+");
    
    if (fis == NULL) return 1;
    
    buf_down[0] = buf_mid[0] = buf_up[0] = '\0';
    
    fgets(buf_mid, BUFF_SIZE, fis);
    fgets(buf_down, BUFF_SIZE, fis);
    
    while (!feof(fis)) {
        
        read_line();
        strcpy(buf_up, buf_mid);
        strcpy(buf_mid, buf_down);
        if (fgets(buf_down, BUFF_SIZE, fis) == NULL) {
            
            buf_down[0]= '\0';
            
        }
    }
    
    read_line(); //read last line with buf_mid and buf_up

    fclose(fis);

    return 0;
    
}


/**
 * Reads the line, looking for numbers. If found, checks with buffers if it is a part number
 **/
 
void read_line() {
    
    char c = '\0';
    char number[5] = {'\0'};
    int isValid = FALSE;
    int current_free = 0;
    
    for (int i = 0; i < BUFF_SIZE; i++) {
        
        c = buf_mid[i];
        
        if (isdigit(c)) {
            
            number[current_free] = c;
            number[current_free + 1] = '\0';
            current_free++;
            //if not valid, check once more with new position
            if (!isValid) isValid = check_surrounding(i);
            
        } else if (number[0] != '\0') { //after every number, sum if is valid
            
            //sum_if_valid(isValid, number);
            number[0] = '\0';
            current_free = 0;
            if (isValid == TRUE) isValid = FALSE;
            
        }
        
    }
}


/**
 * Checks for surrounding characters in the passed possition of the mid buffer.
 * If it is surrouned by at least one symbol other than dot (.), returns true. False otherwise
 **/

int check_surrounding(int pos) {
    
    if (pos > 0)
        if (buf_mid[pos - 1] != '.' && !isdigit(buf_mid[pos - 1]))
            return TRUE;
            
    if (pos < (BUFF_SIZE - 1))
        if (buf_mid[pos + 1] != '.' && !isdigit(buf_mid[pos + 1]))
            return TRUE;
    
    //TODO check in other lines
    
    return FALSE;
    
}


