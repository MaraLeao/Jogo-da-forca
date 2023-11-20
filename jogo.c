#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void desenharForca () 
{
    //array da forca(com o indice 0 sendo o desenho da forca)
}

//frases 
                   void frase(int opcao) {
    switch(opcao) {
        // inicio
        case 1:
            printf("⋆⭒˚｡⋆ BEM VINDO AO JOGO DA FORCA ヾ(˃ᴗ˂)◞ • *✰\n");
            break;
        case 2:
            printf("Regras✰: \n 1- A palavra secreta e a dica devem ter até 250 caracteres. \n 2- seu limte de erros são 6 tentativas \n ");
            break;
        //multiplayer
        case 3:
            printf("( ´･･)ﾉ(._.`)  Quantos jogadores irão participar?: ");
            break;
        case 4:
            printf("(ง'̀-'́)ง Vez do próximo jogador\n");
            break;
        // palavras
        case 5:
            printf("(„• ֊ •„)  Digite a palavra escolhida: ");
            break;
        case 6:
            printf("(•ˋ _ ˊ•) Essa palavra é longa demais!\n tente novamente: ");
            break;
        case 7:
            printf("╮ (. ❛ ᴗ ❛.) ╭ Algo deu errado!\n tente novamente: ");
            break;
        case 8:
            printf("(´｡• ◡ •｡`) ♡ Obrigada!, sua palavra foi registrada com sucesso.\n");
            break;
        // dica
        case 9:
            printf(" Por favor insira uma dica:  \n");
            break;    
         case 10:
            printf("(•ˋ _ ˊ•) Essa dica é longa demais!\n tente novamente: ");
            break;
        case 11:
            printf("╮ (. ❛ ᴗ ❛.) ╭ Algo deu errado!\n tente novamente: ");
            break;
        case 12:
            printf("(´｡• ◡ •｡`) ♡ Obrigada!, sua dica foi registrada com sucesso.\n");
            break;
        //começo da partida
        case 13:
            printf("(૭ ｡•̀ ᵕ •́｡ )૭ HORA DE COMEÇAR OS JOGOS\n");
            break;
        // letras
        case 14:
            printf("Digite uma letra: ");
            break;
        case 15:
            printf("( • ᴖ • ｡) essa letra já foi usada!\n tente novamente: ");
            break;
        case 16:
            printf("╮ (. ❛ ᴗ ❛.) ╭ Algo deu errado!\n tente novamente: ");
            break;
        case 17:
            printf("✧⁺⸜(●′▾‵●)⸝⁺✧ A LETRA ESTÁ NA PALAVRA!!!\n");
            break;
        case 18:
            printf("(｡•́︿•̀｡) a letra não está na palavra\n");
            break;
        //resultados
        case 19:
            printf("*ੈ✩‧₊˚༺˚  PARABÉNS!!! VOCÊ GANHOU O JOGO☆༻*ੈ✩‧₊˚!\n Deseja continuar?[Y/N]: ");
            break;
        case 20:
            printf("Sinto muito, não foi dessa vez (T-T)\n Deseja continuar?[Y/N]: ");
            break;
        // encerramento
        case 21:
            printf("Jogo encerrado.\n");
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}


int main() {

    const int TENTATIVAS = 6;

    char palavra[250], letras_erradas[27], letra, status_atual;
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
