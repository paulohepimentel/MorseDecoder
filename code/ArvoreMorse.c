#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArvoreMorse.h"
/**
 * Autor: Paulo Henrique
 */

void CriaArvore(Apontador* raiz){
    *raiz = (Apontador)malloc(sizeof(No));
    (*raiz)->Caractere = '\0';
    (*raiz)->esq = NULL;
    (*raiz)->dir = NULL;
}

void InsereArvore(Apontador* no, char Letra, char* CodMorse, int j){
    if(*no == NULL){
        *no = (Apontador)malloc(sizeof(No));
        (*no)->Caractere = '\0';
        (*no)->dir = NULL;
        (*no)->esq = NULL;
    }
    if (CodMorse[j] == '.' && no != NULL){
        j++;
        InsereArvore(&(*no)->esq, Letra, CodMorse, j);
        return;
    }
    else if (CodMorse[j] == '-' && no != NULL){
        j++;
        InsereArvore(&(*no)->dir, Letra, CodMorse, j);
        return;
    }
    else{
        (*no)->Caractere = Letra;
        strcpy((*no)->Mletra, CodMorse);
        return;
    }
}

void InsereTabela(Apontador *Arvore){

    char Letra;
    char MorseCode[5];
    int i,j;

    FILE *arq;

    CriaArvore(Arvore);

    arq = fopen("TabelaMorse.txt", "r");
    if(arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
    else {
        for(i=0; i<26 ;i++){
            fscanf(arq,"%c %s\n",&Letra,MorseCode);
            j = 0;
            InsereArvore(Arvore,Letra,MorseCode,j);
        }
    }
    fclose(arq);
}

void ImprimeArvore(Apontador no){
    if(no == NULL)
        return;
    ImprimeArvore(no->esq);
    if(no->Caractere != '\0')
        printf("Letra: %c -> %s \n", no->Caractere, no->Mletra);
    ImprimeArvore(no->dir);
}

void Codificar(Apontador no, char * Morse, char Letra){
    if (no == NULL)
        return;

    if(Letra == no->Caractere){
            strcpy(Morse, no->Mletra);
            return;
    }
    Codificar(no->esq,Morse,Letra);
    Codificar(no->dir,Morse,Letra);
}

void codificarTexto (Apontador Arvore){

    char Codificado[300]; // String que conterá a entrada codificada.
    char Morse[10]; // string auxiliar para codificar.
    char ch; // caracter auxiliar para parametro da funcao "Codificar".
    int j=0;
    FILE *arq;

    arq = fopen("Entrada1.txt", "r");
    if(arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
    else{
        while((ch = fgetc(arq))!= EOF ){
            if (ch == ' ')
                strcat(Codificado, " ");
            else{
                Codificar(Arvore,Morse,ch);
                if(j==0){
                    strcpy(Codificado,Morse);
                    strcat(Codificado, " ");
                }else{
                strcat(Codificado, Morse);
                strcat(Codificado, " ");
                }
            }
            j++;
        }
    }
    printf("Texto codificado: %s\n",Codificado);
}

void traduzirCodigoMorse(Apontador Arvore){
    char decodificado[300]; // String que conterá a entrada decodificada.
    char string[200]; // string que recebera o conteudo do arquivo de entrada.
    char morse[10]; // string auxiliar para decodificar.
    int i = 0, j = 0, k = 0;
    char ch;
    char letra;

    for(j=0;j<100;j++){
        string[j] = '\0';
    }

    FILE *arq;

    arq = fopen("Entrada2.txt", "r");
    if(arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
    else{
        //Le o arquivo e o armazena na string auxiliar.
        while((ch = fgetc(arq))!= EOF ){
            string[i] = ch;
            i++;
        }
    }
    i = 0;
    while (string[i] != '\0'){
        j=0;
        if (string[i] != ' '){
            while(string[i] != ' ' && string[i] != '\0'){
                morse[j]= string[i];
                i++;
                j++;
            }
            morse[j] = '\0';
            decodificar(Arvore, morse, &letra);
            if (string[i+1] == ' '){
                decodificado[k] = letra;
                decodificado[k+1] = ' ';
                k += 2;
            }else {
                decodificado[k] = letra;
                k++;
            }
        }else {
            i++;
        }
    }
    decodificado[k] = '\0';
    printf("%s \n", decodificado);
}

 void decodificar(Apontador no,char* morse,char *letra){
    if(no == NULL){
        return;
    }
    if (*morse == '.' ){
        decodificar(no->esq, morse+1, letra);
    }
    else if (*morse == '-'){
        decodificar(no->dir,morse+1, letra);
    }
    else{
        *letra = no->Caractere;
        return;
    }
}
