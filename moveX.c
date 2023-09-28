#include <stdio.h>

void moveX(char c, int i){
    if(c[i] == '\0'){

        return c;
    }

    if(c[i] == 'x'){
        moveX(c, i + 1);
    }
                                                                                                                                    

}




int main(){

    char c[100];
    scanf("%s", &c);

    char x = moveX(c, 0);


    printf("%s", x);

    return 0;
}