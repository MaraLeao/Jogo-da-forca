#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_MAX 250
#define TENTATIVAS 7

void desenharForca () 
{
    //array da forca(com o indice 0 sendo o desenho da forca)
}

typedef struct {
    char    letra;
    char    letras_erradas[6];
    char    palavra[TAM_MAX];
    char    status_atual[TAM_MAX];
    bool    mascara[TAM_MAX];
    bool    tentativaNaoVazia;
    bool    letraRepetida;
    int     qtd_jogadores;
    int     qtd_erro;
    int     fim;
} dadosPalavras;

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

int main() {

    dadosPalavras dadosJogo;
    char* p_letra = &dadosJogo.letra;

    
    //Perguntar quantojogadores sao

    resetarDados(&dadosJogo); //setar todos os dados pra 0

    //receber palavra chave
    printf("Escreva a palavra: ");
    scanf("%s", &dadosJogo.palavra);

    //escrever os tracinhos na quantidade de letras
    for (int i = 0; i < strlen(dadosJogo.palavra); i++) {
            dadosJogo.status_atual[i]= '_';
    }

    do {
        dadosJogo.tentativaNaoVazia = false;

        printf("%s\n", dadosJogo.status_atual);
        //printf("letras erradas: [ %s ]\n", dadosJogo.letras_erradas);

        //if(qtd_jogadores > 1) 
            //se jogDaVez % 2 = 0
                //print hora do jogador 2
            //else
                //print hora do jogador 1
    
        //aparecer forca e a quantidade de espaço de letras

        //receber a letra da vez
        printf("Escreva a letra: ");
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
            printf("A letra %c esta na palavra\n", dadosJogo.letra);
            for(int i = 0; i <= strlen(dadosJogo.palavra); i++) {
                if (dadosJogo.mascara[i]) {
                    dadosJogo.status_atual[i] = dadosJogo.palavra[i];
                } 
            }

            if (!strcmp(dadosJogo.status_atual, dadosJogo.palavra)) 
                dadosJogo.fim = true;

        } else if (dadosJogo.letraRepetida) {
            dadosJogo.qtd_erro++;
            printf("Voce ja adivinhou essa letra, voce tem %d tentativas\n", (TENTATIVAS - dadosJogo.qtd_erro));
            
        } else {
            dadosJogo.qtd_erro++;
            printf("A letra %c nao esta na palavra, voce tem %d tentativas\n", dadosJogo.letra, (TENTATIVAS - dadosJogo.qtd_erro));
    
            //strcat(dadosJogo.letras_erradas, p_letra); coloquei essa funcao aqui pra juntar as letras erradas, mas por algum motivo esta dando problema
            
        }

        // Quebra o loop
        if (dadosJogo.qtd_erro == TENTATIVAS)
                break;
            
            
        

        
        
    }
    while (!dadosJogo.fim);

    //se ganhar o jogo 
        //printar mensagem de vencedor
    //senao
        //vc perdeu, lamento



}
