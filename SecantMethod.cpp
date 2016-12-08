#include <stdio.h>
#include <math.h>

float fx(float coeffs[],int s,float x)
{
    int i;
    float res = 0.0;

    for(i=s; i>=0; i--)
    {

        res = res * x + coeffs[i];

    }

    return res;
}

int main()
{
    float coeffs[100],x1,x2,x3,e;
    int n,i,j;

    printf("Highest Degree of the Polynomial: ");
    scanf("%d",&n);
    printf("\nEach Co-efficients of the Polynomial one by one:\n");

    for(i=n; i>=0; i--)
    {
        scanf("%f",&coeffs[i]);
    }

    printf("\nEnter the Values of Two Initial Estimates (x1,x2):\n");
    scanf("%f %f",&x1,&x2);
    printf("\nError: ");
    scanf("%f",&e);
    printf("\n");


    x3=((fx(coeffs,n,x2)*x1)-(fx(coeffs,n,x1)*x2))/(fx(coeffs,n,x2)-fx(coeffs,n,x1));

    j=1;
    while(fabs((x3-x2)/x3)>e)
    {

        printf("Iteration: %d & root = %.3f\n",j,x3);
        j++;
        x1=x2;
        x2=x3;
        x3=((fx(coeffs,n,x2)*x1)-(fx(coeffs,n,x1)*x2))/(fx(coeffs,n,x2)-fx(coeffs,n,x1));

    }

    printf("\nFinal root = %.3f\n",x3);

    return 0;

}



