#include <stdio.h>
#include <time.h>
//Function will test that all rows, columns and diagonals add up to the same and if one is not equal it returns 0, if it is a loshu it returns 1.
int isLoshu(int loshu[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        int lo1row = loshu[i][0] + loshu[i][1] + loshu[i][2];
        int lo1col = loshu[0][i] + loshu[1][i] + loshu[2][i];
        int lo1dia = loshu[0][0] + loshu[1][1] + loshu[2][2];
        int lo1dia2 = loshu[0][2] + loshu[1][1] + loshu[2][0];
        if((lo1row != lo1col) || (lo1row != lo1dia) || (lo1col != lo1dia) ||(lo1row != lo1dia2) || (lo1col != lo1dia2) || (lo1dia != lo1dia2))
        {
            return 0;
            break;
        }
    }
    return 1;
}

int main() {
    int random = 0;
    int counter = 0;
    //random is used to run the while loop for as long as it takes to generate a random loshu while counter tracks the amount of times the while loop been gone through.
    while(random == 0)
    {
        //This creates an array of numbers 1-9 and randomizes the order and then assigns it to a 2d array.
        int array[9];
        for(int i = 1; i < 10; i++)
        {
            array[i-1] = i;
        }
        for(int i = 0; i < 9; i++)
        {
            int temp = array[i];
            int randDex = rand() % 10;
            array[i] = array[randDex];
            array[randDex] = temp;
        }   
        int randLoshu[3][3];
        int track = 0;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                randLoshu[i][j] = array[track];
                track++;
            }
        } 
        //use the function to check if it's a loshu, if not add to counter and continue. Else it will display the count of squares, and the successful square
        //before breaking out of the while loop.
        if(isLoshu(randLoshu) == 0)
        {
            counter++;
        }
        else
        {
            random == 1;
            printf("Number of squares generated before success: %d", counter);
            for(int i = 0; i < 3; i++)
            {
                printf("\n[%d %d %d]", randLoshu[i][0], randLoshu[i][1], randLoshu[i][2]);
            }
            break;
        }
    }
    return 0;
}