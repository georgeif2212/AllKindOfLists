typedef struct Alumno
{
  int id;
  char name[20];
  int edad;
} Alumno;

typedef struct Nodo
{
  Alumno *datos;
  struct Nodo *sig;
} Nodo;

typedef struct ListaSC
{
  Nodo *cabeza;
  Nodo *cola;
} ListaSC;

// Alumno* crear_Alumno(int ID);
Alumno *crear_Alumno(int ID, char NAME[20], int EDAD);
Nodo *crear_Nodo(Alumno *alumno);
ListaSC *crear_ListaSC();
int isEmpty(ListaSC lista);
void insertar_cabeza(ListaSC *lista, Nodo *aux);
void insertar_cola(ListaSC *lista, Nodo *elemento);
void insertar_enmedio(ListaSC *lista, Nodo *despues, Nodo *elemento);
void quitar_cabeza(ListaSC *lista);
void quitar_cola(ListaSC *lista);
void quitar_enmedio(ListaSC *lista, Nodo *elemento);
Nodo *buscaElemento(ListaSC *lista, Nodo *elemento);
void vaciarLista(ListaSC *lista);
void printLista(ListaSC *lista);