#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int opcCadastro; // variavel que recebe a opção para login ou cadastro
char cadastrousuario[10]; // variavel para receber o nome de usuario no cadastro
char cadastrosenha[10]; // variavel para receber a senha no cadastro
char loginusuario[10]; // variavel para receber o nome de usuario no login
char loginsenha [10]; // variavel para receber a senha no login
char linhacadastro [100]; //variavél para leitura do arquivo
int selecionarOpcao; // Variavel para selecionar opcao dentro do menu
int selecionarDificuldade; // Variavel para selecionar a dificuldade do jogo
int pontuacaomaxima = 0, pontos = 0,pontospc = 0, jog = 0;
int pontuacaousuario = 0, pontuacaopc = 0;
char salvarpontos[20];
char rankingfacil [100];
char rankingmedio [100];
char rankingdificil [100];
char matriz10Usuario[10][10];
int matriz10Barcos[10][10];
char matriz10PC [10][10];
int matriz10BarcosPC [10][10];

void titulobatalha(){ //função com o nome do jogo utilizada no inicio e no menu principal

		printf("\t.########.....###....########....###....##.......##.....##....###....\n");
		printf("\t.##.....##...##.##......##......##.##...##.......##.....##...##.##...\n");
		printf("\t.##.....##..##...##.....##.....##...##..##.......##.....##..##...##..\n");
		printf("\t.########..##.....##....##....##.....##.##.......#########.##.....##.\n");
		printf("\t.##.....##.#########....##....#########.##.......##.....##.#########.\n");
		printf("\t.##.....##.##.....##....##....##.....##.##.......##.....##.##.....##.\n");
		printf("\t.########..##.....##....##....##.....##.########.##.....##.##.....##.\n");
		printf("\t.....................................................................\n");
		printf("\t..........##....##....###....##.....##....###....##..................\n");
		printf("\t..........###...##...##.##...##.....##...##.##...##..................\n");
		printf("\t..........####..##..##...##..##.....##..##...##..##..................\n");
		printf("\t..........##.##.##.##.....##.##.....##.##.....##.##..................\n");
		printf("\t..........##..####.#########..##...##..#########.##..................\n");
		printf("\t..........##...###.##.....##...##.##...##.....##.##..................\n");
		printf("\t..........##....##.##.....##....###....##.....##.########............\n\n\n");

	}
	 	
void teladecadastro(){ //função para realizar o cadastro de jogadores

	char linhacadastro[100];
	int verificacao = 1;
	int idade;
	while (verificacao == 1) {
		while(idade < 5){
		
		    system("cls");
			printf("\t\t\t..######.....###....########.....###.....######..########.########...#######.\n");
			printf("\t\t\t.##....##...##.##...##.....##...##.##...##....##....##....##.....##.##.....##\n");
			printf("\t\t\t.##........##...##..##.....##..##...##..##..........##....##.....##.##.....##\n");
			printf("\t\t\t.##.......##.....##.##.....##.##.....##..######.....##....########..##.....##\n");
			printf("\t\t\t.##.......#########.##.....##.#########.......##....##....##...##...##.....##\n");
			printf("\t\t\t.##....##.##.....##.##.....##.##.....##.##....##....##....##....##..##.....##\n");
			printf("\t\t\t..######..##.....##.########..##.....##..######.....##....##.....##..#######.\n");
			printf("\n");
			printf("Digite a sua idade: (Idade minima para jogar: 5 anos)");
			scanf("%d",&idade);
			if(idade < 5){
				printf("Infelizmente a sua idade não corresponde à classificação indicativa :(\n");
				system("pause");
			}
		}
        printf("Digite um nome de usuário: ");
        scanf("%s", cadastrousuario);
        FILE *arquivo;
        arquivo = fopen("teladecadastro.txt", "r");
        if (arquivo == NULL) { // se for o primeiro cadastro, não é feita a rerificação
            verificacao = 0;
		}else{ // se o arquivo ja possuir cadastros, verifica se ha um nome de usuario igual ja cadastrado
		
	        while (fgets(linhacadastro,100, arquivo)) {
	            if (strstr(linhacadastro, cadastrousuario) != NULL) {
	                printf("Nome de usuário já utilizado, tente outro.\n");
	                system("pause");
	                verificacao = 1;
	                fclose(arquivo);
	            }else{
	            	verificacao = 0;
				}
	        }
		fclose(arquivo);
		}
    }	
    while(strlen(cadastrosenha) < 6){
		
    printf("Digite uma senha: (Minimo 6 digitos)");
    scanf("%s", cadastrosenha);
	    if(strlen(cadastrosenha) < 6){
	     	printf("A senha deve conter no minimo 6 digitos\n");
		}
        
   	}
   	
	FILE* arquivo;
	arquivo = fopen("teladecadastro.txt", "a");
	fprintf(arquivo,"%s ",cadastrousuario);
	fprintf(arquivo,"%s",cadastrosenha);
	fprintf(arquivo,"\n");
	fclose(arquivo);
}
		
