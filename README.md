# 🔐 Discrete Math II Project

This repository contains a C language implementation of a **modular arithmetic validator system**, developed as part of the **Discrete Mathematics II** course at the University of Brasília (UnB - FGA), during the first semester of 2025.

📘 This project demonstrates the application of number theory concepts such as **modular arithmetic**, **coprimality**, **primality**, **modular exponentiation**, and classical theorems like **Fermat** and **Euler**, in a real algorithmic problem-solving scenario.

---

## Context

This algorithm was built as part of an academic exam. The task was to simulate a mathematical verification mechanism for system access — a form of **mathematical security** using modular congruence checks.

It combines concepts such as:

- Prime verification (Euclidean Algorithm)
- Modular inverses (Extended Euclidean Algorithm)
- Efficient modular exponentiation
- Fermat’s Little Theorem
- Euler’s Theorem and Euler’s Totient Function φ(n)
- The Division Theorem

The output must show a **detailed step-by-step breakdown**, mimicking a pedagogical mathematical explanation.

---

## What the Algorithm Does

Given five positive integers **H, G, n, x, n1**, the program:

1. Validates if G and n are coprime.
2. Computes the **modular inverse of G mod n** using the extended Euclidean algorithm.
3. Calculates the modular division **a = H ⊘ G in Zn**.
4. Checks if **a and n1** are coprime.
5. Determines whether **n1 is prime**.
6. Depending on primality:
   - Applies **Fermat’s Little Theorem** if prime
   - Applies **Euler’s Theorem** otherwise
7. Decomposes the exponent **x = q·ϕ(n1) + r**
8. Rewrites the expression `a^x mod n1` based on that decomposition
9. Efficiently computes the final result step-by-step, printing each operation.

---

## How to Compile and Run

```bash
gcc main.c
./a.out
```

You will be prompted to enter 5 positive integers: H, G, n, x, n1
The program will then execute and display a full breakdown of the congruence logic.

---

## Test Plan

| Case   | Input (H, G, n, x, n1) | Expected Path | Justification                                                     |
| ------ | ---------------------- | ------------- | ----------------------------------------------------------------- |
| **1**  | 10, 3, 7, 5, 7         | Fermat        | n1 is prime, validates application of Fermat's Little Theorem.    |
| **2**  | 11, 4, 9, 5, 6         | Euler         | n1 is not prime, numbers are coprime, requires φ(n1) calculation. |
| **3**  | 10, 6, 9, 5, 7         | Error         | G and n are not coprime, modular division not valid.              |
| **4**  | 13, 5, 9, 7, 7         | Fermat        | Tests larger exponent with Fermat’s Theorem.                      |
| **5**  | 17, 4, 9, 0, 6         | Euler         | x = 0, triggers trivial case (a^0 ≡ 1 mod n1).                    |
| **6**  | 12, 4, 9, 5, 9         | Error         | a and n1 not coprime, Euler’s Theorem cannot be applied.          |
| **7**  | 20, 5, 12, 8, 13       | Fermat        | n1 = 13 is prime, tests with larger prime base.                   |
| **8**  | 15, 4, 9, 5, 8         | Error         | a and n1 not coprime, Euler’s Theorem invalid.                    |
| **9**  | 7, 3, 7, 6, 7          | Fermat        | x = n1 - 1, validates full exponent cycle in Fermat’s Theorem.    |
| **10** | 25, 7, 12, 14, 15      | Euler         | n1 = 15, φ(15) = 8, complex Euler case with non-prime modulus.    |

## 👤 Author

Vitor Feijó Leonardo
📍 Universidade de Brasília — FGA
