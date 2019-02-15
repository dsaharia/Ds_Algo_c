#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Movies {
    char name[5];
    int duration;

}movies;

void print(movies*);
void bubble_sort(movies*,movies*,int);
int main()
{
    FILE *fmovies1, *fmovies2;
    int count = 0, number1, number2, i=0, j=0;
    char title1[5], title2[5];
    movies *movies1, *movies2;

    fmovies1 = fopen("movies1.txt","r");
    fmovies2 = fopen("movies2.txt", "r");
    while (fscanf(fmovies1, "%*s %d", &number1) == 1) {
	count++;
    
    }
    rewind(fmovies1);
    
    movies1 = (movies*) malloc(sizeof(movies) * count);
    movies2 = (movies*) malloc(sizeof(movies) * count);
    while(fscanf(fmovies1, "%s %d", title1, &number1) == 2 && fscanf(fmovies2, "%s %d", title2, &number2) == 2) {
	strcpy(movies1[i].name, title1);
	movies1[i].duration = number1;

	strcpy(movies2[i].name, title2);
	movies2[i].duration = number2;
	i++;
    }
    //print(movies1);
    //print(movies2);
    bubble_sort(movies1, movies2, count);
    print(movies1);
    print(movies2);
}

void print(movies *mov_ptr)
{
    int i;
    for (i=0;i<5;i++)
    {
	printf("%s ", mov_ptr[i].name);
    
    }
    printf("\n");


}

void bubble_sort(movies* movies1, movies* movies2, int count)
{
    int i,k;
    movies temp;

    for(k=1;k<count;k++) {
	for(i=0;i<count-k;i++) {
	    if(movies1[i].duration > movies1[i+1].duration) {
		temp = movies1[i];
		movies1[i] = movies1[i+1];
		movies1[i+1] = temp;
	    }
    
	}
    
    }
    // For Movies 2
    
    for(k=1;k<count;k++) {
	for(i=0;i<count-k;i++) {
	    if(movies2[i].duration > movies2[i+1].duration) {
		temp = movies2[i];
		movies2[i] = movies2[i+1];
		movies2[i+1] = temp;
	    }
    
	}
    
    }
}

void median(movies *movies1, movies *movies2, count)
{
    
    if (count == 1) { 
        return (movies1[0].duration + movies2[0].duration)/2;
    }
    if (count == 2) {
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;	
    
    }


}
