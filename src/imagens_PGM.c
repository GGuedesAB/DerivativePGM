#include "imagens_PGM.h"

PGM *LerPGM(char *entrada)
{
    int i, j;
    char img_format[3];
    PGM *img_retornada;
    img_retornada = (PGM*)malloc(sizeof(PGM));
    FILE *img_original = NULL;
    img_original = fopen(entrada, "r");
    if (NULL == img_original)
    {
        printf("\nO arquivo nao foi encontrado no diretorio, nao pode ser lido ou nao existe.\n");
        exit(1);
    }
    fscanf(img_original, "%s", img_format);
    if (img_retornada == NULL)
    {
        printf("\nErro, nao foi possivel alocar memoria para o programa.\n");
        exit(1);
    }

    fscanf(img_original, "%d %d %d", &img_retornada->c, &img_retornada->l, (int*)&img_retornada->maximo);
    img_retornada = cria_PGM(img_retornada->l, img_retornada->c, img_retornada->maximo);
    for (i=0; i<img_retornada->l; i++)
    {
        for (j=0; j<img_retornada->c; j++)
        {
            fscanf(img_original, "%d", (int*)&img_retornada->imagem[i][j]);
        }
    }
    if (feof(img_original) == 1)
    {
        printf("\nErro ao ler a imagem, os parametros do PGM passado nao condizem com as dimensoes da imagem.\n");
        fclose(img_original);
        exit(1);
    }
    else
    fclose(img_original);
    return img_retornada;
}

void Convolucao(PGM *img, char **kernel, PGM *saida)
{
    int i, j, k, l, soma;
    img = expande_imagem(img);
    for (i=1; i<img->l-1; i++)
    {
        for (j=1; j<img->c-1; j++)
        {
            soma = 0;
            for (l=-1; l<=1; l++)
            {
                for (k=-1; k<=1; k++)
                {
                    {
                        soma = soma + (kernel[l+1][k+1]*img->imagem[i+l][j+k]);
                    }
                }
            }
            if (soma < 0)
            {
                soma = 0;
            }
            else if (soma > 255)
            {
                soma = 255;
            }
            saida->imagem[i-1][j-1] = soma;
        }
    }
}

char** cria_kernel()
{
    char** kernel;
    int i, j;
    kernel = (char**)malloc(3*sizeof(char*));
    for (i=0; i<3; i++)
    {
        kernel[i] = (char*)malloc(sizeof(char));
    }
    for (i=0; i<3; i++)
    {
        for (j=0;j<3;j++)
        {
            if (0 == j)
            {
                kernel[i][j] = 1;
            }
            else if (1 == j)
            {
                kernel[i][j] = 0;
            }
            else if (2 == j)
            {
                kernel[i][j] = -1;
            }
        }
    }
    return kernel;
}

PGM* cria_PGM (int l, int c, int maximo)
{
    int i;
    PGM* novo_PGM;
    novo_PGM = (PGM*)malloc(sizeof(PGM));
    novo_PGM->l = l;
    novo_PGM->c = c;
    novo_PGM->maximo = maximo;
    novo_PGM->imagem = (unsigned char**)malloc(l*sizeof(unsigned char*));
    if (NULL == novo_PGM->imagem)
    {
        fprintf(stderr, "\nErro, nao foi possivel alocar memoria para o programa.\n");
        exit(1);
    }
    for (i=0;i<l;i++)
    {
        novo_PGM->imagem[i] = (unsigned char*)malloc(c*sizeof(unsigned char));
        if (NULL == novo_PGM->imagem[i])
        {
            fprintf(stderr, "\nErro, nao foi possivel alocar memoria para o programa.\n");
            exit(1);
        }
    }
    return novo_PGM;
}

PGM* expande_imagem (PGM* img)
{
    int i, j;
    PGM* expandida;
    expandida = cria_PGM(img->l+2, img->c+2, img->maximo);
    for (i=0; i<img->l; i++)
    {
        for (j=0; j<img->c; j++)
        {
            expandida->imagem[i+1][j+1] = img->imagem[i][j];
        }
    }
    i=0;
    for (j=0; j<expandida->c; j++)
    {
        if (j==1 || j==expandida->c-1)
        {
            i--;
        }
        expandida->imagem[0][j] = img->imagem[0][i];
        expandida->imagem[expandida->l-1][j] = img->imagem[img->l-1][i];
        i++;
    }
    j=0;
    for (i=1; i<expandida->l-1;i++)
    {
        expandida->imagem[i][0] = img->imagem[i-1][0];
        expandida->imagem[i][expandida->c-1] = img->imagem[i-1][img->c-1];
    }
    return expandida;
}

PGM* Copia_PGM (PGM* original)
{
    PGM *Copia;
    Copia = cria_PGM(original->l, original->c, original->maximo);
    return Copia;
}

void SalvarPGM(PGM *img, char *saida)
{
    int i, j;
    FILE* imagem_final = NULL;
    imagem_final = fopen(saida, "w");
    if (NULL == imagem_final)
    {
        printf("\nErro, nao foi possivel criar um PGM de saida.\n");
        exit(1);
    }
    fprintf(imagem_final, "P2\n");
    fprintf(imagem_final, "%d %d %d\n", img->c, img->l, img->maximo);
    for (i=0; i<img->l;i++)
    {
        for (j=0; j<img->c;j++)
        {
            if (j==img->c-1)
            {
                fprintf(imagem_final, "%d\n", img->imagem[i][j]);
            }
            else
            {
                fprintf(imagem_final, "%d ", img->imagem[i][j]);
            }
        }
    }
    fclose(imagem_final);
}

void desaloca_PGM(PGM* alocado)
{
    int i;
    for (i=0; i<alocado->c ;i++)
    {
        free(alocado->imagem[i]);
    }
    free(alocado->imagem);
    free(alocado);
}

void desaloca_kernel(char **kernel_alocado)
{
    int i;
    for (i=0; i<3; i++)
    {
        free(kernel_alocado[i]);
    }
    free(kernel_alocado);
}
