#ifndef LIBROS_H_
#define LIBROS_H_

typedef struct
{
	int id;
    char editorial[128];
}Editorial;

typedef struct
{
    int id;
    char titulo[128];
    char autor[128];
    int precio;
    int editorialId;
}Libro;

Editorial* Editorial_new();
Editorial* Editorial_newParametros(char* idStr, char* editorialStr);
Libro* libros_new();
Libro* libro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialStr);

int editorial_setId(Editorial* this, int id);
int editorial_setEditorial(Editorial* this, char* editorial);
int libro_setId(Libro* this, int id);
int Libro_getId(Libro* this, int* id);
int libro_setTitulo(Libro* this, char* titulo);
int Libro_getTitulo(Libro* this, char* autor);
int libro_setAutor(Libro* this, char* autor);
int Libro_getAutor(Libro* this, char* autor);
int libro_setPrecio(Libro* this, int precio);
int Libro_getPrecio(Libro* this, int* precio);
int libro_setEditorial(Libro* this, int editorialId);
int Libro_getEditorial(Libro* this, int* editorialId);

int Libro_mostrarUno(Libro* libro);
void libro_showLibroYEditoriales(LinkedList* pArraylistaLibros, LinkedList* pArraylistaEditoriales, int min, int max, int maxEd);
int libro_compareParameter(char* message);
int libro_comparebyAutor(void* aut1, void* aut2);
int libro_discount(void* cost);


#endif /* LIBROS_H_ */
