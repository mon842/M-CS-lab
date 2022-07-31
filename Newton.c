#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) (x * x * x) - (3 * x) - 5
#define g(x) (3 * x * x) - 3

int main()
{
    float x0, x1, x2, xans = 0.0, xans2 = 0.0, f0, g0, f1, f2, e, N;
    int step = 1;
    printf("\nEnter two initial guesses:\n");
    scanf("%f%f", &x1, &x2);
    printf("Enter tolerable error:\n");
    scanf("%f", &e);
    printf("Enter maximum iteration:\n");
    scanf("%d", &N);
    /* Calculating Functional Value */
    f1 = fabs(f(x1));
    f2 = fabs(f(x2));
    if (f1 < f2)
    {
        x0 = x1;
    }
    else
    {
        x0 = x2;
    }

    do
    {
        g0 = g(x0);
        f0 = f(x0);
        if (g0 == 0.0)
        {
            printf("Mathematical Error.");
            exit(0);
        }

        x1 = x0 - f0 / g0;

        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, f0, x1, f1);
        x0 = x1;

        step = step + 1;


        f1 = f(x1);

    } while (fabs(f1) > e);

    printf("\nRoot is: %f", x1);
    getch();

    return 0;
}
