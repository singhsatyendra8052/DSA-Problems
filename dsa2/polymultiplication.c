#include<stdio.h>
#include<stdlib.h>
struct term
{
    int coefficient;
    int exponent;
    struct term *next;
};
void insertpoly(struct term **poly,int coeff,int exp)
{
    struct term *newterm=(struct term *)malloc(sizeof(struct term));
    newterm->coefficient=coeff;
    newterm->exponent=exp;
    newterm->next=NULL;
    if (*poly==NULL)
    {
        *poly=newterm;
    }
    else
    {
        struct term *temp;
        temp=*poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newterm;
    }
    
    
}
struct term *polymultiply(struct term *poly1,struct term *poly2,int num1,int num2)
{
    struct term *result=NULL;
    struct term *temp1=poly1;
    struct term *temp2=poly2;
    while (temp1!=NULL)
    {
        while (temp2!=NULL)
        {
            int e1,e2;
            e1=temp1->coefficient*temp2->coefficient;
            if (temp1->exponent==0&&temp2->exponent==1)
            {
                e2=1;
            }
            else if (temp1->exponent==1&&temp2->exponent==0)
            {
                e2=1;
            }
            
            else if (temp1->exponent==1||temp2->exponent==1)
            {
                e2=temp1->exponent+temp2->exponent;
            }
            else
            {
                e2=temp1->exponent*temp2->exponent;
            }
            
            
            insertpoly(&result,e1,e2);
            temp2=temp2->next;
        }
        temp1=temp1->next;
        temp2=poly2;
    }
    
    return result;
}
void printpolynomial(struct term *poly) {
    if (poly == NULL) {
        printf("0");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
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
        insertpoly(&poly1, coeff, exp);
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
        insertpoly(&poly2, coeff, exp);
    }
    printf("first polynomial: ");
    printpolynomial(poly1);
    printf("second polynomial: ");
    printpolynomial(poly2);
    result = polymultiply(poly1, poly2,num1,num2);
    printf("result of multipliction: ");
    printpolynomial(result);
    return 0;
}
