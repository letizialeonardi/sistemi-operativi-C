#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#define PERM 0644


int main(int argc, char **argv){
	
	char buffer;
	/* int nread = 1; non usata */
	int n; /* variabile aggiunta */
	
	if(argc != 2){
		printf("Devo inserire esattamente un'opzione\n");
		exit(1);
	}
	
	if(argv[1][0] != '-'){
		printf("Devo inserire esattamente il parametro -n\n");
		exit(2);
	}
	/* dopo avere verificato che il parametro inizi per -, si deve fare la conversione e controllare che il risultato sia strettamente positivo! */
	n = atoi(&argv[1][1]);
	if (n <= 0)  
        {
                printf("Errore: l'opzione non e' corretta\n");
		exit (3);
	}
	int i = 0; 
	/* In generale e' sempre meglio fare un while esterno con la lettura */
	while (	read(0, &buffer, 1) )
	{	
		/* controlliamo se il carattere e' il terminatore di linea */
		if(buffer == '\n') i++; /* incrementiamo il contatore (a me sembrerebbe piu' chiaro inizializzarlo a 1, ma non ho voluto cambiare troppo la sua soluzione ...*/
		write(1, &buffer, 1); /* scriviamo comunque il carattere sia che sia \n o un altro carattere */
		/* ora dobbiamo controllare se dobbiamo uscire */
		if (i == n) break;
	/* while(i < atoi(&argv[1][1])){
		while(buffer != '\n'){	
			nread = read(0, &buffer, 1);
			if(buffer == '\n'){
				write(1, &buffer, 1);
			}
			else if(nread > 0){
				write(1, &buffer, 1);
			}
		}
		i+=1;
		buffer = ' '; nota bene: questo reset direi che in generale non sia mai necessario ... 
		*/
	}
	
	exit(0);	
}


