#include <stdio.h>

typedef struct Points {
    int x,y;

}points;

int main()
{
    FILE *fpoints = fopen("points.txt","r");
    points point[10];
    int i;

    for(i=0;i<10;i++)
    {
	fscanf(fpoints,"%d\n%d", &(point[i].x), &(point[i].y)); // To read from file and save in a structure
    
    }
    for(i=0;i<10;i++)
    {
	printf("%d %d\n",(point[i].x), (point[i].y));
    }
}
