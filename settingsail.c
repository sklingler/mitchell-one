// Mitchell Klingler
// COP 3223
// October 9th 2017
// Project 5
// SettingSail.c

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float lower_temp = 0, upper_temp = 0, temp = 0.0, month_percent = 0, array[12];
    int i = 1, day = 0, in_bounds = 0, days_In_Month = 0, choice = 0, largest = 0, largest_month = 0;
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

    if(ifp == NULL) {
        printf("Not a Correct File Pathway.\n");
        exit (1);
    }
    for(i=1; i<13; i++) {
        fscanf(ifp, "%d", &days_In_Month);
        printf( "Month has %d temps\n", days_In_Month);

        for(day = 0; day < (int)days_In_Month; day++) {
            fscanf(ifp, "%f", &temp);
            printf("read temp: %f\n", temp);

            if(temp >= lower_temp && temp <= upper_temp) {
                in_bounds++;
            }
        }

        month_percent = 0.0;
        // just in case...
        if(days_In_Month > 0)
            month_percent = ((in_bounds)/((float)days_In_Month))*100.0;

        // I thought you werent supposed to keep an array?
        // You don't need it.
        array[i] = month_percent;

        printf("Month %d = %2.1f\n", i, month_percent);

        //if(largest < array[i]) {
        if(largest < month_percent) {
            // largest = array[i];
            largest = month_percent;
            largest_month = i;
        }
        in_bounds = 0;
    }

    // I do NOT understand this line.
    // largest/largest is always = 1 (unless largest is 0, in which case you abort)
    //choice = (largest/largest) * (largest_month);
    //printf("You should leave for the Caribbean in month %d\n", choice);
    printf("You should leave for the Caribbean in month %d\n", largest_month);

    fclose(ifp);

    return 0;
}
