/******************************************************************************

Determine which games would have been possible if the bag had been loaded with
only 12 red cubes, 13 green cubes, and 14 blue cubes. What is the sum of the
IDs of those games?

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define RED_CUBES 12
#define GREEN_CUBES 13
#define BLUE_CUBES 14
#define FALSE 0
#define TRUE 1

FILE *pfile;
int sum; //the sum of the IDs of possible games
int next_free; //the next free position in substring
char substring [15]; //stores parts of the text to analyze for data

void parse_text();
int sum_if_valid(int isValid, int id);
int evaluate_extraction();
int extract_gameid();
void skip_to_eol();
char add_char(char c);
void clear_substring();



int main()
{
    sum = 0;
    next_free = 0;
    
    pfile = fopen("input", "r+");
    
    if (pfile == 0) {
        
        printf("File could not be loaded");
        
        return 1;
        
    }
    
    parse_text();

    return 0;
}

/**
 * Parses and stores the text until it finds a punctuation symbol. Then, it redirects to
 * other functions to store an id or check if the dice extraction is valid
 **/
 
void parse_text() {
    
    char c; //auxiliary character
    int id;    //temportal number to store the game's IDs
    int isValid = TRUE; //bool storing if the line is valid. Default to TRUE
    
    while (!feof(pfile)) {
        
        c = fgetc(pfile);
        
        if (c == '\n') {
            
            sum_if_valid(isValid, id);
            //reset the variables
            clear_substring();
            id = 0;
            isValid = TRUE;
            
        } else if (c == ',' || c == ';') {
            
            isValid = evaluate_extraction();
            
            clear_substring();
            
            if (isValid == FALSE) skip_to_eol();
            
        } else if (c == ':') {
            
            id = extract_gameid();
            
            if (id == 0) {
                
                break;
                
            }
            
            clear_substring();
            
        } else {
            
            add_char(c);
            
        }
        
    }
    
}

/**
 * Sums the value of the id to the total if the parameter given is TRUE.
 * Returns the value added.
 **/

int sum_if_valid(int validates, int id) {
    
    if (validates) sum += id;
    
    return id;
    
}

/**
 * Returns TRUE if extraction is valid and FALSE otherwise. Also stores id number when found
 **/

int evaluate_extraction() {
    
    //TODO functionality of extraction verification
    
    return FALSE;
    
}

/**
 * Returns the game id if present in the substring array
 **/
 
 int extract_gameid() {
    
    char c;
    char number[4] = {'\0'};
    int counter = 0;
     
    for (int i = 0; i < strlen(substring); i++) {
        
        c = substring[i];
        
        if (isdigit(c)) {
            
            number[counter] = c;
            number[counter + 1] = '\0';
            counter++;
            
        }
        
    }
    
    return (atoi(number));
     
 }

/**
 * Moves the file pointer to the start of the next line
 **/
 
void skip_to_eol() {
    
    char c;
    
    while (!feof(pfile)) {
        
        c = fgetc(pfile);
        
        if (c == '\n') { //stop when found a new line
            
            fseek(pfile, -1, SEEK_CUR);
            break;
            
        } 
    }
}


/**
 * Adds a char to the substring. Returns the char added
 **/

char add_char(char c) {
    
    if (next_free < 14) { //limit to array size
        
        substring[next_free] = c;
        substring[next_free + 1] = '\0';
        next_free++;
        
    }
    
    return c;
    
}

void clear_substring() {
    
    substring[0] = '\0';
    next_free = 0;
    
}




