# 🎓 Teacher & Student Management System in C

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="Language" />
  <img src="https://img.shields.io/badge/Paradigm-Procedural-blue?style=for-the-badge" alt="Paradigm" />
  <img src="https://img.shields.io/badge/Platform-Cross--Platform-lightgrey?style=for-the-badge" alt="Platform" />
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" alt="License" />
</p>

---

## 📌 Overview

**Teacher & Student Management System** (Öğretmen & Öğrenci Otomasyonu) is a console-based automation system developed in standard **C**. 

The program provides an efficient command-line interface (CLI) for managing student records, grade tracking, and standard administrative CRUD (Create, Read, Update, Delete) operations. It demonstrates core computer science fundamentals such as dynamic memory management, file handling / persistent I/O, and structured data handling using C structs.

---

## ✨ Key Features

- **Student Record Management:** Add new students with unique identifiers, personal information, and course details.
- **Grade & Performance Tracking:** Record exam results, calculate grade averages, and track academic status.
- **Search & Query System:** Fast lookup functionality to find student profiles by ID or name.
- **Update & Deletion:** Modify existing student credentials or remove records cleanly.
- **Data Persistence:** Read and write records directly to file storage (`.txt` / binary datastream) to retain state across sessions.
- **Menu-Driven CLI:** User-friendly, interactive terminal menu with input validation.

---

## 🛠️ Technical Concepts Demonstrated

- **Structures (`struct`):** Custom data models representing student and course entities.
- **Pointers & Memory:** Direct memory manipulation and pointer arithmetic for clean record handling.
- **File I/O (`stdio.h`):** Sequential/formatted file read/write operations (`fopen`, `fprintf`, `fscanf`, `fread`, `fwrite`).
- **Control Flow & Modularity:** Modular function separation for UI rendering, business logic, and storage.

---

## 🚀 Getting Started

### Prerequisites
You need a standard C compiler such as **GCC**, **Clang**, or **MinGW** installed on your system.

To check if GCC is installed:
```bash
gcc --version
