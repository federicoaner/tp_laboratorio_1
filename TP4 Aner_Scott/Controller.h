int controller_loadFromText(char* path , LinkedList* pArrayListTarjeta);
int controller_loadFromBinary(char* path , LinkedList* pArrayListTarjeta);
int controller_addTarjeta(LinkedList* pArrayListTarjeta);
int controller_editTarjeta(LinkedList* pArrayListTarjeta);
int controller_removeTarjeta(LinkedList* pArrayListTarjeta);
int controller_ListTarjeta(LinkedList* pArrayListTarjeta);
int controller_sortTarjeta(LinkedList* pArrayListTarjeta);
int controller_saveAsText(char* path , LinkedList* pArrayListTarjeta);
int controller_saveAsBinary(char* path , LinkedList* pArrayListTarjeta);
int OrderByName(void* a, void* b);


