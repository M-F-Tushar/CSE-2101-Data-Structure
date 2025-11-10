# Chapter 1: Introduction and Overview - Complete Study Guide

## 1.1 INTRODUCTION

### What This Chapter Covers
- Basic terminology and concepts
- Data organization methods
- Different data structures
- Operations on data structures
- Algorithms and their complexity
- Time-space tradeoffs

---

## 1.2 BASIC TERMINOLOGY & ELEMENTARY DATA ORGANIZATION

### Core Definitions

#### 1. **Data**
- Simple values or collections of values
- Example: Numbers, names, addresses

#### 2. **Data Items**
- **Elementary Items**: Cannot be divided further
  - Example: Social Security Number (134-24-5533)
- **Group Items**: Can be divided into sub-items
  - Example: Employee Name → First Name, Middle Initial, Last Name

### Data Organization Hierarchy

```
FILE (All employees)
  ↓
RECORD (Single employee)
  ↓
FIELD (Individual attribute like Name, Age)
```

#### 3. **Entity**
- Something with specific attributes
- **Example**: An employee is an entity

**Attributes & Values:**
| Attribute | Value |
|-----------|-------|
| Name | ROHLAND, GAIL |
| Age | 34 |
| Sex | F |
| Social Security Number | 134-24-5533 |

#### 4. **Entity Set**
- Collection of similar entities
- Example: All employees in a company

#### 5. **Attribute Range**
- Set of all possible values for an attribute
- Example: Age range might be 18-65

### Key Hierarchy Terms

**FIELD** → Single unit of information representing one attribute
- Example: "Age" field containing value "34"

**RECORD** → Collection of all field values for one entity
- Example: One complete employee record with all their information

**FILE** → Collection of records for all entities in an entity set
- Example: All employee records together

#### 6. **Primary Key**
- A field that uniquely identifies each record
- **Symbol**: K
- **Key Values**: k₁, k₂, k₃...

### Example 1.1(a): Automobile Dealership

**Record contains:**
- Serial Number *(Primary Key)*
- Type
- Year
- Price
- Accessories

**Why Serial Number is Primary Key:**
- Each automobile has a unique serial number
- No two cars share the same serial number

### Example 1.1(b): Membership File

**Record contains:**
- Name *(Primary Key)*
- Address
- Telephone Number
- Dues Owed

**Important Notes:**
- Name and Address can be group items
- Address CANNOT be primary key (family members share addresses)
- Telephone Number CANNOT be primary key (family members share phones)

### Record Types by Length

#### **Fixed-Length Records**
- All records have same data items
- Same space assigned to each field
- Example: All employee records have exactly 10 fields

#### **Variable-Length Records**
- Different records can have different lengths
- Have minimum and maximum lengths
- **Example**: Student records
  - Student A: Takes 4 courses
  - Student B: Takes 6 courses
  - Different record lengths!

### Three Steps in Studying Data Structures

1. **Logical/Mathematical Description**
   - How the structure is conceptually organized

2. **Computer Implementation**
   - How to build it in actual code

3. **Quantitative Analysis**
   - Memory needed
   - Processing time required

### Important Note: Storage Types

**Primary (Main) Memory:**
- Direct access to any location
- Access time doesn't depend on location
- This textbook focuses on this type

**Secondary (External) Storage:**
- File management/Database management
- Different access patterns
- Beyond scope of this text

---

## 1.3 DATA STRUCTURES

### What is a Data Structure?

**Definition:** A logical or mathematical model for organizing data

**Two Key Considerations:**
1. Rich enough to mirror real-world relationships
2. Simple enough to process efficiently

### Classification of Data Structures

```
DATA STRUCTURES
├── Primitive Data Structures
│   ├── Integer
│   ├── Real
│   ├── Character
│   └── Boolean
│
└── Non-Primitive Data Structures
    ├── Linear Data Structures
    │   ├── Arrays
    │   ├── Linked Lists
    │   ├── Stacks
    │   └── Queues
    │
    └── Non-Linear Data Structures
        ├── Trees
        └── Graphs
```

