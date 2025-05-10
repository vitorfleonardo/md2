# Avaliação de Matemática Discreta II - Parte 2

Este repositório contém a implementação em **linguagem C** do sistema solicitado na **Avaliação P1 - Parte 2** da disciplina **Matemática Discreta II** da Universidade de Brasília (UnB - FGA).

Aluno: Vitor Feijó Leonardo
Matrícula: 221008516

## 🎯 Objetivo

O sistema implementa um **processo matemático detalhado** para validar acessos em sistemas, aplicando conceitos de:

- **Congruência**
- **Coprimalidade** e **Primalidade**
- **Pequeno Teorema de Fermat**
- **Teorema de Euler**
- **Exponenciação Modular Eficiente**
- **Função Totiente de Euler (φ(n))**
- **Teorema da Divisão**

## 🚀 Como Executar o Programa

1. **Compilação**

   No terminal, navegue até o diretório onde o arquivo `main.c` está salvo e execute:

   ```bash
   gcc main.c
   ./a.out
   ```

## 🧪 Plano de Casos de Teste - Sistema de Cálculo Modular

### Técnicas Aplicadas no caso de testes

- **Partição de Equivalência**
- **Análise de Valor Limite**
- **Cobertura de Fluxo**

---

| Caso   | Entrada (H, G, n, x, n1) | Caminho Esperado | Justificativa                                                  |
| ------ | ------------------------ | ---------------- | -------------------------------------------------------------- |
| **1**  | 10, 3, 7, 5, 7           | Fermat           | n1 é primo, verifica a aplicação do Pequeno Teorema de Fermat. |
| **2**  | 11, 4, 9, 5, 6           | Euler            | n1 não é primo, coprimos, exige cálculo de φ(n1).              |
| **3**  | 10, 6, 9, 5, 7           | Erro             | mdc(9, 6) ≠ 1, divisão modular não possível.                   |
| **4**  | 13, 5, 9, 7, 7           | Fermat           | Valida caso com expoente maior para Fermat.                    |
| **5**  | 17, 4, 9, 0, 6           | Euler            | x = 0, força análise de caso trivial (a^0 ≡ 1).                |
| **6**  | 12, 4, 9, 5, 9           | Erro             | n1 = 9, mdc(5, 9) ≠ 1, Euler não aplicável.                    |
| **7**  | 20, 5, 12, 8, 13         | Fermat           | n1 = 13 é primo, força cálculo maior com número primo.         |
| **8**  | 15, 4, 9, 5, 8           | Erro             | n1 = 8, mdc(5, 8) ≠ 1, Euler não aplicável.                    |
| **9**  | 7, 3, 7, 6, 7            | Fermat           | x = n1 - 1, testa ciclo completo de Fermat.                    |
| **10** | 25, 7, 12, 14, 15        | Euler            | n1 = 15, φ(15) = 8, caso maior para Euler.                     |

---

### 📌 Observações

- Os **casos 3, 6 e 8** devem bloquear o fluxo na **ETAPA 1**.
- Os demais devem seguir até as etapas de **cálculo e reescrita da expressão**.
