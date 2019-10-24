#include <stdio.h>
#include <math.h>

int main(){
	int i, j;
	double matriz_estendida[3][4]={{1, 0, -1, 0.2},
							 {-0.5, 1, -0.25, -1.425},
							 {1, -0.5, 1, 2}};
	double x[3]={0.5, 0.5, 0.5};
	double erro=5*1/100;
	double x_aux[4], distancia[4];
	double max, maior, dr;//dr teste de parada do teste de convergencia
	//primeira interação
	for(i=0;i<299;i++){
        if(i==0){
        x_aux[1]=(matriz_estendida[0][3]-(matriz_estendida[0][1]*x[1])-(matriz_estendida[0][2]*x[2]))/matriz_estendida[0][0];
        }
        else{
        x_aux[1]=(matriz_estendida[0][3]-(matriz_estendida[0][1]*x_aux[2])-(matriz_estendida[0][2]*x_aux[3]))/matriz_estendida[0][0];
        }
        x_aux[2]=(matriz_estendida[1][3]-(matriz_estendida[1][0]*x_aux[1])-(matriz_estendida[1][2]*x[2]))/matriz_estendida[1][1];
		x_aux[3]=(matriz_estendida[2][3]-(matriz_estendida[2][0]*x_aux[1])-(matriz_estendida[2][1]*x_aux[2]))/matriz_estendida[2][2];
		//printf("%lf %lf %lf\n", x_aux[1], x_aux[2], x_aux[3]);
		max=fabs(x_aux[1]);
		if(fabs(x_aux[2])>max){
			max=x_aux[2];
		}
		if(fabs(x_aux[3])>max){
			max=x_aux[3];
		}
		distancia[1]=fabs(x[0]-x_aux[1]);
		distancia[2]=fabs(x[1]-x_aux[2]);
		distancia[3]=fabs(x[2]-x_aux[3]);
		maior=distancia[1];
		if(distancia[2]>maior){
			maior=distancia[2];
		}
		if(distancia[3]>maior){
			maior=distancia[3];
		}
		dr=maior/max;

		if(dr<0.01){
			printf("solucao: %.2lf %.2lf %.2lf\n", x_aux[1], x_aux[2], x_aux[3]);
			printf("Numero de iteracao: %i", i+1);

			return 0;
		}
		else{
			x[0]=x_aux[1];
			x[1]=x_aux[2];
			x[2]=x_aux[3];

		}
	}
    printf("solucao: %lf %lf %lf\n", x_aux[1], x_aux[2], x_aux[3]);
    printf("Numero de iteracao: %i", i+1);
    return 0;

}
