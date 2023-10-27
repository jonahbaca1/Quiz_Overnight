#include <stdio.h>
#include <time.h>
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
    //declare two loshus, one to make sure it can find loshus and the other to test and make sure it's correct
    int loshu[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
    //square that is not loshu gets commented out.
    //int loshu[3][3] = {{4,9,3}, {2,5,6}, {1,7,8}};
    //isLoshu used to track if the square is a loshu in the for loop
    //int isLoshu = 1;
    srand(time(NULL));
    int test = isLoshu(loshu);
    int random = 0;
    int counter = 0;
    while(random == 0)
    {
        int randLoshu[3][3] = {{rand() % 10, rand() % 10, rand() % 10},{rand() % 10, rand() % 10,rand() % 10},{rand() % 10,rand() % 10,rand() % 10}};
        //printf("%d", randLoshu[0][0]);
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
/*

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
*/