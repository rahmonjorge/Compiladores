#include <stdio.h>
#include <time.h>

#define N 100000000

#define fim_string -1
#define AP -2
#define FP -3
#define K -4
#define S -5
#define I -6
#define B -7
#define C -8
#define D -9
#define E -10
#define F -11
#define Y -12

#define lt -13
#define add -14
#define sub -15
#define mul -16
#define True -17
#define False -18

// FIB
static int entrada[N] = {S, AP, K, AP, S, I, I, FP, FP, AP, S, AP, S, AP, K, S, FP, K, FP, AP, K, AP, S, I, I, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 2, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, lt, FP, FP, FP, FP, AP, K, I, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, K, K, FP, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 1, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, sub, FP, FP, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, K, K, FP, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 2, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, sub, FP, FP, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, add, FP, FP, FP, FP, 20, fim_string};

// FAT
// static int entrada[N] = {S, AP, K, AP, S, I, I, FP, FP, AP, S, AP, S, AP, K, S, FP, K, FP, AP, K, AP, S, I, I, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 2, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, lt, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, 1, FP, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, K, K, FP, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 1, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, sub, FP, FP, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, mul, FP, FP, FP, FP, 20, fim_string};

static int saida[N];

void printar_array(unsigned int *array1)
{
    int i;

    for (i = 0; array1[i] != fim_string; i++)
    {
        switch (array1[i])
        {
        case B:
            printf("B");
            break;
        case C:
            printf("C");
            break;
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
        case D:
            printf("D");
            break;
        case E:
            printf("E");
            break;
        case F:
            printf("F");
            break;
        case I:
            printf("I");
            break;
        case Y:
            printf("Y");
            break;
        case lt:
            printf("<");
            break;
        case add:
            printf("+");
            break;
        case sub:
            printf("-");
            break;
        case True:
            printf("Tru");
            break;
        case False:
            printf("Fal");
            break;
        case mul:
            printf("*");
            break;
        case fim_string:
            printf("_");
            break;
        default:
            printf("%u", array1[i]);
        }
    }
    printf("\n");
}

/*
 * Remove o parenteses da posição 0 e seu oposto
 */

