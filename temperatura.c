#include <stdio.h>
#include <stdlib.h>

double f_a_c(double a){

    return (a-32)*5/9;
}
int main (int argc, char *argv[]){
    int tipo= atoi(argv [1]);
    char uni= argv[2][0];
    double temp= atof(argv[3]);
    

    if(tipo==1){
        if (uni=='f'){
            double conv=f_a_c(temp);
            printf("temperatura en celsius: %.2f\n", conv);
                if(conv<35){
                    printf("tenes hipotermia!!!");
                }else if(conv>=35 && conv<=37.5){
                    printf("tenes temperatura normal");
                }else if (conv>37.5){
                    printf("tenes fiebre");
                }
            }else if(uni=='c'){
                if(temp<35){
                    printf("tenes hipotermia!!!");
                }else if(temp>35 && temp<=37.5){
                    printf("tenes temperatura normal");
                }else if (temp>37.5){
                    printf("tenes fiebre");
                }
            }
    }else if(tipo==0){
        if (uni=='f'){
            double conv2= f_a_c(temp);
            printf("temperatura en celsius: %.2f\n", conv2);
            if (conv2<10){
                printf("hace frio, abrigate!!!");
            }else if(conv2>=10 && conv2<25){
                printf("está re lindo, sali con una remera y short");
            }else if (conv2>25){
                printf("hace calor, anda a tomar un helado");
            }
            
        } else if(uni=='c'){
            if (temp<10){
                printf("hace frio, abrigate!!!");
            }else if(temp>=10 && temp<25){
                printf("esta re lindo, sali con una remera y short");
            }else if (temp>25){
                printf("hace calor, anda a tomar un helado");
            }
        }
    } 
   return 0; 
}