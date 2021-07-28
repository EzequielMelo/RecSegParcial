#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Libros.h"
#include "parser.h"
#include "funcionesGet.h"
#define ATTEMPS 3
#define NAMETAM 128

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArraylistaLibros, LinkedList* pArraylistaEditoriales)
{
	FILE* pFile;
	FILE* pFileEd;
	int rtn=-1;

	if((pFile=fopen(path, "r"))!=NULL)
	{
		pFileEd = fopen("editoriales.csv", "r");
		ll_clear(pArraylistaLibros);

		if(!parser_LibroFromText(pFile, pArraylistaLibros))
		{
			parser_EditorialFromText(pFileEd, pArraylistaEditoriales);
			rtn= 0;
		}

	}
    return rtn;
}

int controller_loadFromBinary(char* path , LinkedList* pArraylistaLibros, LinkedList* pArraylistaEditoriales)
{
	FILE* pFile;
	FILE* pFileEd;
	int rtn=-1;
	if((pFile = fopen(path, "rb"))!= NULL)
	{
		pFileEd = fopen("editoriales.csv", "r");
		ll_clear(pArraylistaLibros);
		if(!parser_LibroFromBinary(pFile, pArraylistaLibros))
		{
			parser_EditorialFromText(pFileEd, pArraylistaEditoriales);
			rtn=0;
		}
	}
    return rtn;
}



/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

/*
int controller_addLibro(LinkedList* pArraylistaLibros)
{
	int rtn=-1;//error
	Libro* libro;
	//FILE *pFile;
	int id;
	char auxTitulo[128];
	char auxAutor[128];
	int auxPrecio;
	int auxEditorial;
	int option;

	if(pArraylistaLibros!=NULL)
	{
		libro=Libros_new();
		if(libro!=NULL)
		{
			getIntNumber(&id, "Ingrese un ID:",
					"Error ID invalida", 1, 10000, ATTEMPS);
			getStringChar(auxTitulo, "Ingrese un autor: ",
					"Error ingrese caracteres validos", 128, ATTEMPS, 1);
			getStringChar(auxAutor, "Ingrese un autor: ",
					"Error ingrese caracteres validos", 128, ATTEMPS, 1);
			getIntNumber(&auxPrecio, "Ingrese horas trabajadas:",
					"Error ingrese un horario valido", 1, 30000, ATTEMPS);
			getIntNumber(&auxEditorial, "Ingrese el sueldo:",
					"Error sueldo valido", 1, 300000, ATTEMPS);
			libro_setId(libro, id);
			libro_setTitulo(libro, auxTitulo);
			libro_setAutor(libro, auxAutor);
			libro_setPrecio(libro, auxPrecio);
			libro_setEditorial(libro, auxEditorial);
			if(!getIntNumber(&option, "Desea cargar los Datos?\n1-SI\n2-NO",
					"Error opcion invalida", 1, 2, ATTEMPS))
			{
				if(!ll_add(pArraylistaLibros, libro))
				{
					puts("Libro Cargado con exito");
					printf("%d,%s,%s,%d,%d\n", (*libro).id, (*libro).titulo, (*libro).autor, (*libro).precio, (*libro).editorialId);
					rtn=0;
				}
			}
		}

	}

    return rtn;
}
*/

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* employee;
	int rtn=-1;
	int idToGet;
	int i;
	int len;
	int option;
	int subOption;
	char auxNombre[NAMETAM];
	int auxHorasTrabajadas;
	int auxSueldo;

	setbuf(stdout,NULL);
	puts("Ingrese el ID del empleado:");
	scanf("%d", &idToGet);

	len=ll_len(pArrayListEmployee);
	for(i=0;i<len;i++)
	{
		employee=ll_get(pArrayListEmployee, i);
		if(employee->id == idToGet)
		{
			employee=ll_get(pArrayListEmployee, i);
			do
			{
				puts("Este es el empleado que desea modificar:");
				printf("%d,%s,%d,%d\n", employee->id,
										employee->nombre,
										employee->horasTrabajadas,
										employee->sueldo);
				getIntNumber(&option, "Ingrese\n1-SI desea modificar:\n2-NO desea modificar:\n",
									"Error opcion invalida", 1, 2, ATTEMPS);
				switch(option)
				{
				case 1:
				do
				{
					getIntNumber(&subOption, "Ingrese:\n1-Modificar nombre:\n2-Modificar horas trabajadas:\n"
										  "3-Modificar sueldo:\n4-Salir:\n",
										"Error opcion invalida", 1, 4, ATTEMPS);
				switch(subOption)
				{
					case 1:
						getStringChar(auxNombre, "Ingrese el nuevo nombre:\n",
									 "Error ingrese caracteres validos", NAMETAM, ATTEMPS);
						employee_setNombre(employee, auxNombre);
						break;
					case 2:
						getIntNumber(&auxHorasTrabajadas, "Ingrese horas trabajadas:",
								"Error ingrese un horario valido", 1, 30000, ATTEMPS);
						employee_setHorasTrabajadas(employee, auxHorasTrabajadas);
						break;
					case 3:
						getIntNumber(&auxSueldo, "Ingrese el sueldo:",
											"Error sueldo valido", 1, 300000, ATTEMPS);
						employee_setSueldo(employee, auxSueldo);
						break;
				}
				}while(subOption!=4);
				break;
				}
			}while(option!=2);

		}
	}

    return rtn;
}
*/
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* employee;
	int rtn=-1;
	int idToGet;
	int i;
	int len;
	int option;

	setbuf(stdout,NULL);
	puts("Ingrese el ID del empleado:");
	scanf("%d", &idToGet);

	len=ll_len(pArrayListEmployee);
	for(i=0;i<len;i++)
	{
		employee=ll_get(pArrayListEmployee, i);
		if(employee->id == idToGet)
		{
			employee=ll_get(pArrayListEmployee, i);

			puts("Este es el empleado que desea eliminar:");
			printf("%d,%s,%d,%d\n", employee->id,
									employee->nombre,
									employee->horasTrabajadas,
									employee->sueldo);
			getIntNumber(&option, "Ingrese\n1-SI desea eliminar:\n2-NO desea eliminar:\n",
								"Error opcion invalida", 1, 2, ATTEMPS);
			if(option==1)
			{
				puts("Empleado removido con exito");
				ll_remove(pArrayListEmployee, i);
				break;
			}else
			{
				puts("Operacion cancelada");
			}
		}
	}
    return rtn;
}
*/
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_listLibro(LinkedList* pArraylistaLibros, LinkedList* pArrayListaEditoriales)
{
	int rtn=-1;
	int len;
	int lenEd;

	if(pArraylistaLibros != NULL && pArrayListaEditoriales != NULL)
	{
		len=ll_len(pArraylistaLibros);
		lenEd=ll_len(pArrayListaEditoriales);
		libro_showLibroYEditoriales(pArraylistaLibros, pArrayListaEditoriales, 0, len, lenEd);
		rtn=1;
	}
	puts("Final");
    return rtn;
}

