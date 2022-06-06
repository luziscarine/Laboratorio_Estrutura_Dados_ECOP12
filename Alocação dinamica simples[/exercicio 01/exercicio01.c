#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Struct created by number of item specifics
typedef struct no
{
    int codigo;
    float preco;
    int quantidade_estoque;
    struct No* proximo;
} No;

// Control of items in the principal program

typedef struct lista {
    struct No *inicio;
    struct No *fim;
} Lista;


No * primeiro = NULL; // Ponter for the first element in the list
int total = 0;        // number of elements in the list

No *auxiliar; // two ponter from base on the list
No *anterior;

Lista *cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista)); // necessary by the control the list
    if (li != NULL) // lace if : case the first element in the list is initial, empty or
                   // last position
        {
            li -> fim = NULL;
            li -> inicio = NULL;
        } return li;
}

void insere_produto (Lista *li){

No *novo = (No*) malloc(sizeof(No));

printf("Please insert the code of product: ");           scanf("%i", &novo -> codigo);
printf("Pleas insert the price of product: ");           scanf("%f", &novo -> preco);
printf("Please insert the items in stock of product: "); scanf("%i", &novo -> quantidade_estoque);

if (li->inicio == NULL) {
    li -> inicio = novo; // the initial element apont for the same endress by the new ponter
    li -> fim = novo; // the final element apont for the same endress by the new ponter
    li -> fim -> proximo = NULL;
} else {
    li -> fim -> proximo = novo;
    li -> fim = novo;
    li -> fim -> proximo = NULL;
} printf("\nProduct insert is sucesfull!");
getchar();
}

void aplica_taxa(Lista *li, float taxa) {
    if (li -> inicio == NULL) {
        printf("\n Empty list"); // case the list is empty
    } else { //case the list is not empty
        auxiliar = li -> inicio;
        do {
            // Aplication for the descont
            auxiliar -> preco = auxiliar -> preco - auxiliar -> preco * (taxa/100);
            auxiliar = auxiliar -> proximo; // the auxiliar ponter is directly aponted
                                           // by the next element
        } while (auxiliar != NULL); //case not exists more elements by insertion
        printf("the insertion is complete!");
    }
    getchar();
}



int main ()
{


    getchar();
    return 0;
}
