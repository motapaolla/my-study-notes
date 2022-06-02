#include <stdio.h>
#include <stdlib.h>
 
#define MAX 100001
 
int main() {
 
    int i;
    long long int a[MAX];
    long long int t, soma;
     
    while(1){
        scanf("%lld",&t);
        if ( t == 0 ) {
            break;
        }
         
        for(i = 0; i < t; i++){
            scanf("%lld",&a[i]);
        }
         
        soma = 0;
        for (i = 1; i < t; i++){
             
            if(a[i-1] < 0){
                soma = (-1)*(a[i-1]) + soma;
            }else{
                soma = soma + a[i-1];
            }
            a[i] = a[i] + a[i-1];
             
        }
        printf("%lld\n",soma);
    }
     
    return 0;
}