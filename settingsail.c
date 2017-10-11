// Mitchell Klingler
// COP 3223
// October 9th 2017
// Project 5
// SettingSail.c



#include <stdio.h>
#include <stdlib.h>

int main()
{
    float lower_temp = 0, upper_temp = 0, temp = 0.0, percent = 0, array[12];
    int i = 1, z = 0, in_bounds = 0, days_In_Month = 0, choice = 0, largest = 0, largest_month = 0;
    char file_Name[60];

    printf("Tell me about your crew's preferred temperature to sail:\n");

    printf("What is the lowest temperature they can sail in?\n");
    scanf("%f", &lower_temp);

    printf("What is the highest temperature they can sail in?\n");
    scanf("%f", &upper_temp);

    printf("What is the name of the weather data file?\n");
    scanf("%s", file_Name);

    FILE *ifp;
    ifp = fopen(file_Name, "r");

    if(ifp == NULL){
        printf("Not a Correct File Pathway.\n");
        exit (1);
    }
        for(i=1; i<13; i++){
                fscanf(ifp, "%d", &days_In_Month);

                    for(z = 0; z < (int)days_In_Month; z++) {
                        fscanf(ifp, "%f", &temp);

                        if(temp > lower_temp && temp < upper_temp){
                            in_bounds++;
                        }
                    }

                    percent = ((in_bounds)/((float)days_In_Month))*100;
                    array[i] = percent;

                    printf("Month %d = %2.1f\n", i, percent);

                    if(largest < array[i]){
                        largest = array[i];
                        largest_month = i;
                    }
                    in_bounds = 0;
                }

                choice = (largest/largest) * (largest_month);
                printf("You should leave for the Caribbean in month %d\n", choice);

    fclose(ifp);

    return 0;
}
