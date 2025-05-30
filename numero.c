#include <stdio.h>
#include <stdlib.h>

// nesse codigo ira ser usado o calloc inves de malloc pq o calloc pode servir como uma especie de contador 
void main()
{
    //numeros que serão ordenados 
int num[]={1,3,48,78,9,0,9,23,67,1,2,55,6,4,5,56,78,12,23,4,5,7,98,76,45,11,10,16,7,3,6,16,26,56,45,89,100,34,54,789,232,14,177,676,890,900,786,123432,67654,898,99,767,56,55,790,8,879,988,1008,787};

int tamanho= sizeof(num)/sizeof(num[0]);
int i,f= 0;
int nmaior= num[0];

//ver qual é o numero maior do array 
for(i=0;i<=tamanho;i++)
{
   if(num[i]>nmaior) nmaior=num[i];
}

int *count = (int *)calloc(nmaior+1, sizeof(int));
//essa liha cria um vetor que a locação de memoria e o vetor começa em 0

for(i=0;i<tamanho;i++)
{
    count[num[i]]++;
}


// faz o array dnv só que na ordem certa
for(i=0; i<= nmaior;i++)
{
    while(count[i]-- >0)
    {
        num[f++]=i;
    }
}

 printf("Esses sao os numeros ordenados:");
for(i=0;i<tamanho; i++)
{
    printf("%d , ", num[i]);
}

free(count); // liberando a memoria que foi ocupada 
return 0;
}