#include <stdio.h>
#include <stdlib.h>

int main(){
	int tam = 5;
	char matrixcpu[tam][tam];
	char matrixplayer[tam][tam];
	int i, j, r, valor, cpurow, cpucol, row, col;
	int hpplayer = 3;
	int hpcpu = 3;
	int turno = 1;
	srand(time(NULL));   
	
	for (i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			r = rand(); 
			valor = (r % 10) + 1;	
				if (valor<8){
					matrixcpu[i][j]='_';
				}else{
					matrixcpu[i][j]='*';
				}
			}
		}
	
	for (i=0;i<tam;i++){
		for(j=0;j<tam;j++){
				if (matrixcpu[i][j]=='*'){
					printf("%c \t",'_');
				}else{
				printf("%c \t",matrixcpu[i][j]);	
				}
		}
		printf("\n");
	}
	
	printf("===================================================\n");
	
	for (i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			r = rand(); 
			valor = (r % 10) + 1;	
				if (valor<8){
					matrixplayer[i][j]='_';
				}else{
					matrixplayer[i][j]='*';
				}
			}
		}
	
	
	for (i=0;i<tam;i++){
		for(j=0;j<tam;j++){
				printf("%c \t",matrixplayer[i][j]);	
		}
		printf("\n");
	}

	while(hpplayer!=0||hpcpu!=0){
		printf("\n");
		printf("Turno %d\n",turno);
		r = rand();
		cpurow = (r % tam) + 1;
		
		r = rand();
		cpucol = (r % tam) + 1;
		
		printf("Elige un numero de fila para atacar\n");
		scanf("%d",&row);
		
		printf("Elige un numero de columna para atacar\n");
		scanf("%d",&col);
		
		if(matrixplayer[cpurow][cpucol]=='*'){
			hpplayer--;
			matrixplayer[cpurow][cpucol]='1';
		}else{
			matrixplayer[cpurow][cpucol]='0';
		}
		
		if(matrixcpu[row-1][col-1]=='*'){
			hpcpu--;
			matrixcpu[row-1][col-1]='1';
		}else{
			matrixcpu[row-1][col-1]='0';
		}
		
		for (i=0;i<tam;i++){
			for(j=0;j<tam;j++){
					if (matrixcpu[i][j]=='*'){
						printf("%c \t",'_');
					}else{
					printf("%c \t",matrixcpu[i][j]);	
					}
			}
			printf("\n");
		}	
		
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	
		for (i=0;i<tam;i++){
			for(j=0;j<tam;j++){
				printf("%c \t",matrixplayer[i][j]);	
			}
			printf("\n");
		}
		
		printf("El cpu escogio %d para la fila y %d para la columna\n",cpucol,cpurow);
		
		printf("Te quedan %d vidas\n", hpplayer);
		printf("Al cpu le quedan %d vidas\n", hpcpu);
		
		if(hpplayer==0){
			printf("GANO EL CPU\n");
			return 0;
		}
		
		if(hpcpu==0){
			printf("GANASTE!\n");
			return 0;
		}		
		
		turno++;
	}

	return 0;	
}
