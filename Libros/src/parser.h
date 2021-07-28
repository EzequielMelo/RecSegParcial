#ifndef PARSER_H_
#define PARSER_H_

int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro);
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial);
int parser_LibroFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
