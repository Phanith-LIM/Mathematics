#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    //Open File AUC_data.csv
    FILE * file;
    double x[351],y[351],trapz = 0;
    char line[100];
    char *sp;
    file = fopen("AUC_data.csv","r");
    if (file == NULL)
    {
        printf("Error");
        return 1;
    }
    // Read file from AUC_data.csv and store x,y
    for (int i = 0; i < 351; i++)
    {
        fgets(line,100,file);
        sp = strtok(line,";");
        x[i]= atof(sp);
        sp = strtok(NULL,";");
        y[i]= atof(sp);
    }
    //Calculate Area Under Curves use Trapz Rules
    for (int i = 0; i < 350; i++)
    {
        trapz = trapz + ((y[i]+y[i+1])*(x[i+1]-x[i]))/2;
    }
    printf("\nArea under curve : %lf\n\n",trapz);
    fclose(file);
    return 0;
}