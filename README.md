# Restaurant Management System (RMS)

**Name:** Andrew Baez  
**Panther ID:** 6286900  
**FIU Email:** abaez058@fiu.edu

---

## Overview

The **Restaurant Management System (RMS)** is a C-based program designed to simulate the management of a restaurant's menu and order operations. It demonstrates key systems programming concepts such as pointer arithmetic, function pointers, string manipulation, and modular programming.

---

## System Capabilities

The system supports up to **10 menu items**, each with:
- Name
- Category
- Price

---

## Core Features

### 1. Add Menu Items
- Safely add new menu items with **boundary checks** to prevent buffer overflows

### 2. Search Functionality
- Search for items by name using **pointer-based linear search**

### 3. Order Processing
- Calculate total prices and process orders using **pointer arithmetic**

### 4. Dynamic Sorting
- Sort the menu dynamically by:
  - **Price**
  - **Name**
  - **Category**
- Uses **function pointers** for flexible comparison strategies

### 5. Data Integrity
- Ensure data consistency and robust error handling through:
  - **Null-pointer checks**
  - **Loop protection macros**

---

## Technical Highlights

- **Pointer Arithmetic:** Efficient memory manipulation and data access
- **Function Pointers:** Dynamic sorting with pluggable comparison functions
- **String Manipulation:** Safe handling of menu item names and categories
- **Modular Programming:** Clean, maintainable code structure
- **Systems Programming Concepts:** Demonstrates low-level C programming best practices

---

## System Constraints

- Maximum capacity: **10 menu items**
- Implements comprehensive **boundary validation**
- Robust **error handling** throughout all operations
