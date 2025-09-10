#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void main()
{
    LARGE_INTEGER start, end, frequency;
    QueryPerformanceFrequency(&frequency);

    int num[]={1,3,48,78,9,0,9,23,67,1,2,55,6,4,5,56,78,12,23,4,5,7,98,76,45,11,10,16,7,3,6,16,26,56,45,89,100,34,54,789,232,14,177,676,890,900,786,123432,67654,898,99,767,56,55,790,8,879,988,1008,787};
    int tamanho= sizeof(num)/sizeof(num[0]);
    int i,f= 0;
    int nmaior= num[0];

    QueryPerformanceCounter(&start);

    for(i=0;i<=tamanho;i++)
    {
        if(num[i]>nmaior) nmaior=num[i];
    }

    int *count = (int *)calloc(nmaior+1, sizeof(int));

    for(i=0;i<tamanho;i++)
    {
        count[num[i]]++;
    }

    for(i=0; i<= nmaior;i++)
    {
        while(count[i]-- >0)
        {
            num[f++]=i;
        }
    }

    QueryPerformanceCounter(&end);

    double tempo_gasto = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("Esses sao os numeros ordenados:");
    for(i=0;i<tamanho; i++)
    {
        printf("%d , ", num[i]);
    }

    printf("\nTempo de execucao: %f segundos\n", tempo_gasto);

    free(count);
    return 0;
}