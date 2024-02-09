
#include <stdio.h>
#include <stdlib.h>
struct Term {
    int coefficient;
    int exponent;
    struct Term *next;
};
void insertTerm(struct Term **poly, int coeff, int exp) {
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term *temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}
struct Term *addPolynomials(struct Term *poly1, struct Term *poly2) {
    struct Term *result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coefficient + poly2->coefficient;
            if (sumCoeff != 0) {
                insertTerm(&result, sumCoeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}
void printPolynomial(struct Term *poly) {
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
int main() {
    struct Term *poly1 = NULL;
    struct Term *poly2 = NULL;
    struct Term *result = NULL;
    int numTerms1, numTerms2;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &numTerms1);
    for (int i = 0; i < numTerms1; i++) {
        int coeff, exp;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &numTerms2);
    for (int i = 0; i < numTerms2; i++) {
        int coeff, exp;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }
    printf("First polynomial: ");
    printPolynomial(poly1);
    printf("Second polynomial: ");
    printPolynomial(poly2);
    result = addPolynomials(poly1, poly2);
    printf("Result of addition: ");
    printPolynomial(result);
    return 0;
}