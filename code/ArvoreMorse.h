#ifndef ARVOREMORSE_H_INCLUDED
#define ARVOREMORSE_H_INCLUDED
/**
 * Autor: Paulo Henrique
 */

typedef struct No* Apontador;

typedef struct No{
    char Caractere;
    char Mletra[7];
    Apontador esq, dir;
}No; // Estrutura do no da arvore com as letras ta tabela morse.

void CriaArvore(Apontador* raiz); // Inicializa a arvore apenas com a raiz.
void InsereArvore(Apontador* no, char Letra, char* CodMorse, int j); // Insere letra por letra na arvore.
void InsereTabela(Apontador *Arvore);// insere a tabela inteira na arvore com auxilio da funcao "InsereArvore".
void ImprimeArvore(Apontador no); // Imprime todas as letras e seus respectivos "caminhos" na arvore.

void Codificar(Apontador no, char * Morse, char Letra); // Pega letra por letra da entrada, e obtem o seu codigo morse.
void codificarTexto (Apontador Arvore); // Percorre a entrada passando letra por letra como parametro pra funcao "Codificar".
void traduzirCodigoMorse(Apontador Arvore); // Percorre a entrada mandando o codigo de cada letra para a funcao "decodificar".
void decodificar(Apontador Arvore,char* morse,char *letra); // recebe cada codigo e encontra a letra equivalente.


#endif // ARVOREMORSE_H_INCLUDED
