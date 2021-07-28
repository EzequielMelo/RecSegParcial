#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Libros.h"
#include "parser.h"
#include "funcionesGet.h"
#define ATTEMPS 3

Editorial* Editorial_new()
{
	Editorial* newEditorial = NULL;
	newEditorial= (Editorial*)malloc(sizeof(Editorial));
	if(newEditorial!=NULL)
	{
		newEditorial->id=0;
		strcpy(newEditorial->editorial, " ");
	}
	return newEditorial;
}

Editorial* Editorial_newParametros(char* idStr, char* editorialStr)
{
	Editorial* newEditorial;
	if(idStr != NULL && editorialStr != NULL)
	{
		newEditorial= (Editorial*)malloc(sizeof(Editorial));
		if(newEditorial != NULL)
		{
			newEditorial->id=atoi(idStr);
			strncpy(newEditorial->editorial, editorialStr, 128);
		}
	}
	return newEditorial;
}

int editorial_setId(Editorial* this, int id)
{
	int rtn=-1;
	if(this!=NULL && id>0)
	{
		this->id = id;
		rtn=0;
	}
	return rtn;
}

int editorial_setEditorial(Editorial* this, char* editorial)
{
	int rtn=-1;
	if(this!=NULL && editorial!=NULL)
	{
		strcpy(this->editorial, editorial);
		rtn=0;
	}
	return rtn;
}

Libro* libros_new()
{
	Libro* newLibro = NULL;
	newLibro= (Libro*)malloc(sizeof(Libro));
	if(newLibro!=NULL)
	{
		newLibro->id=0;
		strcpy(newLibro->titulo, " ");
		strcpy(newLibro->autor, " ");
		newLibro->precio=0;
		newLibro->editorialId=0;
	}
	return newLibro;
}

Libro* libro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialStr)
{
	Libro* newLibro;
	if(idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && editorialStr != NULL)
	{
		newLibro= (Libro*)malloc(sizeof(Libro));
		if(newLibro != NULL)
		{
			newLibro->id=atoi(idStr);
			strncpy(newLibro->titulo, tituloStr, 128);
			strncpy(newLibro->autor, autorStr, 128);
			newLibro->precio=atoi(precioStr);
			newLibro->editorialId=atoi(editorialStr);
		}
	}
	return newLibro;
}

int libro_setId(Libro* this, int id)
{
	int rtn=-1;
	if(this!=NULL && id>0)
	{
		this->id = id;
		rtn=0;
	}
	return rtn;
}

int Libro_getId(Libro* this, int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int libro_setTitulo(Libro* this, char* titulo)
{
	int rtn=-1;
	if(this!=NULL && titulo!=NULL)
	{
		strcpy(this->titulo, titulo);
		rtn=0;
	}
	return rtn;
}

int Libro_getTitulo(Libro* this, char* autor)
{
	int retorno = -1;
	if(this != NULL && autor != NULL)
	{
		retorno = 0;
		strncpy(autor, this->autor, 128);
	}
	return retorno;
}

int libro_setAutor(Libro* this, char* autor)
{
	int rtn=-1;
	if(this!=NULL && autor!=NULL)
	{
		strcpy(this->titulo, autor);
		rtn=0;
	}
	return rtn;
}

int Libro_getAutor(Libro* this, char* autor)
{
	int retorno = -1;
	if(this != NULL && autor != NULL)
	{
		retorno = 0;
		strncpy(autor, this->autor, 128);
	}
	return retorno;
}

int libro_setPrecio(Libro* this, int precio)
{
	int rtn=-1;
	if(this!=NULL && precio>0)
	{
		this->precio = precio;
		rtn=0;
	}
	return rtn;
}

int Libro_getPrecio(Libro* this, int* precio)
{
	int rtn = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		rtn = 0;
	}
	return rtn;
}

int libro_setEditorial(Libro* this, int editorialId)
{
	int rtn=-1;
	if(this!=NULL && editorialId>0)
	{
		this->editorialId = editorialId;
		rtn=0;
	}
	return rtn;
}

