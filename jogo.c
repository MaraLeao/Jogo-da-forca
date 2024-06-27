#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>

#define TAM_MAX 250
#define TENTATIVAS 6
#define NUM_PALAVRA_ALT 30

typedef struct {
    char    letra;
    char    multiplayer;
    char    palavra[TAM_MAX];
    char    status_atual[TAM_MAX];
    bool    mascara[TAM_MAX];
    bool    tentativaNaoVazia;
    bool    letraRepetida;
    int     qtd_erro;
    int     fim;
} dadosPalavras;

dadosPalavras dadosJogo;

void resetarDados(dadosPalavras * dado) {
    //usei esses memset para setar todos os componentes das array pra 0 e false
    memset(dado -> palavra, 0, TAM_MAX * sizeof(char));
    memset(dado -> status_atual, 0, TAM_MAX * sizeof(char));
    memset(dado -> mascara, false, TAM_MAX * sizeof(bool));
    dado -> qtd_erro = 0;
    dado -> multiplayer = 0;
    dado -> tentativaNaoVazia = false;
    dado -> fim = false;
}


char * banco_palavras[] = {
    //banco de palavras para jogo single
    "cachorro", "gato", "elefante", "leao", "tigre",
    "girafa", "macaco", "zebra", "coelho", "rato",
    "pato", "coruja", "galo", "papagaio", "cobra",
    "jacare", "tartaruga", "peixe", "tubarao", "baleia",
    "golfinho", "vaca", "porco", "cavalo", "ovelha",
    "aranha", "escorpiao", "lagarto", "pomba", "abelha"
};
  
//função para escolher uma palavra do banco
char *escolhe_palavra_aleat(char **palavras_gp, int num_palavras_aleat) { 
    //gera um numero aleatorio com o rand() para servir de indice do array banco_palavras, e o "%" nesse caso serve para   delimitar o indice apenas menor que a qtd de palavras
    int indice_aleat = rand() % (num_palavras_aleat); 
    return palavras_gp[indice_aleat];
}

//pega o indice aleatorio gerado na funcao "escolhe_palavra_aleat" e copia a palavra do indice pra palavra no struct
void novaPalavra(dadosPalavras *dado) {
    strcpy(dado->palavra, escolhe_palavra_aleat(banco_palavras, NUM_PALAVRA_ALT)); // copia a palavra do banco de palavras
}

