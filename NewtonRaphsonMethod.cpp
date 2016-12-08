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

float dfx(float coeffs1[],int s,float x)
{
    int i;
    float res = 0.0;

    for(i=s; i>=0; i--)
    {

        res = res * x + coeffs1[i];

    }

    return res;
}

int main()
{
    float coeffs[100],coeffs1[100],x,x1,e;
    int n,i,j;

    printf("Highest Degree of the Polynomial: ");
    scanf("%d",&n);
    printf("\nEach Co-efficients of the Polynomial one by one:\n");

    for(i=n; i>=0; i--)
    {
        scanf("%f",&coeffs[i]);
    }

    printf("\nEnter the value of First Approximation: ");
    scanf("%f",&x);
    printf("\nError: ");
    scanf("%f",&e);
    printf("\n");

    for(i=n-1; i>=0; i--)
    {
        coeffs1[i]=coeffs[i+1]*(i+1);
    }

    x1=x-(fx(coeffs,n,x)/dfx(coeffs1,n-1,x));

    j=1;
    while(fabs((x1-x)/x1)>e)
    {
        if(dfx(coeffs1,n-1,x)==0)
        {
            printf("'''''''''''''''''''''");
            break;
        }
        printf("Iteration: %d & root = %.3f\n",j,x1);
        j++;
        x=x1;
        x1=x-(fx(coeffs,n,x)/dfx(coeffs1,n-1,x));
    }

    printf("\nFinal root = %.3f\n",x1);

    return 0;

}



