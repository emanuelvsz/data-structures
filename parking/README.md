# Estacionamento do Emanuel

* Projeto solicitado pela professora Cledja Rolim para a matéria de Estrutura de Dados do terceiro período de Sistemas de Informação

## <a href="#sumary">Sumário</a>

* <a href="#introduction">Introdução</a>
  * <a href="#functional-requirements">Requisitos funcionais</a>
* <a href="#folder-structure">Estrutura de pastas</a>
* <a href="#used-libraries">Bibliotecas utilizadas</a>
* <a href="program-interfaces">Interfaces do programa</a>
* <a href="#how-execute">Como executar?</a>


## <p id="introduction">Introdução</p> 

Implementar um algoritmo que faça o gerenciamento de um estacionamento com 2 becos de 10 carros cada.

### <p id="functional-requirements">Requisitos Funcionais</p>

1. **Entrada e Saída de Carros**
   - O programa deve permitir que carros entrem e saiam do estacionamento.
   - Cada beco pode guardar até 10 carros, totalizando 20 carros no estacionamento.

2. **Gerenciamento de Becos**
   - Cada beco deve ser gerenciado separadamente.
   - Deve haver uma indicação clara de qual beco possui vagas disponíveis e quantas.

3. **Controle de Vagas**
   - Ao chegar um carro, o sistema deve informar se há vaga disponível e em qual beco.
   - Se não houver vaga, o sistema deve oferecer a opção de colocar o carro em uma fila de espera.

4. **Fila de Espera**
   - Deve haver um mecanismo para gerenciar uma fila de espera.
   - Quando uma vaga se tornar disponível, o carro na fila de espera deve ser alocado em um beco com vaga.

5. **Remoção de Carros**
   - Se um carro precisar sair e não estiver na saída, todos os carros bloqueando seu caminho devem ser removidos temporariamente e depois reposicionados.
   - O programa deve informar quantas vezes um carro foi manobrado para sair e se ele esteve na fila de espera.

6. **Relatórios**
   - Ao remover um carro, o programa deve informar a quantidade de manobras realizadas e se o carro esteve na fila de espera.

### <p id="folder-structure">Estrutura de pastas</p>

```
.
├── README.md
├── handlers
│   ├── parking.c
│   └── stack.c
├── interfaces
│   ├── parking.h
│   └── stack.h
├── main.c
├── parking
└── ui
    ├── display.c
    └── display.h
```

### <p id="used-libraries">Bibliotecas utilizadas</p>

* ``<stdio.h>`` -> A biblioteca fornece funções para realizar operações de entrada e saída em C.
* ``<stdlib.h>`` -> A biblioteca oferece várias funções utilitárias, principalmente relacionadas à alocação de memória, controle de processos e conversão de tipos.

### <p id="program-interfaces">Interfaces do programa</a>

#### ``parking.h``

```
typedef struct {
    Stack beco1;
    Stack beco2;
    int wait_queue[MAX_QUEUE];
    int queue_front;
    int queue_rear;
    int queue_size;
} Parking;

void init_parking(Parking *p);
int park_car(Parking *p, int car_id);
int retrieve_car(Parking *p, int car_id);
int add_to_queue(Parking *p, int car_id);
int remove_from_queue(Parking *p);
void process_queue(Parking *p);
void display_status(Parking *p);
```

#### ``stack.h``

```
typedef struct {
    int cars[MAX_CARS];
    int top;
} Stack;

void init_stack(Stack *s);
int push(Stack *s, int car_id);
int pop(Stack *s);
int peek(Stack *s);
int is_empty(Stack *s);
int is_full(Stack *s);
int size(Stack *s);
int contains(Stack *s, int car_id);
int get_car(Stack *s, int index);

```

### <p id="how-execute">Como executar?</p>

```  
gcc main.c handlers/parking.c handlers/stack.c ui/display.c -Iinterfaces -Ihandlers -Iui -o parking
```
