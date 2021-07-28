int controller_loadFromText(char* path , LinkedList* pArraylistaLibros, LinkedList* pArraylistaEditoriales);
int controller_addLibro(LinkedList* pArraylistaLibros);
int controller_editLibro(LinkedList* pArraylistaLibros);
int controller_removeLibro(LinkedList* pArraylistaLibros);
int controller_listLibro(LinkedList* pArraylistaLibros, LinkedList* pArrayListaEditoriales);
int controller_sortLibro(LinkedList* pArraylistaLibros);
int controller_discountLibro(LinkedList* pArraylistaLibros, LinkedList* pArrayListaEditoriales);
int controller_saveAsText(char* path , LinkedList* pArraylistaLibros);

int controller_loadFromBinary(char* path , LinkedList* pArraylistaLibros, LinkedList* pArraylistaEditoriales);
int controller_saveAsBinary(char* path , LinkedList* pArraylistaLibros);

int controller_mostrarTodo(LinkedList* pArrayListeLibro);


