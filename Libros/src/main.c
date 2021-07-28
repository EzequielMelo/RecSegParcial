/*
 ============================================================================
 Name        : Libros.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Libros.h"
#include "parser.h"
#include "funcionesGet.h"
#define ATTEMPS 3

int main(void)
{
    int option = 0;
    setbuf(stdout, NULL);
    LinkedList* listaLibros = ll_newLinkedList();
    LinkedList* listaEditoriales = ll_newLinkedList();
    char archivo[128];
    int cargo;

    puts("Bienvenido!!! Ingrese una opcion:");
    do{
        puts("1. Cargar datos de libros.");
        puts("2. Añadir nuevo libro");
        puts("3. Modificar datos de libros");
        puts("4. Eliminar libro");
        puts("5. Listar libros");
        puts("6. Ordenar libros");
        puts("7. Guardar nuevos datos");
        puts("8. Salir");

		getIntNumber(&option, "Ingrese una opcion del menu:",
				"Error opcion invalida", 0, 10, ATTEMPS);
        switch(option)
        {
            case 1:
            	getStringChar(archivo, "Ingrese el nombre del archivo", "Error opcion incorrecta", 128, ATTEMPS, 3);
            	strcat(archivo, ".csv");
                cargo=controller_loadFromText(archivo, listaLibros, listaEditoriales);
                if(cargo==0)
                {
                	puts("Archivo cargado con exito");
                }else
                {
                	puts("Error en la carga");
                }
                break;
            case 2:
            	controller_sortLibro(listaLibros);
            	break;
            case 3:
            	controller_listLibro(listaLibros, listaEditoriales);
                break;
            case 4:
            	controller_discountLibro(listaLibros, listaEditoriales);
                break;
            case 5:
            	controller_saveAsText("mapeado.csv" , listaLibros);
                break;
            case 6:
            	getStringChar(archivo, "Ingrese el nombre del archivo", "Error opcion incorrecta", 128, ATTEMPS, 3);
            	strcat(archivo, ".bin");
            	controller_loadFromBinary(archivo , listaLibros, listaEditoriales);
                break;
            case 7:
            	controller_saveAsBinary("datos.bin" , listaLibros);
                break;
            case 8:
            	controller_mostrarTodo(listaLibros);
            	break;
        }
    }while(option != 9);
    ll_deleteLinkedList(listaLibros);
    ll_deleteLinkedList(listaEditoriales);
    return 0;
}
