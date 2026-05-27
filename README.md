# Conversor Universal de Sistemas de Numeração

Trabalho Prático 1 — GCC241 Introdução à Computação  
Universidade Federal de Lavras (UFLA)

## Integrantes

- Ana Carolina Silva Sousa
- Miguel Augusto de Lima

## Descrição

Este projeto implementa um conversor universal entre os sistemas de numeração:

- Decimal (base 10)
- Binário (base 2)
- Octal (base 8)
- Hexadecimal (base 16)

O objetivo do trabalho é implementar manualmente os algoritmos de conversão entre bases, sem utilizar funções prontas da linguagem.

## Estrutura
---
projeto/
├── conversao.hpp       # declarações dos algoritmos de conversão
├── conversao.cpp       # implementação dos algoritmos de conversão
├── parser.hpp          # declarações do parser de entrada
├── parser.cpp          # leitura, validação e parsing de entrada
├── formatador.hpp      # declarações do formatador de saída
├── formatador.cpp      # impressão, modo batch, quiz e calculadora
├── principal.cpp       # ponto de entrada (main), menu CLI
├── tests/
│   └── testes.cpp      # suíte de testes automatizados (30+ casos)
├── entrada_exemplo.csv # exemplo de arquivo para o modo batch
└── README.md
# Funcionalidades

## F1 — Decimal → outras bases
Conversão de decimal para:
- binário
- octal
- hexadecimal

Utilizando o método das divisões sucessivas.

---

## F2 — Outras bases → decimal
Conversão de:
- binário → decimal
- octal → decimal
- hexadecimal → decimal

Utilizando somatório posicional.

---

## F3 — Conversões usando agrupamento de bits
- binário ↔ octal
- binário ↔ hexadecimal

Sem passar pelo decimal.

---

## F4 — Octal ↔ hexadecimal
Conversão realizada utilizando binário como intermediário.

---

## F5 — Validação de entrada
O programa detecta entradas inválidas:
- dígitos inválidos;
- caracteres incorretos;
- bases incompatíveis.

Exemplos:
- `128` em octal;
- `2` em binário;
- `G` em hexadecimal inválido.

---

## F6 — Números fracionários
Suporte para números fracionários em todas as bases.

Exemplo:

```txt
10.625 (decimal) → 1010.101 (binário)