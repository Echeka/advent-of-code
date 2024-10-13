/******************************************************************************

Determine which games would have been possible if the bag had been loaded with
only 12 red cubes, 13 green cubes, and 14 blue cubes. What is the sum of the
IDs of those games?

*******************************************************************************/
#include <stdio.h>

#define RED_CUBES 12
#define GREEN_CUBES 13
#define BLUE_CUBES 14

FILE *pfile;



//TODO look for string splitting lib/method

int main()
{
    
    int sum = 0;    //the sum of the IDs of possible games
    int num;    //temportal number to store the possible game's IDs
    int qred = qgreen = qblue = 0;  //the quantities of dice extracted each time
    int nice_games[100]; //stores the numbers of the games that are possible
    
    
    
    pfile = fopen("input", "r+");
    
    if (pfile == 0) {
        
        printf("File could not be loaded");
        
        return 1;
    }
    
    while (!feof(pfile)) {
        
        printf("%d", BLUE_CUBES);
        
    }
    

    return 0;
}


//returns the number of the game if it is possible. Otherwise, returns 0 (false)
int is_possible() {
    
    
    
    return 0;
    
}

//Searches until it finds a new line escape secuence and
int* analyze_row(FILE* ptr) {
    
    
    
}
