
# 🏃 AED Athlete Management System

A modular C application developed as part of the *Algoritmos e Estruturas de Dados* (AED) course in the 1st year of an Integrated Master's degree.

This program manages athletes, teams, and their performance in competitive events such as canoe/kayak races. It supports registering participants, recording times, managing qualifications, and evaluating performance based on minimum required times.

---

## 📦 Features

- Register athletes with name, gender, and birth date
- Automatically categorize athletes into:
  - Junior (≤18)
  - Senior (19–35)
  - Veteran (>35)
- Create same-gender teams
- Define events and minimum qualifying times
- Record athlete/team results in multiple events
- View and filter qualified participants by event
- Remove athletes and associated teams/times
- Print standings and top performers

---

## 🛠️ Technologies

- **C (ANSI C)**
- Modular TAD-based architecture (`atleta`, `equipa`, `tempo`, `minimo`, `gestor`, etc.)
- Dynamic memory management (`malloc`, `free`)
- Data structures:
  - Hash-based dictionary
  - Sequenced list
  - Iterators
- CLI input parsing

---

## ⚙️ Build Instructions

### 🔧 With `gcc`

```bash
gcc *.c -o aed
```

### 🔧 With `make` (if available)

```bash
make
```

---

## ▶️ Run

You can start the program normally:

```bash
./aed
```

Or feed it input from a file:

```bash
./aed < test.txt
```

---

## 📄 Sample Input Format

```text
ATLETA 1 M
João Silva
15/05/2001
ATLETA 2 M
Carlos Nunes
22/07/2002
EQUIPA EQ01 1 2
EVENTO Campeonato Nacional
1
K2 500 M
1
EQ01
1:42.25
MINIMO K2 500 M
1:45.00
APURADOS K2 500 M
SAIR
```

---

## 📚 Academic Context

- **Course**: Algoritmos e Estruturas de Dados (AED)
- **Degree**: Integrated Master’s in Engineering
- **Year**: 1st Year, 2nd Semester
- **Language**: C

---

## 🧠 Authors

**António Alves**
**João Alves**
