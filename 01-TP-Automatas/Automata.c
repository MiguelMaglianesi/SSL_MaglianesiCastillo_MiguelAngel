#include <stdio.h>
#include <string.h>
#include <ctype.h>

int columna(int c)
{
    if(c == '+' || c == '-') return 0;

    if(c == '0') return 1;

    if(c >= '1' && c <= '7') return 2;

    if(c == '8' || c == '9') return 3;

    if(c == 'o') return 4;

    if(c == 'x' || c == 'X') return 5;

    if((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) return 6;

    if(c == '@') return 7;

    return 8;
}

int verifica(char *s)
{
    unsigned i;

    for(i = 0; s[i]; i++)
    {
        if(!(s[i] == '+' || s[i] == '-' ||
            (s[i] >= '0' && s[i] <= '9') ||
            s[i] == 'o' ||
            s[i] == 'x' || s[i] == 'X' ||
            (s[i] >= 'a' && s[i] <= 'f') ||
            (s[i] >= 'A' && s[i] <= 'F') ||
            s[i] == '@'))
            {
                return 0;
            }
    }

    return 1;
}

int esConstante(const char *cadena)
{
    static int tt[8][9] = {
        {1,2,3,3,8,8,8,8,8}, //q0
        {8,3,3,3,8,8,8,8,8}, //q1
        {8,8,8,8,4,5,8,0,8}, //q2
        {8,3,3,3,8,8,8,0,8}, //q3
        {8,6,6,8,8,8,8,8,8}, //q4
        {8,7,7,7,8,8,7,8,8}, //q5
        {8,6,6,8,8,8,8,0,8}, //q6
        {8,7,7,7,8,7,7,0,8}, //q7
    };

    int e = 0;
    unsigned int i = 0;
    int c = cadena[0];

    while(c != '\0' && e != 8)
    {
        e = tt[e][columna(c)];
        c = cadena[++i];
    }

    if(e == 2 || e == 3 || e == 6 || e == 7) return 1;

    return 0;
}

int contar(char *s)
{
    if(s[0] == '0' && s[1] == 'o') return 2;

    if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) return 3;

    return 1;
}

int main()
{
    char cadena[] = "123@";

    int decimales = 0;
    int octales = 0;
    int hexadecimales = 0;

    unsigned int i = 0;
    unsigned int inicio = 0;

    char constante[100];
    
    if(!verifica(cadena))
    {
        printf("ERROR LEXICO");
        return 0;
    }

    while(1)
    {
        if(cadena[i] == '@' || cadena[i] == '\0')
        {
            unsigned int j;
            unsigned int k = 0;

            for(j = inicio; j < i; j++)
            {
                constante[k] = cadena[j];
                k++;
            }

            constante[k] = '\0';

            if(!esConstante(constante))
            {
                printf("ERROR LEXICO\n");
                return 0;
            }

            /*contar que tipo es el caracter para sumar*/
            if(contar(constante) == 1) decimales++;
            else if(contar(constante) == 2) octales++;
            else if(contar(constante) == 3) hexadecimales++;

            if(cadena[i] == '\0') break;

            inicio = i + 1;
        }

        i++;
    }

    printf("DECIMALES: %d\n", decimales);
    printf("OCTALES: %d\n", octales);
    printf("HEXADecimales: %d\n", hexadecimales);
    return 0;
}