int controller_mostrarTodo(LinkedList* pArrayListeLibro)
{
	int rtn = -1;
	int cantidad;
	int i;
	Libro* libro;
	if(pArrayListeLibro != NULL)
	{
		if(!ll_isEmpty(pArrayListeLibro))
		{
			cantidad= ll_len(pArrayListeLibro);
			for(i=0; i<cantidad; i++)
			{
				libro = ll_get(pArrayListeLibro, i);
				Libro_mostrarUno(libro);
			}
			printf("\n\tCantidad libros: %d\n", cantidad);
			rtn = 0;
		}
		else
		{
			rtn = 1; //no hay elementos para listar.
		}
	}
	return rtn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortLibro(LinkedList* pArraylistaLibros)
{
	/*
	int parameter=0;
	parameter=libro_compareParameter("Indique el modo:\n1. (Z-A)\n2. (A-Z)\n");
	*/
	ll_sort(pArraylistaLibros, libro_comparebyAutor, 1);

    return 1;
}

int controller_discountLibro(LinkedList* pArraylistaLibros, LinkedList* pArraylistaEditoriales)
{
	int rtn = -1;

	if(pArraylistaLibros!= NULL)
	{
		rtn=1;
		if(!ll_isEmpty(pArraylistaLibros))
		{
			if(!ll_map(pArraylistaLibros, libro_discount))
			{
				controller_listLibro(pArraylistaLibros, pArraylistaEditoriales);
				rtn=0;
			}
		}
	}
	/*
	librosDesc = ll_map(pArraylistaLibros, libro_discount);
	puts("Se aplicaran descuentos a:");
	controller_listLibro(librosDesc, pArrayListaEditoriales);
	*/


    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_saveAsText(char* path , LinkedList* pArraylistaLibros)
{
	Libro* libros;
	FILE *pFile;
	int rtn=-1;
	int i;
	int max;
	max=ll_len(pArraylistaLibros);

	pFile=fopen(path, "w");
	for(i=0; i<max; i++)
	{
		libros=ll_get(pArraylistaLibros, i);
		fprintf(pFile,"%d,%s,%s,%d,%d\n", libros->id,
										libros->titulo,
										libros->autor,
										libros->precio,
										libros->editorialId);
		rtn=0;
	}
    return rtn;
}

int controller_saveAsBinary(char* path , LinkedList* pArraylistaLibros)
{
	Libro* libros;
	FILE *pFile;
	int rtn=-1;
	int i;
	int max=0;
	max=ll_len(pArraylistaLibros);

	pFile=fopen(path, "wb");
	for(i=0; i<max; i++)
	{
		libros=ll_get(pArraylistaLibros, i);
		fwrite(libros, sizeof(Libro), 1, pFile);
		rtn=0;
	}

    return rtn;
}

