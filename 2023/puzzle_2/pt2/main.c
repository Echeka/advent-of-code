/******************************************************************************
Day 2 part 2. Power of games.

Problem: find out the minimum cubes of each color needed to make each game possible.
After that, multiply those cubes to get the 'power'.
Lastly, sum the powers of all the games.

Answer rule: must interact directly with the Linux system to get the input
*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define DELIMITERS ",; "

FILE *is;   

int parse_line(char *line);

int main() {
    
    char buf[256];
    int power = 0; //each of the lines powers
    int sum = 0; //sum of the powers

    //read from the file generated in part 1 through shell command
    is = popen("cat ../input", "r");
    
    if (!is) return 1;

    while (fgets(buf, sizeof(buf), is) != NULL) {
        
        power = parse_line(buf);
        
    }

    pclose(is);

    return 0;
    
}

/**
 * Parses the line, invoking other functions to return the power of the cubes
 **/
 
int parse_line(char *line) {
    
    char *token = strtok(line, DELIMITERS);
    int min_green = 0, min_red = 0, min_blue = 0;
    int power = 0;
    
    if (token == NULL) {
        
        printf("Parsing error!");
        return 0;
        
    }
    
    while ((token = strtok(NULL, DELIMITERS)) != NULL) {
        
        
        
    }
    
    //TODO while loop that analyzes if it is a number (then stores the number) (make function)
    //or if it is a word, stores the first character (make function to check)
    //if number and word are valid, they change values of minimum dice
    //add pointers to ints for cubes to interact with them in parsing function
    
    return (power);
    
}

/**
 * Analyzes a char token??
 **/
 



