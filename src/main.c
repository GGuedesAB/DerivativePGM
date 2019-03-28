#include "imagens_PGM.h"
#define DEFAULT_ARG_NUMBER 3

int main(int argc, char *argv[])
{
	for(int i = DEFAULT_ARG_NUMBER-1; i > 0; i--)
	{
		if(NULL == argv[i]){
			printf("Missing arguments.\nCorrect example: \"./a.out source.pgm destination.pgm\" \n");
			exit(0);
		}
	}
    PGM *minha_img;
    PGM *saida;
    char **kernel;
    kernel = cria_kernel();
    minha_img = LerPGM(argv[argc-2]);
    saida = Copia_PGM(minha_img);
    Convolucao(minha_img, kernel, saida);
    SalvarPGM(saida, argv[argc-1]);
    desaloca_PGM(minha_img);
    desaloca_PGM(saida);
    desaloca_kernel(kernel);
    return 0;
}