void teladelogin(){ // função para realizar o login de jogadores
	char verificausuario[50];
	char verificasenha[50];
	int verificacao = 0;
	while(verificacao == 0){
	
		//teladelogin:
		system("cls");
		printf("\t\t\t.##........#######...######...####.##....##\n");
		printf("\t\t\t.##.......##.....##.##....##...##..###...##\n");
		printf("\t\t\t.##.......##.....##.##.........##..####..##\n");
		printf("\t\t\t.##.......##.....##.##...####..##..##.##.##\n");
		printf("\t\t\t.##.......##.....##.##....##...##..##..####\n");
		printf("\t\t\t.##.......##.....##.##....##...##..##...###\n");
		printf("\t\t\t.########..#######...######...####.##....##\n");
		printf("\n\n");
		FILE* arquivo;
		arquivo = fopen("teladecadastro.txt", "r");
		printf("Digite um nome de usuario\n");
		scanf("%s",loginusuario);
		printf("Digite uma senha\n");
		scanf("%s",loginsenha);
		
			while (fgets(linhacadastro,100, arquivo)) {
				sscanf(linhacadastro, "%s %s", verificausuario, verificasenha);
		      	if (strcmp(verificausuario, loginusuario) == 0 && strcmp(verificasenha, loginsenha) == 0) { // verifica se o login esta no arquivo
		         	printf("Login permitido\n"); // Caso os dados estejam certos o login é permitido
					verificacao = 1;
				} 
			}	
			if(verificacao == 0){
			    printf("Usuario ou senha incorretos\n"); // Caso os dados estejam errados o login não  é permitido
			    system("pause");
			}
		fclose(arquivo);
	}
}

void menu(){ // função com as opções do menu do jogo
	telaInicial:
	printf("\t\t\t  #    # ###### #    # #    # \n");
	printf("\t\t\t  ##  ## #      ##   # #    # \n");
	printf("\t\t\t  # ## # #####  # #  # #    # \n");
	printf("\t\t\t  #    # #      #  # # #    # \n");
	printf("\t\t\t  #    # #      #   ## #    # \n");
	printf("\t\t\t  #    # ###### #    #  ####  \n\n");
						
	printf("\t\t\t1 - Jogar\n"); // para começar o jogo
	printf("\t\t\t2 - Mudar a cor tema do jogo\n"); // para mudar o tema do jogo
	printf("\t\t\t3 - Ranking de jogadores\n"); // para ver o ranking de jogadores
	printf("\t\t\t4 - Instruções de como jogar\n");
	printf("\t\t\tEscolha uma opção:\n");
}

void selecionardificuldade(){ // função com as opções dentro do menu jogo
				
	printf("................##....##.####.##.....##.########.##..........########..########.................\n");              
	printf("................###...##..##..##.....##.##.......##..........##.....##.##.......................\n");          
	printf("................####..##..##..##.....##.##.......##..........##.....##.##.......................\n");
	printf("................##.##.##..##..##.....##.######...##..........##.....##.######...................\n");
	printf("................##..####..##...##...##..##.......##..........##.....##.##.......................\n");
	printf("................##...###..##....##.##...##.......##..........##.....##.##.......................\n"); 
	printf("................##....##.####....###....########.########....########..########.................\n");
	printf("................................................................................................\n");
	printf(".########..####.########.####..######..##.....##.##.......########.....###....########..########\n");
	printf(".##.....##..##..##........##..##....##.##.....##.##.......##.....##...##.##...##.....##.##......\n");
	printf(".##.....##..##..##........##..##.......##.....##.##.......##.....##..##...##..##.....##.##......\n");
	printf(".##.....##..##..######....##..##.......##.....##.##.......##.....##.##.....##.##.....##.######..\n");
	printf(".##.....##..##..##........##..##.......##.....##.##.......##.....##.#########.##.....##.##......\n");
	printf(".##.....##..##..##........##..##....##.##.....##.##.......##.....##.##.....##.##.....##.##......\n");
	printf(".########..####.##.......####..######...#######..########.########..##.....##.########..########\n");
	printf("\n");
	printf("\n");
	printf("Selecione a opção de jogo:\n\n");
	printf("1 - Nivel de dificuldade -> Fácil -> 12 embarcações\n");
	printf("2 - Nivel de dificuldade -> Médio -> 9 embarcações\n");
	printf("3 - Nivel de dificuldade -> Dificil -> 6 embarcações\n");
	printf("4 - Retomar jogo salvo\n");
	printf("5 - Voltar\n");
}

