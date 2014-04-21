#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    FILE *fpIn;
    char c [6];

    int itemCounter = 0;
    int nameSkipper = 0;
    int xCounter = 0;
    int yCounter = 0;

    if ((fpIn=fopen("CoordsFile.txt","r"))==NULL){
       printf("Error! opening file\n");
       exit(1);         /* Program exits if file pointer returns NULL. */
    }

    printf("Data from file:\n");
    while (fscanf(fpIn,"%s\n",c) != EOF)

    //It is presumed that the input file is well-behaving

    {
        itemCounter++;

        if (nameSkipper == 1)
        {
            xCounter++;
        }

        if (nameSkipper == 2)
        {
            yCounter++;
        }

        nameSkipper++;

        if (nameSkipper == 3)
        {
            nameSkipper = 0;
        }

    }

    // the x and ycounters now contain the amount of items

    double xCoord[xCounter];
    double yCoord[yCounter];

    double calcTotal;
    double x;
    double y;

    int rewindedIndex =0;
    int pythIndex =0;

    rewind(fpIn);
    printf("Data from file:\n");
    while (fscanf(fpIn,"%s\n",c) != EOF)

    //It is presumed that the input file is well-behaving

    {

        //Place coordinate points in their respective variables

        if (nameSkipper == 1)
        {
            xCoord[rewindedIndex] =atof(c);


        }

        if (nameSkipper == 2)
        {
            yCoord[rewindedIndex] =atof(c);
        }

        nameSkipper++;

        if (nameSkipper == 3)
        {
            nameSkipper = 0;
            rewindedIndex++;
        }

    }

    while (pythIndex<xCounter-1)
        {
            x = xCoord[pythIndex+1]-xCoord[pythIndex];

            y = yCoord[pythIndex+1]-yCoord[pythIndex];

            calcTotal += sqrt(pow(x,2)+pow(y,2));

            pythIndex++;
        }

    printf("Total distance:\n");
    printf("%lf\n",calcTotal);


    fclose(fpIn);

    return 0;
}
