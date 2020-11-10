#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
/// <summary>
///   Gera tabela const char idx[256]
/// 
/// O unico parametro opcional e o nome do arquivo
/// que sera gerado no diretorio corrente. Sem isso
/// a tabela sera apenas mostrada na saida padrao
/// 
/// </summary>
/// <param name="[arquivo de saida]"></param>
/// 
/// <returns>o arquivo em disco ou a tabela na tela</returns>
int main(int argc, char** argv)
{
	FILE* saida = stdout;
	int disco = 0; // gerou arquivo?
	char ref[256] = { 0 };
	int out = 1;
	// inserir a tabela aqui
	// inserir a tabela aqui
	if (argc > 1)
	{
		saida = fopen(argv[1], "w");
		disco = 1;
	};
	fprintf(saida, "\nconst char idx[256] =\n{\n\n");
	for (int i = 0; i < 240; i = i + 1)
	{
		fprintf(saida, "%3d, ", ref[i]);
		if (out % 16 == 0)
			fprintf(saida, " // %03d-%03d\n", out - 16, out - 1);
		out += 1;
	};
	// ultima linha
	for (int i = 240; i < 254; i = i + 1)
	{
		fprintf(saida, "%3d, ", ref[i]);
		out += 1;
	};
	// ultimo valor na ultima linha :) 
	fprintf(saida, "%3d, ", ref[255]);
	if (out % 16 == 0) fprintf(saida, " // %03d-%03d\n", out - 16, out - 1);
	out += 1;
	// ultimo valor
	fprintf(saida, "  0   // 240-255\n\n}; // ARFNeto '20\n");
	if (disco) fprintf(stderr, "\nGerado trecho de codigo em '%s'\n", argv[1]);
	return 0;
};	// main()

