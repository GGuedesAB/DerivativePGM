#include "imagens_PGM.h"

int main(int argc, char *argv[])
{
    for(int i = DEFAULT_ARG_NUMBER-1; i > 0; i--)
    {
        if(NULL == argv[i]){
            printf("Missing arguments.\nCorrect example: \"./a.out source.pgm destination.pgm\" \n");
            exit(0);
        }
    }
    char **kernel = CriaKernel();
    PGM *minha_img = LerPGM(argv[1]);
    PGM *saida = AlocaPGM(minha_img);
    minha_img = ExpandeImagem(minha_img);
    Convolucao(minha_img, kernel, saida);
    SalvarPGM(saida, argv[2]);
    saida = DesalocaPGM(saida);
    minha_img = DesalocaPGM(minha_img);
    kernel = DesalocaKernel(kernel);
    if (NULL == saida && NULL == minha_img && NULL == kernel)
    {
        printf("\n\n**Convolucao feita com sucesso.**\n\n");
    }
    else
    {
        printf("\n\nOcorreu um erro ao desalocar os espaços de memoria utilizados.\n");
        exit(1);
    }
    return 0;
}