void pausa(){ // função que exibe a mensagem de jogo pausado
	printf(".########.....###....##.....##..######.....###....########...#######.\n");
    printf(".##.....##...##.##...##.....##.##....##...##.##...##.....##.##.....##\n");
    printf(".##.....##..##...##..##.....##.##........##...##..##.....##.##.....##\n");
    printf(".########..##.....##.##.....##..######..##.....##.##.....##.##.....##\n");
    printf(".##........#########.##.....##.......##.#########.##.....##.##.....##\n");
    printf(".##........##.....##.##.....##.##....##.##.....##.##.....##.##.....##\n");
    printf(".##........##.....##..#######...######..##.....##.########...#######.\n");
}

void salvarmatrizes(int matrizUsuario[10][10], int matrizPC[10][10], char matrizcharusuario[10][10], char matrizcharpc[10][10]) { 
//armazena as matrizes dentro do arquivo de texto
    int i, j;
    char nomearquivo[50];
    strcpy(nomearquivo, loginusuario);
    FILE *file;
    
    file = fopen(strcat(nomearquivo,".txt"), "w");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            fprintf(file, "%d ", matrizUsuario[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            fprintf(file, "%d ", matrizPC[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            fprintf(file, "%c ", matrizcharusuario[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            fprintf(file, "%c ", matrizcharpc[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    fclose(file);
}

void recebe(int matrizUsuario[10][10], int matrizPC[10][10], char matrizcharusuario[10][10], char matrizcharpc[10][10]){
// recebe as matrizes do arquivo txt para o jogo
	int i,j;
	char nomearquivo[50];
	strcpy(nomearquivo,loginusuario);
	FILE *file;
	file = fopen(strcat(nomearquivo,".txt"), "r");
		//rewind(file);
		
	    for (i = 0; i < 10; i++) {
	       for (j = 0; j < 10; j++) {
	            fscanf(file, "%d", &matrizUsuario[i][j]);
	        }
	    }
	    for (i = 0; i < 10; i++) {
           for (j = 0; j < 10; j++) {
                fscanf(file, "%d", &matrizPC[i][j]);
            }
	    }
		for (i = 0; i < 10; i++) {
		    for (j = 0; j < 10; j++) {
		        fscanf(file, "%s",&matrizcharusuario[i][j]);
		    }
	    }
	    for (i = 0; i < 10; i++) {
	        for (j = 0; j < 10; j++) {
		        fscanf(file, "%s",&matrizcharpc[i][j]);
		    }
	    }
	    fclose(file);
}

void pontoserodadas( int pmax, int pts, int ptspc, int rds){ // printa pontos, pontuação maxima e rodadas dentro do arquivo txt
	FILE *file;
	char nomearquivo[50];
	strcpy(nomearquivo, loginusuario);
	file = fopen(strcat(nomearquivo,"pontos.txt"), "w");
	fprintf(file, "%d \n", pmax);
	fprintf(file, "%d \n", pts);
	fprintf(file, "%d \n", ptspc);
	fprintf(file, "%d \n", rds);
	fclose(file);
}

void pts(int *pmaxima, int *pts, int *ptspc, int *rodadas){ // recebe pontos, pontuação maxima e rodadas do arquivo txt
	FILE *file;
	char nomearquivo[50];
	strcpy(nomearquivo, loginusuario);
	file = fopen(strcat(nomearquivo,"pontos.txt"), "r");
	fscanf(file,"%d %d %d %d", pmaxima, pts, ptspc, rodadas);
	fclose(file);
}

void gerarbarcos(int barcos2, int barcos3, int barcos4){ // função que posiciona os barcos nas matrizes
	
	

int i, j, l, c;
int totalbarcos = 0, totalbarcospc = 0;
int BarcosAleatorios;
	
    for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			matriz10Usuario[i][j] = '~';
		}
	}
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			matriz10Barcos[i][j] = 0;
		}
	}
	while(totalbarcos < barcos2){
		BarcosAleatorios = rand() % 2;
		l = rand() % 10;
		c = rand() % 10;
		//printf("%d\n",x);
		switch(BarcosAleatorios){
			case 0:
				if(matriz10Barcos [l][c] == 0 && matriz10Barcos [l][c+1] == 0 && c+1 < 9){
					matriz10Barcos [l][c] = 2;
					matriz10Barcos[l][c+1] = 2;	
					totalbarcos ++;
				}
			case 1:
				if(matriz10Barcos [l][c] == 0 && matriz10Barcos [l+1][c] == 0 && l+1 < 9){
					matriz10Barcos [l][c] = 2;
					matriz10Barcos[l+1][c] = 2;	
					totalbarcos ++;
				}
		
		}
	}
	while(totalbarcos < barcos3){
		BarcosAleatorios = rand() % 2;
		l = rand() % 10;
		c = rand() % 10;
		//printf("%d\n",x);
		switch(BarcosAleatorios){
			case 0:
				if(matriz10Barcos [l][c] == 0 && matriz10Barcos [l][c+1] == 0 && matriz10Barcos [l][c+2] == 0 && c+2 < 9){
					matriz10Barcos [l][c] = 3;
					matriz10Barcos[l][c+1] = 3;	
					matriz10Barcos [l][c+2] = 3;
					totalbarcos ++;
				}
			case 1:
				if(matriz10Barcos [l][c] == 0 && matriz10Barcos [l+1][c] == 0 && matriz10Barcos [l+2][c] == 0 && l+2 < 9){
					matriz10Barcos [l][c] = 3;
					matriz10Barcos[l+1][c] = 3;	
					matriz10Barcos [l+2][c] = 3;
					totalbarcos ++;
				}
			
		}
	}
	while(totalbarcos < barcos4){
		BarcosAleatorios = rand() % 2;
		l = rand() % 10;
	    c = rand() % 10;
		//printf("%d\n",x);
		switch(BarcosAleatorios){
			case 0:
				if(matriz10Barcos [l][c] == 0 && matriz10Barcos [l][c+1] == 0 && matriz10Barcos [l][c+2] == 0 && matriz10Barcos [l][c+3] == 0 && c+3 < 9){
					matriz10Barcos [l][c] = 4;
					matriz10Barcos[l][c+1] = 4;	
					matriz10Barcos [l][c+2] = 4;
					matriz10Barcos [l][c+3] = 4;
					totalbarcos ++;
				}
			case 1:
				if(matriz10Barcos [l][c] == 0 && matriz10Barcos [l+1][c] == 0 && matriz10Barcos [l+2][c] == 0 && matriz10Barcos [l+3][c] == 0 && l+3 < 9){
					matriz10Barcos [l][c] = 4;
					matriz10Barcos[l+1][c] = 4;	
					matriz10Barcos [l+2][c] = 4;
					matriz10Barcos [l+3][c] = 4;
					totalbarcos ++;
				}
		
		}
	}
	/*printf("Jogador\n");
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			printf("%d",matriz10Barcos[i][j]);
			printf(" ");
		}
		printf("\n");
	}*/
	printf("\n");
	//pc
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			matriz10PC[i][j] = '~';
		}
	}
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			matriz10BarcosPC[i][j] = 0;
		}
	}
	while(totalbarcospc < barcos2){
		BarcosAleatorios = rand() % 2;
		l = rand() % 10;
		c = rand() % 10;
		switch(BarcosAleatorios){
			case 0:
				if(matriz10BarcosPC [l][c] == 0 && matriz10BarcosPC [l][c+1] == 0  && c+1 < 9){
					matriz10BarcosPC[l][c] = 2;
					matriz10BarcosPC[l][c+1] = 2;	 
					totalbarcospc ++;
				}
			case 1:
				if(matriz10BarcosPC [l][c] == 0 && matriz10BarcosPC [l+1][c] == 0 && l+1 < 9){
					matriz10BarcosPC [l][c] = 2;
					matriz10BarcosPC[l+1][c] = 2;	
					totalbarcospc ++;
				}
		}
	}
	while(totalbarcospc < barcos3){
		BarcosAleatorios = rand() % 2;
		l = rand() % 10;
		c = rand() % 10;
		switch(BarcosAleatorios){
			case 0:
				if(matriz10BarcosPC [l][c] == 0 && matriz10BarcosPC [l][c+1] == 0 && matriz10BarcosPC [l][c+2] == 0 && c+2 < 9){
					matriz10BarcosPC[l][c] = 3;
					matriz10BarcosPC[l][c+1] = 3;	 
					matriz10BarcosPC [l][c+2] = 3;
					totalbarcospc ++;
				}
			case 1:
				if(matriz10BarcosPC [l][c] == 0 && matriz10BarcosPC [l+1][c] == 0 && matriz10BarcosPC [l+2][c] == 0 && l+2 < 9){
					matriz10BarcosPC [l][c] = 3;
					matriz10BarcosPC[l+1][c] = 3;	
					matriz10BarcosPC [l+2][c] = 3;
					totalbarcospc ++;
				}
		}
	}
	while(totalbarcospc < barcos4){
		BarcosAleatorios = rand() % 2;
		l = rand() % 10;
		c = rand() % 10;
		switch(BarcosAleatorios){
			case 0:
				if(matriz10BarcosPC [l][c] == 0 && matriz10BarcosPC [l][c+1] == 0 && matriz10BarcosPC [l][c+2] == 0 && matriz10BarcosPC [l][c+3] == 0 && c+3 < 9){
					matriz10BarcosPC[l][c] = 4;
					matriz10BarcosPC[l][c+1] = 4;	 
					matriz10BarcosPC [l][c+2] = 4;
					matriz10BarcosPC [l][c+3] = 4;
					totalbarcospc ++;
				}
			case 1:
				if(matriz10BarcosPC [l][c] == 0 && matriz10BarcosPC [l+1][c] == 0 && matriz10BarcosPC [l+2][c] == 0 && matriz10BarcosPC [l+3][c] == 0 && l+3 < 9){
					matriz10BarcosPC [l][c] = 4;
					matriz10BarcosPC[l+1][c] = 4;	
					matriz10BarcosPC [l+2][c] = 4;
					matriz10BarcosPC [l+3][c] = 4;
					totalbarcospc ++;
				}
		}
	}
	/*printf("PC\n");
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			printf("%d",matriz10BarcosPC[i][j]);
			printf(" ");
		}
		printf("\n");
	}*/
}

