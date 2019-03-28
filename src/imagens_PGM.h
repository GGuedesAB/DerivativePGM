#ifndef IMAGENS_PGM_H_INCLUDED
#define IMAGENS_PGM_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int c;                  //Numero de colunas na imagem
    int l;                  //Numero de linhas na imagem
    unsigned char maximo;   //Valor maximo para cada pixel
    unsigned char **imagem; //Variavel para armazenar os pixels da imagem (matriz)
}PGM;

/*---------------------------------------------------------------------------
Protótipo: char** CriaKernel().
Função: Alocar dinâmicamente e atribuir valores da matriz "kernel de Prewitt" a
um char**.
Entrada: Vazio.
Saída: Matriz 3x3 do tipo kernel de Prewitt.
-----------------------------------------------------------------------------*/
char**CriaKernel();



/*---------------------------------------------------------------------------
Protótipo: char** DesalocaKernel(char **kernel_alocado).
Função: Desalocar a matriz "kernel de Prewitt" previamente alocada.
Entrada: A matriz "kernel de Prewitt" alocada.
Saída: Variável desalocada e apontando para NULL.
-----------------------------------------------------------------------------*/
char** DesalocaKernel(char **kernel_alocado);



/*---------------------------------------------------------------------------
Protótipo: PGM* LerPGM(char *entrada).
Função: Ler a imagem de um arquivo "*.pgm" e a retornar para um ponteiro de PGM.
Entrada: O nome do arquivo a ser lido.
Saída: A imagem do tipo pgm lida do arquivo.
-----------------------------------------------------------------------------*/
PGM* LerPGM(char *entrada);




/*---------------------------------------------------------------------------
Protótipo: PGM* CriaPGM(int l, int c, int maxim).
Função: Alocar um ponteiro do tipo PGM e seu elemento imagem segundo o numero
de linhas, numero de colunas e valor maximo de um pixel.
Entrada: Numero de linhas, numero de colunas, valor maximo do pixel.
Saída: Um ponteiro do tipo PGM e seu elemento imagem devidamente alocados.
-----------------------------------------------------------------------------*/
PGM* CriaPGM(int l, int c, int maxim);




/*---------------------------------------------------------------------------
Protótipo: PGM* DesalocaPGM (PGM *alocado).
Função: Desalocar um ponteiro do tipo PGM.
Entrada: Um ponteiro do tipo PGM que está alocado.
Saída: Um ponteiro do tipo PGM e seu elemento imagem devidamente desalocados e
apontando para NULL.
-----------------------------------------------------------------------------*/
PGM* DesalocaPGM (PGM *alocado);




/*---------------------------------------------------------------------------
Protótipo: PGM* ExpandeImagem(PGM* imagem).
Função: Expandir o elemento imagem contido em um ponteiro do tipo PGM,
preparando-o para a convolução.
Entrada: Um ponteiro do tipo PGM.
Saída: O elemento imagem do tipo PGM expandido.
-----------------------------------------------------------------------------*/
PGM* ExpandeImagem(PGM *imagem);




/*---------------------------------------------------------------------------
Protótipo: PGM* AlocaPGM(PGM* original).
Função: Alocar um ponteiro do tipo PGM segundo outro ponteiro do tipo PGM.
Entrada: Um ponteiro do tipo PGM.
Saída: Um ponteiro do tipo PGM e seu elemento imagem devidamente alocados.
-----------------------------------------------------------------------------*/
PGM* AlocaPGM (PGM* original);




/*---------------------------------------------------------------------------
Protótipo: void SalvarPGM(PGM *img, char *saida).
Função: Salvar em um arquivo "*.pgm" um tipo PGM.
Entrada: Um ponteiro do tipo PGM e o nome do arquivo que será salvado.
Saída: Um arquivo "*.pgm" com o conteúdo de um tipo PGM.
-----------------------------------------------------------------------------*/
void SalvarPGM(PGM *img, char *saida);




/*---------------------------------------------------------------------------
Protótipo: PGM* Convolucao(PGM *img, char **kernel, PGM *saida).
Função: Realizar a operação de convolução entre o elemento imagem de um tipo
PGM e a matriz kernel e salvar o resultado em um outro tipo PGM.
Entrada: Um ponteiro do tipo PGM , uma matriz kernel e outro ponteiro do tipo
PGM.
Saída: O resultado da operação de convolução entre o elemento imagem do ponteiro
do tipo PGM "img" e a matriz "kernel".
-----------------------------------------------------------------------------*/
void Convolucao(PGM *img, char **kernel, PGM *saida);

#endif // IMAGENS_PGM_H_INCLUDED
