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
    int tamanho, repeticao;



    int inicializa (Lista **lista) {
        printf("Inicializando lista...\n\n");
        *lista = NULL;
    }



    int vazia (Lista* lista) {
        return (lista == NULL);
    }


    void inserir_inicio (Lista **lista, int valor) {
        Lista *novo_elemento;

        novo_elemento = (Lista*)malloc(sizeof(Lista));
        novo_elemento->dado = valor;
		novo_elemento->prox = NULL;

        if (*lista == NULL ) { //se a lista estiver vazia, elemento é o primeiro elemento da lista
            *lista = novo_elemento;
        } else { // se a lista NÃO estiver vazia, prox do elemento recebe lista e lista recebe elemento 
            novo_elemento->prox = *lista;
            *lista = novo_elemento;
        }
    }




	void inserir_final (Lista **lista, int valor) {
        Lista *novo_elemento, *percorre;

        novo_elemento = (Lista*)malloc(sizeof(Lista));
        novo_elemento->dado = valor;
        novo_elemento->prox = NULL;

		if (*lista == NULL) {
			*lista = novo_elemento;
		} else {
			percorre = *lista;
			
			while (percorre->prox != NULL) {
				percorre = percorre->prox;
			}
			
			percorre->prox = novo_elemento;
		}
    }



    int busca (Lista* lista, int valor)
    {
        Lista* nova_lista;
        nova_lista = lista;

        while (nova_lista != NULL) {
            if  (nova_lista->dado == valor) {
                printf("Valor %d encontrado no endereço %d\n", nova_lista->dado, nova_lista);
            }
            
            nova_lista = nova_lista->prox;
        }

        return NULL; /* não achou o elemento */
    }



    int retira_dado (Lista *lista, int valor) {
    	Lista *percorre, *anterior;

    	if (lista != NULL) {
    		while (percorre != NULL) {    				
    			if (percorre->dado == valor) {
    				anterior->prox = percorre->prox;
					free(percorre);
					return 0;
				}
				
				anterior = percorre;
    			percorre = percorre->prox;
			}
			
			return 101;
		} else {
			printf("Lista vazia!");
		}
		
		return 0;
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
    	Lista *anterior, *percorre;

    	percorre = *lista;

    	if (*lista != NULL) {
			while (percorre->prox != NULL) {
			    anterior = percorre;
                percorre = percorre->prox;
			}
			
			anterior->prox = percorre->prox;
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



	int inverter_com_o_de_tras (Lista *lista) {

	}



    int inverter_lista (Lista **lista) {
    	Lista *percorre,*aux_1,*aux_2,*aux_3;
    	
	    percorre = *lista;
	    
	    if(percorre==NULL)
	    {
	        return 1;
	    }
	    else if(percorre->prox==NULL)
	    {
	        return 0;
	    }
	    else
	    {
	        aux_1       = *lista;          /*O ponteiro aux_a aponta para o primeiro nó, uma vez que o ponteiro "ini" passará a apontar para o último. */
	        aux_2       = aux_1->prox;     /*O ponteiro aux_p passa a apontar para o segundo nó da lista.*/
	        aux_3       = aux_2->prox;     /*O ponteiro aux_v passa a apontar para o terceiro nó da lista.*/
	        aux_1->prox = NULL;            /*O primeiro nó da lista passa a ser o último, apontando para NULL.*/
	        aux_2->prox = aux_1;           /*O segundo nó da lista passa a apontar para o primeiro, começando a inversão da lista.*/
	                                       /*Início - Processo de inversão.*/
	        while(aux_3!=NULL)
	        {
	            aux_1 = aux_2;              /*O ponteiro aux_a pega o valor do nó a sua frente na lista.*/
	            aux_2 = aux_3;              /*O ponteiro aux_p pega o valor do nó a sua frente na lista.*/
	            aux_3 = aux_3->prox;        /*O ponteiro aux_v pega o valor do nó a sua frente na lista.*/
	            aux_2->prox = aux_1;         /*O nó para o qual aux_p está apontado passa a apontar para o nó anterior a ele na lista.*/
	        }
	        
	        *lista = aux_2;
	    }
	    
		return 0;
	}
	
	int repete_dado (Lista *lista, int valor, int *resp) {
		int cont = 0;
		
		if (lista == NULL)
		{
	        *resp = 0;
	        return 1;
		}
		
	    while (lista != NULL) {
	       if (lista->dado == valor)
	          cont++;
	          
	       lista = lista->prox;
	    }
	    
	    if (cont > 1)
	       *resp = 1;
	    else
	       *resp = 0;
	       
		return 0;
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

        while (lista != NULL) {
        	printf("%d ", lista->dado);
            lista = lista->prox;
		}
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
    
    printf("\nQuantidade que o elemento 2 repete:\n");
    repete_dado(lista, 2, &repeticao);
    printf("%d\n", repeticao);
    
    printf("\nInvertendo a lista:\n");
    inverter_lista(&lista);
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

    printf("\nRetirando dado 78:\n");
    retira_dado(&lista, 78);
    imprimir_lista(lista);

    printf("\nRetirando dado do início:\n");
	retira_inicio(&lista);
	imprimir_lista(lista);

	printf("\nRetirando dado do final:\n");
	retira_final(&lista);
    imprimir_lista(lista);

    return 0;
}
