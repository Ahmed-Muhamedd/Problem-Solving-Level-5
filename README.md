# 🔗 Problem Solving - Level 5: Data Structure Manipulation

This repository contains a Level 5 problem-solving project that focuses on manual implementation and manipulation of core data structures using C++. It is designed to deepen understanding of how data structures work under the hood without relying on built-in collections.

## 🚀 Project Overview

In this task, I implemented the following data structures and operations from scratch:

### 1. 🧱 Doubly Linked List
- Created manually using a `Node` class.
- Each node contains references to both the previous and next nodes.
- Supports typical operations like insertion, deletion, traversal, and searching.

### 2. 📚 Dynamic Array
- Custom implementation of a resizable array.
- Handles resizing automatically when adding/removing elements.
- Used as a foundation for other data structures.

### 3. 📦 Stack (LIFO)
- Implemented using the custom dynamic array.
- Supports push, pop, and peek operations.
- Used for `undo` and `redo` operations.

### 4. 📬 Queue (FIFO)
- Implemented using the custom dynamic array.
- Supports enqueue and dequeue operations.

### 5. 🔁 Undo/Redo System
- Built using two stacks:
  - `undoStack`: stores previous states.
  - `redoStack`: stores reverted states for recovery.
- Simulates user operations with ability to reverse and reapply actions.

## ⚙️ Key Concepts Practiced
- Pointers and node linking in doubly linked lists.
- Dynamic memory management.
- Manual handling of array capacity and indexing.
- Understanding stack and queue behaviors.
- Real-world use case of stack with undo/redo mechanisms.

## 🛠️ Technologies Used
- Language: C++
- Platform: Console Application

---

This project is a great exercise to enhance low-level data structure skills, pointer logic, and memory manipulation. It provides a deeper understanding of how higher-level abstractions work internally and how to apply them effectively in real applications.

