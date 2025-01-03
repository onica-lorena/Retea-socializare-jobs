# Rețea Socializare Jobs

„Rețea Socializare Jobs” este o aplicație de consolă scrisă în C++ care permite gestionarea anunțurilor de joburi și monitorizarea aplicațiilor candidaților. Aplicația oferă funcționalități precum adăugarea, modificarea și ștergerea anunțurilor de joburi, precum și vizualizarea candidaților care au aplicat pentru un anumit job.

## Funcționalități
1. Adăugare joburi noi în listă.
2. Modificare detalii ale joburilor existente.
3. Ștergere joburi din sistem.
4. Vizualizare candidați care au aplicat pentru un job specific.

## Structura proiectului
- **`main.cpp`**: Codul principal care implementează meniul și interacțiunile utilizatorului.
- **`GestionareJoburi.hpp`**: Declarațiile claselor și funcțiilor utilizate pentru gestionarea joburilor și aplicațiilor.
- **`jobs.txt`**: Fișier text care stochează lista de joburi.
- **`aplicari.txt`**: Fișier text care stochează aplicațiile candidaților.

## Tehnologii utilizate
- **Limbaj**: C++
- **Paradigmă**: Programare orientată pe obiecte (OOP)
- **Sistem de rulare**: Consolă

## Cum să rulezi aplicația

### Folosind terminalul:
1. Clonează repository-ul:
   ```bash
   git clone https://github.com/onica-lorena/Retea-socializare-jobs.git
2. Compilează proiectul folosind un compilator C++:
   ```bash
   g++ main.cpp -o Retea-socializare-jobs
3. Rulează aplicația:
   ```bash
   ./Retea-socializare-jobs

### Folosind un IDE:
1. **Code::Blocks**:
   - Creează un proiect nou și adaugă fișierele `main.cpp` și `GestionareJoburi.hpp`.
   - Click pe **Build and Run**.

2. **Dev-C++**:
   - Deschide fișierul `main.cpp` și include header-ul `GestionareJoburi.hpp`.
   - Click pe **Execute > Compile and Run**.

3. **Visual Studio**:
   - Creează un proiect nou de tip **Console Application**.
   - Adaugă fișierele `main.cpp` și `GestionareJoburi.hpp` în proiect.
   - Compilează și rulează aplicația.

---

## Exemple de utilizare

### 1. Adăugare Job
- **Comanda**: `1`
- Introduceți detalii precum ID-ul, titlul jobului, descrierea și abilitățile necesare (separate prin virgulă).

### 2. Modificare Job
- **Comanda**: `2`
- Introduceți ID-ul jobului și noile detalii (descriere și abilități).

### 3. Ștergere Job
- **Comanda**: `3`
- Introduceți ID-ul jobului pe care doriți să îl ștergeți.

### 4. Vizualizare Candidați
- **Comanda**: `4`
- Introduceți ID-ul jobului pentru a vizualiza candidații care au aplicat.

## Autori
- **Onica Lorena-Andreea**  
- [Profil GitHub](https://github.com/onica-lorena)


