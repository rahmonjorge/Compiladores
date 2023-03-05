#include <stdio.h>
#include <time.h>

#define N 100000000

#define fim_string -1
#define AP -2 // Abre Parenteses
#define FP -3 // Fecha Parenteses
#define K -4
#define S -5
#define I -6
#define B -7
#define C -8

/*
 * Entrada SK
 */

//#include "ent-ksi.h"
#include "ent-curry.h"
// static int entrada[N] = {S, AP, K, AP, K, FP, FP, AP, K, S, FP, AP, S, K, FP, K, K, AP, S, K, FP, K, fim_string};
static int saida[N];

void printar_array(unsigned int *array1)
{
    int i;
    unsigned int fimString = -1;
    for (i = 0; array1[i] != fimString; i++)
    {
        switch (array1[i])
        {
        case S:
            printf("S");
            break;
        case K:
            printf("K");
            break;
        case FP:
            printf(")");
            break;
        case AP:
            printf("(");
            break;
        case fim_string:
            break;
        default:
            printf("%u ", array1[i]);
        }
    }
    printf("\n");
}

/*
 * Remove o parenteses da posição 0 e seu oposto
 */

void remove_parenteses(int *array1)
{
    int p = 0;
    int paren = 1;
    while (paren)
    {
        array1[p] = array1[p + 1];
        p++;
        if (array1[p] == AP)
        {
            paren++;
        }
        else if (array1[p] == FP)
        {
            paren--;
        }
    }
    p--;
    while (array1[p + 1] != fim_string && array1[p + 2] != fim_string)
    {
        array1[p] = array1[p + 2];
        p++;
    }
    array1[p] = fim_string;
}

/*
 * Procura o fim do conjunto de inteiros
 */
void casa_parenteses(int *array1, int *p)
{
    int paren = 1;
    int a = *p;
    while (paren)
    {
        unsigned int c = array1[a];
        if (c == AP)
        {
            paren++;
        }
        else if (c == FP)
        {
            paren--;
        }
        a++;
    }
    *p = a;
}

/*
 * Verifica se a posicao do array é um inteiro ou um conjunto de inteiros
 */
void acha_argumento(int *array1, int *p)
{
    int c = (*p)++;
    if (array1[c] == AP)
    {
        casa_parenteses(array1, p);
    }
}

/*
 * Kab = a
 */

void reduz_K(int *array1, int *array2)
{
    int A, nA;
    int n = 1;

    A = n;
    acha_argumento(array1, &n);

    nA = n - 1;
    acha_argumento(array1, &n);

    int k = 0;
    int i;

    for (i = A; i <= nA; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (; array1[n] != fim_string; n++)
    {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * Sabc = ac(bc)
 */
void reduz_S(int *array1, int *array2)
{
    int A, nA;
    int U, nU;
    int P, nP;
    int n = 1;
    A = n;
    acha_argumento(array1, &n);
    nA = n - 1;
    U = n;
    acha_argumento(array1, &n);
    nU = n - 1;
    P = n;
    acha_argumento(array1, &n);
    nP = n - 1;

    int k = 0;
    int i;

    for (i = A; i <= nA; i++)
    {
        array2[k] = array1[i];
        k++;
    }
    for (i = P; i <= nP; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = U; i <= nU; i++)
    {
        array2[k] = array1[i];
        k++;
    }
    for (i = P; i <= nP; i++)
    {
        array2[k] = array1[i];
        k++;
    }
    array2[k] = FP;
    k++;
    for (; array1[n] != fim_string; n++)
    {
        array2[k] = array1[n];
        k++;
    }
    array2[k] = fim_string;
}

/*
 * Ia = a
 */
void reduz_I(int *array1, int *array2)
{
    int A, nA;
    int n = 1;

    A = n;
    acha_argumento(array1, &n);
    nA = n - 1;

    int k = 0;
    int i;

    for (i = A; i <= nA; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (; array1[n] != fim_string; n++)
    {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * B a b c = a (b c)
 */
void reduz_B(int *array1, int *array2)
{
    int A, nA;
    int U, nU;
    int P, nP;
    int n = 1;
    A = n;
    acha_argumento(array1, &n);
    nA = n - 1;
    U = n;
    acha_argumento(array1, &n);
    nU = n - 1;
    P = n;
    acha_argumento(array1, &n);
    nP = n - 1;

    int k = 0;
    int i;

    for (i = A; i <= nA; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = U; i <= nU; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = P; i <= nP; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    for (; array1[n] != fim_string; n++)
    {
        array2[k] = array1[n];
        k++;
    }
    array2[k] = fim_string;
}

/*
 * C f g x = f x g
 */
void reduz_C(int *array1, int *array2)
{
    int A, nA;
    int U, nU;
    int P, nP;
    int n = 1;
    A = n;
    acha_argumento(array1, &n);
    nA = n - 1;
    U = n;
    acha_argumento(array1, &n);
    nU = n - 1;
    P = n;
    acha_argumento(array1, &n);
    nP = n - 1;

    int k = 0;
    int i;

    for (i = A; i <= nA; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = P; i <= nP; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = U; i <= nU; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (; array1[n] != fim_string; n++)
    {
        array2[k] = array1[n];
        k++;
    }
    array2[k] = fim_string;
}

int main()
{
    int *array1, *array2, *array3;
    array1 = entrada;
    array2 = saida;
    while (array1[1] != fim_string)
    {
        switch (array1[0])
        {
        case I:
            reduz_I(array1, array2);
            break;
        case B:
            reduz_B(array1, array2);
            break;
        case C:
            reduz_C(array1, array2);
            break;
        case AP:
            remove_parenteses(array1);
            array2[0] = fim_string;
            break;
        case K:
            reduz_K(array1, array2);
            break;
        case S:
            reduz_S(array1, array2);
            break;
        default:
            break;
        }
        array3 = array1;
        array1 = array2;
        array2 = array3;
    }
    printar_array(array1);
    float clks = CLOCKS_PER_SEC;
    printf("\nTempo = %f", (clock() / clks));
    return 0;
}