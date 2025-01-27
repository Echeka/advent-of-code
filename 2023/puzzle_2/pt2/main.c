/******************************************************************************
Day 2 part 2. Power of games.

Problem: find out the minimum cubes of each color needed to make each game possible.
After that, multiply those cubes to get the 'power'.
Lastly, sum the powers of all the games.

Answer rule: must interact directly with the Linux system to get the input
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define DELIMITERS ",; "

FILE *is;   
int min_green = 0, min_red = 0, min_blue = 0;

int parse_line(char *line);
int check_number(const char *token);
char check_word(const char *token);
void update_min_values(char c, int qty);
int get_power(int a, int b, int c);

int main() {
    
    char buf[512];
    int power = 0; //each of the lines powers
    int sum = 0; //sum of the powers
    int line = 1;

    //read from the file generated in part 1 through shell command
    is = popen("cat ../input", "r");
    
    if (!is) return 1;

    while (fgets(buf, sizeof(buf), is) != NULL) { //stops reading after newline (included)
        
        power = parse_line(buf);
        
        if (power != 0) sum += power;
        
    }
    
    printf("Sum: %d\n", sum);

    pclose(is);

    return 0;
    
}

/**
 * Parses the line, invoking other functions to return the power of the cubes
 **/
 
int parse_line(char *line) {
    
    char *token = strtok(line, DELIMITERS); //skip first token, as it does not have relevant data
    int num = 0; //aux variable to store numbers until a color is parsed
    char c = '\0'; //aux variable to store de char defining the color of the cube
    int power = 0;
    
    if (token == NULL) {
        
        printf("!! Parsing error\n");
        return 0;
        
    }
    
    while ((token = strtok(NULL, DELIMITERS)) != NULL) {
        
        if (isdigit(token[0])) {
            
            num = check_number(token);
            
        } else if (isalpha(token[0])) {
            
            c = check_word(token);
            update_min_values(c, num);
            //if the token contains \n, get the power. The 'Game' substring is discarded
            if (strchr(token, '\n') != NULL) {
                
                power = get_power(min_green, min_blue, min_red);
                min_green = min_red = min_blue = 0;
                break;
                
            }
            
            c = 'x';
            num = 0;
            
        }
        
    }
    
    return (power);
    
}

/**
 * Analyzes a token passed for numeric values
 * Returns the integer parsed
 **/
 
int check_number(const char *token) {
    
    int num = atoi(token);
    
    if (num == 0) printf("!! Number parsing error\n");
    
    return (num);
    
}


/**
 * Analyzes a token passed for character values and checks for newline character
 * Returns the char representing the color of the cube
 **/
 
char check_word(const char *token) {
    
    if (token[0] != 'b' && token[0] != 'r' && token[0] != 'g') {
        
        printf("!! String parsing error\n: %c", token[0]);
        return ('x');
        
    }
    
    return (token[0]);
    
}



/**
 * Analyzes a token passed for string values and 
 **/
 
void update_min_values(char c, int qty) {
    
    if (c == 'g') {
        
        if (qty > min_green) min_green = qty;
        
    } else if (c == 'b') {
        
        if (qty > min_blue) min_blue = qty;
        
    } else if (c == 'r') {
        
        if (qty > min_red) min_red = qty;
        
    } else {
        
        printf("!! Values could not be updated\n");
        
    }
    
}


/**
 * Returns the power of three numbers
 **/
 
int get_power(int a, int b, int c) {
    
    return (a*b*c);
    
}
