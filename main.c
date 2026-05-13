#include <stdio.h>  
#include <math.h>   


int main() {
	
	double z = -15.0;
	double N0 = 1.0;
	double Z0_halo = 5.0;
	double Z0_disco = 0.2;
	
    // Fórmula
    //double n_z = N0 * exp(-fabs(z) / Z0_halo);
    
    printf("Modelo exponencial de densidade\n");
    
    //Arquivo do halo
    FILE *arquivo1; 
    arquivo1 = fopen("dados_densidade_halo.txt", "w");
    
    if (arquivo1 != NULL) {
    	
    	printf("Z	Densidade N(z))\n");
    	for (z = -15.0; z <= 15.0; z += 0.01) {
		    double densidade = N0 * exp(-fabs(z) / Z0_halo);
		    printf("%f %f\n", z, densidade);
		    fprintf(arquivo1, "%f\t%f\n", z, densidade);
		}
		fclose(arquivo1);
        printf("Arquivo 'dados_densidade_halo.txt' gerado com sucesso!\n");
		
	} else {
        printf("Erro ao criar o arquivo de dados.\n");
    }
    
    printf("--------------------------------------------\n\n");
    
    // Arquivo do disco
    FILE *arquivo; 
    arquivo = fopen("dados_densidade_disco.txt", "w");
    
    if (arquivo != NULL) {
    	
    	printf("Z	Densidade N(z))\n");
    	for (z = -15.0; z <= 15.0; z += 0.01) {
		    double densidade = N0 * exp(-fabs(z) / Z0_disco);
		    printf("%f %f\n", z, densidade);
		    fprintf(arquivo, "%f\t%f\n", z, densidade);
		}
		fclose(arquivo);
        printf("Arquivo 'dados_densidade_disco.txt' gerado com sucesso!\n");
		
     	
	} else {
        printf("Erro ao criar o arquivo de dados.\n");
    }
    return 0; 
	
	
}
