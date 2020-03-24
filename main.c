#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

int main(int argc, char *argv[]){
    int *p,filas=7,columnas=9,n=0;
	p=(int*)malloc(filas*columnas*sizeof(int));
	MenuPpl(filas,columnas,p,n);
	
	
	printf("\n\nsi retorno a main");
	getch();
	
	free(p);
	printf("\n\nmemoria liberada\n");
	getch();
  
    //system("PAUSE");	
    return 0;
}

void MenuPpl(int filas, int columnas, int *p, int n){ //menux=1
	int opc,NoValido=0;
	do{
		printf("5 EN LINEA\n\n");
		printf("1)score\n2)jugar\n3)salir\n\n");
		//printf("filas=%d\ncolumnas=%d\n\n",filas,columnas);
		if(NoValido!=0){
			printf("opcion no valida\n");
		}
		printf("ingrese opcion: ");
		scanf("%d",&opc);
		if(opc<1||opc>3){
			system("cls");
			NoValido=1;
		}
	}while(opc<1||opc>3);
	NoValido=0;
	if(opc==1||opc==2){
		opciones(1,opc,filas,columnas,p,n);
	}
}



void opciones(int menux, int opc, int filas, int columnas, int *p, int n){
	system("cls");
	if(menux==1){ //ppl
	
		if(opc==1){ //opc=score
			score(filas,columnas,p,n);
		}else if(opc==2){ //opc=jugar
			MenuJugar(filas,columnas,p,n);
		}else{
              
        }
	}else if(menux==2){ //MenuJugar
	
		if(opc==1){ //opc=dimensiones
			MenuDimensiones(filas,columnas,p,n);
		}else if(opc==2){ //opc=nivel
			MenuNivel(filas,columnas,p,n);
		}else if(opc==3){ //opc=jugar con pc
			juego(filas,columnas,p,n);
		}else if(opc==4){ //opc=jugador 1 vs jugador 2
			TwoPlayers(filas,columnas,p,n);
		}else{
			MenuPpl(filas,columnas,p,n);
		}
		
	}else if(menux==3){ //MenuDimensiones
        
		if(opc==1){ //opc=cambiar dimensiones
			//free(p);
			dimensiones(filas,columnas,p,n);
		}else{
			MenuJugar(filas,columnas,p,n);
		}
		
	}else if(menux==4){ //MenuNivel
          
        if(opc==1){ //opc==cambiar nivel
            nivel(filas,columnas,p,n);
        }else{
            MenuJugar(filas,columnas,p,n);
        }
              
    }
}

void llenarArchivo(int turno, int mod){
	FILE *fp;
	int user1,user2,pc1,pc2,player1_1,player1_2,player2_1,player2_2;
	
	
	fp=fopen("file.txt", "r");
	fscanf(fp,"%d" "%d" "%d" "%d" "%d" "%d" "%d" "%d",&user1, &user2, &pc1, &pc2, &player1_1, &player1_2, &player2_1, &player2_2);
	fclose(fp);
	
	if(mod==1){
		if(turno==1){
			user1++;
			pc2++;
		}else{
			user2++;
			pc1++;
		}
	}else{
		if(turno==1){
			player1_1++;
			player2_2++;
		}else{
			player1_2++;
			player2_1++;
		}
	}
	
	fp=fopen("file.txt", "w+");
	fprintf(fp,"%d " "%d " "%d " "%d " "%d " "%d " "%d " "%d ",user1, user2, pc1, pc2, player1_1, player1_2, player2_1, player2_2);
	fclose(fp);
}






void score(int filas, int columnas, int *p, int n){
	FILE *fp;
	int user1,user2,pc1,pc2,player1_1,player1_2,player2_1,player2_2;
	fp=fopen("file.txt", "r");
	fscanf(fp,"%d" "%d" "%d" "%d" "%d" "%d" "%d" "%d",&user1, &user2, &pc1, &pc2, &player1_1, &player1_2, &player2_1, &player2_2);
	fclose(fp);
	printf("SCORE\n\n");
	printf("USER vs. PC\n");
	printf("User:   \t\t%3d victorias\t%3d derrotas\n",user1, user2);
	printf("Pc:     \t\t%3d victorias\t%3d derrotas\n",pc1, pc2);
	printf("\nMULTIPLAYER\n");
	printf("Player1:\t\t%3d victorias\t%3d derrotas\n",player1_1, player1_2);
	printf("Player2:\t\t%3d victorias\t%3d derrotas\n",player2_1, player2_2);
	printf("\n\natras: ");
	getch();
	system("cls");
	MenuPpl(filas,columnas,p,n);
}