void desenharForca () 
{
   //desenho da forca fazendo uso do switch case
    printf("\n\n");

    switch (dadosJogo.qtd_erro) {
    case 0:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 1:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 2:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("  |   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 3:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 4:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 5:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf(" /    |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 6:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf(" / \\  |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    }
}


int main() {
    setlocale(0, "Portuguese");
    int i;
    int escolha = 0;
    system("cls");

    do {
        //MENU 
        printf("\t        MENU\n");
        printf("\t     JOGO DA FORCA\n\n");
        printf(" \t---------------------- \n  \t \t Opcoes\n\n");
        printf(" \t1. Regras \n");
        printf(" \t2. Modos de jogo \n");
        printf(" \t3. Sair \n\n");
        printf("\t===============================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                //MENU -> regras
                system("cls");
                printf("\n\n regras:\n a) as palavras devem ser curtas ,\n b)voce tem um "
                    "limte de 6 erros\n c) nao utilize simbolos, acentuacao ou "
                    "numeros\n\n ");
                break;
            case 2:
                //MENU -> jogar
                srand(time(NULL));//inicando o time 

                resetarDados(&dadosJogo); //resetar todos os dados pra 0
                system("cls");

                printf("Quer jogar multiplayer?[S/N] ");
                scanf(" %c", &dadosJogo.multiplayer);
                //receber palavra chave

                if(dadosJogo.multiplayer == 'S' || dadosJogo.multiplayer == 's') {
                    //introducao multiplayer
                    system("cls");
                    printf("\tBem-vindo a FORCA!\n\nVoce escolheu a vers�o multiplayer, vai poder escolher a palavra que o outro jogador vai adivinhar\n\nSe atente as regras:\n\n\t=> as palavras devem ser curtas ,\n\t=> voce tem um limte de 6 erros\n\t=> nao utilize simbolos, acentuacao ou numeros\n\n");
                    printf("Agora escreva a palavra a ser adivinhada: ");
                    scanf("%s", &dadosJogo.palavra);
                    system("cls");
                } else {
                    //introducao singleplayer
                    novaPalavra(&dadosJogo);
                    system("cls");
                    printf("\tBem-vindo a FORCA!\n\nVoce escolheu a vers�o singleplayer, lembre-se que tem um limite de 6 erros, boa sorte :)\n");
                }


                //escrever os tracinhos na quantidade de letras
                for ( i = 0; i < strlen(dadosJogo.palavra); i++) {
                        dadosJogo.status_atual[i]= '_';
                }

                do {

                    dadosJogo.tentativaNaoVazia = false;//resetando a variavel para false

                    desenharForca();
                    printf("%s\n", dadosJogo.status_atual);   

                    //receber a letra da vez
                    printf("Digite a letra: ");
                    scanf(" %c", &dadosJogo.letra);

                    //for para ver se a letra aparece pelo menos uma vez na palavra
                    for (i = 0; i <= strlen(dadosJogo.palavra); i++) {

                        if (dadosJogo.palavra[i] == dadosJogo.letra) {
                            if(dadosJogo.status_atual[i] == dadosJogo.letra) {
                                dadosJogo.letraRepetida = true;     //marca a letra repetida
                                break;
                            } else {
                                dadosJogo.mascara[i] = true;  //marca a posicao da letra
                                dadosJogo.tentativaNaoVazia = true;  //tem uma letra na palavra chave
                            }
                        }
                    }

                    // sequencia de if para colocar a letra na palavra ou tirar ponto
                    if(dadosJogo.tentativaNaoVazia) {
                        printf("A letra %c esta na palavra :)\n", dadosJogo.letra);
                        

                        for(i = 0; i <= strlen(dadosJogo.palavra); i++) {
                            if (dadosJogo.mascara[i]) {
                                dadosJogo.status_atual[i] = dadosJogo.palavra[i];  //atualiza o status atual pra letra que acertou
                            } 
                        }

                        if (!strcmp(dadosJogo.status_atual, dadosJogo.palavra)) //verifica se ganhou o jogo
                            dadosJogo.fim = true;   

                    } else if (dadosJogo.letraRepetida) {
                        dadosJogo.qtd_erro++; 
                        printf("Voce ja utilizou essa letra, voce tem %d tentativas\n", (TENTATIVAS - dadosJogo.qtd_erro));
                        

                    } else {
                        dadosJogo.qtd_erro++;
                        printf("A letra %c nao esta na palavra :/, voce tem %d tentativas\n", dadosJogo.letra, (TENTATIVAS - dadosJogo.qtd_erro));
                        
                    }


                    if (dadosJogo.qtd_erro == TENTATIVAS) //verifica se ja atingiu as tentativas maximas
                        break;


                } while (!dadosJogo.fim && dadosJogo.qtd_erro < TENTATIVAS); //fim segundo do while

                if (dadosJogo.fim)  //mensagem vencedor
                    printf("\nPARABENS!!! Voce ganhou o jogo, foi otimo jogar com voce :D \n\n\n");
                else                //mensagem perdedor
                    printf("\nAhh que pena, voce perdeu, a palavra era: %s\n\n\n", dadosJogo.palavra);

                break;
            case 3:
                //MENU -> sair
                printf("Saindo do programa. Ate logo!\n");
                break;
            default:
                printf("\n\n\n»»-----------Opcao invalida. Escolha uma opcao "
                        "valida.\n\n\n");
                break;
            }
        } while (escolha != 3);//fim do while maior

        return 0;
    } 