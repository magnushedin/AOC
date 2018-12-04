#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_X 1024
#define MAX_Y 1024

int main(int argc, char* argv[]) {
    FILE *fp;
    char buff[30];
    char subbuff[30];
    int inputArray[MAX_X][MAX_Y] = { 0 };
    int nbrOfInput = 0;

    int x = 0, y = 0, dx = 0, dy = 0;
    char *startPoint, *endPoint, *number;
    int answer = 0;
    int bto = 0;

    char s[1014];

    fp = fopen("input", "r");

    for (int i=0; i<MAX_X; i++) {
        for (int j=0; j<MAX_Y; j++) {
            inputArray[i][j] = 0;
        }
    }

    // Read input from file and store in array
    while(fgets(buff, 30, fp) != NULL) {
        nbrOfInput++;
        

        // X value
        startPoint = strchr(buff, '@');
        endPoint = strchr(buff, ',');
        if (startPoint != NULL) {
            memcpy(subbuff, startPoint+2, endPoint-startPoint-2);
            subbuff[endPoint-startPoint-2] = '\0';
            x = atoi(subbuff);
            //printf("x = %d\n", x);
        }

        // Y value
        startPoint = strchr(buff, ',');
        endPoint = strchr(buff, ':');
        if (startPoint != NULL) {
            memcpy(subbuff, startPoint+1, endPoint-startPoint-1);
            subbuff[endPoint-startPoint-1] = '\0';
            y = atoi(subbuff);
            //printf("y = %d\n", y);
        }

        // dx value
        startPoint = strchr(buff, ':');
        endPoint = strchr(buff, 'x');
        if (startPoint != NULL) {
            memcpy(subbuff, startPoint+2, endPoint-startPoint-2);
            subbuff[endPoint-startPoint-2] = '\0';
            dx = atoi(subbuff);
            //printf("dx = %d\n", dx);
            //printf("dx = %s\n", subbuff);
        }

        // dy value
        startPoint = strchr(buff, 'x');
        if (startPoint != NULL) {
            dy = atoi(startPoint+1);
            //printf("dy = %d\n", dy);
            //printf("dy = %s\n", startPoint+1);
        }
        
        
        for (int i=x; i<=dx+x-1; i++) {
            for (int j=y; j<=dy+y-1; j++) {
                inputArray[i][j]++;
                //printf("%d", inputArray[i][j]);
            }
            //printf("\n");
        }
    }

    fclose(fp);

    fp = fopen("input", "r");

    // The answer
    nbrOfInput = 0;
    while (fgets(buff, 30, fp) != NULL)
    {
        nbrOfInput++;

        // X value
        startPoint = strchr(buff, '@');
        endPoint = strchr(buff, ',');
        if (startPoint != NULL)
        {
            memcpy(subbuff, startPoint + 2, endPoint - startPoint - 2);
            subbuff[endPoint - startPoint - 2] = '\0';
            x = atoi(subbuff);
            //printf("x = %d\n", x);
        }

        // Y value
        startPoint = strchr(buff, ',');
        endPoint = strchr(buff, ':');
        if (startPoint != NULL)
        {
            memcpy(subbuff, startPoint + 1, endPoint - startPoint - 1);
            subbuff[endPoint - startPoint - 1] = '\0';
            y = atoi(subbuff);
            //printf("y = %d\n", y);
        }

        // dx value
        startPoint = strchr(buff, ':');
        endPoint = strchr(buff, 'x');
        if (startPoint != NULL)
        {
            memcpy(subbuff, startPoint + 2, endPoint - startPoint - 2);
            subbuff[endPoint - startPoint - 2] = '\0';
            dx = atoi(subbuff);
            //printf("dx = %d\n", dx);
            //printf("dx = %s\n", subbuff);
        }

        // dy value
        startPoint = strchr(buff, 'x');
        if (startPoint != NULL)
        {
            dy = atoi(startPoint + 1);
            //printf("dy = %d\n", dy);
            //printf("dy = %s\n", startPoint+1);
        }

        for (int i = x; i <= dx + x - 1; i++)
        {
            for (int j = y; j <= dy + y - 1; j++)
            {
                if ((inputArray[i][j] != 1) && (!bto)) {
                    bto = 1;
                };
                //printf("%d", inputArray[i][j]);
            }
            //printf("\n");
        }

        if (!bto) {
            answer = nbrOfInput;
            printf("%s\n", buff);
        }
        bto = 0;
    }

    fclose(fp);

    printf("The answer is: %d\n", answer);

}