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

PGM *LerPGM(char *entrada);

PGM *cria_PGM(int l, int c, int maxim);

PGM* expande_imagem(PGM *imagem);

PGM* Copia_PGM (PGM* original);

void SalvarPGM(PGM *img, char *saida);

void Convolucao(PGM *img, char **kernel, PGM *saida);

void desaloca_PGM (PGM* alocado);

void desaloca_kernel(char **kernel_alocado);

char** cria_kernel();

#endif // IMAGENS_PGM_H_INCLUDED
