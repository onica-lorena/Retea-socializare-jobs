#ifndef GESTIONARE_JOBURI_HPP
#define GESTIONARE_JOBURI_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Job {
public:
    string id;
    string titlu;
    string descriere;
    vector<string> skills;

    Job(string id, string titlu, string descriere, vector<string> skills);

    friend ostream& operator<<(ostream& os, const Job& job);
};

class Aplicare {
public:
    string jobID;
    string candidat;

    Aplicare(string jobID, string candidat);

    friend ostream& operator<<(ostream& os, const Aplicare& aplicare);
};

class GestionareJoburi {
private:
    vector<Job> joburi;
    vector<Aplicare> aplicari;

    void citesteJoburiDinFisier();
    void scrieJoburiInFisier();
    void citesteAplicariDinFisier();
    void scrieAplicariInFisier();

public:
    GestionareJoburi();
    ~GestionareJoburi();

    bool existaJob(const string& id);
    void adaugaJob(const string& id, const string& titlu, const string& descriere, const string& skillsLine);
    void modificaJob(const string& id, const string& descriereNoua, const string& skillsLineNou);
    void stergeJob(const string& id);
    void vizualizeazaCandidati(const string& idJob);
};

void clearScreen();
void afiseazaMeniu();
void adaugaJob(GestionareJoburi& gestionare, const string& id, const string& titlu, const string& descriere, const string& skills);
void modificaJob(GestionareJoburi& gestionare, const string& id, const string& descriere, const string& skills);
void stergeJob(GestionareJoburi& gestionare, const string& id);
void vizualizeazaCandidati(GestionareJoburi& gestionare, const string& id);

#endif
