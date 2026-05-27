# Conversor Universal de Sistemas de Numeração

**GCC241 – Introdução à Computação | UFLA | 2026/1 | Turma 14A**

## Integrantes

- Ana Carolina Silva Sousa
- Miguel Augusto de Lima

## Linguagem

C++ (padrão C++11 ou superior)

## Descrição

Conversor universal entre as bases **binária (2)**, **octal (8)**, **decimal (10)** e **hexadecimal (16)**, com suporte a números fracionários, modo passo-a-passo, modo batch via CSV, quiz interativo e calculadora de máximos representáveis.

Todos os algoritmos de conversão foram implementados do zero, sem uso de funções prontas da linguagem (como `strtol`, `printf("%x")`, `std::bitset` etc.).

---

## Estrutura do Projeto

```
projeto/
├── src/
│   ├── conversao.hpp       # declarações dos algoritmos de conversão
│   ├── conversao.cpp       # implementação dos algoritmos de conversão
│   ├── parser.hpp          # declarações do parser de entrada
│   ├── parser.cpp          # leitura, validação e parsing de entrada
│   ├── formatador.hpp      # declarações do formatador de saída
│   ├── formatador.cpp      # impressão, modo batch, quiz e calculadora
│   └── principal.cpp       # ponto de entrada (main), menu CLI
├── tests/
│   └── testes.cpp          # suíte de testes automatizados (30+ casos)
├── entrada_exemplo.csv     # exemplo de arquivo para o modo batch
└── README.md
```

---

## Compilação

Certifique-se de ter o `g++` instalado. Na raiz do projeto, execute:

```bash
g++ -o conversor src/principal.cpp src/conversao.cpp src/parser.cpp src/formatador.cpp -lm
```

## Execução

```bash
./conversor
```

O programa exibirá um menu com 16 opções.

---

## Opções do Menu

| Opção | Descrição |
|-------|-----------|
| 1  | Decimal → Binário |
| 2  | Decimal → Octal |
| 3  | Decimal → Hexadecimal |
| 4  | Binário → Decimal |
| 5  | Octal → Decimal |
| 6  | Hexadecimal → Decimal |
| 7  | Binário → Octal |
| 8  | Binário → Hexadecimal |
| 9  | Octal → Binário |
| 10 | Octal → Hexadecimal |
| 11 | Hexadecimal → Binário |
| 12 | Hexadecimal → Octal |
| 13 | Modo Batch (lê de arquivo .csv) |
| 14 | Calculadora de máximos (dado k bits) |
| 15 | Modo Quiz interativo |
| 16 | Sair |

---

## Exemplos de Uso

### Conversão simples (opção 1 — Decimal → Binário)
```
Insira o valor a ser convertido: 10
Deseja ver o trace da conversão? (1 para sim, 0 para não): 0

 Base 10 -> Base 2: 1010
```

### Com trace passo-a-passo (opção 1 — Decimal → Binário)
```
Insira o valor a ser convertido: 10
Deseja ver o trace da conversão? (1 para sim, 0 para não): 1

=== Decimal → Binário ===

-- Parte inteira (divisões sucessivas) --
10 ÷ 2 = 5  resto 0
5 ÷ 2 = 2  resto 1
2 ÷ 2 = 1  resto 0
1 ÷ 2 = 0  resto 1
Lendo restos de baixo para cima: 1010

 Base 10 -> Base 2: 1010
```

### Número fracionário (opção 1 — Decimal → Binário)
```
Insira o valor a ser convertido: 10.625
Deseja ver o trace da conversão? (1 para sim, 0 para não): 0

 Base 10 -> Base 2: 1010.101
```

### Entrada inválida
```
Insira o valor a ser convertido: 89
Deseja ver o trace da conversão? (1 para sim, 0 para não): 0
Dígito '9' inválido para base 8!
```

### Calculadora de máximos (opção 14)
```
Insira o número de bits: 8
Maiores números representados com 8 bits nas bases:
Binário  : 11111111
Decimal  : 255
Octal    : 377
Hexadecimal : FF
```

---

## Modo Batch (opção 13)

Lê um arquivo `.csv` no formato:

```
valor;base_origem;base_destino
```

E grava um arquivo de saída no formato:

```
valor;base_origem;resultado;base_destino
```

### Exemplo — `entrada_exemplo.csv`
```
10;10;2
FF;16;10
777;8;2
1010.101;2;10
```

### Executando
```
Nome do arquivo de entrada: entrada_exemplo.csv
Nome do arquivo de saida: saida.csv
Arquivo imprimido em saida.csv.
```

---

## Modo Quiz (opção 15)

- Gera conversões aleatórias entre as 4 bases.
- **+5 pontos** por resposta correta, **−4 pontos** por resposta errada.
- 5 níveis de dificuldade com faixas de magnitude crescentes:

| Nível | Faixa de valores | Pontuação necessária |
|-------|-----------------|----------------------|
| 1 | 1 – 15 | 0 – 25 pts |
| 2 | 1 – 100 | 26 – 50 pts |
| 3 | 1 – 500 | 51 – 75 pts |
| 4 | 1 – 5000 | 76 – 99 pts |
| 5 | 1 – 10000 | 100+ pts |

- Digite `sair` a qualquer momento para encerrar.
- O jogo termina automaticamente se a pontuação ficar negativa.

---

## Testes Automatizados

Para compilar e rodar a suíte de testes:

```bash
g++ -o testes tests/testes.cpp src/conversao.cpp src/parser.cpp -lm
./testes
```

A saída mostra cada caso com `[OK]` ou `[FALHOU]` e um resumo final.

---

## Limitações Conhecidas

- Números fracionários são truncados em **16 casas** após a vírgula; quando isso ocorre, o resultado exibe `[...]` ao final.
- A parte inteira das conversões é limitada ao intervalo do tipo `int` do sistema (tipicamente até 2.147.483.647 em sistemas 32-bit).
- O modo quiz não suporta números fracionários.
- O separador decimal aceito é `.` ou `,`.

---

## Vídeo de Demonstração

colocar o link do video

---

## Verificação de Funções Proibidas

Para confirmar que nenhuma função vetada foi utilizada:

```bash
grep -nE "\b(bin|oct|hex|parseInt|strtol|toBinaryString|bitset)\b" src/*.cpp src/*.hpp
```
