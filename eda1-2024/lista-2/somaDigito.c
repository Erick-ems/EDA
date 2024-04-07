#include <stdio.h>
#include <string.h>

int converteInt(char *str, int start, int end, int *v){
    if(start >= end){
        return;
    }
    v[start] = str[start] - '0';
    converteInt(str, start + 1, end, v);
}

int soma(int *v, int start, int end){
    if(start >= end){
        return 0;
    }
    return v[start] + soma(v, start + 1, end);
}

int main(){
    int resultado = 0;
    char str[14];

    scanf("%s", str);

    int len = strlen(str);
    int v[len];

    converteInt(str, 0, len, v);
    resultado = soma(v, 0, len);

    printf("%d\n", resultado);

    return 0;
}
