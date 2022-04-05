#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct lista {
        int dado;
        struct lista *prox
    };
    typedef struct lista Lista;
    int tamanho;



    int inicializa (Lista **lista) {
        printf("Inicializando lista...\n\n");
        *lista = NULL;
    }



    int vazia (Lista* lista) {
        return (lista == NULL);
    }


    void inserir_inicio (Lista **lista, int valor) {
        Lista* nova_lista;

        nova_lista = (Lista*) malloc(sizeof(Lista));
        nova_lista->dado = valor;
		nova_lista->prox = NULL;

        if (*lista == NULL ) {
            *lista = nova_lista;
        } else {
            nova_lista->prox = *lista;
            *lista = nova_lista;
        }
    }




	void inserir_final (Lista **lista, int valor) {
        Lista *lista_nova, *percorre;

        lista_nova = (Lista*) malloc(sizeof(Lista));
        lista_nova->dado = valor;
        lista_nova->prox = NULL;

		if (*lista == NULL) {
			*lista = lista_nova;
		} else {
			percorre = *lista;
			while (percorre->prox != NULL) {
				percorre = percorre->prox;
			}
			percorre->prox = lista_nova;
		}
    }



    int busca (Lista* lista, int valor)
    {
        Lista* nova_lista;

        for (nova_lista =lista ; nova_lista != NULL; nova_lista = nova_lista->prox) {
            if  (nova_lista->dado == valor) {
                printf("Valor %d encontrado no endereço %d\n", nova_lista->dado, nova_lista);
            }
        }

        return NULL; /* não achou o elemento */
    }



    int retira_dado (Lista *lista, int valor) {
    	Lista *percorre;
    	Lista *anterior;

    	if (lista != NULL) {
    		while (percorre->dado != valor) {
    			anterior = percorre;
    			percorre = percorre->prox;
			};

			anterior->prox = percorre->prox;
			free(percorre);
		} else {
			printf("Lista vazia!");
		}
	}



	int retira_inicio (Lista **lista) {
    	Lista *aux1;

    	if (*lista != NULL) {
			aux1 = *lista;
			*lista = (*lista)->prox;
			free(aux1);
		} else {
			printf("Lista vazia!");
		}
	}



	int retira_final (Lista **lista) {
    	Lista *aux1, *percorre;

    	percorre = *lista;

    	if (*lista != NULL) {
			while (percorre != NULL) {
			    aux1 = percorre->prox;
                percorre = percorre->prox;
			}

			//aux1->prox = percorre;
			free(percorre);
		} else {
			printf("Lista vazia!");
		}
	}



    int obter_tamanho (Lista *lista, int *tam) {
        Lista *percorre;
        *tam = 0;

        if (lista != NULL) {
            percorre = lista;
            while (percorre != NULL) {
                (*tam)++;
                percorre = percorre->prox;
            }
        } else {
            printf("Lista Vazia! Impossível encontrar o tamanho.\n");
        }

        return *tam;
    }



    int obter_primeiro_valor(Lista **lista) {
        Lista *percorre;
        percorre = lista;

        if (lista != NULL) {
            printf("Primeiro dado da lista: %d\n", percorre->dado);
        } else {
            printf("Lista Vazia!\n");
        }
    }



    int obter_ultimo_valor(Lista **lista) {
        int tam, count_pos;
        Lista *percorre;
        percorre = lista;

        obter_tamanho(lista, &tam);
        count_pos = 0;
        if (lista != NULL) {
            while (count_pos < tam-1) {
                percorre = percorre->prox;
                count_pos++;
            }

            printf("Último dado da lista: %d\n\n", percorre->dado);
        } else {
            printf("Lista Vazia!\n");
        }
    }



    int inverter_lista (Lista *lista) {

	}



	int remover_penultimo (Lista **lista) {
		Lista *antepenultimo, *penultimo, *ultimo, *percorre;
		int tam, i;

		obter_tamanho(*lista, &tam);
		if ((tam == 0) || (tam == 1))
			return 103;

		if (tam == 2) {
			penultimo = *lista;
			ultimo = penultimo->prox;
			free(penultimo);
			*lista = ultimo;
			return 0;
		} else {
			percorre = *lista;
			for (i = 1; i < tam-2; i++) {
				percorre = percorre->prox;
			}

			antepenultimo = percorre;
			penultimo = antepenultimo->prox;
			ultimo = penultimo->prox;

			free(penultimo);
			antepenultimo->prox = ultimo;
			return 0;
		}
	}



    void imprimir_lista (Lista *lista) {
        Lista *percorre;

        percorre = lista;

		if (lista == NULL) {
			printf("Lista vazia!");
		}

        do {
        	printf("%d ", lista->dado);
            lista = lista->prox;
		} while (lista != NULL);
		printf("\n");
    }



    printf("Programa criador de Lista Encadeada 2.\n\n");

    Lista *lista;

    inicializa(&lista);

    printf("\nInserindo dados no início:\n");
    inserir_inicio(&lista, 23);
    inserir_inicio(&lista, 45);
    inserir_inicio(&lista, 56);
    inserir_inicio(&lista, 78);

    imprimir_lista(lista);
    obter_tamanho(lista, &tamanho);
    printf("\nTamanho da lista: %d\n", tamanho);
    obter_primeiro_valor(lista);
    obter_ultimo_valor(lista);
    imprimir_lista(lista);

    printf("\nInserindo dado no início:\n");
    inserir_inicio(&lista, 99);
    imprimir_lista(lista);

    printf("\nRetirando dado x:\n");
    retira_dado(&lista, 45);
    imprimir_lista(lista);

    printf("\nBuscando dado:\n");
    busca(lista, 56);
    busca(lista, 99);

    inserir_final(&lista, 103);
    inserir_final(&lista, 158);
    inserir_inicio(&lista, 291);
    inserir_final(&lista, 303);
    printf("\nInserindo dados no fim e apenas 291 no início:\n");
    imprimir_lista(lista);

    printf("\nBuscando dado:\n");
    busca(lista, 303);

    printf("\nRemovendo penúltimo:\n");
    remover_penultimo(&lista);
    imprimir_lista(lista);

    printf("\nBuscando dado:\n");
	busca(lista, 291);

	printf("\nRemovendo penúltimo:\n");
	remover_penultimo(&lista);
    imprimir_lista(lista);

    printf("\nRetirando dado x:\n");
    retira_dado(&lista, 78);
    imprimir_lista(lista);

    printf("\nRetirando dado do início:\n");
	retira_inicio(&lista);
	imprimir_lista(lista);

    //esta parte ainda n funciona
	//printf("\nRetirando dado do final:\n");
	//retira_final(&lista);
    //imprimir_lista(lista);

    return 0;
}
