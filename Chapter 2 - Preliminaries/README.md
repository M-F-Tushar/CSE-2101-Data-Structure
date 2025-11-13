# Chapter 2: Preliminaries - Complete Study Guide

## Table of Contents
1. [Introduction](#introduction)
2. [Mathematical Notations and Functions](#mathematical-notations)
3. [Algorithmic Notations](#algorithmic-notations)
4. [Control Structures](#control-structures)
5. [Complexity of Algorithms](#complexity-of-algorithms)
6. [Asymptotic Notations](#asymptotic-notations)
7. [Subalgorithms](#subalgorithms)
8. [Variables and Data Types](#variables-data-types)
9. [Solved Problems](#solved-problems)
10. [Practice Exercises](#practice-exercises)

---

## 1. Introduction {#introduction}

This chapter establishes the foundational concepts needed for studying data structures and algorithms:

- **Algorithm format and notation** used throughout the text
- **Mathematical functions** commonly used in algorithm analysis
- **Control structures** for structured programming
- **Algorithm complexity** for comparing algorithmic solutions
- **Variable types** and their usage

### Key Concepts

**Algorithm**: A finite step-by-step list of well-defined instructions for solving a particular problem.

**Hierarchical Program Organization**:
```
Main Module
    ↓
Submodule 1    Submodule 2    Submodule 3
    ↓              ↓              ↓
Detailed        Detailed       Detailed
Submodules     Submodules     Submodules
```

---

## 2. Mathematical Notations and Functions {#mathematical-notations}

### 2.1 Floor and Ceiling Functions

**Floor Function** ⌊x⌋: The greatest integer that does not exceed x.

**Ceiling Function** ⌈x⌉: The least integer that is not less than x.

#### Examples:

| Expression | Value | Explanation |
|------------|-------|-------------|
| ⌊3.14⌋ | 3 | Greatest integer ≤ 3.14 |
| ⌈3.14⌉ | 4 | Least integer ≥ 3.14 |
| ⌊√5⌋ | 2 | Greatest integer ≤ 2.236... |
| ⌈√5⌉ | 3 | Least integer ≥ 2.236... |
| ⌊-8.5⌋ | -9 | Greatest integer ≤ -8.5 |
| ⌈-8.5⌉ | -8 | Least integer ≥ -8.5 |
| ⌊7⌋ | 7 | For integers: ⌊x⌋ = ⌈x⌉ |
| ⌈7⌉ | 7 | For integers: ⌊x⌋ = ⌈x⌉ |

**Important Property**: If x is not an integer, then ⌊x⌋ + 1 = ⌈x⌉

---

### 2.2 Remainder Function and Modular Arithmetic

**Modulo Operation**: k (mod M) is the integer remainder when k is divided by M.

**Formal Definition**: k (mod M) is the unique integer r such that:
```
k = Mq + r where 0 ≤ r < M
```

#### Examples:

**Positive Numbers**:
- 25 (mod 7) = 4 (because 25 = 7×3 + 4)
- 25 (mod 5) = 0 (because 25 = 5×5 + 0)
- 35 (mod 11) = 2 (because 35 = 11×3 + 2)
- 3 (mod 8) = 3 (because 3 = 8×0 + 3)

**Negative Numbers** (from Solved Problem 2.2):
- -26 (mod 7): First find |-26| (mod 7) = 5, then 7 - 5 = **2**
- -2345 (mod 6): First find |2345| (mod 6) = 5, then 6 - 5 = **1**
- -371 (mod 8): First find |371| (mod 8) = 3, then 8 - 3 = **5**
- -39 (mod 3): Since -39 is divisible by 3, result is **0**

#### Congruence Relation

**Notation**: a ≡ b (mod M)

**Definition**: a is congruent to b modulo M if and only if M divides (b - a)

**Useful Properties**:
- 0 ≡ M (mod M)
- a ± M ≡ a (mod M)

#### Clock Arithmetic (Modulo 12)

Examples of arithmetic modulo 12:
- 6 + 9 = 15 ≡ 3 (mod 12)
- 7 × 5 = 35 ≡ 11 (mod 12)
- 1 - 5 = -4 ≡ 8 (mod 12)
- 2 + 10 = 12 ≡ 0 (mod 12)

---

### 2.3 Integer and Absolute Value Functions

**Integer Function INT(x)**: Converts x to an integer by truncating the fractional part.

Examples:
- INT(3.14) = 3
- INT(√5) = 2
- INT(-8.5) = -8
- INT(7) = 7

**Note**: 
- INT(x) = ⌊x⌋ when x is positive
- INT(x) = ⌈x⌉ when x is negative

**Absolute Value ABS(x) or |x|**: The greater of x or -x.

Examples:
- |-15| = 15
- |7| = 7
- |-3.33| = 3.33
- |4.44| = 4.44
- |-0.075| = 0.075

**Properties**:
- |x| = |-x|
- For x ≠ 0, |x| is always positive

---

### 2.4 Summation Symbol (Σ)

The summation symbol Σ (Greek letter sigma) represents the sum of a sequence.

**General Form**:
```
  n
  Σ aⱼ = aₘ + aₘ₊₁ + aₘ₊₂ + ... + aₙ
 j=m
```

Where j is called a **dummy variable** or **dummy index**.

#### Examples:

**Example 1**: Product of sequences
```
  n
  Σ aᵢbᵢ = a₁b₁ + a₂b₂ + ... + aₙbₙ
 i=1
```

**Example 2**: Sum of squares
```
  5
  Σ j² = 2² + 3² + 4² + 5²
 j=2
    = 4 + 9 + 16 + 25
    = 54
```

**Example 3**: Sum of first n natural numbers
```
  n              n(n+1)
  Σ j = 1+2+...+n = ------
 j=1                2
```

**Practical Application**:
```
  50            50(51)
  Σ j = 1+2+...+50 = ------ = 1275
 j=1               2
```

---

### 2.5 Factorial Function

**Definition**: The product of positive integers from 1 to n.

**Notation**: n! (read "n factorial")

**Formula**: n! = 1 × 2 × 3 × ... × (n-2) × (n-1) × n

**Special Case**: 0! = 1

#### Examples:

| n | n! | Calculation |
|---|-----|-------------|
| 2 | 2 | 1 × 2 = 2 |
| 3 | 6 | 1 × 2 × 3 = 6 |
| 4 | 24 | 1 × 2 × 3 × 4 = 24 |
| 5 | 120 | 5 × 4! = 5 × 24 = 120 |
| 6 | 720 | 6 × 5! = 6 × 120 = 720 |

**Recursive Property**: For n > 1, n! = n × (n-1)!

---

### 2.6 Permutations

**Definition**: An arrangement of n elements in a given order.

**Count**: There are **n!** permutations of a set of n elements.

#### Example: Permutations of {a, b, c}

There are 3! = 6 permutations:
```
abc    acb    bac    bca    cab    cba
```

#### More Examples:
- 4 elements → 4! = 24 permutations
- 5 elements → 5! = 120 permutations
- 10 elements → 10! = 3,628,800 permutations

---

### 2.7 Exponents and Logarithms

#### Exponents

**Integer Exponents**:
- aᵐ = a × a × a × ... × a (m times)
- a⁰ = 1
- a⁻ᵐ = 1/aᵐ

**Rational Exponents**:
- aᵐ/ⁿ = ⁿ√(aᵐ) = (ⁿ√a)ᵐ

**Examples**:
- 2⁴ = 16
- 2⁻⁴ = 1/16 = 0.0625
- 25^(1/2) = √25 = 5
- 8^(2/3) = (∛8)² = 2² = 4

#### Logarithms

**Definition**: logᵦ x represents the exponent to which b must be raised to obtain x.

**Equivalence**: y = logᵦ x ⟺ bʸ = x

**Examples**:

| Expression | Value | Reason |
|------------|-------|--------|
| log₂ 8 | 3 | 2³ = 8 |
| log₂ 64 | 6 | 2⁶ = 64 |
| log₁₀ 100 | 2 | 10² = 100 |
| log₁₀ 0.001 | -3 | 10⁻³ = 0.001 |
| logᵦ 1 | 0 | b⁰ = 1 |
| logᵦ b | 1 | b¹ = b |

**Important**: The logarithm of a negative number or 0 is **not defined**.

#### Types of Logarithms

1. **Common Logarithms** (base 10): log₁₀ x
2. **Natural Logarithms** (base e ≈ 2.718): ln x or logₑ x
3. **Binary Logarithms** (base 2): log₂ x or lg x

**Convention in this text**: log x means log₂ x unless otherwise specified.

#### Finding Floor and Ceiling of Binary Logarithms

Use powers of 2:

| Expression | Value | Reason |
|------------|-------|--------|
| ⌊log₂ 100⌋ | 6 | 2⁶ = 64 < 100 < 2⁷ = 128 |
| ⌈log₂ 100⌉ | 7 | 2⁶ = 64 < 100 < 2⁷ = 128 |
| ⌊log₂ 1000⌋ | 9 | 2⁹ = 512 < 1000 < 2¹⁰ = 1024 |
| ⌈log₂ 1000⌉ | 10 | 2⁹ = 512 < 1000 < 2¹⁰ = 1024 |

---

## 3. Algorithmic Notations {#algorithmic-notations}

### 3.1 Algorithm Format

An algorithm consists of two parts:

**Part 1**: A paragraph describing:
- Purpose of the algorithm
- Variables used
- Input data

**Part 2**: A list of steps to be executed

### 3.2 Algorithm Example: Finding Largest Element

**Problem**: Find the location and value of the largest element in an array.

**Algorithm 2.1**: (Largest Element in Array)
```
Input: Array DATA with N numerical values
Output: Location LOC and value MAX of largest element
Variable: K (counter)

Step 1. [Initialize] Set K := 1, LOC := 1, MAX := DATA[1]
Step 2. [Increment counter] Set K := K + 1
Step 3. [Test counter] If K > N, then:
            Write: LOC, MAX, and Exit
Step 4. [Compare and update] If MAX < DATA[K], then:
            Set LOC := K and MAX := DATA[K]
Step 5. [Repeat loop] Go to Step 2
```

**Flowchart**:
```
       START
         ↓
    K = 1, LOC = 1
    MAX = DATA[1]
         ↓
      K = K + 1
         ↓
    ┌───────────┐
    │ Is K > N? │──Yes→ Write: LOC, MAX → STOP
    └───────────┘
         ↓ No
  ┌──────────────────┐
  │MAX < DATA[K]?    │
  └──────────────────┘
    Yes ↓          ↓ No
   LOC = K         │
   MAX = DATA[K]   │
        ↓          ↓
        └──────────┘
             ↓
        (Loop back to K = K + 1)
```

### 3.3 C Implementation

```c
#include <stdio.h>
#include <conio.h>

void main() {
    int DATA[10] = {22, 65, 1, 99, 32, 17, 74, 49, 33, 2};
    int N, LOC, MAX, K;
    
    N = 10;
    K = 0;
    LOC = 0;
    MAX = DATA[0];
    
    clrscr();
    
loop:
    K = K + 1;
    if(K == N) {
        printf("LOC = %d, MAX = %d", LOC, MAX);
        getch();
        exit();
    }
    if(MAX < DATA[K]) {
        LOC = K;
        MAX = DATA[K];
    }
    goto loop;
}
```

**Output**: `LOC = 3, MAX = 99`

**Note**: In C, arrays begin with index 0 instead of 1.

---

### 3.4 Algorithm Conventions

#### Identifying Numbers
- **Algorithm 4.3**: Third algorithm in Chapter 4
- **Algorithm P5.3**: Algorithm in Solved Problem 5.3 of Chapter 5

#### Control Flow
- Steps execute sequentially unless directed otherwise
- **Go to Step n**: Transfers control to Step n
- **Exit**: Completes the algorithm (like STOP in FORTRAN)

#### Multiple Statements in One Step
```
Set K := 1, LOC := 1 and MAX := DATA[1]
```
Executed from left to right.

#### Comments
- Appear in brackets [like this]
- Indicate the main purpose of the step
- Usually at beginning or end of step

#### Variable Names
- Use CAPITAL LETTERS
- Examples: MAX, DATA, LOC
- Counter variables also capitalized in algorithms (K, N)

#### Assignment Statement
- Uses := notation (Pascal style)
- Example: `MAX := DATA[1]`
- In C, use = sign: `MAX = DATA[1]`

#### Input/Output
**Input**:
```
Read: Variable names
```

**Output**:
```
Write: Messages and/or variable names
Print: Messages and/or variable names
```

#### Procedures
- Independent algorithmic modules
- Solve specific problems
- Can be called by main algorithms or other subalgorithms

---

## 4. Control Structures {#control-structures}

Three types of logic/flow of control:
1. **Sequence Logic** (Sequential Flow)
2. **Selection Logic** (Conditional Flow)
3. **Iteration Logic** (Repetitive Flow)

### 4.1 Sequence Logic

**Description**: Modules execute in order unless instructed otherwise.

**Flowchart**:
```
    Module A
        ↓
    Module B
        ↓
    Module C
```

**Example**:
```
Step 1. Read: X, Y
Step 2. Set SUM := X + Y
Step 3. Write: SUM
Step 4. Exit
```

---

### 4.2 Selection Logic (Conditional Structures)

#### Type 1: Single Alternative

**Format**:
```
If condition, then:
    [Module A]
[End of If structure]
```

**Flowchart**:
```
    ┌──────────┐
    │Condition?│──No→ (Continue)
    └──────────┘
        ↓ Yes
     Module A
        ↓
    (Continue)
```

**Example**:
```
If X < 0, then:
    Write: "X is negative"
[End of If structure]
```

#### Type 2: Double Alternative

**Format**:
```
If condition, then:
    [Module A]
Else:
    [Module B]
[End of If structure]
```

**Flowchart**:
```
      ┌──────────┐
   No │Condition?│ Yes
   ┌──┴──────────┴──┐
   ↓                ↓
Module B         Module A
   ↓                ↓
   └────────┬───────┘
            ↓
       (Continue)
```

**Example**:
```
If SCORE >= 60, then:
    Write: "Pass"
Else:
    Write: "Fail"
[End of If structure]
```

#### Type 3: Multiple Alternatives

**Format**:
```
If condition(1), then:
    [Module A₁]
Else if condition(2), then:
    [Module A₂]
Else if condition(M), then:
    [Module Aₘ]
Else:
    [Module B]
[End of If structure]
```

**Example**: Quadratic Equation Solver

**Algorithm 2.2**: (Quadratic Equation)
```
Input: Coefficients A, B, C of ax² + bx + c = 0
Output: Real solutions (if any)

Step 1. Read: A, B, C
Step 2. Set D := B² - 4AC  [Discriminant]
Step 3. If D > 0, then:
            (a) Set X1 := (-B + √D)/2A
            (b) Set X2 := (-B - √D)/2A
            (c) Write: X1, X2
        Else if D = 0, then:
            (a) Set X := -B/2A
            (b) Write: 'UNIQUE SOLUTION', X
        Else:
            Write: 'NO REAL SOLUTIONS'
        [End of If structure]
Step 4. Exit
```

**C Implementation**:
```c
#include <stdio.h>
#include <conio.h>
#include <math.h>

void main() {
    int A, B, C, D;
    float X, X1, X2;
    
    clrscr();
    printf("Enter the values of A, B and C: ");
    scanf("%d %d %d", &A, &B, &C);
    
    D = B*B - 4*A*C;
    
    if (D > 0) {
        X1 = ((-1)*B + sqrt(D))/(2*A);
        X2 = ((-1)*B - sqrt(D))/(2*A);
        printf("X1 = %.2f, X2 = %.2f", X1, X2);
    }
    else if (D == 0) {
        X = (-1)*B/(2*A);
        printf("UNIQUE SOLUTION X = %.2f", X);
    }
    else {
        printf("NO REAL SOLUTIONS");
    }
    getch();
}
```

**Output Example**:
```
Enter the values of A, B and C: 1 -3 -4
X1 = 4.00, X2 = -1.00
```

---

### 4.3 Iteration Logic (Repetitive Structures)

#### Type 1: Repeat-For Loop

**Format**:
```
Repeat for K = R to S by T:
    [Module]
[End of loop]
```

**Components**:
- **R**: Initial value
- **S**: End/test value
- **T**: Increment

**Flowchart**:
```
    K = R
      ↓
  ┌────────────┐
  │ Is K > S?  │──Yes→ (Continue)
  └────────────┘
      ↓ No
    Module
   (body of loop)
      ↓
    K = K + T
      ↓
   (Loop back)
```

**Example**:
```
Repeat for I = 1 to 10:
    Write: I, I²
[End of loop]
```

This prints numbers 1-10 and their squares.

#### Type 2: Repeat-While Loop

**Format**:
```
Repeat while condition:
    [Module]
[End of loop]
```

**Flowchart**:
```
  ┌────────────┐
  │Condition?  │──No→ (Continue)
  └────────────┘
      ↓ Yes
    Module
   (body of loop)
      ↓
   (Loop back)
```

**Important Requirements**:
1. Initialize condition before the loop
2. Modify condition within the loop (to eventually terminate)

**Example**: Rewriting Algorithm 2.1 with Repeat-While

**Algorithm 2.3**: (Largest Element in Array)
```
Input: Nonempty array DATA with N values
Output: Location LOC and value MAX of largest element

1. [Initialize] Set K := 1, LOC := 1, MAX := DATA[1]
2. Repeat Steps 3 and 4 while K ≤ N:
3.     If MAX < DATA[K], then:
           Set LOC := K and MAX := DATA[K]
       [End of If structure]
4.     Set K := K + 1
   [End of Step 2 loop]
5. Write: LOC, MAX
6. Exit
```

**C Implementation**:
```c
#include <stdio.h>
#include <conio.h>

void main() {
    int DATA[10] = {22, 65, 1, 99, 32, 17, 74, 49, 33, 2};
    int N, LOC, MAX, K;
    
    N = 10;
    K = 0;
    LOC = 0;
    MAX = DATA[0];
    
    clrscr();
    
    while(K < N) {
        if(MAX < DATA[K]) {
            LOC = K;
            MAX = DATA[K];
        }
        K = K + 1;
    }
    
    printf("LOC = %d, MAX = %d", LOC, MAX);
    getch();
}
```

**Output**: `LOC = 3, MAX = 99`

---

## 5. Complexity of Algorithms {#complexity-of-algorithms}

### 5.1 Definition and Measurement

**Complexity f(n)**: Function giving the running time and/or storage space requirement of an algorithm in terms of input size n.

**Two Main Measures**:
1. **Time**: Counted by number of key operations
   - For sorting/searching: number of comparisons
2. **Space**: Maximum memory needed

**Note**: Unless stated otherwise, "complexity" refers to running time.

---

### 5.2 Cases in Complexity Analysis

1. **Worst Case**: Maximum value of f(n) for any possible input
2. **Average Case**: Expected value of f(n)
3. **Best Case**: Minimum value of f(n)

**Note**: Average case assumes a probabilistic distribution for input data.

**Expectation Formula**:
```
E = n₁p₁ + n₂p₂ + ... + nₖpₖ
```
where nᵢ occurs with probability pᵢ.

---

### 5.3 Example: Linear Search

**Problem**: Find location LOC of ITEM in array DATA with n elements.

**Algorithm 2.4**: (Linear Search)
```
Input: Array DATA with N elements, ITEM to search
Output: Location LOC of ITEM, or LOC = 0 if not found

1. [Initialize] Set K := 1 and LOC := 0
2. Repeat Steps 3 and 4 while LOC = 0 and K ≤ N:
3.     If ITEM = DATA[K], then: Set LOC := K
4.     Set K := K + 1  [Increments counter]
   [End of Step 2 loop]
5. [Successful?]
   If LOC = 0, then:
       Write: ITEM is not in the array DATA
   Else:
       Write: LOC is the location of ITEM
   [End of If structure]
6. Exit
```

**C Implementation**:
```c
#include <stdio.h>
#include <conio.h>

void main() {
    int DATA[10] = {22, 65, 1, 99, 32, 17, 74, 49, 33, 2};
    int ITEM = 17;
    int N, LOC, K;
    
    N = 10;
    K = 0;
    LOC = -1;
    
    clrscr();
    
    while(LOC == -1 && K < N) {
        if(ITEM == DATA[K])
            LOC = K;
        K = K + 1;
    }
    
    if(LOC == -1)
        printf("ITEM is not in the array DATA");
    else
        printf("%d is the location of ITEM", LOC);
    
    getch();
}
```

**Output**: `5 is the location of ITEM`

#### Complexity Analysis

Let C(n) = number of comparisons between ITEM and DATA[K].

**Worst Case**:
- Occurs when ITEM is last element or not in array
- **C(n) = n**

**Best Case**:
- Occurs when ITEM is first element
- **C(n) = 1**

**Average Case**:
- Assume ITEM is in DATA
- Equally likely to be at any position
- Probability of each position = 1/n

```
C(n) = 1·(1/n) + 2·(1/n) + 3·(1/n) + ... + n·(1/n)
     = (1/n)(1 + 2 + 3 + ... + n)
     = (1/n) · n(n+1)/2
     = (n+1)/2
```

**Interpretation**: On average, need to check about half the elements.

---

### 5.4 Rate of Growth and Big O Notation

#### Standard Functions and Growth Rates

| n | log₂ n | n | n log₂ n | n² | n³ | 2ⁿ |
|---|--------|---|----------|----|----|-----|
| 5 | 3 | 5 | 15 | 25 | 125 | 32 |
| 10 | 4 | 10 | 40 | 100 | 10³ | 10³ |
| 100 | 7 | 100 | 700 | 10⁴ | 10⁶ | 10³⁰ |
| 1000 | 10 | 10³ | 10⁴ | 10⁶ | 10⁹ | 10³⁰⁰ |

**Growth Order** (slowest to fastest):
```
log n  <  n  <  n log n  <  n²  <  n³  <  2ⁿ
```

#### Big O Notation

**Definition**: f(n) = O(g(n)) means there exist positive constants M and n₀ such that:
```
|f(n)| ≤ M|g(n)| for all n ≥ n₀
```

**Read as**: "f(n) is of order g(n)" or "f(n) is big O of g(n)"

**Example**: For polynomial P(n) = aₘnᵐ + aₘ₋₁nᵐ⁻¹ + ... + a₁n + a₀
```
P(n) = O(nᵐ)
```

**Specific Example**:
```
8n³ - 576n² + 832n - 248 = O(n³)
```

#### Common Algorithm Complexities

| Algorithm | Complexity | Order |
|-----------|-----------|-------|
| Linear Search | n | O(n) |
| Binary Search | log₂ n | O(log n) |
| Bubble Sort | n² | O(n²) |
| Merge Sort | n log₂ n | O(n log n) |

---

## 6. Other Asymptotic Notations {#asymptotic-notations}

### 6.1 Omega Notation (Ω)

**Definition**: f(n) = Ω(g(n)) if there exist positive constants M and n₀ such that:
```
|f(n)| ≥ M|g(n)| for all n ≥ n₀
```

**Meaning**: g(n) is a **lower bound** for f(n).

**Examples**:
- f(n) = 18n + 9: Since f(n) > 18n for all n, **f(n) = Ω(n)**
- f(n) = 90n² + 18n + 6: Since f(n) > 90n² for n ≥ 0, **f(n) = Ω(n²)**

**Best Practice**: Choose g(n) as large as possible while satisfying the definition.

---

### 6.2 Theta Notation (Θ)

**Definition**: f(n) = Θ(g(n)) if there exist positive constants c₁, c₂, and n₀ such that:
```
c₁|g(n)| ≤ f(n) ≤ c₂|g(n)| for all n ≥ n₀
```

**Meaning**: g(n) is both an upper and lower bound for f(n).

**Equivalence**: f(n) = Θ(g(n)) ⟺ f(n) = O(g(n)) AND f(n) = Ω(g(n))

**Examples**:
- f(n) = 18n + 9:
  - f(n) > 18n (satisfies Ω(n))
  - f(n) ≤ 27n for n ≥ 1 (satisfies O(n))
  - Therefore: **f(n) = Θ(n)**

- f(n) = 16n² + 30n - 90: **f(n) = Θ(n²)**
- f(n) = 7·2ⁿ + 30n: **f(n) = Θ(2ⁿ)**

---

### 6.3 Little Oh Notation (o)

**Definition**: f(n) = o(g(n)) if:
```
f(n) = O(g(n)) AND f(n) ≠ Ω(g(n))
```

**Meaning**: f(n) grows strictly slower than g(n).

**Examples**:
- f(n) = 18n + 9:
  - f(n) = O(n²) but f(n) ≠ Ω(n²)
  - Therefore: **f(n) = o(n²)**
  - However: **f(n) ≠ o(n)** (because f(n) = Θ(n))

---

### 6.4 Summary of Notations

| Notation | Meaning | Example |
|----------|---------|---------|
| O (Big O) | Upper bound | f(n) ≤ c·g(n) |
| Ω (Omega) | Lower bound | f(n) ≥ c·g(n) |
| Θ (Theta) | Tight bound | c₁·g(n) ≤ f(n) ≤ c₂·g(n) |
| o (Little o) | Strict upper bound | f(n) < g(n) asymptotically |

**Visual Representation**:
```
        Growth Rate
           ↑
      2ⁿ   |     f(n) = o(2ⁿ)
           |     
      n³   |---- f(n) = O(n³)
           |     
      n²   |---- f(n) = Θ(n²)  [Tight bound]
           |     
      n    |---- f(n) = Ω(n)
           |     
    log n  |
           └─────────────→ n
```

---

## 7. Subalgorithms {#subalgorithms}

### 7.1 Definition and Purpose

**Subalgorithm**: A complete and independently defined algorithmic module that:
- Is called by a main algorithm or another subalgorithm
- Receives values (arguments) from the calling algorithm
- Performs computations
- Sends results back to the calling algorithm

**Benefits**:
- Can be called by multiple algorithms
- Can be called multiple times in the same algorithm
- Promotes code reusability

---

### 7.2 Subalgorithm Format

**Heading**:
```
NAME(PAR1, PAR2, ..., PARK)
```

**Components**:
- **NAME**: Name of the subalgorithm
- **PAR1, PAR2, ..., PARK**: Parameters for data transmission

**Key Difference from Algorithm**:
- Uses **Return** statement instead of **Exit**
- Emphasizes control transfer back to calling program

---

### 7.3 Types of Subalgorithms

#### Type 1: Function Subalgorithm

**Characteristic**: Returns only **one value** to the calling algorithm.

**Example**: Function to Calculate Mean

**Function 2.5**: MEAN(A, B, C)
```
1. Set AVE := (A + B + C)/3
2. Return(AVE)
```

**Usage in Algorithm**:
```
Set TEST := MEAN(T1, T2, T3)
```

**Process**:
1. Argument values T1, T2, T3 are transferred to parameters A, B, C
2. MEAN is executed
3. Value of AVE replaces MEAN(T1, T2, T3) in the statement
4. Average is assigned to TEST

**C Implementation**:
```c
#include <stdio.h>
#include <conio.h>

void main() {
    int A, B, C;
    float MEAN(int, int, int);
    
    clrscr();
    printf("Enter the values of A, B and C: ");
    scanf("%d %d %d", &A, &B, &C);
    printf("The average of %d, %d and %d is: %.2f", 
           A, B, C, MEAN(A, B, C));
    getch();
}

float MEAN(int T1, int T2, int T3) {
    float AVE;
    AVE = (T1 + T2 + T3)/3;
    return(AVE);
}
```

**Output**:
```
Enter the values of A, B and C: 22 36 8
The average of 22, 36 and 8 is: 22.00
```

---

#### Type 2: Procedure Subalgorithm

**Characteristic**: Can return **multiple values** to the calling algorithm.

**Example**: Procedure to Switch Values

**Procedure 2.6**: SWITCH(AAA, BBB)
```
1. Set TEMP := AAA, AAA := BBB and BBB := TEMP
2. Return
```

**Usage in Algorithm**:
```
Call SWITCH(BEG, AUX)
```

**Process**:
1. Values of BEG and AUX are transferred to AAA and BBB
2. Procedure executes (interchanges AAA and BBB)
3. New values of AAA and BBB are transferred back to BEG and AUX
4. Net effect: BEG and AUX are swapped

**C Implementation**:
```c
#include <stdio.h>
#include <conio.h>

int AAA = 10;
int BBB = 20;

void SWITCH(void);

void main() {
    clrscr();
    printf("AAA = %d BBB = %d", AAA, BBB);
    SWITCH();
    printf("\nAfter calling SWITCH procedure, AAA = %d BBB = %d", 
           AAA, BBB);
    getch();
}

void SWITCH(void) {
    int TEMP;
    TEMP = AAA;
    AAA = BBB;
    BBB = TEMP;
    return;
}
```

**Output**:
```
AAA = 10 BBB = 20
After calling SWITCH procedure, AAA = 20 BBB = 10
```

---

### 7.4 Function vs. Procedure Conversion

**Note**: Any function can be converted to a procedure by adding an extra parameter.

**Example**:
```
Function: MEAN(A, B, C) returns AVE
          ↓
Procedure: MEAN(A, B, C, AVE)
```

**Usage Comparison**:
```
Function:  Set TEST := MEAN(T1, T2, T3)
Procedure: Call MEAN(T1, T2, T3, TEST)
```

Both achieve the same result.

**Convention**: This text generally uses procedures rather than functions.

---

## 8. Variables and Data Types {#variables-data-types}

### 8.1 Four Basic Data Types

#### 1. Character
- **Encoding**: EBCDIC or ASCII
- **Storage**: One character per byte (8 bits)

**Partial EBCDIC Code Table**:

| Character | Zone | Numeric | Hex |
|-----------|------|---------|-----|
| A | 1100 | 0001 | C1 |
| B | 1100 | 0010 | C2 |
| Z | 1110 | 1001 | E9 |
| 0 | 1111 | 0000 | F0 |
| 9 | 1111 | 1001 | F9 |
| blank | 0100 | 0000 | 40 |

#### 2. Real (Floating Point)
- **Format**: Exponential form
- **Example**: 3.14 × 10²

#### 3. Integer (Fixed Point)
- **Positive integers**: Binary representation
- **Negative integers**: 2's complement or similar

#### 4. Logical (Boolean)
- **Values**: True or False
- **Storage**: 1 bit (1 = true, 0 = false)
- **Alternative**: Full byte (11111111 = true, 00000000 = false)

---

### 8.2 Data Type Interpretation Example

**Example 2.11**: Suppose 32-bit memory location X contains:
```
0110 1100 1100 0111 1101 0110 0110 1100
```

**Interpretation depends on data type**:

**(a) Character type (EBCDIC)**:
- Breaks into 4 bytes: `01101100 11000111 11010110 01101100`
- Hex: `6C C7 D6 6C`
- Characters: `%G0%`

**(b) Integer or Real type**:
- Interpreted as a numeric value (specific value depends on format)

**C Program Demonstration**:
```c
#include <stdio.h>
#include <conio.h>

void main() {
    char c1 = '1';    // Character
    int c2 = 1;       // Integer
    
    clrscr();
    printf("c1 (char) = %c \n", c1);
    printf("c1's ASCII value = %d\n", c1);
    printf("c2 (int) = %d", c2);
    getch();
}
```

**Output**:
```
c1 (char) = 1
c1's ASCII value = 49
c2 (int) = 1
```

**Explanation**:
- Character '1' has ASCII value 49
- Integer 1 has value 1
- Same symbol, different interpretations!

---

### 8.3 Local and Global Variables

#### Local Variables
- **Scope**: Accessible only within a specific program module
- **Lifetime**: Exist only during module execution
- **Example**: TEMP in SWITCH procedure

**Example 2.12**: In Procedure SWITCH(AAA, BBB):
- **AAA, BBB**: Parameters (transfer data)
- **TEMP**: Local variable (exists only in procedure)
- TEMP in SWITCH does not interfere with TEMP in other modules

**C Implementation**:
```c
#include <stdio.h>
#include <conio.h>

int AAA = 10;  // Global variables
int BBB = 20;

void SWITCH(void);

void main() {
    clrscr();
    printf("AAA = %d BBB = %d", AAA, BBB);
    SWITCH();
    printf("\nAfter calling SWITCH procedure, AAA = %d BBB = %d", 
           AAA, BBB);
    getch();
}

void SWITCH(void) {
    int TEMP;      // Local variable
    TEMP = AAA;
    AAA = BBB;
    BBB = TEMP;
    return;
}
```

#### Global Variables
- **Scope**: Accessible by all program modules
- **Declaration**: Language-specific syntax
  - FORTRAN: COMMON statement
  - Pascal: Scope rules
  - C: Declare outside all functions

#### Nonlocal Variables
- **Scope**: Accessible by some (but not all) program modules

---

### 8.4 Communication Between Modules

**Two Methods**:

1. **Direct** (Preferred):
   - Well-defined parameters
   - Clear data flow
   - Easy to debug

2. **Indirect** (Use with caution):
   - Nonlocal and global variables
   - **Side effects**: Indirect changes to variables
   - Harder to detect errors

**Warning**: Be careful with global/nonlocal variables as side effects can cause hard-to-find bugs!

---

## 9. Solved Problems {#solved-problems}

### Problem 2.1: Floor and Ceiling Functions

**Find**: (a) ⌊7.5⌋, ⌊-7.5⌋, ⌊-18⌋, ⌊√30⌋, ⌊³√30⌋, ⌊7/2⌋
         (b) ⌈7.5⌉, ⌈-7.5⌉, ⌈-18⌉, ⌈√30⌉, ⌈³√30⌉, ⌈7/2⌉

**Solution**:

**(a) Floor (greatest integer not exceeding x)**:
- ⌊7.5⌋ = 7
- ⌊-7.5⌋ = -8 (not -7, because -8 < -7.5)
- ⌊-18⌋ = -18 (integers: floor = ceiling)
- ⌊√30⌋ = ⌊5.477...⌋ = 5
- ⌊³√30⌋ = ⌊3.107...⌋ = 3
- ⌊7/2⌋ = ⌊3.5⌋ = 3

**(b) Ceiling (least integer not less than x)**:
- ⌈7.5⌉ = 8
- ⌈-7.5⌉ = -7 (not -8, because -7 > -7.5)
- ⌈-18⌉ = -18 (integers: floor = ceiling)
- ⌈√30⌉ = ⌈5.477...⌉ = 6
- ⌈³√30⌉ = ⌈3.107...⌉ = 4
- ⌈7/2⌉ = ⌈3.5⌉ = 4

---

### Problem 2.2: Modular Arithmetic

**(a) Find**: 26 (mod 7), 34 (mod 8), 2345 (mod 6), 495 (mod 11)

**Solution**:
- 26 (mod 7): 26 = 7×3 + **5** → **5**
- 34 (mod 8): 34 = 8×4 + **2** → **2**
- 2345 (mod 6): 2345 = 6×390 + **5** → **5**
- 495 (mod 11): 495 = 11×45 + **0** → **0**

**(b) Find**: -26 (mod 7), -2345 (mod 6), -371 (mod 8), -39 (mod 3)

**Solution** (for negative k):
1. Find |k| (mod M) = r'
2. If r' ≠ 0, then k (mod M) = M - r'
3. If r' = 0, then k (mod M) = 0

- -26 (mod 7): |−26| (mod 7) = 5, so 7 - 5 = **2**
- -2345 (mod 6): |−2345| (mod 6) = 5, so 6 - 5 = **1**
- -371 (mod 8): |−371| (mod 8) = 3, so 8 - 3 = **5**
- -39 (mod 3): |−39| (mod 3) = 0, so **0**

**(c) Arithmetic modulo 15**: Evaluate 9+13, 7+11, 4-9, 2-10

**Solution** (use a ± M ≡ a (mod M)):
- 9 + 13 = 22 = 22 - 15 = **7**
- 7 + 11 = 18 = 18 - 15 = **3**
- 4 - 9 = -5 = -5 + 15 = **10**
- 2 - 10 = -8 = -8 + 15 = **7**

---

### Problem 2.3: Permutations

**List all permutations of 1, 2, 3, 4**

**Solution**: There are 4! = 24 permutations:

```
Starting with 1:
1234  1243  1324  1342  1423  1432

Starting with 2:
2134  2143  2314  2341  2413  2431

Starting with 3:
3124  3142  3214  3241  3412  3421

Starting with 4:
4123  4132  4213  4231  4312  4321
```

---

### Problem 2.4: Exponents and Logarithms

**(a) Find**: 2⁻⁵, 8^(2/3), 25^(-3/2)

**Solution**:
- 2⁻⁵ = 1/2⁵ = **1/32**
- 8^(2/3) = (³√8)² = 2² = **4**
- 25^(-3/2) = 1/25^(3/2) = 1/(√25)³ = 1/5³ = **1/125**

**(b) Find**: log₂ 32, log₁₀ 1000, log₂(1/16)

**Solution**:
- log₂ 32 = **5** (because 2⁵ = 32)
- log₁₀ 1000 = **3** (because 10³ = 1000)
- log₂(1/16) = log₂(2⁻⁴) = **-4**

**(c) Find**: ⌊log₂ 1000⌋, ⌊log₂ 0.01⌋

**Solution**:
- ⌊log₂ 1000⌋: 2⁹ = 512 < 1000 < 2¹⁰ = 1024, so **9**
- ⌊log₂ 0.01⌋: 2⁻⁷ = 1/128 ≈ 0.0078 < 0.01 < 2⁻⁶ = 1/64 ≈ 0.0156, so **-7**

---

### Problem 2.6: Complexity Analysis

**Given**: Algorithm 2.3 finds largest element. Let C(n) = number of times LOC and MAX are updated in Step 3.

**(a) Worst case**: Describe and find C(n)

**Solution**:
- **Scenario**: Elements in increasing order
- Each comparison forces update
- **C(n) = n - 1**

**(b) Best case**: Describe and find C(n)

**Solution**:
- **Scenario**: Largest element appears first
- No updates needed
- **C(n) = 0**

**(c) Average case for n = 3**

**Solution**: Let 1, 2, 3 represent largest, second-largest, smallest.

| Permutation | Updates (nₚ) | Explanation |
|-------------|--------------|-------------|
| 123 | 0 | Largest first, no updates |
| 132 | 0 | Largest first, no updates |
| 213 | 1 | Update at position 1 |
| 231 | 1 | Update at position 1 |
| 312 | 1 | Update at position 2 |
| 321 | 2 | Updates at positions 1, 2 |

**Average**:
```
C(3) = (0 + 0 + 1 + 1 + 1 + 2)/6 = 5/6
```

---

### Problem 2.7: Complexity of Nested Loops

**(a) Find C(n) for**:
```
Algorithm P2.7A:
1. Repeat for I = 1 to N:
2.   Repeat for J = 1 to N:
3.     Repeat for K = I to N:
4.       Module A  [Takes M time units]
```

**Solution**:
- Triple nested loop
- K ranges from I to N (not 1 to N)
- Total executions: Σᵢ₌₁ⁿ Σⱼ₌₁ⁿ Σₖ₌ᵢⁿ M
- Number of triplets (i, j, k) where 1 ≤ i ≤ k ≤ n and 1 ≤ j ≤ n
- For fixed i: (n - i + 1) values of k, n values of j
- Total: Σᵢ₌₁ⁿ n(n - i + 1) = n · n(n+1)/2 = n²(n+1)/2

**C(n) = M · n²(n+1)/2 ≈ M · n³/2 = O(n³)**

**(b) Find C(n) for**:
```
Algorithm P2.7B:
1. Set J := 1
2. Repeat Steps 3 and 4 while J ≤ N:
3.   Module A  [Takes M time units]
4.   Set J := B × J  [B > 1]
```

**Solution**:
- J takes values: 1, B, B², B³, B⁴, ...
- Loop continues while Bᵀ ≤ N
- First T where Bᵀ > N
- T = ⌊log_B N⌋ + 1

**C(n) = M · T = M(⌊log_B N⌋ + 1) = O(log n)**

---

### Problem 2.8: Finding Largest and Second-Largest

**(a) Write procedure FIND(DATA, N, LOC1, LOC2)**

**Solution**:
```
Procedure P2.8: FIND(DATA, N, LOC1, LOC2)
Finds location LOC1 of largest and LOC2 of second-largest element

1. Set FIRST := DATA[1], SECOND := DATA[2]
   Set LOC1 := 1, LOC2 := 2

2. [Are FIRST and SECOND initially correct?]
   If FIRST < SECOND, then:
       (a) Interchange FIRST and SECOND
       (b) Set LOC1 := 2 and LOC2 := 1
   [End of If structure]

3. Repeat for K = 3 to N:
       If FIRST < DATA[K], then:
           (a) Set SECOND := FIRST and FIRST := DATA[K]
           (b) Set LOC2 := LOC1 and LOC1 := K
       Else if SECOND < DATA[K], then:
           Set SECOND := DATA[K] and LOC2 := K
       [End of If structure]
   [End of loop]

4. Return
```

**(b) Why not return values of largest and second-largest?**

**Solution**: Using LOC1 and LOC2, the calling program can access DATA[LOC1] and DATA[LOC2] directly. Additional parameters would be redundant.

**C Implementation**:
```c
#include <stdio.h>
#include <conio.h>

int DATA[10] = {22, 65, 1, 99, 32, 17, 74, 49, 33, 2};
int N, LOC1, LOC2, FIRST, SECOND;

void main() {
    void FIND(int[], int, int, int);
    clrscr();
    N = 10;
    LOC1 = -1;
    LOC2 = -1;
    FIND(DATA, N, LOC1, LOC2);
    printf("FIRST = %d, LOC1 = %d, SECOND = %d, LOC2 = %d", 
           FIRST, LOC1, SECOND, LOC2);
    getch();
}

void FIND(int LIST[], int LEN, int L1, int L2) {
    int TEMP, K;
    FIRST = LIST[0];
    SECOND = LIST[1];
    L1 = 0;
    L2 = 1;
    
    if(FIRST < SECOND) {
        TEMP = FIRST;
        FIRST = SECOND;
        SECOND = TEMP;
        L2 = 0;
        L1 = 1;
    }
    
    for(K = 2; K < LEN; K++) {
        if(FIRST < LIST[K]) {
            SECOND = FIRST;
            FIRST = LIST[K];
            L2 = L1;
            L1 = K;
        }
        else if(SECOND < LIST[K]) {
            SECOND = LIST[K];
            L2 = K;
        }
    }
    
    LOC1 = L1;
    LOC2 = L2;
}
```

**Output**: `FIRST = 99, LOC1 = 3, SECOND = 74, LOC2 = 6`

---

### Problem 2.9: Sieve Method for Prime Numbers

**Problem**: Find all prime numbers less than a given number m (e.g., 30).

**Method**:
1. List numbers 1 to m
2. Cross out 1
3. Cross out multiples of 2 (except 2)
4. Find next uncrossed number (3), cross out its multiples
5. Repeat until √m
6. Remaining numbers are prime

**Visual Example (m = 30)**:
```
Initial: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
        16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

After 2: X 2 3 X 5 X 7 X 9 X 11 X 13 X 15 
        X 17 X 19 X 21 X 23 X 25 X 27 X 29 X

After 3: X 2 3 X 5 X 7 X X X 11 X 13 X X 
        X 17 X 19 X X X 23 X 25 X X X 29 X

After 5: X 2 3 X 5 X 7 X X X 11 X 13 X X 
        X 17 X 19 X X X 23 X X X X X 29 X

Result: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
```

**Algorithm**:

**Procedure P2.9A**: CROSSOUT(A, N, K)
```
1. If A[K] = 1, then: Return
2. Repeat for L = 2K to N by K:
       Set A[L] := 1
   [End of loop]
3. Return
```

**Algorithm P2.9B**: Print primes less than N
```
1. [Initialize array A]
   Repeat for K = 1 to N:
       Set A[K] := K

2. [Eliminate multiples of K]
   Repeat for K = 2 to √N:
       Call CROSSOUT(A, N, K)

3. [Print the primes]
   Repeat for K = 2 to N:
       If A[K] ≠ 1, then: Write: A[K]

4. Exit
```

**C Implementation**:
```c
#include <stdio.h>
#include <conio.h>
#include <math.h>

int A[100];

void CROSSOUT(int, int);

void main() {
    int K, N;
    clrscr();
    printf("Enter the value of N: ");
    scanf("%d", &N);
    
    A[0] = -1;
    for(K = 1; K <= N; K++)
        A[K] = K;
    
    for(K = 2; K <= sqrt(N); K++)
        CROSSOUT(N, K);
    
    for(K = 2; K <= N; K++)
        if(A[K] != 1)
            printf("%d ", A[K]);
    
    getch();
}

void CROSSOUT(int n, int k) {
    int L;
    if(A[k] == 1)
        return;
    for(L = 2*k; L <= n; L = L + k)
        A[L] = 1;
    return;
}
```

**Output** (N = 20):
```
Enter the value of N: 20
2 3 5 7 11 13 17 19
```

---

### Problem 2.10: Big O for Polynomials

**Prove**: If P(n) = aₘnᵐ + aₘ₋₁nᵐ⁻¹ + ... + a₁n + a₀, then P(n) = O(nᵐ)

**Solution**:

Let b₀ = |a₀|, b₁ = |a₁|, ..., bₘ = |aₘ|

For n ≥ 1:
```
|P(n)| ≤ b₀ + b₁n + b₂n² + ... + bₘnᵐ
       = b₀/nᵐ · nᵐ + b₁/nᵐ⁻¹ · nᵐ + ... + bₘnᵐ
       ≤ (b₀ + b₁ + ... + bₘ)nᵐ
       = M · nᵐ
```

where M = |a₀| + |a₁| + ... + |aₘ|

Therefore, **P(n) = O(nᵐ)**

**Examples**:
- 5x³ + 3x = O(x³)
- x⁵ - 4,000,000x² = O(x⁵)

---

### Problem 2.11: Rule of Sums

**Given**: T₁(n) = O(f(n)) and T₂(n) = O(g(n))

**Find**: T₁(n) + T₂(n) = ?

**Solution**:

From definitions:
- T₁(n) ≤ c·f(n) for n ≥ n₁
- T₂(n) ≤ d·g(n) for n ≥ n₂

Let n₀ = max(n₁, n₂). Then for n ≥ n₀:
```
T₁(n) + T₂(n) ≤ c·f(n) + d·g(n)
               ≤ (c + d)·max(f(n), g(n))
```

**Therefore**: T₁(n) + T₂(n) = **O(max(f(n), g(n)))**

**Rule of Sums**: When adding complexities, the larger dominates.

**Examples**:
- O(n) + O(n²) = O(n²)
- O(n log n) + O(n) = O(n log n)

---

### Problem 2.12: Rule of Products

**Given**: T₁(n) = O(f(n)) and T₂(n) = O(g(n))

**Find**: T₁(n) · T₂(n) = ?

**Solution**:

From definitions:
- T₁(n) ≤ c·f(n) for n ≥ n₁
- T₂(n) ≤ d·g(n) for n ≥ n₂

Let n₀ = max(n₁, n₂). Then for n ≥ n₀:
```
T₁(n) · T₂(n) ≤ (c·f(n)) · (d·g(n))
               = (c·d) · f(n) · g(n)
               = k · f(n) · g(n)  [where k = c·d]
```

**Therefore**: T₁(n) · T₂(n) = **O(f(n) · g(n))**

**Rule of Products**: When multiplying complexities, multiply the functions.

**Examples**:
- O(n) · O(n) = O(n²)
- O(log n) · O(n) = O(n log n)
- O(n) · O(2ⁿ) = O(n · 2ⁿ)

---

### Problem 2.13: Variables Classification

**Question**: Describe difference between local variables, parameters, and global variables.

**Solution**:

| Type | Scope | Purpose | Lifetime |
|------|-------|---------|----------|
| **Local** | Single module only | Internal computation | During module execution |
| **Parameters** | Transfer between modules | Data transmission | During call |
| **Global** | All modules | Shared data | Entire program |

**Local Variables**:
- Private to a specific program/subprogram
- Cannot be accessed outside their module
- Example: TEMP in SWITCH procedure

**Parameters**:
- Transfer data between subprogram and caller
- Act as interface
- Example: AAA, BBB in SWITCH(AAA, BBB)

**Global Variables**:
- Accessible by all program modules
- Declared with language-specific syntax
- Example: Variables declared outside all functions in C

---

### Problem 2.14: Global Variables - Advantages and Disadvantages

**Question**: NUM denotes number of records in a file. Advantages of making NUM global? Disadvantages of global variables in general?

**Advantages of Global NUM**:
- Many procedures process all records using NUM
- NUM is same for all procedures
- No need to pass NUM as parameter repeatedly
- Simplifies function signatures

**Disadvantages of Global Variables (General)**:
- **Side effects**: Unintended changes from any module
- **Debugging difficulty**: Hard to track which module changed value
- **Hidden dependencies**: Not clear which modules depend on global
- **Testing complexity**: Module behavior depends on global state
- **Maintenance issues**: Changes affect multiple modules

**Best Practice**: Use global variables sparingly, only when clearly beneficial.

---

### Problem 2.15: Data Type Interpretation

**Question**: 32-bit memory location AAA contains:
```
0100 1101 1100 0001 1110 1001 0101 1101
```
What data is stored?

**Solution**:

**Cannot determine without knowing data type!**

**If Character (EBCDIC)**:
- Break into 4 bytes: `01001101 11000001 11101001 01011101`
- Convert to hex: `4D C1 E9 5D`
- Look up EBCDIC table:
  - 4D → M
  - C1 → A
  - E9 → Z
  - 5D → )
- **Data**: `(AZ)`

**If Integer**:
- Interpret as binary number
- Value depends on signed/unsigned representation

**If Real**:
- Interpret using floating-point format
- Value depends on IEEE 754 or other format

**Key Point**: Data type determines interpretation!

---

### Problem 2.16: Integer vs. Real Data Types

**Question**: Integers are mathematically also real numbers. Why have two different data types?

**Solution**:

**1. Arithmetic Simplicity**:
- **Integer arithmetic**: Simple binary operations
- **Real arithmetic**: Complex exponential form calculations
- **Performance**: Integer operations much faster

**2. Precision**:
- **Integers**: Exact representation (within range)
- **Reals**: Approximations, floating-point errors

**3. Round-off Errors**:
- **Integer arithmetic**: No round-off errors
- **Real arithmetic**: Accumulating round-off errors

**Example**:
```
Integer: 5 + 3 = 8 (exact)
Real:    0.1 + 0.2 = 0.30000000000000004 (approximation)
```

**4. Storage Efficiency**:
- Integers typically use less space
- More predictable memory usage

**5. Use Cases**:
- **Integers**: Counting, indexing, exact quantities
- **Reals**: Measurements, scientific calculations

---

## 10. Practice Exercises {#practice-exercises}

### Supplementary Problems

#### 2.1 Floor and Ceiling
Find:
- (a) ⌊3.4⌋, ⌊-3.4⌋, ⌊-7⌋, ⌊√75⌋, ⌊³√75⌋, ⌊e⌋
- (b) ⌈3.4⌉, ⌈-3.4⌉, ⌈-7⌉, ⌈√75⌉, ⌈³√75⌉, ⌈e⌉

**Answers**:
- (a) 3, -4, -7, 8, 4, 2
- (b) 4, -3, -7, 9, 5, 3

---

#### 2.2 Modular Arithmetic
**(a)** Find: 48 (mod 5), 48 (mod 7), 1397 (mod 11), 2468 (mod 9)

**Answers**: 3, 6, 1, 8

**(b)** Find: -48 (mod 5), -152 (mod 7), -358 (mod 11), -1326 (mod 13)

**Answers**: 2, 2, 4, 12

**(c)** Using arithmetic modulo 13, evaluate:
```
9+10, 8+12, 3+4, 3-4, 2-7, 5-8
```

**Answers**: 6, 7, 7, 12, 8, 10

---

#### 2.3 Absolute Value and Factorials
**(a)** Find: |3 + 8|, |3 - 8|, |-3 + 8|, |-3 - 8|

**Answers**: 11, 5, 5, 11

**(b)** Find: 7!, 8!, 14!/12!, 15!/16!

**Answers**: 5040, 40320, 182, 1/16

---

#### 2.4 Exponents and Logarithms
**(a)** Find: 3⁴, 4^(7/2), 27^(-2/3)

**Answers**: 81, 128, 1/9

**(b)** Find: log₂ 64, log₁₀ 0.001, log₂(1/8)

**Answers**: 6, -3, -3

**(c)** Find: ⌊lg 1,000,000⌋, ⌊lg 0.001⌋

**Answers**: 19, -10

---

#### 2.5 Average Case Complexity
Consider complexity function C(n) measuring updates to LOC in Algorithm 2.3. Find C(n) for average case when n = 4, assuming all arrangements equally likely.

**Solution Approach**:
- List all 4! = 24 permutations
- Count updates for each
- Calculate average

**Answer**: C(4) = 25/12 ≈ 2.08

---

#### 2.6 & 2.7 Procedure P2.8 Analysis
Let C(n) = number of comparisons in Procedure P2.8.

**(a) Best case**: C(n) = 2n - 3

**(b) Worst case**: C(n) = 2n - 3

**(c) Average case (n=4)**: C(4) = 5

**Note**: Number of comparisons is independent of input order!

For updates analysis (Problem 2.7), results vary based on input arrangement.

---

#### 2.8 Complexity of Nested Structures

**(a) Triple nested loop**:
```
Repeat for I = 1 to N:
    Repeat for J = 1 to I:
        Repeat for K = 1 to J:
            Module A
```

**Analysis**:
```
Σᵢ₌₁ⁿ Σⱼ₌₁ⁱ Σₖ₌₁ʲ 1 = Σᵢ₌₁ⁿ Σⱼ₌₁ⁱ j
                    = Σᵢ₌₁ⁿ i(i+1)/2
                    ≈ n³/6
```

**Answer**: **C(n) = O(n³)**

**(b) Halving loop**:
```
Set J := N
Repeat while J > 1:
    Module A
    Set J := J/2
```

**Analysis**: J takes values N, N/2, N/4, ..., 2, 1
- Stops when J ≤ 1
- Approximately log₂ N iterations

**Answer**: **C(n) = O(log n)**

---

#### 2.9 Recursive Function Complexity
```c
fun(n) {
    if(n <= 2) return(1);
    else return(fun(n-1) * fun(n-2));
}
```

**Analysis**:
- Recurrence: T(n) = T(n-1) + T(n-2) + c
- Similar to Fibonacci
- Each call branches into two recursive calls

**Answer**: **T(n) = O(2ⁿ)** (exponential complexity)

**Note**: Very inefficient for large n!

---

### Programming Problems

#### 2.1 DIV Function
Write function DIV(J, K) where:
- Returns 1 if J divides K
- Returns 0 otherwise

**C Implementation**:
```c
int DIV(int J, int K) {
    if(K % J == 0)
        return 1;
    else
        return 0;
}
```

**Examples**:
- DIV(3, 15) = 1 (3 divides 15)
- DIV(3, 16) = 0 (3 doesn't divide 16)

---

#### 2.2 Prime Number Test
Write program using DIV(J, K) that reads N > 10 and determines if N is prime.

**Algorithm**:
1. If DIV(2, N) = 1, then N is not prime
2. For odd K where 1 < K² ≤ N:
   - If DIV(K, N) = 1, then N is not prime
3. If no divisors found, N is prime

**C Implementation**:
```c
#include <stdio.h>
#include <conio.h>
#include <math.h>

int DIV(int, int);

void main() {
    int N, K, isPrime;
    
    printf("Enter N (> 10): ");
    scanf("%d", &N);
    
    isPrime = 1;  // Assume prime
    
    // Check if even
    if(N > 2 && DIV(2, N)) {
        isPrime = 0;
    }
    else {
        // Check odd divisors
        for(K = 3; K * K <= N; K += 2) {
            if(DIV(K, N)) {
                isPrime = 0;
                break;
            }
        }
    }
    
    if(isPrime)
        printf("%d is PRIME", N);
    else
        printf("%d is NOT PRIME", N);
    
    getch();
}

int DIV(int J, int K) {
    return (K % J == 0) ? 1 : 0;
}
```

---

#### 2.3 Two Largest Elements Program
Write program that finds LOC1 (largest) and LOC2 (second largest) in array DATA with N > 1 elements.

**Test Data**: 70, 30, 25, 80, 60, 50, 30, 75, 25, 60

**Expected Output**:
```
LOC1 = 3 (value 80)
LOC2 = 7 (value 75)
```

(Implementation provided in Solved Problem 2.8)

---

#### 2.4 Sieve Method Implementation
Write program to find prime numbers less than N.

**Test**:
- (a) N = 1000
- (b) N = 10,000

(Implementation provided in Solved Problem 2.9)

---

#### 2.5 Empirical Complexity Analysis
**(a)** Write subprogram COUNT(A, N, C) that finds C (number of LOC updates) using Algorithm 2.3.

**(b)** Write Procedure P2.27:
1. Reads N random numbers (0 to 1) into array A
2. Uses COUNT to find C

**(c)** Write program that:
- Repeats Procedure P2.27 1000 times
- Finds average of 1000 C values
- Tests for N = 3 and N = 4
- Compares with theoretical values

**Pseudocode**:
```
Total := 0
Repeat 1000 times:
    Generate N random numbers
    Call COUNT(A, N, C)
    Total := Total + C
Average := Total / 1000
Print: Average
```

---

#### 2.6 Digit Analysis Algorithm
Write pseudocode that receives an integer and prints:
- Number of digits
- Sum of digits

**Algorithm**:
```
Algorithm: DIGIT_ANALYSIS(NUM)
Input: Integer NUM
Output: Number of digits and sum

1. Set DIGIT_COUNT := 0, DIGIT_SUM := 0
2. Set TEMP := |NUM|  [Absolute value]
3. Repeat while TEMP > 0:
       Set DIGIT := TEMP mod 10
       Set DIGIT_SUM := DIGIT_SUM + DIGIT
       Set DIGIT_COUNT := DIGIT_COUNT + 1
       Set TEMP := TEMP / 10  [Integer division]
   [End of loop]
4. Write: "Number of digits:", DIGIT_COUNT
5. Write: "Sum of digits:", DIGIT_SUM
6. Exit
```

**Example**:
- Input: 12345
- Output: "Number of digits: 5", "Sum of digits: 15"

---

## Multiple Choice Questions & Answers

### Questions with Detailed Explanations

**2.1** _____ of a set of n elements is an arrangement of elements in a given order.

**(a) Combination** (b) Permutation (c) Exponent (d) Logarithm

**Answer: (b) Permutation**

**Explanation**: A permutation arranges all elements in a specific order. Combinations don't consider order.

---

**2.2** There are _____ permutations of a set of n elements.

**(a) n!** (b) n (c) n² (d) n+1

**Answer: (a) n!**

**Explanation**: 
- 3 elements: 3! = 6 permutations
- 4 elements: 4! = 24 permutations
- n elements: n! permutations

---

**2.3** Logarithms to base 10 are called _____ logarithms.

(a) Natural (b) Simple **(c) Common** (d) Binary

**Answer: (c) Common**

**Explanation**:
- Base 10: Common logarithms (log₁₀)
- Base e: Natural logarithms (ln)
- Base 2: Binary logarithms (lg)

---

**2.4** The first part of an algorithm tells the _____ of the algorithm.

(a) Logic (b) Process **(c) Purpose** (d) Steps

**Answer: (c) Purpose**

**Explanation**: Part 1 describes purpose, variables, and input data.

---

**2.5** Each step of an algorithm may contain its _____ in brackets.

(a) Purpose (b) Functions (c) Steps **(d) Comments**

**Answer: (d) Comments**

**Explanation**: Comments in [brackets] explain step purpose.

---

**2.6** The term _____ will be used for an independent algorithmic module.

(a) Program (b) Logic **(c) Procedure** (d) Name

**Answer: (c) Procedure**

**Explanation**: Procedures are independent modules solving specific problems.

---

**2.7** _____ logic employs conditions leading to selection of alternative modules.

**(a) Selection** (b) Sequential (c) Iteration (d) Procedural

**Answer: (a) Selection**

**Explanation**: Selection logic uses If-Then-Else structures.

---

**2.8** A structure with "If condition, then: [Module A] Else: [Module B]" is:

(a) Multiple Alternative **(b) Double Alternative** (c) Single Alternative (d) None

**Answer: (b) Double Alternative**

**Explanation**: Two options: execute Module A or Module B.

---

**2.9** _____ loop uses a condition to control the loop.

(a) Repeat-for (b) Repeat (c) Continue **(d) Repeat-while**

**Answer: (d) Repeat-while**

**Explanation**: Repeat-while continues while condition is true.

---

**2.10** In complexity theory, _____ case refers to expected value of f(n).

**(a) Average** (b) Best (c) Worst (d) Good

**Answer: (a) Average**

**Explanation**: 
- Average: Expected value (probabilistic)
- Best: Minimum value
- Worst: Maximum value

---

**2.11** O(n²) is complexity of which sorting algorithm?

(a) Binary search (b) Linear search (c) Merge sort **(d) Bubble sort**

**Answer: (d) Bubble sort**

**Explanation**:
- Linear search: O(n)
- Binary search: O(log n)
- Merge sort: O(n log n)
- Bubble sort: O(n²)

---

**2.12** The _____ notation defines a lower bound for f(n).

**(a) Omega** (b) Big O (c) Theta (d) Little Oh

**Answer: (a) Omega**

**Explanation**:
- Omega (Ω): Lower bound
- Big O: Upper bound
- Theta (Θ): Tight bound (both)
- Little oh (o): Strict upper bound

---

**2.13** Each program module contains its own list of _____ variables.

(a) Global **(b) Local** (c) Search (d) Binary

**Answer: (b) Local**

**Explanation**: Local variables accessible only within their module.

---

**2.14** _____ function of C allocates a block of memory.

**(a) malloc()** (b) calloc() (c) free (d) realloc()

**Answer: (a) malloc()**

**Explanation**: 
- malloc(): Allocates memory
- calloc(): Allocates and initializes
- free(): Deallocates memory
- realloc(): Resizes allocated memory

---

**2.15** Variables accessible by some (not all) modules are _____ variables.

(a) Global (b) Local (c) Search **(d) Nonlocal**

**Answer: (d) Nonlocal**

**Explanation**:
- Local: One module only
- Nonlocal: Some modules
- Global: All modules

---

## Summary and Key Takeaways

### Essential Concepts

**1. Mathematical Foundations**:
- Floor/Ceiling functions for integer bounds
- Modular arithmetic for cyclic operations
- Factorial and permutations for counting
- Logarithms for measuring growth rates

**2. Algorithm Structure**:
- Two-part format: description + steps
- Clear variable naming and comments
- Structured control flow (no spaghetti code!)
- Parameters for data transmission

**3. Control Structures**:
- **Sequence**: Linear execution
- **Selection**: If-Then-Else decisions
- **Iteration**: Repeat-For and Repeat-While loops

**4. Complexity Analysis**:
- **Time**: Count key operations
- **Space**: Measure memory usage
- **Cases**: Best, Average, Worst
- **Big O**: Upper bound notation

**5. Asymptotic Notations**:
```
O(g): f ≤ c·g    [Upper bound]
Ω(g): f ≥ c·g    [Lower bound]
Θ(g): c₁·g ≤ f ≤ c₂·g    [Tight bound]
o(g): f < g asymptotically    [Strict upper]
```

**6. Variable Scope**:
- **Local**: Module-specific
- **Parameters**: Interface between modules
- **Global**: Program-wide (use carefully!)

---

### Growth Rate Hierarchy

From slowest to fastest:
```
O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2ⁿ) < O(n!)
```

**Practical Limits** (for n = 1,000,000):
- O(log n): ~20 operations ✓ Excellent
- O(n): ~1,000,000 operations ✓ Good
- O(n log n): ~20,000,000 operations ✓ Acceptable
- O(n²): ~1,000,000,000,000 operations ✗ Poor
- O(2ⁿ): Impossible to compute!

---

### Best Practices

**1. Algorithm Design**:
- Use meaningful variable names
- Include comments for clarity
- Prefer structured control (avoid goto)
- Handle edge cases

**2. Complexity Considerations**:
- Always analyze worst case
- Consider average case when relevant
- Choose algorithms based on input size
- Be aware of space-time tradeoffs

**3. Programming Style**:
- Minimize global variables
- Use parameters for communication
- Keep functions focused and small
- Document assumptions

---

### Common Pitfalls

**1. Mathematical**:
- Forgetting floor/ceiling for negative numbers
- Incorrect modulo for negative values
- Confusing log bases

**2. Algorithmic**:
- Off-by-one errors in loops
- Infinite loops (forgetting loop variable update)
- Missing edge cases

**3. Complexity**:
- Counting operations incorrectly
- Ignoring hidden loops
- Comparing different complexity measures

---

## Conclusion

This chapter establishes the foundation for studying data structures:

✓ **Mathematical tools** for analysis
✓ **Algorithmic notation** for clear communication
✓ **Control structures** for organized programming
✓ **Complexity analysis** for comparing solutions
✓ **Variable management** for proper program organization

**Next Steps**: With these fundamentals, you're ready to explore specific data structures (arrays, linked lists, stacks, queues, trees, graphs) and their associated algorithms.

---