### Primitive Data Structures
- Basic data types: Integer, Real, Character, Boolean
- Cannot be divided further
- Also called "simple data types"

### Non-Primitive Data Structures

#### **Linear Data Structures**
- Elements form a sequence or linear list
- Data arranged in linear fashion
- Examples: Arrays, Linked Lists, Stacks, Queues

#### **Non-Linear Data Structures**
- Data NOT arranged in sequence
- Insertion/deletion not in linear fashion
- Examples: Trees, Graphs

---

## DETAILED DATA STRUCTURES

### 1. ARRAYS

#### **Linear (One-Dimensional) Array**

**Definition:** A list of finite number (n) of similar elements

**Three Notation Styles:**

1. **Subscript Notation:** A₁, A₂, A₃, ..., Aₙ
2. **Parenthesis Notation:** A(1), A(2), A(3), ..., A(N)
3. **Bracket Notation:** A[1], A[2], A[3], ..., A[N]

**Terms:**
- K in A[K] is called a **subscript**
- A[K] is called a **subscripted variable**

#### Example 1.2: Student Array

```
Index | STUDENT Array
------|---------------
1     | John Brown
2     | Sandra Gold
3     | Tom Jones
4     | June Kelly
5     | Mary Reed
6     | Alan Smith
```

**Access Examples:**
- STUDENT[1] = "John Brown"
- STUDENT[2] = "Sandra Gold"
- STUDENT[6] = "Alan Smith"

#### **Two-Dimensional Array**

**Definition:** Collection where each element needs TWO subscripts

**Also Called:**
- Matrices (in mathematics)
- Tables (in business)

#### Example 1.3: Store Sales Data

**Scenario:** 28 stores, 4 departments each, tracking weekly sales

```
         Dept 1  Dept 2  Dept 3  Dept 4
Store 1   2872    805    3211    1560
Store 2   2196   1223    2525    1744
Store 3   3257   1017    3686    1951
  ...
Store 28  2618    931    2333     982
```

**Array Access:**
- SALES[1, 1] = 2872 (Store 1, Dept 1)
- SALES[1, 2] = 805 (Store 1, Dept 2)
- SALES[28, 4] = 982 (Store 28, Dept 4)

**Array Size:** 28 × 4
- 28 rows (horizontal)
- 4 columns (vertical)

---

### 2. LINKED LISTS

**Introduced through a practical example:**

#### The Brokerage Firm Problem

**Initial Data:**
```
Customer    | Salesperson
------------|------------
Adams       | Smith
Brown       | Ray
Clark       | Jones
Drew        | Ray
Evans       | Smith
Farmer      | Jones
Geller      | Ray
Hill        | Smith
Infeld      | Ray
```

#### **Problem with Simple Table Storage:**
- Takes up space storing repeated salesperson names
- Hard to find all customers for one salesperson

#### **Solution 1: Using Pointers**

```
Customer Array          Salesperson Array
Loc | Name    | Pointer    Loc | Name
----|---------|--------    ----|------
1   | Adams   | 3          1   | Jones
2   | Brown   | 2          2   | Ray
3   | Clark   | 1          3   | Smith
4   | Drew    | 2
5   | Evans   | 3
6   | Farmer  | 1
7   | Geller  | 2
8   | Hill    | 3
9   | Infeld  | 2
```

**Benefit:** Saves space (integer pointer < name string)

**Drawback:** Still need to search entire customer file to find one salesperson's customers

#### **Solution 2: Reverse Pointers**

```
Salesperson Array
Loc | Name  | Pointers to Customers
----|-------|----------------------
1   | Jones | 3, 6
2   | Ray   | 2, 4, 7, 9
3   | Smith | 1, 5, 8
```

**Drawback:** Each salesperson needs multiple pointers; changes frequently

#### **Solution 3: Linked List (Best Solution!)**

```
Salesperson         Customer File
Loc | Name | Start  Loc | Name   | Next
----|------|-----  -----|--------|-----
1   | Jones| 3     1    | Adams  | 5
2   | Ray  | 2     2    | Brown  | 4
3   | Smith| 1     3    | Clark  | 6
                   4    | Drew   | 7
                   5    | Evans  | 8
                   6    | Farmer | 0
                   7    | Geller | 9
                   8    | Hill   | 0
                   9    | Infeld | 0
```

