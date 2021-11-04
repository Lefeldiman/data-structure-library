/* 
 * File:   main.c
 * Author: root
 *
 * Created on November 5, 2013, 2:40 PM
 */

#include <stdio.h>
#include <stdlib.h>

int fatorialIterativo(long long int num);
int fatorialRecursivo(long long int n);

int main()
{ 
    long long int n, res;
    printf("Digite um numero ...: ");
    scanf("%lld",&n);
    
    res = fatorialIterativo(n);
    printf("\nO fatorial de %lld Iterativo ...: %lld ",n,res);
    printf("\n")
    getchar();
    res = fatorialRecursivo(n);
    printf("\nO fatorial de %lld Recursivo ...: %lld ",n,res);
    getchar();
    return 0;
}

int fatorialIterativo(long long int num){ 
    int produto = 1, i;
    for(i = num; i>0; i--)
       produto *= i;         
    return produto;
}

int fatorialRecursivo(long long int n){
    if(n==0)
        return (1);
    return (n*fatorialRecursivo(n-1));
}