void jogo(int pontuacaomaxima, int pontos,int  pontospc,int jog){ // função responsavel pelo jogo
	int i, j, l, c;
	int linha, coluna;
	int jogadas = 0;
	for(jogadas = jog; jogadas >= 1; jogadas--){
		do{
			digite:
			system("cls");
			printf("Digite 11 na opção linha para SALVAR o jogo\n");
			printf("Digite 12 na opção linha para PAUSAR o jogo\n\n");
			printf("x = água\n");
			printf("2 = barco de 2 posições\n");
			printf("3 = barco de 3 posições\n");
			printf("4 = barco de 4 posições\n\n");
			printf("Jogadas Restantes: %d\n\n", jogadas);
			printf("Pontuacao: %d\n\n",pontos);

			printf("  0 1 2 3 4 5 6 7 8 9\n");
			for(i = 0; i < 10; i++){
				printf("%d ", i);
				for(j = 0; j < 10; j++){
				printf("%c",matriz10PC[i][j]);
				printf(" ");
				}
			printf("\n");
			}
			printf("Digite uma linha:\n");
			scanf("%d",&linha);
			if(linha == 11){
				salvarmatrizes(matriz10BarcosPC,matriz10Barcos, matriz10PC, matriz10Usuario );
				pontoserodadas(pontuacaomaxima, pontos, pontospc, jogadas);
				printf("Jogo salvo com sucesso!\n");
				system("pause");
				goto sair;
			}if(linha == 12){
				system("cls");
				pausa();
				system("pause");
				system("cls");
				goto digite;
			}
			printf("Digite uma coluna:\n");
			scanf("%d",&coluna);
			if(matriz10PC[linha][coluna] != '~'){
				printf("Coordenada ja informada anteriormente, tente outra\n");
				system("pause");
				goto digite;
			}
			else if(matriz10BarcosPC[linha][coluna] == 2){ // verifica se possui um barco na posicao escolhida
				matriz10PC[linha][coluna] = '2'; // caso houver um barco na matriz do tipo inteiro, a matriz do tipo char recebe "x"
				pontos = pontos + 15; // a cada acerto a variavel pontos recebe 15 pontos
			}else if(matriz10BarcosPC[linha][coluna] == 3){ // verifica se possui um barco na posicao escolhida
				matriz10PC[linha][coluna] = '3'; // caso houver um barco na matriz do tipo inteiro, a matriz do tipo char recebe "x"
				pontos = pontos + 10; // a cada acerto a variavel pontos recebe 10 pontos
			}else if(matriz10BarcosPC[linha][coluna] == 4){ // verifica se possui um barco na posicao escolhida
				matriz10PC[linha][coluna] = '4'; // caso houver um barco na matriz do tipo inteiro, a matriz do tipo char recebe "x"
				pontos = pontos + 5; // a cada acerto a variavel pontos recebe 5 pontos
			}else{
				matriz10PC[linha][coluna] = 'x';
			}
			system("cls");
			
			if(pontos >= pontuacaomaxima){
				break;
			}
			
		}while(matriz10BarcosPC[linha][coluna] == 2 || matriz10BarcosPC[linha][coluna] == 3 || matriz10BarcosPC[linha][coluna] == 4);
		do{
			l = rand() % 10;
			c = rand() % 10;
			if(matriz10Barcos[l][c] == 2){
				matriz10Usuario[l][c] = '2';
				pontospc = pontospc + 15;
			}else if(matriz10Barcos[l][c] == 3){
				matriz10Usuario[l][c] = '3';
				pontospc = pontospc + 10; // a cada acerto a variavel pontospc recebe 10 pontos
			}else if(matriz10Barcos[l][c] == 4){
				matriz10Usuario[l][c] = '4';
				pontospc = pontospc + 5;
			}else{
				matriz10Usuario[l][c] = 'x';
			}
			printf("Jogadas Restantes: %d\n\n", jogadas);
			printf("Pontuacao: %d\n\n",pontospc);
			printf("  0 1 2 3 4 5 6 7 8 9\n");
			for(i = 0; i < 10; i++){
				printf("%d ", i);
				for(j = 0; j < 10; j++){
					printf("%c",matriz10Usuario[i][j]);
					printf(" ");
				}
				printf("\n");
			}
			system("pause");
			system("cls");
		}while(matriz10Barcos[l][c] == 2 || matriz10Barcos[l][c] == 3 || matriz10Barcos[l][c] == 4);
	
		if(pontospc >= pontuacaomaxima){
			break;
		}
	}
	//printf("%i",jogadas);
	if(jogadas == 0){
		jogadas = 1;
	}
	pontuacaousuario = jogadas*pontos;
	pontuacaopc = jogadas*pontospc;
	printf("PARABENS!! VOCÊ JOGOU MUITO BEM!\n\n");
	printf("Pontuacao do Jogador: %i\n",pontuacaousuario);
	printf("Pontuacao do PC: %i\n",pontuacaopc);
	system("pause");
	sair:
	printf("");
}
	
