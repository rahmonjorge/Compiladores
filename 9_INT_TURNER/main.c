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
#define D -9
#define E -10
#define F -11

/*
 * Entrada SK
 */
#include "turner.h"

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
 * Sxyz = xz(yz)
 */
void reduz_S(int *array1, int *array2)
{
    int X, nX;
    int Y, nY;
    int Z, nZ;
    int n = 1;
    X = n;
    acha_argumento(array1, &n);
    nX = n - 1;
    Y = n;
    acha_argumento(array1, &n);
    nY = n - 1;
    Z = n;
    acha_argumento(array1, &n);
    nZ = n - 1;

    int k = 0;
    int i;

    for (i = X; i <= nX; i++)
    {
        array2[k] = array1[i];
        k++;
    }
    for (i = Z; i <= nZ; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = Y; i <= nY; i++)
    {
        array2[k] = array1[i];
        k++;
    }
    for (i = Z; i <= nZ; i++)
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
 * B x y z = x (y z)
 */
void reduz_B(int *array1, int *array2)
{
    int X, nX;
    int Y, nY;
    int Z, nZ;
    int n = 1;
    X = n;
    acha_argumento(array1, &n);
    nX = n - 1;
    Y = n;
    acha_argumento(array1, &n);
    nY = n - 1;
    Z = n;
    acha_argumento(array1, &n);
    nZ = n - 1;

    int k = 0;
    int i;

    for (i = X; i <= nX; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = Y; i <= nY; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = Z; i <= nZ; i++)
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
 * C x y z = x z y
 */
void reduz_C(int *array1, int *array2)
{
    int X, nX;
    int Y, nY;
    int Z, nZ;
    int n = 1;
    X = n;
    acha_argumento(array1, &n);
    nX = n - 1;
    Y = n;
    acha_argumento(array1, &n);
    nY = n - 1;
    Z = n;
    acha_argumento(array1, &n);
    nZ = n - 1;

    int k = 0;
    int i;

    for (i = F; i <= nX; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = Z; i <= nZ; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = Y; i <= nY; i++)
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
 * D c f g x = c (f x) (g x)
 * D x y z w = x (y w) (z w)
 */
void reduz_D(int *array1, int *array2)
{
    int X, nX;
    int Y, nY;
    int Z, nZ;
    int W, nW;
    int n = 1;

    X = n;
    acha_argumento(array1, &n);
    nX = n - 1;
    Y = n;
    acha_argumento(array1, &n);
    nY = n - 1;
    Z = n;
    acha_argumento(array1, &n);
    nZ = n - 1;
    W = n;
    acha_argumento(array1, &n);
    nW = n - 1;

    int k = 0;
    int i;

    for (i = X; i <= nX; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = Y; i <= nY; i++)
    {
        array2[k] = array1[i];
        k++;
    }
    for (i = W; i <= nW; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    array2[k] = AP;
    k++;

    for (i = Z; i <= nZ; i++)
    {
        array2[k] = array1[i];
        k++;
    }
    for (i = W; i <= nW; i++)
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
 * E c f g x = c f (g x)
 * E x y z w = x y (z w)
 */
void reduz_E(int *array1, int *array2)
{
    int X, nX;
    int Y, nY;
    int Z, nZ;
    int W, nW;
    int n = 1;

    X = n;
    acha_argumento(array1, &n);
    nX = n - 1;
    Y = n;
    acha_argumento(array1, &n);
    nY = n - 1;
    Z = n;
    acha_argumento(array1, &n);
    nZ = n - 1;
    W = n;
    acha_argumento(array1, &n);
    nW = n - 1;

    int k = 0;
    int i;

    for (i = X; i <= nX; i++)
    {
        array2[k] = array1[i];
        k++;
    }
    for (i = Y; i <= nY; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = Z; i <= nZ; i++)
    {
        array2[k] = array1[i];
        k++;
    }
    for (i = W; i <= nW; i++)
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
 * F c f g x = c (f x) g
 * F x y z w = x (y w) z
 */
void reduz_F(int *array1, int *array2)
{
    int X, nX;
    int Y, nY;
    int Z, nZ;
    int W, nW;
    int n = 1;

    X = n;
    acha_argumento(array1, &n);
    nX = n - 1;
    Y = n;
    acha_argumento(array1, &n);
    nY = n - 1;
    Z = n;
    acha_argumento(array1, &n);
    nZ = n - 1;
    W = n;
    acha_argumento(array1, &n);
    nW = n - 1;

    int k = 0;
    int i;

    for (i = X; i <= nX; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = Y; i <= nY; i++)
    {
        array2[k] = array1[i];
        k++;
    }
    for (i = W; i <= nW; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    for (i = Z; i <= nZ; i++)
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
        case I:
            reduz_I(array1, array2);
            break;
        case B:
            reduz_B(array1, array2);
            break;
        case C:
            reduz_C(array1, array2);
            break;
        case D:
            reduz_D(array1, array2);
            break;
        case E:
            reduz_E(array1, array2);
            break;
        case F:
            reduz_F(array1, array2);
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