**How Ray's Customers Chain:**
Ray (pointer=2) → Brown (2, next=4) → Drew (4, next=7) → Geller (7, next=9) → Infeld (9, next=0 = END)

**Key Terms:**
- **Pointer:** Points from one list to another list
- **Link:** Points within the same list (like customer to customer)
- **0 or NULL:** Indicates end of list

**Benefits:**
- Easy to get all customers for one salesperson
- Easy to insert new customers
- Easy to delete customers

---

### 3. TREES

**Definition:** Data structure reflecting hierarchical relationships

**Also Called:** Rooted tree graph

#### Example 1.4: Employee Record Structure

**Hierarchical Organization:**

```
                    Employee
                       |
        ├──────┬───────┼────────┬─────────┬──────────┐
     Soc.Sec  Name  Address    Age    Salary    Dependents
               |       |
          ┌────┼────┐  ├─────────┐
        Last First MI  Street   Area
                              |
                         ┌────┼─────┐
                       City State  ZIP
```

**Level-Based Representation:**

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

**Key Points:**
- Employee is the ROOT
- Name and Address are GROUP ITEMS
- Last, First, City, State are ELEMENTARY ITEMS

#### Example 1.5: Algebraic Expression Tree

**Expression:** (2x + y) × (a - 7b)³

**Notation:**
- ↑ means exponentiation
- \* means multiplication

**Tree Representation:**

```
          *
         / \
        /   \
       +     ↑
      / \   / \
     *   y -   3
    / \   / \
   2   x a   *
            / \
           7   b
```

**Reading the Tree:**
- Bottom operations happen first
- Top operation (* at root) happens last
- Order: multiply 7×b, subtract a-7b, raise to power 3, add 2x+y, final multiply

---

### 4. STACK (LIFO System)

**Definition:** Last-In, First-Out linear list

**Operations:**
- Insert at TOP only
- Delete from TOP only

**Real-World Analogy:** Stack of dishes on a spring

```
    TOP → [Dish 5] ← Most recent
          [Dish 4]
          [Dish 3]
          [Dish 2]
 BOTTOM → [Dish 1] ← Oldest
```

**Key Property:** Last dish placed is first dish removed

---

### 5. QUEUE (FIFO System)

**Definition:** First-In, First-Out linear list

**Operations:**
- Delete from FRONT only
- Insert at REAR only

**Real-World Analogy:** Line of people waiting for a bus

```
FRONT → [Person 1] [Person 2] [Person 3] [Person 4] ← REAR
        (Gets bus    (Waiting)  (Waiting)  (Just
         first)                             arrived)
```

**Key Property:** First person in line is first to board bus

---

### 6. GRAPH

**Definition:** Data structure showing relationships between pairs of elements (not necessarily hierarchical)

#### Example: Airline Routes

```
      Boston -------- New York
        |                |
        |                |
     Chicago -------- Philadelphia
        |                |
        |                |
   Los Angeles ------ Miami
```

**Key Points:**
- Lines show direct flights
- Not hierarchical (no parent-child relationships)
- Shows connections/relationships

---

## 1.4 DATA STRUCTURE OPERATIONS

### Major Operations

#### 1. **TRAVERSING**
- Access each record exactly once
- Process certain items in the record
- Also called "visiting" the record

**Example:** Get names and addresses of all members for mailing list

#### 2. **SEARCHING**
- Find location of record with specific key
- Find all records satisfying conditions

**Example:** Find address for member named "John Smith"

#### 3. **INSERTING**
- Add new record to structure

**Example:** Add new member to membership file

#### 4. **DELETING**
- Remove record from structure

**Example:** Remove deceased member from file

#### 5. **SORTING**
- Arrange records in logical order
- Alphabetical or numerical

**Example:** Sort members by last name

#### 6. **MERGING**
- Combine two sorted files into one sorted file

**Example:** Merge old member list with new member list