void MenuJugar(int filas, int columnas, int *p, int n){ //menux=2
	int opc,NoValido=0;
	do{
		printf("JUGAR\n\n");
		printf("1)dimensiones\n2)nivel\n3)jugar con pc\n4)jugador 1 vs jugador 2\n5)menu principal\n\n");
		//printf("filas=%d\ncolumnas=%d\n\n",filas,columnas);
		if(NoValido!=0){
			printf("opcion no valida\n");
		}
		printf("ingrese opcion: ");
		scanf("%d",&opc);
		if(opc<1||opc>5){
			system("cls");
			NoValido=1;
		}
	}while(opc<1||opc>5);
	NoValido=0;
	opciones(2,opc,filas,columnas,p,n);
}






void MenuDimensiones(int filas, int columnas, int *p, int n){ //menux=3
	int opc,NoValido=0;
	do{
		if(p==NULL){
			system("cls");
			printf("no hay suficiente memoria, por favor cambie por dimensiones menores");
			opciones(3,opc,filas,columnas,p,n);
		}
		printf("DIMENSIONES\n\n");
		printf("filas=%d\ncolumnas=%d\n\n",filas,columnas);
		printf("1)cambiar dimensiones\n2)atras\n\n");
		if(NoValido!=0){
			printf("opcion no valida\n");
		}
		printf("ingrese opcion: ");
		scanf("%d",&opc);
		if(opc<1||opc>2){
			system("cls");
			NoValido=1;
		}
	}while(opc<1||opc>2);
	NoValido=0;
	opciones(3,opc,filas,columnas,p,n);
}

void dimensiones(int filas, int columnas, int *p, int n){
	int NoValido=0;
	free(p);
	do{
		printf("DIMENSIONES\n\n");
		if(NoValido!=0){
			printf("numero de filas debe estar entre 5 y 20\n");
		}
		printf("ingrese numero de filas: ");
		scanf("%d",&filas);
		if(filas<5||filas>20){
				system("cls");
				NoValido=1;
		}
	}while(filas<5||filas>20);
	system("cls");
	NoValido=0;
	do{
		printf("DIMENSIONES\n\n");
		printf("filas=%d\n\n",filas);
		if(NoValido!=0){
			printf("numero de columnas debe estar entre 5 y 20\n");
		}
		printf("ingrese numero de columnas: ");
		scanf("%d",&columnas);
		if(columnas<5||columnas>20){
			system("cls");
			NoValido++;
		}
	}while(columnas<5||columnas>20);
	system("cls");
	NoValido=0;
	p=(int*)malloc(filas*columnas*sizeof(int));
	MenuDimensiones(filas,columnas,p,n);
}





void juego(int filas, int columnas, int *p, int n){
	int mod=1;
	int NoValido=0,i,j,f,c,count=0,nAux,pc,adios=0,win=0,turno=0;
    nAux=iniciarTab(filas,columnas,p,n);
    count=count+nAux;
	NoValido=0;
	
	do{
		
		do{
			
			if(count==(filas*columnas)){
                adios=1;
				break;
			}
			imprimir(filas,columnas,p,n,nAux);
			if(NoValido==1){
				printf("\nposicion no valida");
				f=c=0;
			}else if(NoValido==2){
				printf("\nposicion ya esta ocupada");
				f=c=0;
			}
			
			turno=1;
			printf("\ncoordenadas\n:");
			printf("fila: ");
			scanf("%d",&f);
			if(f==0){
				break;
			}
			printf("columna: ");
			scanf("%d",&c);
			if(c==0){
				break;
			}
			if(f<1||f>filas||c<1||c>columnas){
				system("cls");
				NoValido=1;
				continue;
		 	}
	 		if(*((p+(f*columnas)+c-columnas)-1)!=0){
                 NoValido=2;
 			     system("cls");
	 		}else{
 			      *((p+(f*columnas)+c-columnas)-1)=turno;
 			      NoValido=0;
            }
		}while(NoValido!=0);
		
		if(f==0||c==0){
			break;
		}
		
		
		
		win=ganar(filas,columnas,p,turno);
		if(win==1){
			break;
		}
		
		
		
		
		
		
		count++;
		if(count==(filas*columnas)||adios==1){
           break;
        }
		
		turno=2;
		pc=inteligencia(filas,columnas,p,n);
		*(p+pc)=turno;
		
		
		win=ganar(filas,columnas,p,turno);
		if(win==2){
			break;
		}

		count++;
		system("cls");
	}while(1);
	
	system("cls");
	if(f!=0&&c!=0){
			imprimir(filas,columnas,p,n,nAux);
			llenarArchivo(turno,mod);
			if(win==1){
				printf("\nhas ganado el juego");
			}else if(win==2){
				printf("\nhas perdido el juego");
			}
			
			getch();	
	}else{
		turno=2;
		llenarArchivo(turno,mod);
	}
	
	system("cls");
	
	MenuPpl(filas,columnas,p,n);
}


