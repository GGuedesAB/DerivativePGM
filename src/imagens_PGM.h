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
Prot�tipo: char** CriaKernel().
Fun��o: Alocar din�micamente e atribuir valores da matriz "kernel de Prewitt" a
um char**.
Entrada: Vazio.
Sa�da: Matriz 3x3 do tipo kernel de Prewitt.
-----------------------------------------------------------------------------*/
char**CriaKernel();



/*---------------------------------------------------------------------------
Prot�tipo: char** DesalocaKernel(char **kernel_alocado).
Fun��o: Desalocar a matriz "kernel de Prewitt" previamente alocada.
Entrada: A matriz "kernel de Prewitt" alocada.
Sa�da: Vari�vel desalocada e apontando para NULL.
-----------------------------------------------------------------------------*/
char** DesalocaKernel(char **kernel_alocado);



/*---------------------------------------------------------------------------
Prot�tipo: PGM* LerPGM(char *entrada).
Fun��o: Ler a imagem de um arquivo "*.pgm" e a retornar para um ponteiro de PGM.
Entrada: O nome do arquivo a ser lido.
Sa�da: A imagem do tipo pgm lida do arquivo.
-----------------------------------------------------------------------------*/
PGM* LerPGM(char *entrada);




/*---------------------------------------------------------------------------
Prot�tipo: PGM* CriaPGM(int l, int c, int maxim).
Fun��o: Alocar um ponteiro do tipo PGM e seu elemento imagem segundo o numero
de linhas, numero de colunas e valor maximo de um pixel.
Entrada: Numero de linhas, numero de colunas, valor maximo do pixel.
Sa�da: Um ponteiro do tipo PGM e seu elemento imagem devidamente alocados.
-----------------------------------------------------------------------------*/
PGM* CriaPGM(int l, int c, int maxim);




/*---------------------------------------------------------------------------
Prot�tipo: PGM* DesalocaPGM (PGM *alocado).
Fun��o: Desalocar um ponteiro do tipo PGM.
Entrada: Um ponteiro do tipo PGM que est� alocado.
Sa�da: Um ponteiro do tipo PGM e seu elemento imagem devidamente desalocados e
apontando para NULL.
-----------------------------------------------------------------------------*/
PGM* DesalocaPGM (PGM *alocado);




/*---------------------------------------------------------------------------
Prot�tipo: PGM* ExpandeImagem(PGM* imagem).
Fun��o: Expandir o elemento imagem contido em um ponteiro do tipo PGM,
preparando-o para a convolu��o.
Entrada: Um ponteiro do tipo PGM.
Sa�da: O elemento imagem do tipo PGM expandido.
-----------------------------------------------------------------------------*/
PGM* ExpandeImagem(PGM *imagem);




/*---------------------------------------------------------------------------
Prot�tipo: PGM* AlocaPGM(PGM* original).
Fun��o: Alocar um ponteiro do tipo PGM segundo outro ponteiro do tipo PGM.
Entrada: Um ponteiro do tipo PGM.
Sa�da: Um ponteiro do tipo PGM e seu elemento imagem devidamente alocados.
-----------------------------------------------------------------------------*/
PGM* AlocaPGM (PGM* original);




/*---------------------------------------------------------------------------
Prot�tipo: void SalvarPGM(PGM *img, char *saida).
Fun��o: Salvar em um arquivo "*.pgm" um tipo PGM.
Entrada: Um ponteiro do tipo PGM e o nome do arquivo que ser� salvado.
Sa�da: Um arquivo "*.pgm" com o conte�do de um tipo PGM.
-----------------------------------------------------------------------------*/
void SalvarPGM(PGM *img, char *saida);




/*---------------------------------------------------------------------------
Prot�tipo: PGM* Convolucao(PGM *img, char **kernel, PGM *saida).
Fun��o: Realizar a opera��o de convolu��o entre o elemento imagem de um tipo
PGM e a matriz kernel e salvar o resultado em um outro tipo PGM.
Entrada: Um ponteiro do tipo PGM , uma matriz kernel e outro ponteiro do tipo
PGM.
Sa�da: O resultado da opera��o de convolu��o entre o elemento imagem do ponteiro
do tipo PGM "img" e a matriz "kernel".
-----------------------------------------------------------------------------*/
void Convolucao(PGM *img, char **kernel, PGM *saida);

#endif // IMAGENS_PGM_H_INCLUDED
