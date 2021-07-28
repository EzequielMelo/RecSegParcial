#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libros.h"
#include "parser.h"
#include "funcionesGet.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro)
{

	int rtn=-1;
	char id[128];
	char titulo[128];
	char autor[128];
	char precio[128];
	char editorial[128];
	char aux[128];
	Libro* libro;
	if(pFile != NULL && pArrayListLibro != NULL)
	{
		fscanf(pFile,"%s\n",aux);
		do
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, editorial);
			libro = libro_newParametros(id, titulo, autor, precio, editorial);
			if(libro != NULL)
			{
				ll_add(pArrayListLibro, libro);
				rtn=0;
			}
		}while(!feof(pFile));
	}
    return rtn;
}

int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial)
{

	int rtn=-1;
	char id[128];
	char editorial[128];
	char aux[128];
	Editorial* editoriales;
	if(pFile != NULL && pArrayListEditorial != NULL)
	{
		fscanf(pFile,"%s\n",aux);
		do
		{
			fscanf(pFile,"%[^,],%[^\n]\n",id ,editorial);
			editoriales = Editorial_newParametros(id, editorial);
			if(editoriales != NULL)
			{
				ll_add(pArrayListEditorial, editoriales);
				rtn=0;
			}
		}while(!feof(pFile));
	}
    return rtn;
}

/*
int parser_LibroFromBinary(FILE* pFile , LinkedList* pArrayListLibro)
{
	int len=0;
	Libro* libro;
	int rtn=-1;

	if(pFile != NULL && pArrayListLibro != NULL)
	{
		len = ll_len(pArrayListLibro);
		//libro = libros_new();
		fread(libro, sizeof(Libro), len, pFile);
		if(!ll_add(pArrayListLibro, libro))
		{
			rtn = 0;
			//printf("%d,%s,%s,%d,%d\n", (*(libro)).id, (*(libro)).titulo, (*(libro)).autor, (*(libro)).precio, (*(libro)).editorialId);
		}
	}
    return rtn;
}
*/

int parser_LibroFromBinary(FILE* pFile , LinkedList* pArrayListLibro)
{
	int retorno = -1; //Error
	Libro* libros;
	if(pFile != NULL && pArrayListLibro != NULL)
	{
		do
		{
			libros = libros_new();
			if(fread(libros, sizeof(Libro), 1, pFile) == 1 &&
			   !ll_add(pArrayListLibro, libros))
			{
				retorno = 0;
			}
		}while(!feof(pFile));

	}
    return retorno;
}
