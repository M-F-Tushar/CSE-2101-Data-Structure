# Chapter 1: Introduction and Overview

## Table of Contents

1. [Introduction](#11-introduction)
2. [Basic Terminology and Data Organization](#12-basic-terminology-elementary-data-organization)
3. [Data Structures](#13-data-structures)
4. [Data Structure Operations](#14-data-structure-operations)
5. [Algorithms: Complexity and Time-Space Tradeoff](#15-algorithms-complexity-time-space-tradeoff)
6. [Solved Problems](#solved-problems)

---

## 1.1 INTRODUCTION

This chapter introduces **data structures** - ways to organize information in a computer.

### What You Will Learn:

```mermaid
graph TD
    A["Chapter 1 Overview"] --> B["Basic Terms & Concepts"]
    A --> C["Data Organization"]
    A --> D["Types of Data Structures"]
    A --> E["Operations on Data"]
    A --> F["Algorithms & Complexity"]
    A --> G["Time-Space Tradeoff"]
    
    style A fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style C fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style D fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style E fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style F fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style G fill:#50C878,stroke:#333,stroke-width:2px,color:#000
```

**In Simple Words:** This chapter teaches you different ways to store and organize information so computers can work with it quickly and efficiently.

---

## 1.2 BASIC TERMINOLOGY; ELEMENTARY DATA ORGANIZATION

### What is Data?

**Data** = Values or sets of values  
**Data Item** = A single piece of data

### Types of Data Items

```mermaid
graph TD
    A["Data Items"] --> B["Elementary Items"]
    A --> C["Group Items"]
    
    B --> D["Cannot be broken down further"]
    B --> E["Example: Social Security Number<br/>134-24-5533"]
    
    C --> F["Can be broken into smaller parts"]
    C --> G["Example: Employee Name"]
    G --> H["First Name"]
    G --> I["Middle Initial"]
    G --> J["Last Name"]
    
    style A fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style C fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style D fill:#F5E663,stroke:#333,stroke-width:2px,color:#000
    style E fill:#F5E663,stroke:#333,stroke-width:2px,color:#000
    style F fill:#F5E663,stroke:#333,stroke-width:2px,color:#000
    style G fill:#F5E663,stroke:#333,stroke-width:2px,color:#000
    style H fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style I fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style J fill:#50C878,stroke:#333,stroke-width:2px,color:#000
```

**In Simple Words:**
- **Elementary Items** = Items that stay as one piece (like an age number: 34)
- **Group Items** = Items made of smaller pieces (like a full name: First + Middle + Last)

---

### Entity, Attributes, and Values

**Entity** = Something that has properties we can describe  
**Attributes** = The properties of that thing  
**Values** = The actual information for each property

```mermaid
graph LR
    A["Entity: Employee"] --> B["Attribute: Name"]
    A --> C["Attribute: Age"]
    A --> D["Attribute: Sex"]
    A --> E["Attribute: SSN"]
    
    B --> F["Value: ROHLAND, GAIL"]
    C --> G["Value: 34"]
    D --> H["Value: F"]
    E --> I["Value: 134-24-5533"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style E fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style F fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style G fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style H fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style I fill:#50C878,stroke:#333,stroke-width:2px,color:#000
```

**Entity Set** = A group of similar entities (example: all employees in a company)

**Information** = Data that has meaning or has been processed

---

### Fields, Records, and Files

Data is organized in a hierarchy (levels from small to big):

```mermaid
graph TD
    A["FILE<br/>(Collection of all records)<br/>Example: All Employee Records"] --> B["RECORD 1<br/>(One entity's data)<br/>Example: John's Info"]
    A --> C["RECORD 2<br/>Example: Mary's Info"]
    A --> D["RECORD 3<br/>Example: Bob's Info"]
    
    B --> E["FIELD: Name<br/>Value: John Smith"]
    B --> F["FIELD: Age<br/>Value: 30"]
    B --> G["FIELD: Salary<br/>Value: 50000"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style C fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style D fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style E fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style F fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style G fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
```

**In Simple Words:**
- **Field** = One piece of information (like "Name" or "Age")
- **Record** = All information about one thing (like all info about one employee)
- **File** = Collection of all records (like a list of all employees)

---

### Primary Key

A **Primary Key** is a field that uniquely identifies each record - no two records can have the same value for this field.

```mermaid
graph TD
    A["Primary Key Examples"] --> B["✅ Serial Number<br/>(Each car has unique one)"]
    A --> C["✅ Student ID<br/>(Each student has unique one)"]
    A --> D["❌ Address<br/>(Multiple people can share)"]
    A --> E["❌ Age<br/>(Many people have same age)"]
    
    style A fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style C fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style D fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style E fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
```

#### Example 1.1

**(a) Automobile Dealership File:**
- Data: Serial Number, Type, Year, Price, Accessories
- **Primary Key: Serial Number** (each car has a unique serial number)

**(b) Membership File:**
- Data: Name, Address, Telephone Number, Dues Owed
- **Primary Key: Name** (assuming no duplicate names)
- Note: Address and Phone cannot be primary keys because family members might share them

---

### Fixed-Length vs Variable-Length Records

```mermaid
graph LR
    A["Record Types"] --> B["Fixed-Length Records"]
    A --> C["Variable-Length Records"]
    
    B --> D["All records same size<br/>Same space for each field"]
    C --> E["Records can be different sizes<br/>Example: Student courses<br/>(different students take<br/>different number of courses)"]
    
    style A fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style C fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style D fill:#F5E663,stroke:#333,stroke-width:2px,color:#000
    style E fill:#F5E663,stroke:#333,stroke-width:2px,color:#000
```

---

### Three Steps in Studying Data Structures

```mermaid
graph LR
    A["Step 1"] --> B["Logical Description<br/>(How it works in theory)"]
    B --> C["Step 2"]
    C --> D["Implementation<br/>(How to build it on computer)"]
    D --> E["Step 3"]
    E --> F["Analysis<br/>(How much memory and time<br/>does it need?)"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style E fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style F fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
```

**Note:** This text focuses on data stored in main memory (RAM), not secondary storage like hard drives. Database management (secondary storage) is a different subject.

---

## 1.3 DATA STRUCTURES

A **data structure** is a way of organizing data - like a blueprint for how information is stored and connected.

### Choosing the Right Data Structure

When picking a data structure, think about two things:

```mermaid
graph TD
    A["Choosing a Data Structure"] --> B["Must match real-world data<br/>(Rich enough to show relationships)"]
    A --> C["Must be simple enough<br/>(Easy to work with and process)"]
    
    style A fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style C fill:#50C878,stroke:#333,stroke-width:2px,color:#000
```

---

### Arrays

An **array** is a list of similar items stored in numbered boxes.

```mermaid
graph LR
    subgraph "STUDENT Array"
        A["[1] John Brown"]
        B["[2] Sandra Gold"]
        C["[3] Tom Jones"]
        D["[4] June Kelly"]
        E["[5] Mary Reed"]
        F["[6] Alan Smith"]
    end
    
    style A fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style B fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style C fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style D fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style E fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style F fill:#50C878,stroke:#333,stroke-width:2px,color:#000
```

**Key Points:**
- Elements are numbered (1, 2, 3, ... n)
- Access any element using its number: STUDENT[3] = "Tom Jones"
- The number is called a **subscript** or **index**

#### Array Notation

Arrays can be written in three ways:
- Subscript notation: A₁, A₂, A₃, ..., Aₙ
- Parenthesis notation: A(1), A(2), A(3), ..., A(N)
- Bracket notation: A[1], A[2], A[3], ..., A[N]

---

#### Two-Dimensional Arrays (Tables/Matrices)

A 2D array has rows and columns, like a spreadsheet:

```mermaid
graph TD
    subgraph "SALES Array (28 stores × 4 departments)"
        A["SALES[1,1]=2872 | SALES[1,2]=805 | SALES[1,3]=3211 | SALES[1,4]=1560"]
        B["SALES[2,1]=2196 | SALES[2,2]=1223 | SALES[2,3]=2525 | SALES[2,4]=1951"]
        C["SALES[3,1]=1744 | SALES[3,2]=3257 | SALES[3,3]=1017 | SALES[3,4]=3686"]
        D["... more rows ..."]
        E["SALES[28,1]=2618 | SALES[28,2]=931 | SALES[28,3]=2333 | SALES[28,4]=982"]
    end
    
    style A fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#95A5A6,stroke:#333,stroke-width:2px,color:#fff
    style E fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
```

- First subscript = Store number (row)
- Second subscript = Department number (column)
- Size: 28 × 4 (28 rows, 4 columns)

---

### Linked Lists

A **linked list** connects data items using pointers (arrows that point to the next item).

#### Example: Customer-Salesperson Relationship

**Original Data:**

| Customer | Salesperson |
|----------|-------------|
| Adams    | Smith       |
| Brown    | Ray         |
| Clark    | Jones       |
| Drew     | Ray         |
| Evans    | Smith       |
| Farmer   | Jones       |
| Geller   | Ray         |
| Hill     | Smith       |
| Infeld   | Ray         |

#### Method 1: Using Pointers to Save Space

Instead of storing the salesperson name for each customer, use a number (pointer) that points to the salesperson:

```mermaid
graph LR
    subgraph "Customer File"
        C1["Adams → 3"]
        C2["Brown → 2"]
        C3["Clark → 1"]
        C4["Drew → 2"]
        C5["Evans → 3"]
    end
    
    subgraph "Salesperson Array"
        S1["1: Jones"]
        S2["2: Ray"]
        S3["3: Smith"]
    end
    
    C1 -.-> S3
    C2 -.-> S2
    C3 -.-> S1
    C4 -.-> S2
    C5 -.-> S3
    
    style C1 fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C2 fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C3 fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C4 fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C5 fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style S1 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style S2 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style S3 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
```

**Advantage:** A number takes less space than a name.

#### Method 2: Linked List Structure

Each salesperson points to their first customer, and each customer points to the next customer of the same salesperson:

```mermaid
graph LR
    subgraph "Salesperson Ray's Customers"
        R["Ray"] --> B["Brown"]
        B --> D["Drew"]
        D --> G["Geller"]
        G --> I["Infeld"]
        I --> END["0 (End)"]
    end
    
    style R fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style G fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style I fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style END fill:#95A5A6,stroke:#333,stroke-width:2px,color:#fff
```

**Terminology:**
- **Pointer**: Points from one list to another list
- **Link**: Points from one item to another item in the same list

---

### Trees

A **tree** shows data with parent-child relationships (hierarchical data).

#### Example 1.4: Employee Record Structure

```mermaid
graph TD
    A["Employee"] --> B["Soc. Sec. No."]
    A --> C["Name"]
    A --> D["Address"]
    A --> E["Age"]
    A --> F["Salary"]
    A --> G["Dependents"]
    
    C --> H["Last"]
    C --> I["First"]
    C --> J["MI"]
    
    D --> K["Street"]
    D --> L["Area"]
    
    L --> M["City"]
    L --> N["State"]
    L --> O["ZIP"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style C fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style D fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style E fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style F fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style G fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style H fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style I fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style J fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style K fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style L fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style M fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style N fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style O fill:#50C878,stroke:#333,stroke-width:2px,color:#000
```

**Level Number Format:**
```
01 Employee
  02 Social Security Number
  02 Name
    03 Last
    03 First
    03 Middle Initial
  02 Address
    03 Street
    03 Area
      04 City
      04 State
      04 ZIP
  02 Age
  02 Salary
  02 Dependents
```

#### Example 1.5: Algebraic Expression Tree

The expression **(2x + y)(a - 7b)³** can be shown as a tree:

```mermaid
graph TD
    A["*"] --> B["+"]
    A --> C["↑"]
    
    B --> D["*"]
    B --> E["y"]
    
    D --> F["2"]
    D --> G["x"]
    
    C --> H["-"]
    C --> I["3"]
    
    H --> J["a"]
    H --> K["*"]
    
    K --> L["7"]
    K --> M["b"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style C fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style D fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style E fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style F fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style G fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style H fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style I fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style J fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style K fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style L fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style M fill:#50C878,stroke:#333,stroke-width:2px,color:#000
```

**Note:** The tree shows the order of operations - operations lower in the tree happen first.

---

### Other Important Data Structures

#### (a) Stack (LIFO - Last In, First Out)

Like a stack of plates - you add and remove only from the top.

```mermaid
graph BT
    A["Bottom: Plate 1"] --> B["Plate 2"]
    B --> C["Plate 3"]
    C --> D["Top: Plate 4"]
    
    E["New Plate"] -.->|"PUSH (add)"| D
    D -.->|"POP (remove)"| F["Remove"]
    
    style A fill:#95A5A6,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style E fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style F fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
```

**Real-life examples:**
- Browser back button (last page visited, first to go back)
- Undo feature in programs

---

#### (b) Queue (FIFO - First In, First Out)

Like a line of people waiting for a bus - first person in line gets on first.

```mermaid
graph LR
    A["Front: Person 1"] --> B["Person 2"]
    B --> C["Person 3"]
    C --> D["Rear: Person 4"]
    
    A -.->|"EXIT (remove)"| E["Gets on bus"]
    F["New Person"] -.->|"JOIN (add)"| D
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style E fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style F fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
```

**Real-life examples:**
- Print queue (first document sent, first to print)
- Cars at a traffic light

---

#### (c) Graph

Shows connections between items - not necessarily in a hierarchy.

```mermaid
graph TD
    A["Boston"] --- B["New York"]
    A --- C["Chicago"]
    B --- D["Philadelphia"]
    C --- D
    D --- E["Miami"]
    C --- F["Los Angeles"]
    
    style A fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style E fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style F fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
```

**Example:** Airline routes between cities

**Real-life examples:**
- Social networks (friends connected to friends)
- Road maps
- Computer networks

---

### Common Names for Data Elements

Different names are used depending on the situation:
- **Data element** or **Data item** - general terms
- **Record** - when talking about files
- **Node** - when talking about linked lists, trees, and graphs

---

## 1.4 DATA STRUCTURE OPERATIONS

The data in our structures is processed using specific operations. The choice of data structure depends on which operations you need to do most often.

### Main Operations

```mermaid
graph TD
    A["Data Structure Operations"] --> B["Primary Operations"]
    A --> C["Special Operations"]
    
    B --> D["1. Traversing"]
    B --> E["2. Searching"]
    B --> F["3. Inserting"]
    B --> G["4. Deleting"]
    
    C --> H["5. Sorting"]
    C --> I["6. Merging"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style E fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style F fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style G fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style H fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style I fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
```

### Operation Descriptions

| Operation | What It Does | Simple Example |
|-----------|--------------|----------------|
| **Traversing** | Visit each item exactly once | Reading every name in a phone book |
| **Searching** | Find an item with a specific value | Looking up a phone number by name |
| **Inserting** | Add a new item | Adding a new contact |
| **Deleting** | Remove an item | Removing an old contact |
| **Sorting** | Arrange items in order | Putting names in alphabetical order |
| **Merging** | Combine two sorted lists into one | Combining two sorted contact lists |

---

### Example 1.6: Membership File Operations

A membership file contains: **Name, Address, Telephone Number, Age, Sex**

```mermaid
graph TD
    A["Membership File Operations"] --> B["(a) Send mail to all members"]
    A --> C["(b) Find members in certain area"]
    A --> D["(c) Find address for a name"]
    A --> E["(d) New member joins"]
    A --> F["(e) Member leaves"]
    A --> G["(f) Member moves"]
    A --> H["(g) Count members 65+"]
    
    B --> B1["TRAVERSE - visit each record"]
    C --> C1["TRAVERSE - check each record"]
    D --> D1["SEARCH - find specific record"]
    E --> E1["INSERT - add new record"]
    F --> F1["DELETE - remove record"]
    G --> G1["SEARCH then UPDATE"]
    H --> H1["TRAVERSE and COUNT"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style E fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style F fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style G fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style H fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style B1 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style C1 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style D1 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style E1 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style F1 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style G1 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style H1 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
```

**Note:** Sometimes you need multiple operations. For example, to delete a specific record, you must first SEARCH for it, then DELETE it.

---

## 1.5 ALGORITHMS: COMPLEXITY, TIME-SPACE TRADEOFF

### What is an Algorithm?

An **algorithm** is a clear, step-by-step list of instructions to solve a problem.

### Measuring Algorithm Efficiency

We measure algorithms by:

```mermaid
graph LR
    A["Algorithm Efficiency"] --> B["Time<br/>(How long does it take?)"]
    A --> C["Space<br/>(How much memory does it use?)"]
    
    B --> D["Complexity = f(n)<br/>Time based on input size"]
    C --> E["Complexity = f(n)<br/>Space based on input size"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style E fill:#50C878,stroke:#333,stroke-width:2px,color:#000
```

**Complexity** = A function that tells us how much time or space an algorithm needs based on the size of the input (n).

---

### Searching Algorithms

#### Linear Search

**How it works:** Check each item one by one until you find what you're looking for.

```
Algorithm: LINEAR SEARCH
Step 1: Start from the first item
Step 2: Compare current item with target
Step 3: If match found, STOP
Step 4: If not, move to next item
Step 5: Repeat until found or end of list
```

```mermaid
graph LR
    A["Start"] --> B["Check Item 1"]
    B -->|"Not found"| C["Check Item 2"]
    C -->|"Not found"| D["Check Item 3"]
    D -->|"Found!"| E["Stop"]
    
    style A fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style B fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style E fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
```

**Complexity:** Average = n/2 comparisons (for n items)
- For 1000 items: about 500 comparisons on average

---

#### Binary Search

**Requirement:** The list must be SORTED first!

**How it works:** Keep dividing the list in half until you find the target.

```
Algorithm: BINARY SEARCH
Step 1: Compare target with MIDDLE item
Step 2: If equal, FOUND!
Step 3: If target < middle, search LEFT half
Step 4: If target > middle, search RIGHT half
Step 5: Repeat with the smaller half
```

```mermaid
graph TD
    A["Full List (1-1000)"] --> B["Compare with Middle (500)"]
    B -->|"Target > 500"| C["Right Half (501-1000)"]
    B -->|"Target < 500"| D["Left Half (1-499)"]
    C --> E["Compare with Middle (750)"]
    E -->|"Target < 750"| F["Left Half (501-749)"]
    F --> G["Keep halving..."]
    G --> H["Found!"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style E fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style F fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style G fill:#95A5A6,stroke:#333,stroke-width:2px,color:#fff
    style H fill:#50C878,stroke:#333,stroke-width:2px,color:#000
```

**Complexity:** log₂(n) comparisons
- For 1000 items: about 10 comparisons
- For 25,000 items: only 15 comparisons!

---

### Comparison: Linear vs Binary Search

| Number of Items | Linear Search | Binary Search |
|-----------------|---------------|---------------|
| 100             | 50            | 7             |
| 1,000           | 500           | 10            |
| 10,000          | 5,000         | 14            |
| 25,000          | 12,500        | 15            |
| 1,000,000       | 500,000       | 20            |

**Binary search is MUCH faster!** But it has drawbacks:
- List must be sorted
- Must be stored in an array (direct access to middle element)
- Inserting/deleting items requires moving other items

---

### Time-Space Tradeoff

Sometimes you can trade memory space for speed, or speed for memory space.

#### Example: Searching by Two Different Keys

**Problem:** A file has Name and Social Security Number. 
- File is sorted by SSN (fast SSN search)
- But searching by Name is slow!

```mermaid
graph TD
    A["Solutions"] --> B["Solution 1: Two Complete Files"]
    A --> C["Solution 2: Main File + Index"]
    
    B --> D["✅ Fast for both keys"]
    B --> E["❌ Double the storage space"]
    
    C --> F["✅ Fast for both keys"]
    C --> G["✅ Minimal extra space"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
    style C fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style D fill:#F5E663,stroke:#333,stroke-width:2px,color:#000
    style E fill:#F5E663,stroke:#333,stroke-width:2px,color:#000
    style F fill:#F5E663,stroke:#333,stroke-width:2px,color:#000
    style G fill:#F5E663,stroke:#333,stroke-width:2px,color:#000
```

**Best Solution:** Main file sorted by SSN + Small index sorted by Name (with pointers to main file)

```mermaid
graph LR
    subgraph "Auxiliary Array (Sorted by Name)"
        I1["Abbey → 2"]
        I2["Brown → 4"]
        I3["Carey → 546"]
        I4["Davis → 1"]
    end
    
    subgraph "Main File (Sorted by SSN)"
        M1["1: 013-44-5555, Davis"]
        M2["2: 025-55-6198, Abbey"]
        M3["3: 027-73-3961, Lane"]
        M4["4: 174-62-3485, Brown"]
    end
    
    I1 -.-> M2
    I2 -.-> M4
    I4 -.-> M1
    
    style I1 fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style I2 fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style I3 fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style I4 fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style M1 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style M2 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style M3 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style M4 fill:#50C878,stroke:#333,stroke-width:2px,color:#000
```

**Hashing:** Another solution uses a special function to calculate the memory address directly from the key. This will be covered in Chapter 9.

---

## SOLVED PROBLEMS

### Problem 1.1: Class List

A professor's class list contains: **Name, Major, Student Number, Test Scores, Final Grade**

**(a) What are the entities, attributes, and entity set?**
- **Entity:** Each student
- **Entity Set:** Collection of all students
- **Attributes:** Name, Major, Student Number, Test Scores, Final Grade

**(b) Describe the field values, records, and file.**
- **Field Values:** Actual data (e.g., "John Smith", 85, "A")
- **Record:** All data for one student
- **File:** All student records together

**(c) Which attributes can be primary keys?**
- ✅ **Name** (if no duplicates) or **Student Number** (always unique)
- Professors usually use Name; registrar uses Student Number

---

### Problem 1.2: Patient File

Hospital patient file contains: **Name, Admission Date, SSN, Room, Bed Number, Doctor**

**(a) Which items can serve as primary keys?**
- ✅ Name (assuming no duplicates)
- ✅ Social Security Number

**(b) Which pair of items can serve as a primary key?**
- ✅ Room + Bed Number together (only one patient per bed)

**(c) Which items can be group items?**
- Name (First, Last)
- Admission Date (Month, Day, Year)
- Doctor (might include specialty)

---

### Problem 1.3: Variable-Length Records

Which items may cause variable-length records?
- (a) age ❌
- (b) sex ❌
- (c) name of spouse ❌
- (d) names of children ✅ (different number of children)
- (e) education ✅ (different levels of detail)
- (f) previous employers ✅ (different number of jobs)

---

### Problem 1.4: Database Systems

**Why are database systems only briefly covered in this text?**

Database systems deal with data stored in secondary memory (hard drives). The way we implement and analyze data structures in secondary memory is very different from main memory (RAM). This book focuses on main memory data structures.

---

### Problem 1.5: Brief Descriptions

**(a) Traversing:** Going through and processing each record exactly once

**(b) Sorting:** Putting records in a specific order (alphabetical, numerical, etc.)

**(c) Searching:** Finding the location of a record with a specific key

---

### Problem 1.6: Brief Descriptions

**(a) Inserting:** Adding a new record while keeping the structure organized

**(b) Deleting:** Removing a specific record from the structure

---

### Problem 1.7: Array Operations

Given array NAME (sorted alphabetically):

| Index | NAME |
|-------|------|
| 1 | Adam |
| 2 | Clark |
| 3 | Evans |
| 4 | Gupta |
| 5 | Jones |
| 6 | Lane |
| 7 | Pace |
| 8 | Smith |

**(a) Find NAME[2], NAME[4], NAME[7]**
- NAME[2] = Clark
- NAME[4] = Gupta
- NAME[7] = Pace

**(b) Insert "Davis" - how many names must move?**
- Davis goes after Clark (position 3)
- Evans through Smith must move down
- **6 names moved**

**(c) Delete "Gupta" - how many names must move?**
- Jones through Smith move up
- **4 names moved**

---

### Problem 1.8: Following Links

Given FIRST = 5 and the following data:

| Index | NAME | LINK |
|-------|------|------|
| 1 | Rogers | 7 |
| 2 | Clark | 8 |
| 4 | Hansen | 10 |
| 5 | Brooks | 2 |
| 6 | Pitt | 1 |
| 7 | Walker | 0 |
| 8 | Fisher | 4 |
| 10 | Leary | 6 |

**Find the order:**

```mermaid
graph LR
    A["FIRST=5<br/>Brooks"] --> B["LINK=2<br/>Clark"]
    B --> C["LINK=8<br/>Fisher"]
    C --> D["LINK=4<br/>Hansen"]
    D --> E["LINK=10<br/>Leary"]
    E --> F["LINK=6<br/>Pitt"]
    F --> G["LINK=1<br/>Rogers"]
    G --> H["LINK=7<br/>Walker"]
    H --> I["LINK=0<br/>END"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style E fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style F fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style G fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style H fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style I fill:#95A5A6,stroke:#333,stroke-width:2px,color:#fff
```

**Order:** Brooks, Clark, Fisher, Hansen, Leary, Pitt, Rogers, Walker (alphabetical!)

---

### Problem 1.9: Expression Tree

Draw tree for: **(7x + y)(5a - b)³**

```mermaid
graph TD
    A["*"] --> B["+"]
    A --> C["↑"]
    
    B --> D["*"]
    B --> E["y"]
    
    D --> F["7"]
    D --> G["x"]
    
    C --> H["-"]
    C --> I["3"]
    
    H --> J["*"]
    H --> K["b"]
    
    J --> L["5"]
    J --> M["a"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#FFB84D,stroke:#333,stroke-width:2px,color:#000
```

**Scope of ↑ (exponentiation):** The subtree containing -, 5, a, b, and 3 → represents (5a - b)³

---

### Problem 1.10: Tree from Level Numbers

```
01 Employee
  02 Name
  02 Number
  02 Hours
    03 Regular
    03 Overtime
  02 Rate
```

```mermaid
graph TD
    A["Employee"] --> B["Name"]
    A --> C["Number"]
    A --> D["Hours"]
    A --> E["Rate"]
    
    D --> F["Regular"]
    D --> G["Overtime"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style E fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style F fill:#50C878,stroke:#333,stroke-width:2px,color:#000
    style G fill:#50C878,stroke:#333,stroke-width:2px,color:#000
```

---

### Problem 1.11: Stack or Queue?

**(a) Batch computer programs submitted:**
- **Queue** - First come, first served

**(b) Program A calls B, B calls C, etc.:**
- **Stack** - Last called program finishes first

**(c) Seniority system for hiring/firing:**
- **Stack** - Last hired is first to be discharged

---

### Problem 1.12: Airline Flights Graph

Given the flight data, draw a directed graph:

```mermaid
graph LR
    Boston -->|"701"| Chicago
    Chicago -->|"702"| Boston
    Philadelphia -->|"705"| Chicago
    Chicago -->|"708"| Miami
    Boston -->|"711"| Philadelphia
    Philadelphia -->|"712"| Boston
    Philadelphia -->|"713"| Atlanta
    Atlanta -->|"715"| Miami
    Philadelphia -->|"717"| Miami
    Miami -->|"718"| Philadelphia
    
    style Boston fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style Chicago fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style Philadelphia fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style Miami fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style Atlanta fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
```

---

### Problem 1.13: Complexity Concepts

**(a) Complexity of an algorithm:**
A function f(n) that measures time and/or space used based on input size n.

**(b) Space-time tradeoff:**
The choice between using more memory to run faster, or using less memory but running slower.

---

### Problem 1.14: Search Comparison

For a data set with n elements:

| n | Linear Search (n/2) | Binary Search (log₂n) |
|---|---------------------|----------------------|
| 1,000 | 500 | 10 |
| 10,000 | 5,000 | 14 |

**Note:** Binary search cannot be used on a linked list because you can't directly access the middle element.

---

### Problem 1.15: Storing Flight Data Efficiently

**(a) To quickly find origin and destination given flight number:**
Store data in arrays ORIG and DEST where the flight number is the subscript (index).

**(b) To quickly find if flight exists between two cities:**
Use a 2D array FLIGHT where FLIGHT[J, K] contains the flight number from CITY[J] to CITY[K], or 0 if no flight exists.

---

### Problem 1.16: Drawbacks of Data Representations

**(a) Subscript-based arrays:**
If flight numbers are spaced far apart (e.g., 701, 2500, 9999), most array positions are wasted.

**(b) 2D flight array:**
If there are very few flights compared to city pairs, the array contains mostly zeros (called a **sparse matrix**) - wasted space.

---

## Summary

### Key Concepts

```mermaid
graph TD
    A["Chapter 1 Summary"] --> B["Data Organization"]
    A --> C["Data Structures"]
    A --> D["Operations"]
    A --> E["Algorithms"]
    
    B --> B1["Fields → Records → Files"]
    B --> B2["Primary Keys"]
    
    C --> C1["Arrays"]
    C --> C2["Linked Lists"]
    C --> C3["Trees"]
    C --> C4["Stacks & Queues"]
    C --> C5["Graphs"]
    
    D --> D1["Traverse, Search"]
    D --> D2["Insert, Delete"]
    D --> D3["Sort, Merge"]
    
    E --> E1["Time & Space Complexity"]
    E --> E2["Linear vs Binary Search"]
    E --> E3["Time-Space Tradeoff"]
    
    style A fill:#E94B3C,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style D fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
    style E fill:#4A90E2,stroke:#333,stroke-width:2px,color:#fff
```

### Remember:

1. **Data** = Values organized in structures
2. **Choose the right structure** for your problem
3. **Primary key** = Unique identifier for each record
4. **Stack** = Last in, first out (LIFO)
5. **Queue** = First in, first out (FIFO)
6. **Binary search** is much faster than linear search (but needs sorted data)
7. **Time-space tradeoff** = Balance between speed and memory usage

---

**End of Chapter 1**

*Continue to [Chapter 2: Preliminaries](../Chapter%202%20-%20Preliminaries/README.md)*