void ranking(){
	
	
	int opcRanking;
	ranking:
	printf(".########.....###....##....##.##....##.####.##....##..######..\n");
	printf(".##.....##...##.##...###...##.##...##...##..###...##.##....##.\n");
	printf(".##.....##..##...##..####..##.##..##....##..####..##.##.......\n");
	printf(".########..##.....##.##.##.##.#####.....##..##.##.##.##...####\n");
	printf(".##...##...#########.##..####.##..##....##..##..####.##....##.\n");
	printf(".##....##..##.....##.##...###.##...##...##..##...###.##....##.\n");
	printf(".##.....##.##.....##.##....##.##....##.####.##....##..######..\n\n");
	printf("Selecione o ranking da dificuldade desejada:\n\n");
	printf("1 - Dificuldade facil\n");
	printf("2 - Dificuldade média\n");
	printf("3 - Dificuldade dificil\n");
	printf("4 - Voltar\n");
	scanf("%i",&opcRanking);
	switch(opcRanking){
		case 1:
			system("cls");
			printf(".########.....###....##....##.##....##.####.##....##..######......########....###.....######..####.##......\n");
			printf(".##.....##...##.##...###...##.##...##...##..###...##.##....##.....##.........##.##...##....##..##..##......\n");
			printf(".##.....##..##...##..####..##.##..##....##..####..##.##...........##........##...##..##........##..##......\n");
			printf(".########..##.....##.##.##.##.#####.....##..##.##.##.##...####....######...##.....##.##........##..##......\n");
			printf(".##...##...#########.##..####.##..##....##..##..####.##....##.....##.......#########.##........##..##......\n");
			printf(".##....##..##.....##.##...###.##...##...##..##...###.##....##.....##.......##.....##.##....##..##..##......\n");
			printf(".##.....##.##.....##.##....##.##....##.####.##....##..######......##.......##.....##..######..####.########\n\n");
			FILE * arquivo;
			arquivo = fopen("rankingfacil.txt", "r");
			while(fgets(rankingfacil, sizeof(rankingfacil), arquivo) != NULL){
				printf("%s", rankingfacil);
			}
			fclose(arquivo);
			printf("\n");
			printf("Digite qualquer tecla para voltar \n\n");
			system("pause");
			system("cls");
			goto ranking;
		case 2:
			system("cls");
			printf(".########.....###....##....##.##....##.####.##....##..######......##.....##.########.########..####..#######.\n");
			printf(".##.....##...##.##...###...##.##...##...##..###...##.##....##.....###...###.##.......##.....##..##..##.....##\n");
			printf(".##.....##..##...##..####..##.##..##....##..####..##.##...........####.####.##.......##.....##..##..##.....##\n");
			printf(".########..##.....##.##.##.##.#####.....##..##.##.##.##...####....##.###.##.######...##.....##..##..##.....##\n");
			printf(".##...##...#########.##..####.##..##....##..##..####.##....##.....##.....##.##.......##.....##..##..##.....##\n");
			printf(".##....##..##.....##.##...###.##...##...##..##...###.##....##.....##.....##.##.......##.....##..##..##.....##\n");
			printf(".##.....##.##.....##.##....##.##....##.####.##....##..######......##.....##.########.########..####..#######.\n\n");
			FILE * arquivo1;
			arquivo1 = fopen("rankingmedio.txt", "r");
			while(fgets(rankingmedio, sizeof(rankingmedio), arquivo1) != NULL){
				printf("%s", rankingmedio);
			}
			fclose(arquivo1);
			printf("\n");
			printf("Digite qualquer tecla para voltar \n\n");
			system("pause");
			system("cls");
			goto ranking;
		case 3:
			system("cls");
			printf(".########.....###....##....##.##....##.####.##....##..######......########..####.########.####..######..####.##......\n");
			printf(".##.....##...##.##...###...##.##...##...##..###...##.##....##.....##.....##..##..##........##..##....##..##..##......\n");
			printf(".##.....##..##...##..####..##.##..##....##..####..##.##...........##.....##..##..##........##..##........##..##......\n");
			printf(".########..##.....##.##.##.##.#####.....##..##.##.##.##...####....##.....##..##..######....##..##........##..##......\n");
			printf(".##...##...#########.##..####.##..##....##..##..####.##....##.....##.....##..##..##........##..##........##..##......\n");
			printf(".##....##..##.....##.##...###.##...##...##..##...###.##....##.....##.....##..##..##........##..##....##..##..##......\n");
			printf(".##.....##.##.....##.##....##.##....##.####.##....##..######......########..####.##.......####..######..####.########\n\n");
			FILE * arquivo2;
			arquivo2 = fopen("rankingdificil.txt", "r");
			while(fgets(rankingdificil, sizeof(rankingdificil), arquivo2) != NULL){
				printf("%s", rankingdificil);
			}
			fclose(arquivo2);
			printf("\n");
			printf("Digite qualquer tecla para voltar \n\n");
			system("pause");
			system("cls");
			goto ranking;
		case 4:
			break;
		default:
			goto ranking;
	}
}

