#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int xx;
    int y;
    int yy;
} Rectangle;

int can_associate(Rectangle r1, Rectangle r2) {
    int l, h;
    l = (r2.x >= r1.xx) ? r2.x - r1.xx : r1.x - r2.xx;
    h = (r2.y >= r2.yy) ? r2.y - r2.yy : r2.y - r2.yy;

    return (l * h) > 0;
}

int aire(Rectangle r) {
    return (r.xx - r.x) * (r.yy - r.y);
}

Rectangle asssociate(Rectangle r1, Rectangle r2) {
    Rectangle r;

    if(r1.x > r2.x) {
        r.x = r1.x;
        r.y = r1.y;
    } else {
        r.x = r2.x;
        r.y = r2.y;
    }

    if(r1.xx > r2.xx) {
        r.xx = r2.xx;
        r.yy = r2.yy;
    } else {
        r.xx = r1.xx;
        r.yy = r1.yy;
    }

    // r.xx = r1.x;
    // r.yy = r1.y;

    return r;
}

void shift ( Rectangle* rectangles, int size, int begin )
{
    int i;
    for ( i = 0; i < size; i++ ) 
    {
        if ( i > begin ) 
        {
            rectangles [ i - 1 ] = rectangles [ i ];
        }
    }
}



int main(int argc, const char** argv) {
    int n, end = 0, i, size;
    Rectangle* rectangles;  

    scanf("%d", &n);
    size = n;
    rectangles = (Rectangle*)malloc(n * sizeof(Rectangle));

    for(i = 0; i < n; i++) {
        scanf("%d %d %d %d", &rectangles[i].x, &rectangles[i].y, &rectangles[i].xx, &rectangles[i].yy);
    }

    while ( !end ) {
        end = 1;
        for(i = 0; i < (size - 1); i++) {
            if(can_associate(rectangles[i], rectangles[i + 1])) {
                end = 0;
                Rectangle r = asssociate(rectangles[i], rectangles[i + 1]);
                rectangles[i] = r;
                shift(rectangles, size, i + 1);
                size--;
                break;
            } 
        }
    }

    if(size == 1) {
        printf("%d\r\n", aire(rectangles[0]));
    } else {
        printf("0\r\n");
    }

    return EXIT_SUCCESS;
}