### Example 1.6: Membership File Operations

**File Contains:** Name, Address, Telephone, Age, Sex

**Operation Examples:**

**(a) Mailing Announcement**
- **Operation:** TRAVERSING
- **Goal:** Get Name and Address for each member

**(b) Members in Certain Area**
- **Operation:** TRAVERSING
- **Goal:** Filter members by location

**(c) Find Address for Given Name**
- **Operation:** SEARCHING
- **Goal:** Locate specific member's record

**(d) New Member Joins**
- **Operation:** INSERTING
- **Goal:** Add new record to file

**(e) Member Dies**
- **Operation:** DELETING
- **Goal:** Remove record from file

**(f) Member Moves**
- **Operation:** SEARCHING then UPDATING
- **Goal:** Find record, then change address/phone

**(g) Count Members 65 or Older**
- **Operation:** TRAVERSING
- **Goal:** Count records meeting condition

---

## 1.5 ABSTRACT DATA TYPES (ADT)

### What is an ADT?

**Definition:** A set of data values and operations specified accurately, independent of implementation

**Key Principle:** You know WHAT it does, but HOW it works is hidden

### Example 1.7: List Representation

**List L:** 1, 2, 3, 4, 5, 6, 7, 8, 9

**Can Be Stored As:**

1. **Linear List:** 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9

2. **Matrix (3×3):**
   ```
   1  2  3
   4  5  6
   7  8  9
   ```

3. **Tree Structure**

4. **Graph Structure**

**ADT Benefit:** Users don't need to know which structure is used! They just insert and retrieve data.

### Example 1.8: Shop Customer Queue

**Scenario:**
- Shop has customers waiting
- Need to determine how many sales assistants needed
- Must simulate waiting line (QUEUE)

**Two Options:**

1. **Write specific program** for this shop
   - Time-consuming
   - Not reusable

2. **Create Queue ADT** (Better!)
   - Reusable for any queue problem
   - Faster to implement shop simulation
   - Focus on application, not queue mechanics

### ADT Model Structure

```
┌─────────────────────────────────────┐
│         Application Program         │
│                                     │
└─────────────┬───────────────────────┘
              │
              │ Interface (Public Functions Only)
              │
┌─────────────▼───────────────────────┐
│              ADT                    │
│  ┌─────────────────────────────┐   │
│  │   Public Functions          │   │
│  │   (Available to users)      │   │
│  └─────────────────────────────┘   │
│  ┌─────────────────────────────┐   │
│  │   Private Functions         │   │
│  │   (Internal use only)       │   │
│  └─────────────────────────────┘   │
│  ┌─────────────────────────────┐   │
│  │   Data Structures           │   │
│  │   - Arrays                  │   │
│  │   - Linked Lists            │   │
│  │   - Records                 │   │
│  └─────────────────────────────┘   │
└─────────────────────────────────────┘
```

### Key ADT Principles

1. **Encapsulation**
   - Data and operations packaged together
   - Hidden from user

2. **Interface**
   - Only public functions accessible
   - Application uses these to interact

3. **Independence**
   - Implementation can change
   - User code doesn't break

4. **Multiple Instances**
   - Can have multiple versions simultaneously
   - Each stores different data

---

## 1.6 ALGORITHMS: COMPLEXITY & TIME-SPACE TRADEOFF

### What is an Algorithm?

**Definition:** Well-defined list of steps for solving a problem

### Measuring Algorithm Efficiency

**Two Major Measures:**
1. **Time:** How long it takes to run
2. **Space:** How much memory it needs

**Complexity Function:** Gives running time/space based on input size

### Searching Algorithms Comparison

#### **Problem:** Find telephone number for given name in membership file

#### **Algorithm 1: LINEAR SEARCH**

**Method:**
1. Check first record
2. Check second record
3. Continue until finding the name

**Complexity:** C(n) = n/2 (average)
- For 1000 records: ~500 comparisons needed

**When to Use:**
- Small files
- Unsorted data
- Infrequent searches

#### **Algorithm 2: BINARY SEARCH**