void imprimir(int filas, int columnas, int *p, int n, int nAux){
			int i,j;
			printf("JUEGO CON PC %dx%d  NIVEL: %d%%  OBSTACULOS: %d\n0=renunciar\n\n   ",filas,columnas,n,nAux);
			for(i=1;i<=columnas;i++){
				if(i<10){
					printf("%d ",i);
				}else{
					printf("%d",i);
				}
			}
			printf("\n");
			for(i=0;i<filas;i++){
				if(i<9){
					printf("%d ",i+1);
				}else{
					printf("%d",i+1);
				}
				for(j=0;j<columnas;j++){
					if(*(p+(i*columnas)+j)==0){
						printf("|%c",' ');
					}else if(*(p+(i*columnas)+j)==1){
						printf("|%c",'X');
					}else if(*(p+(i*columnas)+j)==2){
						printf("|%c",'O');
					}else if(*(p+(i*columnas)+j)==3){
						printf("|%c",'#');
					}
					if((j%columnas)==(columnas-1)){
						printf("|\n");
					}
				}
			}
}






void MenuNivel(int filas, int columnas, int *p, int n){
     int NoValido=0,opc;
     do{
        printf("NIVEL: %d%%\n\n",n);
        if(NoValido==1){
           printf("opcion no valida\n");
        }
        printf("1)cambiar nivel\n2)atras\n\ningrese opcion: ");
        scanf("%d",&opc);
        if(opc<1||opc>2){
           system("cls");
           NoValido=1;
        }
     }while(opc<1||opc>2);
     NoValido=0;
     opciones(4,opc,filas,columnas,p,n);
}

void nivel(int filas, int columnas, int *p, int n){
     int NoValido=0,temp;
     do{
        printf("NIVEL: %d%%\n\n",n);
        if(NoValido==1){
           printf("nivel debe estar entre 0%% y 50%%\n");
        }
        printf("ingrese nivel: ");
        scanf("%d",&temp);
        if(temp<0||temp>50){
           system("cls");
           NoValido=1;
        }
     }while(temp<0||temp>50);
     n=temp;
     system("cls");
     NoValido=0;
     MenuNivel(filas,columnas,p,n);
}


int iniciarTab(int filas, int columnas, int *p, int n){
     int obstaculo,nAux,i,NoValido;
     srand(time(NULL));
	 for(i=0;i<(filas*columnas);i++){
		*(p+i)=0;
	 }
	 nAux=(n*(filas*columnas))/100;
	 if(*(p+nAux)==0){
        for(i=0;i<nAux;i++){
           do{
              NoValido=1;
              obstaculo=rand()%(filas*columnas);
              if(*(p+obstaculo)==0){
                 *(p+obstaculo)=3;
                 NoValido=0;
              }
           }while(NoValido!=0);
        }
     }
     NoValido=0;
     return nAux;
     
     
     
}
     


