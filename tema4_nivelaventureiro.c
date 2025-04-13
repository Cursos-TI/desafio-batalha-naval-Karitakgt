#include<stdio.h>
#include<stdlib.h>

/* Jogo de Batalha Naval */

int main(){

    // Definindo variaveis:

    const int tamanho_tabuleiro = 10;
    const int tamanho_navio = 3;
    const int valor_agua = 0;
    const int valor_navio = 3;

    // Criando o tabuleiro e inicializando com água (0)

    int tabuleiro[10][10];
    for (int i = 0; i < tamanho_tabuleiro; i++)
    {
        for (int j = 0; j < tamanho_tabuleiro; j++)
        {
            tabuleiro[i][j] = valor_agua;
        }
        
    }
    
   // Definindo as coordenadas dos navios (linha e coluna iniciais)

   int linhaH = 2, colunaH = 4; // navio horizontal
   int linhaV = 5, colunaV = 7; // Navio vertical

   // Definindo as coordenadas dos navios na diagonal:

   int linhaDiag1 = 1, colunaDiag1 = 1; // Navio da diagonal linha e coluna aumentam
   int linhaDiag2 = 6, colunaDiag2 = 5; // Navio da diagonal linha aumenta e coluna diminui

    // Verificando se o NAVIO HORIZONTAL cabe no tabuleiro e não sobrepõe outro

    int podeHorizontal = 1;
    if (colunaH + tamanho_navio <= tamanho_tabuleiro)
    {
        for (int i = 0; i < tamanho_navio; i++)
        {
            if (tabuleiro[linhaH][colunaH + i] != valor_agua) {
                podeHorizontal = 0;
                break;
            }
        }
        
    } else {
        podeHorizontal = 0;
    }

    // Posicionando navio horizontal
    if (podeHorizontal)
    {
        for (int i = 0; i < tamanho_navio; i++)
        {
            tabuleiro[linhaH][colunaH +i] = valor_navio;
        }
         
    } else{
        printf("Erro ao posicionar o navio horizontal\n");
        return 1;
    }

    // Verificndo se o NAVIO VERTICAL cabe no tabuleiro e não sobrepõe outro

    int podeVertical = 1;
    if (linhaV + tamanho_navio <= tamanho_tabuleiro)
    {
        for (int i = 0; i < tamanho_navio; i++)
        {
           if (tabuleiro[linhaV +i][colunaV] != valor_agua)
           {
            podeVertical = 0;
            break;
           }
           
        }
        
    } else {
        podeVertical = 0;
    }

    // Posicionando navio vertical

    if (podeVertical)
    {
        for (int i = 0; i < tamanho_navio; i++)
        {
            tabuleiro[linhaV + i][colunaV] = valor_navio;
        }
        
    } else {
        printf("Erro ao posicionar o navio vertical\n");
        return 1;
    }

        

    // Verifica se o NAVIO DIAGONAL 1 cabe no tabuleiro e não sobrepõe
    int podeDiag1 = 1;
    if (linhaDiag1 + tamanho_navio <= tamanho_tabuleiro && colunaDiag1 + tamanho_navio <= tamanho_tabuleiro) {
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linhaDiag1 + i][colunaDiag1 + i] != valor_agua) {
                podeDiag1 = 0;
                break;
            }
        }
    } else {
        podeDiag1 = 0;
    }

    // Posiciona navio diagonal ↘️
    if (podeDiag1) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linhaDiag1 + i][colunaDiag1 + i] = valor_navio;
        }
    } else {
        printf("Erro ao posicionar navio diagonal ↘️.\n");
        return 1;
    }

   // Verifica se o NAVIO DIAGONAL 2 cabe no tabuleiro e não sobrepõe
    int podeDiag2 = 1;

    if (linhaDiag2 + tamanho_navio <= tamanho_tabuleiro && colunaDiag2 - (tamanho_navio - 1) >= 0) {
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linhaDiag2 + i][colunaDiag2 - i] != valor_agua) {
                podeDiag2 = 0;
                break;
            }
        }
    } else {
        podeDiag2 = 0;
    }

    // Posiciona navio diagonal ↙️
    if (podeDiag2) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linhaDiag2 + i][colunaDiag2 - i] = valor_navio;
        }
    } else {
        printf("Erro ao posicionar navio diagonal ↙️.\n");
        return 1;
    }


    // Exibindo o tabuleiro final
    printf("*** TABULEIRO DE BATALHA NAVAL ***\n");
    for (int i = 0; i < tamanho_tabuleiro; i++)
    {
        for (int j = 0; j < tamanho_tabuleiro; j++)
        {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
        
    }
    
    return 0;
}