/******************************************************************************

Determine which games would have been possible if the bag had been loaded with
only 12 red cubes, 13 green cubes, and 14 blue cubes. What is the sum of the
IDs of those games?

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define RED_CUBES 12
#define GREEN_CUBES 13
#define BLUE_CUBES 14
#define FALSE 0
#define TRUE 1

FILE *pfile;
int sum; //the sum of the IDs of possible games

void parse_text();
int sum_if_valid(int isValid, int id);
int evaluate_substring(char *sub);
void skip_to_eol();


int main()
{
    sum = 0;
    
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
    char substring [15]; //stores parts of the text to analyze for data
    int qred = 0, qgreen = 0, qblue = 0; //the quantities of dice extracted each time
    int id;    //temportal number to store the game's IDs
    int isValid = TRUE; //bool storing if the line is valid. Default to TRUE
    
    int count = 0;
    
    while (!feof(pfile)) {
        
        c = fgetc(pfile);
        
        if (c == '\n') {
            
            sum_if_valid(isValid, id);
            //reset the variables
            substring[0] = '\0';
            id = 0;
            isValid = TRUE;
            
        }
        
        if (c == ',' || c == ';') {
            
            isValid = evaluate_substring(substring);
            
            if (isValid == FALSE) {
                
                skip_to_eol();
                printf("%d\n", ++count);
                
            }
            
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

int evaluate_substring(char *sub) {
    
    
    
    return FALSE;
    
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


