/******************************************************************************

Day 3. Engine parts
Given an input file, sum the numbers (adjacent digits always correspond to a single number)
that are beside a symbol other than dot (.). This can be in any direction (up, down, sides and diagonal)

Approach. Store in memory 3 lines at a time. Check for chars that are not digits or dot (.)
that are besides each number

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 256
#define TRUE 1
#define FALSE 0

FILE *fis;
char buf_up[BUFF_SIZE];
char buf_mid[BUFF_SIZE];
char buf_down[BUFF_SIZE];
int total; //final total sum

void read_line();

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
    
    //TODO get tokens and look for digits
    //check sorrounding symbols (if each buf[0] != \0)
    //sum the total
    
}




