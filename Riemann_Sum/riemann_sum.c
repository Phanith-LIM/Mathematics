#include <stdio.h>
#include <math.h>
int main(){
    double a = 0,b = 2,n ,delta_x,function,sum_left,sum_right,sum_mindpoint;
    FILE *fp;
    fp = fopen("data.csv","w");
    if (fp == NULL)
    {
        printf("Error");
        return 1;
    }
    fprintf(fp,"n,Ln,Rn,Mn\n");
    for (int n = 20; n < 10020; n += 20)
    {
        delta_x = (b-a)/n;
        sum_left = 0;
        sum_right = 0;
        sum_mindpoint = 0;
        for (int x = 0; x < n;x++)
        {
            sum_left = sum_left + (pow((a + x*delta_x),3) + 1)*delta_x;
            sum_right = sum_right + (pow((a + (x+1)*delta_x),3) + 1)*delta_x;
            sum_mindpoint = sum_mindpoint + (pow((a + (2*x+1)*(delta_x/2)),3) + 1)*delta_x;
        }
        fprintf(fp,"\n%d,%.12f,%.12f,%.12f",n,sum_left,sum_right,sum_mindpoint);
    }
    fclose (fp);
    printf("Complete..\n");
    return 0;
}