**Prerequisites:** List must be sorted alphabetically

**Method:**
1. Check middle name
2. Determine which half contains target
3. Check middle of that half
4. Continue narrowing down

**Complexity:** C(n) = log₂ n
- For 25,000 records: Maximum 15 comparisons!

**Example with 8 names (sorted):**
```
Looking for "Mary" in: [Alice, Bob, Carol, Dan, Eve, Frank, Gary, Helen]

Step 1: Check middle (Dan)
        Mary > Dan, so search right half

Step 2: Check middle of [Eve, Frank, Gary, Helen] = Frank
        Mary > Frank, so search right half

Step 3: Check middle of [Gary, Helen] = Gary
        Mary > Gary, so search right half

Step 4: Helen is last item - not found!
```

### Drawbacks of Binary Search

**Problem 1:** Requires array storage
- Need direct access to middle element
- Can't use linked lists efficiently

**Problem 2:** Insertions/Deletions are expensive
- Must shift many elements
- Breaks the sorted order

**Solution Examples:**

**Telephone Company:**
- Print new directory yearly
- Keep separate file for new customers
- Update once per year (acceptable delay)

**Bank:**
- Needs instant customer insertion
- Sorted array not suitable
- Uses different data structure

### Time-Space Tradeoff Example

#### **Problem:** File with Name, Social Security Number, and lots of extra data

**Challenge:**
- Easy to search by Name (if sorted alphabetically)
- Hard to search by Social Security Number (requires linear search)

#### **Solution 1: Duplicate File**
- One file sorted by Name
- Another file sorted by SSN
- **Cost:** DOUBLE the space!

#### **Solution 2: Auxiliary Array (Better!)**

```
Auxiliary Array          Main File
(Sorted by Name)        (Sorted by SSN)

Name        | Pointer   SSN         | Name       | Data
------------|-------   -------------|------------|------
Abbey, Greg | 2        013-44-5555  | Davis, E   | XXXX
Brown, John | 4        025-55-6198  | Abbey, G   | XXXX
Carey, Mary | 546      027-73-3961  | Lane, A    | XXXX
Davis, Earl | 1        174-62-3485  | Brown, J   | XXXX
Ellis, Susan| 76       182-74-6398  | Smith, M   | XXXX
```

**How It Works:**
1. Search auxiliary array by Name (binary search)
2. Get pointer
3. Jump directly to location in main file

**Benefits:**
- Minimal extra space (just 2 columns)
- Fast search by name
- Fast search by SSN
- Can update main file efficiently

### Hashing Functions (Preview)

**Extreme Idea:** Use SSN as direct address
- SSN 123-45-6789 → Store at location 123456789

**Problem:**
- Would need 1 BILLION memory locations
- For only thousands of actual records
- Massive waste of space!

**Solution:** Hashing Function H
- Maps SSN → reasonable address range
- Covered in detail later in textbook
- Balances time and space efficiently

---

## KEY TAKEAWAYS

### 1. Data Organization
- Data → Fields → Records → Files
- Primary keys uniquely identify records
- Records can be fixed or variable length

### 2. Data Structure Types
- **Primitive:** Integer, Real, Character, Boolean
- **Non-Primitive Linear:** Arrays, Lists, Stacks, Queues
- **Non-Primitive Non-Linear:** Trees, Graphs

### 3. Core Operations
- Traversing, Searching, Inserting, Deleting
- Sorting, Merging

### 4. Abstract Data Types
- Hide implementation details
- Provide clean interfaces
- Enable code reusability

### 5. Algorithm Efficiency
- **Linear Search:** C(n) = n/2 (simple but slow)
- **Binary Search:** C(n) = log₂ n (fast but requires sorted array)
- Time-space tradeoffs are common

### 6. Design Considerations
- Choose structure based on operations needed
- Consider frequency of operations
- Balance time vs. space requirements
- Think about insert/delete patterns

---

## PRACTICAL WISDOM

**"The choice of data structure depends on:**
- **What data you have**
- **What you need to do with it**
- **How often you need to do it"**

Understanding these fundamentals is essential before diving into specific implementations!