void alterarcor(){
	
	
	int tema; // varievel para alterar a cor tema do jogo
	
	system("cls");
	printf("....###....##.......########.########.########.....###....########.....########.########.##.....##....###...\n");
	printf("..##...##..##..........##....##.......##.....##..##...##..##.....##.......##....##.......####.####..##...##.\n");
	printf(".##.....##.##..........##....######...########..##.....##.########........##....######...##.###.##.##.....##\n");
	printf(".#########.##..........##....##.......##...##...#########.##...##.........##....##.......##.....##.#########\n");
	printf(".##.....##.##..........##....##.......##....##..##.....##.##....##........##....##.......##.....##.##.....##\n");
	printf(".##.....##.########....##....########.##.....##.##.....##.##.....##.......##....########.##.....##.##.....##\n");
	printf("\n\n");
	printf("1 - Tema Dark \n");
	printf("2 - Tema Light \n");
	printf("3 - Voltar \n");
	printf("Qual tema deseja escolher?");
	scanf("%i",&tema); // recebe a opção do usuario
	if (tema == 1){
		system("Color 0F"); // tema escuro
	}else if (tema == 2){
		system("Color F0"); // tema claro
	}
	else{
		
	}
	system("cls");
}

void instrucoes(){
	printf("No começo do jogo, o mapa todo estará preenchido com água, e você terá que digitar as coordenadas indicando a linha e a coluna\n");
	printf("para efetuar um disparo contra o mapa inimigo, caso o disparo acerte uma embarcação aparecerão os numeros 2, 3 ou 4, caso apareça\n");
	printf("o numero 2, você atingiu um barco com duas posições, e essa mesma logica vale para os barcos com 3 e 4 posições, se o disparo não\n");
	printf("atingir um barco, a cooredenada digitada receberá um  x  indicando que o disparo atingiu a água.\n");
	printf("Quando a coordenada digitada atingir um barco inimigo, você poderá jogar novamente, e sempre que o disparo acertar a água, será a vez\n");
	printf("do oponente.\n");
	printf("Todas as modalidades de jogo possuem 30 rodadas, e vence quem destruir todos os barcos inimigos primeiro, ou fizer mais pontos ao final\n");
	printf("das 30 rodadas. A pontuação final é feita da segunte forma, (pontuação alcançada x rodadas restantes).\n");
	printf("Cada tiro em um pedaço de um barco de 2 posições somarão 15 pontos, no de 3 posições 10 pontos, e o barco de 4 posições somarão 5 pontos.\n");
	system("pause");
}

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"Portuguese");
	while(opcCadastro != 1 && opcCadastro != 2){
		
		system("cls");
	
		titulobatalha();
		
	    printf("\t\t\t1 - Realizar cadastro\n"); // Opção 1 o usuario cria um novo cadastro
	    printf("\t\t\t2 - Realizar login\n"); // Opção 2 o usuario entra no jogo através do login
	    scanf("%i",&opcCadastro); // variavel que recebe a opção para login ou cadastro
	    switch(opcCadastro){ 
	    	case 1: 
				teladecadastro();
			case 2:
				teladelogin();
		}
	}
	system("pause");
 
	telaInicial:
		
	system("cls");
	
		titulobatalha();
		
		menu();
		
		scanf("%i",&selecionarOpcao); // variavel para receber a opção dentro do menu
		system("cls");
		    
	    switch(selecionarOpcao){
	    	case 1:
	    			selectdificuldade:
	    			system("cls");
	    			selecionardificuldade();
	
		    		scanf("%i",&selecionarDificuldade);
		    		system("cls");
	    			
	    		switch(selecionarDificuldade){
	    			case 1:
						gerarbarcos(4,8,12);
						jogo(320, 0, 0, 30);
						if(pontuacaousuario == 0){
							goto telaInicial;
						}
						FILE *arquivo;
						arquivo = fopen("rankingfacil.txt", "a");
						fprintf(arquivo,"%s................",loginusuario);
						fprintf(arquivo,"%i\n",pontuacaousuario);
						fclose(arquivo);
						goto telaInicial; // vai para o menu do jogo	
						break;
					case 2:
						gerarbarcos(3,6,9);
						jogo(240,0,0,30);
						if(pontuacaousuario == 0){
							goto telaInicial;
						}
						FILE *arquivo1;
						arquivo1 = fopen("rankingmedio.txt", "a");
						fprintf(arquivo1,"%s................",loginusuario);
						fprintf(arquivo1,"%i\n",pontuacaousuario);
						fclose(arquivo1);
						goto telaInicial; // vai para o menu do jogo	
						break;
					case 3:
						gerarbarcos(2,4,6);
						jogo(160, 0, 0, 30);
						if(pontuacaousuario == 0){
							goto telaInicial;
						}
						FILE *arquivo2;
						arquivo2 = fopen("rankingdificil.txt", "a");
						fprintf(arquivo2,"%s................",loginusuario);
						fprintf(arquivo2,"%i\n",pontuacaousuario);
						fclose(arquivo2);
						goto telaInicial; // vai para o menu do jogo
						break;
					case 4:
						recebe(matriz10BarcosPC, matriz10Barcos, matriz10PC, matriz10Usuario);
						pts(&pontuacaomaxima, &pontos, &pontospc, &jog);
						jogo(pontuacaomaxima,pontos, pontospc, jog);
						if(pontuacaousuario == 0){
							goto telaInicial;
						}
						if(pontuacaomaxima == 320){
							FILE *arquivo;
							arquivo = fopen("rankingfacil.txt", "a");
							fprintf(arquivo,"%s................",loginusuario);
							fprintf(arquivo,"%i\n",pontuacaousuario);
							fclose(arquivo);
							goto telaInicial; // vai para o menu do jogo	
							break;
						}else if(pontuacaomaxima == 240){
							FILE *arquivo1;
							arquivo1 = fopen("rankingmedio.txt", "a");
							fprintf(arquivo1,"%s................",loginusuario);
							fprintf(arquivo1,"%i\n",pontuacaousuario);
							fclose(arquivo1);
							goto telaInicial; // vai para o menu do jogo	
							break;
						}else if(pontuacaomaxima == 160){
							FILE *arquivo2;
							arquivo2 = fopen("rankingdificil.txt", "a");
							fprintf(arquivo2,"%s................",loginusuario);
							fprintf(arquivo2,"%i\n",pontuacaousuario);
							fclose(arquivo2);
							goto telaInicial; // vai para o menu do jogo
							break;
						}
					case 5:
						goto telaInicial;
					default:
						goto selectdificuldade;
				}
	    	case 2:
	    		alterarcor();
	    		goto telaInicial;
	    		
	    	case 3:
	    		ranking();
	    		goto telaInicial;
	    	case 4:
	    		instrucoes();
	    		goto telaInicial;
	    	default:
	    		goto telaInicial;
    	}
    
	return 0;
}

