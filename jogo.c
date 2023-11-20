#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAM_MAX 250
#define TENTATIVAS 6
#define NUM_PALAVRA_ALT 30

void desenharForca () 
{
    //array da forca(com o indice 0 sendo o desenho da forca)
}

typedef struct {
    char    letra;
    char    multiplayer;
    char    letras_erradas[7];
    char    palavra[TAM_MAX];
    char    status_atual[TAM_MAX];
    bool    mascara[TAM_MAX];
    bool    tentativaNaoVazia;
    bool    letraRepetida;
    int     qtd_jogadores;
    int     qtd_erro;
    int     fim;
} dadosPalavras;

dadosPalavras dadosJogo;

void resetarDados(dadosPalavras * dado) {
    //usei esses memset
    memset(dado -> palavra, 0, TAM_MAX * sizeof(char));
    memset(dado -> status_atual, 0, TAM_MAX * sizeof(char));
    memset(dado -> mascara, false, TAM_MAX * sizeof(bool));
    dado -> qtd_erro = 0;
    dado -> qtd_jogadores = 0;
    dado -> tentativaNaoVazia = false;
    dado -> fim = false;
}


char * banco_palavras[] = {
        "cachorro", "gato", "elefante", "leao", "tigre",
        "girafa", "macaco", "zebra", "coelho", "rato",
        "pato", "coruja", "galo", "papagaio", "cobra",
        "jacare", "tartaruga", "peixe", "tubarao", "baleia",
        "golfinho", "vaca", "porco", "cavalo", "ovelha",
        "aranha", "escorpiao", "lagarto", "pomba", "abelha"
};

char *escolhe_palavra_aleat(char **palavras_gp, int num_palavras_aleat) {
    int num_aleat = rand() % num_palavras_aleat;
    return palavras_gp[num_aleat];
}

void novaPalavra(dadosPalavras *dado) {
  strcpy(dado->palavra,
         escolhe_palavra_aleat(banco_palavras, NUM_PALAVRA_ALT)); // copia a palavra do banco de palavras
  memset(dado->status_atual, '_', strlen(dadosJogo.palavra));
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


    srand(time(NULL));

    char* p_letra = &dadosJogo.letra;

    //Perguntar quantojogadores sao
    printf("( ´･･)ﾉ(._.`)  Quantos jogadores irão participar?: ");
    scanf("%d", &qtd_jogadores);

    //Quantos jogadores sao
    resetarDados(&dadosJogo); //setar todos os dados pra 0
    system("cls");

    printf("Quer jogar multiplayer?[S/N]");
    scanf("%c", &dadosJogo.multiplayer);
    //receber palavra chave


    printf("\tBem vindo a FORCA, o jogo basicamente consiste em um Carrasco que irá decidir uma plavra e um prisioneiro que está a um fio de ser executado que tentará adivinhar a palavra escolhida.\n\n\tCarrasco, coloque a venda no prisioneiro e prepare a corda, agora você deve digitar uma palavra para que o prisioneiro possa adivinha, vale lembrar que as palavras não devem conter acentos eno depreferência devem ter por volta de 6 letras\n \n \n\tCarrasco, espero que esteja tudo pronto! Agora escreva a plavra a ser adivinhada: ");

    scanf("%s", &dadosJogo.palavra);

    if(dadosJogo.multiplayer == 'S' || dadosJogo.multiplayer == 's') {
        printf("Escreva a palavra: ");
        scanf("%s", &dadosJogo.palavra);
    } else {
        novaPalavra(&dadosJogo);
        printf("Escolhendo uma palavra ...");
    }


    //escrever os tracinhos na quantidade de letras
    for (int i = 0; i < strlen(dadosJogo.palavra); i++) {
            dadosJogo.status_atual[i]= '_';
    }

    do {
        system("cls");

        dadosJogo.tentativaNaoVazia = false;

        desenharForca();
        printf("%s\n", dadosJogo.status_atual);

        printf("(╥_╥) letras incorretas : [ %s ]\n", dadosJogo.letras_erradas);


   

        //receber a letra da vez
        printf("Prisioneiro, agora você deve adivinhar uma letra: ");

        scanf(" %c", &dadosJogo.letra);


        //for para ver se a letra tem pelo menos uma vez na palavra
        for (int i = 0; i <= strlen(dadosJogo.palavra); i++) {

            if (dadosJogo.palavra[i] == dadosJogo.letra) {
                if(dadosJogo.status_atual[i] == dadosJogo.letra) {
                    dadosJogo.letraRepetida = true;
                    break;
                } else {
                    dadosJogo.mascara[i] = true;
                    dadosJogo.tentativaNaoVazia = true;
                }
            }
        }

        // sequencia de if para colocar a letra na palavra ou tirar ponto
        if(dadosJogo.tentativaNaoVazia) {
            printf("✧⁺⸜(●′▾‵●)⸝⁺✧ A LETRA %c ESTÁ NA PALAVRA!!\n", dadosJogo.letra);
            for(int i = 0; i <= strlen(dadosJogo.palavra); i++) {
                if (dadosJogo.mascara[i]) {
                    dadosJogo.status_atual[i] = dadosJogo.palavra[i];
                } 
            }

            if (!strcmp(dadosJogo.status_atual, dadosJogo.palavra)) 
                dadosJogo.fim = true;

        } else if (dadosJogo.letraRepetida) {
            dadosJogo.qtd_erro++;

            printf("( • ᴖ • ｡) Voce ja utilizou essa letra, voce tem %d tentativas\n", (TENTATIVAS - dadosJogo.qtd_erro));

        } else {
            dadosJogo.qtd_erro++;
            printf("(｡•́︿•̀｡) A letra %c nao esta na palavra, voce tem %d tentativas\n", dadosJogo.letra, (TENTATIVAS - dadosJogo.qtd_erro));

            //strcat(dadosJogo.letras_erradas, p_letra); coloquei essa funcao aqui pra juntar as letras erradas, mas por algum motivo esta dando problema

        }

        //for para comparar a letra com as letras da palavra
            //se tiver uma letra igual a alguma letra da palavra 
                //qtd de acerto ++
                //
            //senao, 
                //qtd_erro++
                //desenhar forca com um membro a mais
        // Quebra o loop
        if (dadosJogo.qtd_erro == TENTATIVAS)
                break;


    } while (!dadosJogo.fim && dadosJogo.qtd_erro < TENTATIVAS);

      if (dadosJogo.fim) {

          printf("*ੈ✩‧₊˚༺˚  PARABÉNS!!! VOCÊ GANHOU O JOGO, AGORA VOCÊ PODERÁ VIVER MAIS UM DIA, MAS LEMBRE-SE A MORTE O AGUARDA.☆༻*ੈ✩‧₊˚! ");
          printf("Deseja jogar novamente?[Y/N]:");
      } else {
          printf("Prepare-se para o seu fim (((＼（✘෴✘）／))) ... A palavra era: %s\n", dadosJogo.palavra);

          printf("Deseja jogar novamente?[Y/N]:");
      }

}
