#include <stdio.h>

typedef struct {
    int coefficient;
    int exponent;
} Term;

#define MAX_TERMS 100

typedef struct {
    Term terms[MAX_TERMS];
    int num_terms;
} Polynomial;

void print_poly(Polynomial poly) {
    int i;
    for (i = 0; i < poly.num_terms; i++) {
        printf("%dx^%d ", poly.terms[i].coefficient, poly.terms[i].exponent);
        if (i != poly.num_terms - 1) {
            printf("+ ");
        }
    }
    printf("\n");
}

Polynomial poly_sub1(Polynomial poly1, Polynomial poly2) {
    Polynomial result;
    int i, j, k;
    i = j = k = 0;

    while (i < poly1.num_terms && j < poly2.num_terms) {
        if (poly1.terms[i].exponent > poly2.terms[j].exponent) {
            result.terms[k++] = poly1.terms[i++];
        } else if (poly1.terms[i].exponent < poly2.terms[j].exponent) {
            result.terms[k].coefficient = -poly2.terms[j].coefficient;
            result.terms[k++].exponent = poly2.terms[j++].exponent;
        } else {
            result.terms[k].coefficient = poly1.terms[i].coefficient - poly2.terms[j].coefficient;
            result.terms[k++].exponent = poly1.terms[i++].exponent;
            j++;
        }
    }

    while (i < poly1.num_terms) {
        result.terms[k++] = poly1.terms[i++];
    }

    while (j < poly2.num_terms) {
        result.terms[k].coefficient = -poly2.terms[j].coefficient;
        result.terms[k++].exponent = poly2.terms[j++].exponent;
    }

    result.num_terms = k;
    return result;
}

Polynomial poly_sub2(Polynomial poly1, Polynomial poly2) {
    Polynomial result;
    int i, j, k;
    i = j = k = 0;

    while (i < poly1.num_terms && j < poly2.num_terms) {
        if (poly1.terms[i].exponent > poly2.terms[j].exponent) {
            result.terms[k++] = poly1.terms[i++];
        } else if (poly1.terms[i].exponent < poly2.terms[j].exponent) {
            result.terms[k].coefficient = -poly2.terms[j].coefficient;
            result.terms[k++].exponent = poly2.terms[j++].exponent;
        } else {
            int diff = poly1.terms[i].coefficient - poly2.terms[j].coefficient;
            if (diff != 0) {
                result.terms[k].coefficient = diff;
                result.terms[k++].exponent = poly1.terms[i].exponent;
            }
            i++;
            j++;
        }
    }

    while (i < poly1.num_terms) {
        result.terms[k++] = poly1.terms[i++];
    }

    while (j < poly2.num_terms) {
        result.terms[k].coefficient = -poly2.terms[j].coefficient;
        result.terms[k++].exponent = poly2.terms[j++].exponent;
    }

    result.num_terms = k;
    return result;
}

int main() {
    Polynomial poly1 = {{{5, 3}, {2, 2}, {3, 0}}, 3};
    Polynomial poly2 = {{{4, 3}, {1, 1}, {2, 0}}, 3};
    Polynomial result;

    printf("다항식 1: ");
    print_poly(poly1);
    printf("다항식 2: ");
    print_poly(poly2);

    result = poly_sub1(poly1, poly2);
    printf("뺄셈 결과 (poly_sub1): ");
    print_poly(result);

    result = poly_sub2(poly1, poly2);
    printf("뺄셈 결과 (poly_sub2): ");
    print_poly(result);

    return 0;
}
