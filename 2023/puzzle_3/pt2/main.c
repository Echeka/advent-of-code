/******************************************************************************

Day 3. Engine parts - part 2
Given an input file, find the stars (*) that are adjacent to two numbers.
Then multiply those numbers to produce a gear ratio. Sum all the gear ratios.

Approach. Store in memory 3 lines at a time. Check for chars that are stars (*) and
check their sorroundings for digits.

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
int get_gear_ratio(int pos);
void get_numbers(char *buffer, int *num1, int *num2, int pos);
void add_char(char *arr, char c);

int main() {
    
    total = 0;
    fis = popen("cat ../input", "r");
    
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

    pclose(fis);

    return 0;
    
}


/**
 * Reads the line, looking for stars. Then checks sorroundings and sums results,
 * if valid
 **/
 
void read_line() {
    
    char c = '\0';
    int num = 0;
    
    for (int i = 0; i < buf_length; i++) {
        
        c = buf_mid[i];
        
        if (c == '*') {
            
            num = check_surrounding(i);
            if (num > 0) total += num;
            
        }
    }
}


/**
 * Returns the gear ratio of the star (0 if no gear ratio could be calculated)
 **/

int check_surrounding(int pos) {
    
    int adj_counter = 0; //how many numbers are surrounding
    int gear_ratio = 0;
    
    if (pos > 0) {
        
        if (isdigit(buf_mid[pos - 1]))
            adj_counter++;
        //check pos - 1 and pos in other lines
        if (buf_up[0] != '\0') {
            
            if (isdigit(buf_up[pos - 1])) {
                
                adj_counter++;
                
            } else if (isdigit(buf_up[pos])) {
                
                adj_counter++;
                
            }
        }
        
        if (buf_down[0] != '\0') {
            
            if (isdigit(buf_down[pos - 1])) {
                
                adj_counter++;
                
            } else if (isdigit(buf_down[pos])) {
                
                adj_counter++;
                
            }
        }
    }
            
    if (pos < (buf_length - 2)) {
        
        if (isdigit(buf_mid[pos + 1]) && !isdigit(buf_mid[pos]))
            adj_counter++;
        //check pos + 1 in other lines
        if (buf_up[0] != '\0')
            if (isdigit(buf_up[pos + 1]) && !isdigit(buf_up[pos]))
                adj_counter++;
        
        if (buf_down[0] != '\0')
            if (isdigit(buf_down[pos + 1]) && !isdigit(buf_down[pos]))
                adj_counter++;
                
    }
    
    if (adj_counter < 3)
        gear_ratio = get_gear_ratio(pos);
    
    return (gear_ratio);
    
}


/**
 * Returns the gear ratio of numbers with at least one digit touching the
 * position given as parameter (0 if no result)
 **/
 
int get_gear_ratio(int pos) {
    
    int gear_ratio = 0, n1 = 0, n2 = 0;
    
    get_numbers(buf_up, &n1, &n2, pos);
    get_numbers(buf_mid, &n1, &n2, pos);
    get_numbers(buf_down, &n1, &n2, pos);
    
    if (n1 > 0 && n2 > 0)
        gear_ratio = n1 * n2;
    
    return (gear_ratio);
    
}

/**
 * Stores the last two numbers of the row to the given int pointers.
 * Intercalates storing numbers to keep the 
 **/
 
void get_numbers(char *buf, int *num1, int *num2, int pos) {
    
    char number[5] = {'\0'};
    char c = '\0';
    int i = pos - 3;
    int turn = FALSE; //FALSE to store in number1, TRUE to store in num2
    
    for (i; i <= pos + 1; i++) {
        
        c = buf[i];
        
        if (isdigit(c)) {
            
            add_char(number, c);
            
        } else if (number[0] != '\0' && (i - 1) >= pos - 1 && (i - 1 - strlen(number)) <= pos + 1) {
            
            if (!turn) {
                
                *num1 = atoi(number);
                
            } else {
                
                *num2 = atoi(number);
                
            }
            
            number[0] = '\0';
            if (turn) {
                
                turn = FALSE;
                
            } else {
                
                turn = TRUE;
                
            }
            
        } else if (c == '\n') {
            
            break;
            
        } else {
            
            number[0] = '\0';
            
        }
    }
    
    c = buf[i];
    //check for remainder digits if last position was a digit
    while (isdigit(c)) {
        
        add_char(number, c);
        c = buf[++i];
        
    }
    
    if (number[0] != '\0' && (i - 1) >= pos - 1 && (i - 1 - strlen(number)) <= pos + 1) {
            
        if (!turn) {
            
            *num1 = atoi(number);
            
        } else {
            
            *num2 = atoi(number);
            
        }
    }
}


/**
 * Adds a char to an array
 **/

void add_char(char *arr, char c) {
    
    char *ptr;
    ptr = strchr(arr, '\0');
    
    if (ptr != NULL) {
        
        *(ptr) = c;
        *(ptr + 1) = '\0';
        
    }
}

















