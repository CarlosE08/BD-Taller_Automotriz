#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Carlos Roberto Escobar Ibarra 217640968

struct autos{
    char nombre[100], t_a[100], marca[100], fail[100];
	int placa, modelo, serv, ID, cos;
	struct rep{
		char fail[100];
		int ID, cos;
	}man[100];
}au[100];

int main()
{
    int cant,i,opc,band, placa, t_a, c, aux=0, p, a, j;
    char nombre[25],resp;
    resp ='s';
    
    while(resp=='s' || resp=='S'){
	    system("CLS");
	    printf("Bienvenido!...\n");
	    printf("1.-Agregar auto\n");
	    printf("2.-Consultar auto\n");
	    printf("3.-Modificar auto\n");
	    printf("4.-Eliminar auto\n");
	    printf("5.-Taller automotriz\n");
	    printf("6.-Reporte total de automotores\n");
	    printf("7.-Salir\n");
	    printf("Elegir opcion: \n");
	    scanf("%d",&opc);
	
	    switch(opc)
	    {
	    case 1:
	        do{
	        	system("CLS");
	    		printf("Agregar un auto en la BD\n");
	            while (1){
	            	printf("\nIngresa la placa del auto %d a agregar\n", aux+1);
	            	scanf("%d", &placa);
					if (au[i].placa==placa || placa < 1000000 || placa > 9999999){
	            		printf("\nPlaca ya en la BD, o con una cifra diferente\n");
	            		printf("Intenta de nuevo\n");
						}
	            	else break;
				}
	            au[aux].placa = placa;
	            printf("Ingresa nombre\n");
	            fflush(stdin);
	            scanf("%s",&au[aux].nombre);
		        printf("Teclea el tipo de auto: 1)Sedan, 2)Cupe, ");
		        printf("3)Hatchback, 4)Sport, 5)Pick-up, 6)Crossover\n");
		        fflush(stdin);
	            scanf("%s",&au[aux].t_a);
		        printf("Ingresa la marca\n");
		        fflush(stdin);
	            scanf("%s",&au[aux].marca);
	            printf("Ingresa el modelo\n");
	            scanf("%d",&au[aux].modelo);
	            au[aux].serv = 0;
		        aux++;
				printf("\n\nDeseas realizar agregar a otro auto? 1)Si o 2)No\n");
	    		scanf("%d",&c);
			}while (c == 1);
	    break;
	    case 2:
	    	do{
	    		system("CLS");
	    		printf("Consulta de un auto en la BD\n");
		    	band = 0;
		        printf("\nIngresa la placa del auto\n");
		        scanf("%d", &placa);
		        for(i=0;i<aux+1;i++){
		        	while (1){
						if (placa < 1000000 || placa > 9999999){
		            		printf("\nLa placa cuenta con una cifra diferente\n");
		            		printf("Intenta de nuevo\n");
		            		scanf("%d", &placa);
							}
		            	else break;
					}
		        	if (placa == au[i].placa){
		            	if (au[i].serv == 1){
			         		if(strcmpi(au[i].nombre,"*")!=0){
				                	printf("\n\n*Auto %d* \nPlaca: %d \nNombre: %s", i+1,au[i].placa,au[i].nombre);
				                	printf("\nTipo: %s \nMarca %s \nModelo: %d ",au[i].t_a,au[i].marca,au[i].modelo);
				                	printf("\nID de serv: %d \nFalla/Manten: %s \nCosto del serv: $%d \n",au[i].ID, au[i].fail, au[i].cos);}
						}
						else {
								printf("\n\n*Auto %d* \nPlaca: %d \nNombre: %s", i+1,au[i].placa,au[i].nombre);
				                printf("\nTipo: %s \nMarca %s \nModelo: %d \n",au[i].t_a,au[i].marca,au[i].modelo);}
				        band++;        
					}
				}
				if (band == 0) printf("No existe el auto en la BD\n");	
				printf("\n\nDesea consultar otro auto? 1)Si o 2)No\n");
	    		scanf("%d",&c);
			}while (c == 1);
	    break;
	    case 3:
	    	do{
	    		band = 0;
	    		system("CLS");
	    		printf("Modificar un auto de la BD\n");band = 0;
		        printf("\nIngresa la placa del auto\n");
		        scanf("%d", &placa);
		        for(i=0;i<aux+1;i++){
		        	while (1){
						if (placa < 1000000 || placa > 9999999){
		            		printf("\nLa placa cuenta con una cifra diferente\n");
		            		printf("Intenta de nuevo\n");
		            		scanf("%d", &placa);
							}
		            	else break;
					}
		        	if (placa == au[i].placa){
		            		if(strcmpi(au[i].nombre,"*")!=0){
		            			printf("\n\n*Auto %d* \nPlaca: %d \nNombre: %s", i+1,au[i].placa,au[i].nombre);
		                		printf("\nTipo: %s \nMarca %s \nModelo: %d \n",au[i].t_a,au[i].marca,au[i].modelo);
		                		printf("\nEstas seguro de modificar? 1)Si 2)No \n");
		                		scanf("%d",&c);
		                		if (c == 1){
		                			printf("Ingresa nuevo nombre\n");
						            fflush(stdin);
						            scanf("%s",&au[i].nombre);
							        printf("Teclea el tipo de auto: 1)Sedan, 2)Cupe, ");
							        printf("3)Hatchback, 4)Sport, 5)Pick-up, 6)Crossover\n");
							        fflush(stdin);
						            scanf("%s",&au[i].t_a);
							        printf("Ingresa la marca\n");
							        fflush(stdin);
						            scanf("%s",&au[i].marca);
						            printf("Ingresa el modelo\n");
						            scanf("%d",&au[i].modelo);
								}
		                		band++;}
					}
				}
				if (band == 0) printf("\nNo existe el auto en la BD\n");	
				printf("\n\nDesea modificar datos de otro auto? 1)Si o 2)No\n");
	    		scanf("%d",&c);
			}while (c == 1);
	    break;
	    case 4:
	    	do{
	    		band = 0;
	    		system("CLS");
	    		printf("Eliminar un auto de la BD\n");band = 0;
		        printf("\nIngresa la placa del auto\n");
		        scanf("%d", &placa);
		        for(i=0;i<aux+1;i++){
		        	while (1){
						if (placa < 1000000 || placa > 9999999){
		            		printf("\nLa placa cuenta con una cifra diferente\n");
		            		printf("Intenta de nuevo\n");
		            		scanf("%d", &placa);
							}
		            	else break;
					}
					if (placa == au[i].placa){
						band++;
						printf("\n\n*Auto %d* \nPlaca: %d \nNombre: %s", i+1,au[i].placa,au[i].nombre);
		                printf("\nTipo: %s \nMarca %s \nModelo: %d \n",au[i].t_a,au[i].marca,au[i].modelo);
		                printf("\nEstas seguro de eliminar? 1)Si 2)No \n");
		                scanf("%d",&c);
		                if (c == 1){
		                	strcpy(au[i].nombre,"*");
	                    	printf("\nSe ha eliminado\n");}
						else printf("\nNo se ha eliminado\n");		
					}
				}
				if (band == 0) printf("\nNo existe el auto en la BD\n");
				printf("\n\nDesea eliminar otro auto? 1)Si o 2)No\n");
	    		scanf("%d",&c);
			}while (c == 1);
		break;	
		case 5:
			do{
	    		band = 0;
	    		system("CLS");
	    		printf("Taller automotriz\n");band = 0;
		        printf("\nIngresa la placa del auto\n");
		        scanf("%d", &placa);
		        for(i=0;i<aux+1;i++){
		        	while (1){
						if (placa < 1000000 || placa > 9999999){
		            		printf("\nLa placa cuenta con una cifra diferente\n");
		            		printf("Intenta de nuevo\n");
		            		scanf("%d", &placa);
							}
		            	else break;
					}
					if (placa == au[i].placa){
						printf("\n\n*Auto %d* \nPlaca: %d \nNombre: %s", i+1,au[i].placa,au[i].nombre);
		                printf("\nTipo: %s \nMarca %s \nModelo: %d \n\n",au[i].t_a,au[i].marca,au[i].modelo);
		                au[i].man[au[i].serv].ID=au[i].serv+1;
			            printf("\nID de serv: %d\n", au[i].man[au[i].serv].ID);
			            printf("\nIngresa la falla a reparar\n");
			            fflush(stdin);
			            gets(au[i].man[au[i].serv].fail);
			            printf("\nIngresa el costo de sevicio\n$");
			            scanf("%d", &au[i].man[au[i].serv].cos);
			            system("CLS");
		                printf("*Auto %d*", i+1);
		                printf("\nFallas a areglar: %d \n",au[i].serv+1);
		                au[i].serv++;	
						printf("\nSe ha a%canido para mantenimiento\n", 164);
						band++;
					}
				}
				if (band == 0) printf("\nNo existe el auto en la BD\n");
				printf("\n\nDeseas realizar mantenimiento a otro auto? 1)Si o 2)No\n");
	    		scanf("%d",&c);
			}while (c == 1);	
		break;	
		case 6:
	         for(i=0;i<aux;i++){
	         
					if(strcmpi(au[i].nombre,"*")!=0){
						printf("\n\n*Auto %d* \nPlaca: %d \nNombre: %s", i+1,au[i].placa,au[i].nombre);
		                printf("\nTipo: %s \nMarca %s \nModelo: %d",au[i].t_a,au[i].marca,au[i].modelo);
		                printf("\nFallas a areglar: %d \n",au[i].serv);
						if (au[i].serv >= 1){
							for(j=0;j<au[i].serv;j++){
		                		printf("\n*ID de serv %d*",au[i].man[j].ID);
								printf("\nFalla/Manten: %s \nCosto del serv: $%d \n",au[i].man[j].fail,au[i].man[j].cos);							
							}
						}
					}
				
			}
	    break;
	    case 7:
	    	resp ='n';
	    break;
	    default:
	        printf("La opcion ingresada no existe\n");
	    }
	    if (opc != 7){
	    	printf("\n\nDesea realizar otra operacion s(Si) o n(No)\n");
	    	fflush(stdin);
	    	scanf("%c",&resp);
		}
    }
    
    printf("\n\nQue tengas un buen d%ca!! :)\n", 161);

    return 0;
}