void TwoPlayers(int filas, int columnas, int *p, int n){
	int mod=2;
    int NoValido=0,i,j,f,c,count=0,nAux,adios=0,win=0,turno=0;
    nAux=iniciarTab(filas,columnas,p,n);
    count=count+nAux;
	NoValido=0;
	
	do{
		
		do{
			
			if(count==(filas*columnas)){
                adios=1;
				break;
			}
			imprimir(filas,columnas,p,n,nAux);
			printf("\nPlayer 1");
			if(NoValido==1){
				printf("\nposicion no valida");
				f=c=0;
			}else if(NoValido==2){
				printf("\nposicion ya esta ocupada");
				f=c=0;
			}
			
			turno=1;
			printf("\ncoordenadas\n:");
			printf("fila: ");
			scanf("%d",&f);
			if(f==0){
				break;
			}
			printf("columna: ");
			scanf("%d",&c);
			if(c==0){
				break;
			}
			if(f<1||f>filas||c<1||c>columnas){
				system("cls");
				NoValido=1;
				continue;
		 	}
	 		if(*((p+(f*columnas)+c-columnas)-1)!=0){
                 NoValido=2;
 			     system("cls");
	 		}else{
 			      *((p+(f*columnas)+c-columnas)-1)=turno;
 			      NoValido=0;
            }
		}while(NoValido!=0);
		
		if(f==0||c==0){
			break;
		}
		
		
		win=ganar(filas,columnas,p,turno);
		if(win==1){
			break;
		}
		
		
		count++;
		if(count==(filas*columnas)||adios==1){
           break;
        }
        
        
		
        
        system("cls");
        do{
			imprimir(filas,columnas,p,n,nAux);
			printf("\nPlayer 2");
			if(NoValido==1){
				printf("\nposicion no valida");
				f=c=0;
			}else if(NoValido==2){
				printf("\nposicion ya esta ocupada");
				f=c=0;
			}
			
			turno=2;
			printf("\ncoordenadas\n:");
			printf("fila: ");
			scanf("%d",&f);
			if(f==0){
				break;
			}
			printf("columna: ");
			scanf("%d",&c);
			if(c==0){
				break;
			}
			if(f<1||f>filas||c<1||c>columnas){
				system("cls");
				NoValido=1;
				continue;
		 	}
	 		if(*((p+(f*columnas)+c-columnas)-1)!=0){
                 NoValido=2;
 			     system("cls");
	 		}else{
 			      *((p+(f*columnas)+c-columnas)-1)=turno;
 			      NoValido=0;
            }
        }while(NoValido!=0);
        
        if(f==0||c==0){
			break;
		}
		
		win=ganar(filas,columnas,p,turno);
		if(win==2){
			break;
		}
		
		
        count++;
		
		system("cls");
	}while(1);
	system("cls");
	if(f!=0&&c!=0&&win!=0){
			imprimir(filas,columnas,p,n,nAux);
			llenarArchivo(turno,mod);
			if(win==1){
				printf("\nEl Jugador %d ha ganado el juego",win);
			}else if(win==2){
				printf("\nEl Jugador %d ha ganado el juego",win);
			}
			
			getch();	
	}else{
		if(turno==1){
			turno=2;
			llenarArchivo(turno,mod);
			MenuPpl(filas,columnas,p,n);
		}else{
			turno=1;
			llenarArchivo(turno,mod);
		}		
	}
	
	system("cls");
	
	MenuPpl(filas,columnas,p,n);     
}




int ganar(int filas, int columnas, int *p, int turno){
	int i,j,count=0,aux=1;
	
	//horizontal (-)
	for(i=0;i<(filas*columnas);i++){
		
		
		if(i==((columnas*aux)-1)){
			aux++;
		}
		if((i%(columnas*aux))==((columnas*aux)-5)){
			if(*(p+i)==0||*(p+i)==3||*(p+i)!=*(p+i+1)){
				i=i+5;
			}
		}
		if(*(p+i)==0||*(p+i)==3){
			continue;
		}
		
		
		if(*(p+i)==*(p+i+1)){
			count++;
		}else{
			count=0;
		}
		
		if(count==4){
			return turno;
		}
	}
	
	//vertical (|)
	count=0;
	for(i=0;i<(filas*(columnas-1));i++){
		
		if(*(p+i)==0||*(p+i)==3){
			continue;
		}
		
		for(j=1;j<5;j++){
			if(*(p+i)==*(p+i+(columnas*j))){
				count++;
			}else{
				count=0;
				break;
			}
		}
		
		if(count==4){
			return turno;
		}
	}
	
	//diagonal (\)
	aux=1;
	count=0;
	for(i=0;i<(filas*(columnas-1));i++){
		
		
		if(i==((columnas*aux)-1)){
			aux++;
		}
		if((i%(columnas*aux))==((columnas*aux)-5)){
			if(*(p+i)==0||*(p+i)==3||*(p+i)!=*(p+i+1+columnas)){
				i=i+5;
			}
		}
		if(*(p+i)==0||*(p+i)==3){
			continue;
		}
		
		
		for(j=1;j<5;j++){
			if(*(p+i)==*(p+i+(columnas*j)+j)){
				count++;
			}else{
				count=0;
				break;
			}
		}
		
		if(count==4){
			return turno;
		}
	}
	
	//diagonal (/)
	count=0;
	for(i=0;i<(filas*(columnas-1));i++){
		
		if(*(p+i)==0||*(p+i)==3){
			continue;
		}
		
		for(j=1;j<5;j++){
			if(*(p+i)==*(p+i+(columnas*j)-j)){
				count++;
			}else{
				count=0;
				break;
			}
		}
		
		if(count==4){
			return turno;
		}
	}
	
	return 0;
		
}






int inteligencia(int filas, int columnas, int *p, int n){
	int pc,i;
	srand(time(NULL));
	
	do{
		
		for(i=0;i<(filas*columnas);i++){
			if(*(p+i)==2&&*(p+i+1)==0){
            	pc=i+1;
            	return pc;
        	}
		}
		pc=rand()%(filas*columnas);
		if(*(p+pc)==0){
            return pc;
        }
	}while(1);
	
	
	
	
	
	
	
}







