#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void desenharForca () 
{
   //desenho da forca fazendo uso do switch case
    printf("\n\n");

    switch (TENTATIVAS) {
    case 6:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 5:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 4:
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
    case 2:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 1:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\  |\n");
        printf(" /    |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    case 0:
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\  |\n");
        printf(" / \  |\n");
        printf("      |\n");
        printf("=========\n");
        break;
    }
}

int main() {

    const int TENTATIVAS = 6;

    char palavra[250], letras_erradas[6], letra, status_atual;
    int  qtd_erro = 0, qtd_acerto = 0, jogDaVez, qtd_jogadores, posicao, i;

    //Quantos jogadores sao

    //receber palavra chave

    //do
        //if(qtd_jogadores > 1) 
            //se jogDaVez % 2 = 0
                //print hora do jogador 2
            //else
                //print hora do jogador 1
    
        //aparecer forca e a quantidade de espaço de letras

        //pedir a letra da vez

        //for para comparar a letra com as letras da palavra
            //se tiver uma letra igual a alguma letra da palavra 
                //qtd de acerto ++
                //
            //senao, 
                //qtd_erro++
                //desenhar forca com um membro a mais

    //while (o jogo continuar)

    //se ganhar o jogo 
        //printar mensagem de vencedor
    //senao
        //vc perdeu, lamento



}
