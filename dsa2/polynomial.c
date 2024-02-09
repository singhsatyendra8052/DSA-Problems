#include <stdio.h>
#include <stdlib.h>
struct term
{
    int coefficient;
    int exponent;
    struct term *next;
};
void insertTerm(struct term **poly, int coeff, int exp)
{
    struct term *newterm = (struct term *)malloc(sizeof(struct term));
    newterm->coefficient = coeff;
    newterm->exponent = exp;
    newterm->next = NULL;
    if (*poly == NULL)
    {
        *poly = newterm;
    }
    else
    {
        struct term *temp = *poly;
        while (temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = newterm;
    }
}
struct term *addpolynomials(struct term *poly1, struct term *poly2)
{
    struct term *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exponent > poly2->exponent)
        {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        }
        else if (poly2->exponent > poly1->exponent)
        {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
        else
        {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0)
            {
                insertTerm(&result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}
void printpolynomial(struct term *poly)
{
    if (poly == NULL)
    {
        printf("0");
        return;
    }
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}
int main()
{
    struct term *poly1 = NULL;
    struct term *poly2 = NULL;
    struct term *result = NULL;
    int num1, num2;
    printf("enter the no. of coefficeint in first polynomial- ");
    scanf("%d", &num1);
    for (int i = 0; i < num1; i++)
    {
        int coeff, exp;
        printf("enter the coefficeint for term %d: ", i + 1);
        scanf("%d", &coeff);
        printf("enter the exponent for term %d: ",i+1);
        scanf("%d",&exp);
        insertTerm(&poly1, coeff, exp);
    }
    printf("Enter the number of terms in the second polynomial:- ");
    scanf("%d", &num2);
    for (int i = 0; i < num2; i++)
    {
       int coeff, exp;
        printf("enter the coefficeint for term %d: ", i + 1);
        scanf("%d", &coeff);
        printf("enter the exponent for term %d: ",i+1);
        scanf("%d",&exp);
        insertTerm(&poly2, coeff, exp);
    }
    printf("first polynomial: ");
    printpolynomial(poly1);
    printf("second polynomial: ");
    printpolynomial(poly2);
    result = addpolynomials(poly1, poly2);
    printf("result of addition: ");
    printpolynomial(result);
    return 0;
}