int Libro_getEditorialId(Libro* this, int* editorialId)
{
	int retorno = -1;
	if(this != NULL && editorialId != NULL)
	{
		*editorialId = this->editorialId;
		retorno = 0;
	}
	return retorno;
}

int Libro_mostrarUno(Libro* libro)
{
	int retorno = -1;
	int id;
	char titulo[128];
	char autor[128];
	int editorial;
	int precio;
	if(!Libro_getId(libro, &id) &&
	   !Libro_getTitulo(libro, titulo) &&
	   !Libro_getAutor(libro, autor) &&
	   !Libro_getPrecio(libro, &precio) &&
	   !Libro_getEditorialId(libro, &editorial))
	{
		printf("%d %s  %s %d %d\n", id, titulo, autor, precio, editorial);
		retorno = 0;
	}
	return retorno;
}

void libro_showLibroYEditoriales(LinkedList* pArraylistaLibros, LinkedList* pArraylistaEditoriales,  int min, int max, int maxEd)
{
	int i;
	int j;
	Libro* this;
	Editorial* thisEd;

	for(i=0; i<max; i++)
	{
		this=ll_get(pArraylistaLibros, i);
		for(j=0; j<maxEd; j++)
		{
			thisEd=ll_get(pArraylistaEditoriales, j);
			if(this->editorialId == thisEd->id)
			{
				printf("%d,%s,%s,%d,%s\n", this->id,
											this->titulo,
											this->autor,
											this->precio,
											thisEd->editorial);
			}
		}

	}
}

int libro_compareParameter(char* message)
{
	int option;
	getIntNumber(&option, message,
			"Error opcion invalida", 1, 2, ATTEMPS);
	if(option==1)
	{
		option=0;
	}else
	{
		if(option==2)
		{
			option=1;
		}
	}

	return option;
}

int libro_comparebyAutor(void* aut1, void* aut2)
{
	int comp=-1;
	Libro* autor1;
	Libro* autor2;

	autor1=aut1;
	autor2=aut2;

	comp= strcmp(autor1->autor, autor2->autor);

	return comp;
}

int libro_discount(void* pElement)
{
	int rtn=-1;
	int precio;
	int editorial;
	Libro* libro;
	libro=pElement;

	if(pElement!=NULL && !Libro_getEditorialId(libro, &editorial) && !Libro_getPrecio(libro, &precio))
	{
		rtn=0;
		if(editorial == 1 && precio >= 300)
		{
			precio = precio - (precio * 0.2);
			rtn = libro_setPrecio(pElement, precio);
		}
		if(editorial == 2 && precio <= 200)
		{
			precio = precio - (precio * 0.1);
			rtn = libro_setPrecio(pElement, precio);
		}
	}

	return rtn;
}

/*
void libro_showLibroYEditoriales(LinkedList* pArraylistaLibros, LinkedList* pArraylistaEditoriales,  int min, int max, int maxEd)
{
	int i;
	int j;
	Libro* this;
	Editorial* thisEd;

	for(i=0; i<maxEd; i++)
	{
		thisEd=ll_get(pArraylistaEditoriales, i);
		for(j=0; j<max; j++)
		{
			this=ll_get(pArraylistaLibros, j);
			if(this->editorialId == thisEd->id)
			{
				printf("%d,%s,%s,%d,%s\n", this->id,
											this->titulo,
											this->autor,
											this->precio,
											thisEd->editorial);
			}
		}

	}
}
*/

/*
void libro_showLibroYEditoriales(LinkedList* pArraylistaLibros, LinkedList* pArraylistaEditoriales,  int min, int max, int maxEd)
{
	int i;
	int j;
	Libro* this;
	Editorial* thisEd;

	for(i=0; i<maxEd; i++)
	{
		thisEd=ll_get(pArraylistaEditoriales, i);
		printf("%s\n", thisEd->editorial);

		for(j=0; j<max; j++)
		{
			this=ll_get(pArraylistaLibros, j);
			if(this->editorialId == thisEd->id)
			{
				printf("%d,%s,%s,%d,%d\n", this->id,
											this->titulo,
											this->autor,
											this->precio,
											this->editorialId);
			}
		}

	}
}
*/