void remove_parenteses(int *array1, int *array2)
{
    int p = 0;
    int paren = 1;
    while (paren)
    {
        array2[p] = array1[p + 1];
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
        array2[p] = array1[p + 2];
        p++;
    }
    array2[p] = fim_string;
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
 * Khg = h
 */

void reduz_K(int *array1, int *array2)
{
    int H, nH;
    int n = 1;

    H = n;
    acha_argumento(array1, &n);
    nH = n - 1;
    acha_argumento(array1, &n);

    int k = 0;
    int i;

    for (i = H; i <= nH; i++)
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
 * Shgx = hx(gx)
 */
void reduz_S(int *array1, int *array2)
{
    int H, nH;
    int G, nG;
    int X, nX;
    int n = 1;
    H = n;
    acha_argumento(array1, &n);
    nH = n - 1;
    G = n;
    acha_argumento(array1, &n);
    nG = n - 1;
    X = n;
    acha_argumento(array1, &n);
    nX = n - 1;

    int k = 0;
    int i;

    for (i = H; i <= nH; i++)
    {
        array2[k] = array1[i];
        k++;
    }
    for (i = X; i <= nX; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = G; i <= nG; i++)
    {
        array2[k] = array1[i];
        k++;
    }
    for (i = X; i <= nX; i++)
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
 * Ih = h
 */

void reduz_I(int *array1, int *array2)
{
    int H, nH;
    int n = 1;

    H = n;
    acha_argumento(array1, &n);
    nH = n - 1;

    int k = 0;
    int i;

    for (i = H; i <= nH; i++)
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
 * Bhgx = h(gx)
 */
void reduz_B(int *array1, int *array2)
{
    int H, nH;
    int G, nG;
    int X, nX;
    int n = 1;
    H = n;
    acha_argumento(array1, &n);
    nH = n - 1;
    G = n;
    acha_argumento(array1, &n);
    nG = n - 1;
    X = n;
    acha_argumento(array1, &n);
    nX = n - 1;

    int k = 0;
    int i;

    for (i = H; i <= nH; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = G; i <= nG; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = X; i <= nX; i++)
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
 * Chgx = hxg
 */
void reduz_C(int *array1, int *array2)
{
    int H, nH;
    int G, nG;
    int X, nX;
    int n = 1;
    H = n;
    acha_argumento(array1, &n);
    nH = n - 1;
    G = n;
    acha_argumento(array1, &n);
    nG = n - 1;
    X = n;
    acha_argumento(array1, &n);
    nX = n - 1;

    int k = 0;
    int i;

    for (i = H; i <= nH; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = X; i <= nX; i++)
    {
        array2[k] = array1[i];
        k++;
    }
    for (i = G; i <= nG; i++)
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
 * Djhgx = j(hx)(gx)
 */
void reduz_D(int *array1, int *array2)
{
    int J, nJ;
    int H, nH;
    int G, nG;
    int X, nX;
    int n = 1;
    J = n;
    acha_argumento(array1, &n);
    nJ = n - 1;
    H = n;
    acha_argumento(array1, &n);
    nH = n - 1;
    G = n;
    acha_argumento(array1, &n);
    nG = n - 1;
    X = n;
    acha_argumento(array1, &n);
    nX = n - 1;

    int k = 0;
    int i;

    for (i = J; i <= nJ; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = H; i <= nH; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = X; i <= nX; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    array2[k] = AP;
    k++;

    for (i = G; i <= nG; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = X; i <= nX; i++)
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
 * Ejhgx = jh(gx)
 */
void reduz_E(int *array1, int *array2)
{
    int J, nJ;
    int H, nH;
    int G, nG;
    int X, nX;
    int n = 1;
    J = n;
    acha_argumento(array1, &n);
    nJ = n - 1;
    H = n;
    acha_argumento(array1, &n);
    nH = n - 1;
    G = n;
    acha_argumento(array1, &n);
    nG = n - 1;
    X = n;
    acha_argumento(array1, &n);
    nX = n - 1;

    int k = 0;
    int i;

    for (i = J; i <= nJ; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = H; i <= nH; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = G; i <= nG; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = X; i <= nX; i++)
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
 *  Fjhgx = j(hx)g
 */
void reduz_F(int *array1, int *array2)
{
    int J, nJ;
    int H, nH;
    int G, nG;
    int X, nX;
    int n = 1;
    J = n;
    acha_argumento(array1, &n);
    nJ = n - 1;
    H = n;
    acha_argumento(array1, &n);
    nH = n - 1;
    G = n;
    acha_argumento(array1, &n);
    nG = n - 1;
    X = n;
    acha_argumento(array1, &n);
    nX = n - 1;

    int k = 0;
    int i;

    for (i = J; i <= nJ; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = H; i <= nH; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    for (i = X; i <= nX; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    for (i = G; i <= nG; i++)
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
 * Yx = x(Yx)
 */
void reduz_Y(int *array1, int *array2)
{
    int X, nX;
    int n = 1;
    X = n;
    acha_argumento(array1, &n);
    nX = n - 1;

    int k = 0;
    int i;

    for (i = X; i <= nX; i++)
    {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    array2[k] = Y;
    k++;

    for (i = X; i <= nX; i++)
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
 * LThg = h < g
 */

void reduz_LT(int *array1, int *array2)
{
    int H, G;
    int n = 1;

    H = n;
    n++;
    G = n;
    n++;

    int k = 0;
    int i;

    if (array1[H] < array1[G])
        array2[k] = True;
    else
        array2[k] = False;
    k++;

    for (; array1[n] != fim_string; n++)
    {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * ADD hg = h + g
 */

void reduz_ADD(int *array1, int *array2)
{
    int H, G;
    int n = 1;

    H = n;
    n++;
    G = n;
    n++;

    int k = 0;
    int i;

    array2[k] = array1[H] + array1[G];
    k++;

    for (; array1[n] != fim_string; n++)
    {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * SUB hg = h - g
 */

void reduz_SUB(int *array1, int *array2)
{
    int H, G;
    int n = 1;

    H = n;
    n++;
    G = n;
    n++;

    int k = 0;
    int i;

    array2[k] = array1[H] - array1[G];
    k++;

    for (; array1[n] != fim_string; n++)
    {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * TRU hg = h
 */

void reduz_True(int *array1, int *array2)
{
    int H, nH;
    int n = 1;

    H = n;
    acha_argumento(array1, &n);
    nH = n - 1;
    acha_argumento(array1, &n);

    int k = 0;
    int i;

    for (i = H; i <= nH; i++)
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
 * FAL hg = g
 */

void reduz_False(int *array1, int *array2)
{
    int G, nG;
    int n = 1;
    acha_argumento(array1, &n);
    G = n;
    acha_argumento(array1, &n);
    nG = n - 1;

    int k = 0;
    int i;

    for (i = G; i <= nG; i++)
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
 * MUL hg = h * g
 */

void reduz_MUL(int *array1, int *array2)
{
    int H, G;
    int n = 1;

    H = n;
    n++;
    G = n;
    n++;

    int k = 0;

    array2[k] = array1[H] * array1[G];
    k++;

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
            remove_parenteses(array1, array2);
            break;
        case I:
            reduz_I(array1, array2);
            break;
        case F:
            reduz_F(array1, array2);
            break;
        case K:
            reduz_K(array1, array2);
            break;
        case B:
            reduz_B(array1, array2);
            break;
        case D:
            reduz_D(array1, array2);
            break;
        case C:
            reduz_C(array1, array2);
            break;
        case E:
            reduz_E(array1, array2);
            break;
        case S:
            reduz_S(array1, array2);
            break;
        case Y:
            reduz_Y(array1, array2);
            break;
        case lt:
            reduz_LT(array1, array2);
            break;
        case add:
            reduz_ADD(array1, array2);
            break;
        case sub:
            reduz_SUB(array1, array2);
            break;
        case mul:
            reduz_MUL(array1, array2);
            break;
        case True:
            reduz_True(array1, array2);
            break;
        case False:
            reduz_False(array1, array2);
            break;
        default:
            if (array1[2] != fim_string)
                reduz_DEF(array1, array2);
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