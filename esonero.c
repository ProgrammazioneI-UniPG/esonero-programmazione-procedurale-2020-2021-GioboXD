#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


int main(){
	char plainText[129]; // array per il plain text
	char plainText2[129]; // array per il plain text decriptato
	char TextE[129]; //testo criptato
	char Key[129]; // Chiave
	bool test = false; // flag per uscire dal cilclo principale (Ripetizione del menù)
	int scelta; // variabile per lo switch
	time_t t; //Registra il tempo attuale, serve per srand e rand
	bool testL=false; //Flag per cilco relativo al controllo della lunghezza
	int c; //Contatore utilizzato nei cicli for
	char f; 
	srand((unsigned) time(&t));
	
	printf("========================\n Hello User!\nThis Program allows you to encript \nand decript your message\n========================\n");
	
	while(test != true){
		printf("Choose:\n- 1 Type your plain message\n- 2 Type your Key\n- 3 Generate randomly a Key\n- 4 Encrypt your message\n- 5 Decrypt your message\n- 0 To exit\n"); //Menù
		scanf("%d", &scelta);
		while((f=getchar())!= '\n' && f != EOF); //Ciclo azzeramento buffer
		switch(scelta){
			case 0: //Caso uscita programma
				printf("=========================\n Bye Bye User!\n Hope to see you again ;)\n=========================\n");
				test=true;
				break;
			case 1: //Inserimento plain text
				printf("Type your string (MAX 128 char):\n");
				fgets(plainText,sizeof(plainText)+1,stdin);
				break;
			case 2: //Inserimento chiave personalizzata
				printf("Type your Key:\n");
				fgets(Key,129,stdin);
				while(testL != true){ 
					
					if((strlen(Key))>=(strlen(plainText))){ //Controllo lunghezza chiave non superiore al plain text
						printf("This is your Key:\n");
						puts(Key);
						testL=true;
					}else{
						printf("ERRORE Your Key is too short\n");
						printf("RETYPE YOUR KEY:\n");
						fgets(Key,sizeof(Key)+1,stdin);
					}
				}
				break;
			case 3:
				printf("Generating your Key\n"); //Generazione randomica della chiave
				for(int c=0; c<strlen(plainText); c++){
					Key[c]=rand() % (127)+32;
				}
				printf("This is your Key:\n");
				puts(Key);
				break;
			case 4:
				
				for(c=0; c<strlen(plainText); c++){ //Criptazione plain text
					TextE[c]=plainText[c]^Key[c];
				}
				printf("Your encripted string is: %s\n", TextE);
				break;
			case 5:
				for(c=0; c<strlen(plainText); c++){ //Decriptazione testo criptato
					plainText2[c]=TextE[c]^Key[c];
				}
				printf("Your decripted string is: %s\n", plainText2);
				break;
		}
	}
			
	return 0;
}