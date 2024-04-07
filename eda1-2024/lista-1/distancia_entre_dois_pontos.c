#include <stdio.h>
#include <math.h>

struct tipoPonto{
    int x;
    int y;
};

double distancia(struct tipoPonto pa, struct tipoPonto pb){
    return sqrt(pow(pb.x - pa.x, 2) + pow(pb.y - pa.y, 2));
}
