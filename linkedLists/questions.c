#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insert(const char* str) {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    while (*str) {
        struct Node* newNode = createNode(*str);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        str++;
    }

    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printListRecursive(struct Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%c -> ", head->data);
    printListRecursive(head->next);
}

int areListsEqual(struct Node* head1, struct Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data) {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return head1 == NULL && head2 == NULL;
}

struct Node* removeChar(struct Node* head, char charToRemove) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == charToRemove) {
            if (prev == NULL) {
                head = current->next;
                free(current);
                current = head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

struct Node* getLastElement(struct Node* head) {
    if (head == NULL) return NULL;
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

struct Node* concatenateLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    struct Node* current = head1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head2;
    return head1;
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* result = NULL;
    char text[100];
    char charToRemove;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir uma nova lista\n");
        printf("2. Imprimir lista iterativamente\n");
        printf("3. Imprimir lista recursivamente\n");
        printf("4. Verificar se duas listas são iguais\n");
        printf("5. Remover caracteres de uma lista\n");
        printf("6. Apresentar o último elemento da lista\n");
        printf("7. Unir duas listas\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Digite o texto para a nova lista: ");
                fgets(text, sizeof(text), stdin);
                list1 = insert(text);
                break;

            case 2:
                printf("Imprimindo lista iterativamente:\n");
                printList(list1);
                break;

            case 3:
                printf("Imprimindo lista recursivamente:\n");
                printListRecursive(list1);
                break;

            case 4:
                printf("Digite o texto para a segunda lista: ");
                fgets(text, sizeof(text), stdin);
                list2 = insert(text);
                if (areListsEqual(list1, list2)) {
                    printf("As listas são iguais.\n");
                } else {
                    printf("As listas são diferentes.\n");
                }
                break;

            case 5:
                printf("Digite o caractere a ser removido: ");
                charToRemove = getchar();
                list1 = removeChar(list1, charToRemove);
                break;

            case 6:
                {
                    struct Node* last = getLastElement(list1);
                    if (last != NULL) {
                        printf("Último elemento da lista: %c\n", last->data);
                    } else {
                        printf("A lista está vazia.\n");
                    }
                }
                break;

            case 7:
                printf("Digite o texto para a segunda lista: ");
                fgets(text, sizeof(text), stdin);
                list2 = insert(text);
                result = concatenateLists(list1, list2);
                printf("Lista resultante após a união:\n");
                printList(result);
                break;

            case 8:
                freeList(list1);
                freeList(list2);
                freeList(result);
                printf("Saindo...\n");
                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
