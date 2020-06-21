#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArvoreMorse.h"
/**
 * Autor: Paulo Henrique
 */



int  main(){
    int usuario;
    Apontador Arvore;
    InsereTabela(&Arvore);

    do{
        printf("Menu: \n 1-> Codifica texto. \n 2-> Decodifica texto. \n 3->Imprime tabela. \n Digite 0 para encerrar o programa! \n Entre com a opcao desejada : ");
        scanf("%d",&usuario);
        switch(usuario){
            case 1:
                codificarTexto(Arvore);
                break;
            case 2:
                traduzirCodigoMorse(Arvore);
                break;
            case 3:
                ImprimeArvore(Arvore);
                break;

        }
        printf("\n\n");

    }while (usuario != 0);
    printf("O programa foi encerrado! \n");

    return 0;
}


