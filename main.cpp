#include "GestionareJoburi.hpp"

Job::Job(string id, string titlu, string descriere, vector<string> skills)
    : id(id), titlu(titlu), descriere(descriere), skills(skills) {}

ostream& operator<<(ostream& os, const Job& job) {
    os << "\nID: " << job.id << ", Titlu: " << job.titlu << ", Descriere: " << job.descriere << ", Skills: ";
    for (const auto& skill : job.skills) {
        os << skill << " ";
    }
    return os;
}

Aplicare::Aplicare(string jobID, string candidat) : jobID(jobID), candidat(candidat) {}

ostream& operator<<(ostream& os, const Aplicare& aplicare) {
    os << "\nJobID: " << aplicare.jobID << ", Candidat: " << aplicare.candidat;
    return os;
}

GestionareJoburi::GestionareJoburi() {
    citesteJoburiDinFisier();
    citesteAplicariDinFisier();
}

GestionareJoburi::~GestionareJoburi() {
    scrieJoburiInFisier();
    scrieAplicariInFisier();
}

void GestionareJoburi::citesteJoburiDinFisier() {
    ifstream fin("jobs.txt");
    if (!fin) return;
    int numarJoburi;
    fin >> numarJoburi;
    fin.ignore();
    for (int i = 0; i < numarJoburi; ++i) {
        string id, titlu, descriere, skillsLine;
        getline(fin, id, ' ');
        getline(fin, titlu, ' ');
        getline(fin, descriere, ' ');
        getline(fin, skillsLine);
        vector<string> skills;
        stringstream ss(skillsLine);
        string skill;
        while (getline(ss, skill, ',')) {
            skills.push_back(skill);
        }
        joburi.emplace_back(id, titlu, descriere, skills);
    }
}

void GestionareJoburi::scrieJoburiInFisier() {
    ofstream fout("jobs.txt");
    fout << joburi.size() << endl;
    for (const auto& job : joburi) {
        fout << job.id << " " << job.titlu << " " << job.descriere << " ";
        for (size_t i = 0; i < job.skills.size(); ++i) {
            fout << job.skills[i];
            if (i < job.skills.size() - 1) fout << ",";
        }
        fout << endl;
    }
}

void GestionareJoburi::citesteAplicariDinFisier() {
    ifstream fin("aplicari.txt");
    if (!fin) return;
    int numarAplicari;
    fin >> numarAplicari;
    fin.ignore();
    for (int i = 0; i < numarAplicari; ++i) {
        string jobID, candidat;
        getline(fin, jobID, ' ');
        getline(fin, candidat);
        aplicari.emplace_back(jobID, candidat);
    }
}

void GestionareJoburi::scrieAplicariInFisier() {
    ofstream fout("aplicari.txt");
    fout << aplicari.size() << endl;
    for (const auto& aplicare : aplicari) {
        fout << aplicare.jobID << " " << aplicare.candidat << endl;
    }
}

bool GestionareJoburi::existaJob(const string& id) {
    for (const auto& job : joburi) {
        if (job.id == id) {
            return true;
        }
    }
    return false;
}

void GestionareJoburi::adaugaJob(const string& id, const string& titlu, const string& descriere, const string& skillsLine) {
    if (existaJob(id)) {
        cout << "\nUn job cu acest ID exista deja." << endl;
        return;
    }
    vector<string> skills;
    stringstream ss(skillsLine);
    string skill;
    while (getline(ss, skill, ',')) {
        skills.push_back(skill);
    }
    joburi.emplace_back(id, titlu, descriere, skills);
    scrieJoburiInFisier();
    cout << "\nJob adaugat cu succes!" << endl;
}

void GestionareJoburi::modificaJob(const string& id, const string& descriereNoua, const string& skillsLineNou) {
    bool jobGasit = false;
    for (auto& job : joburi) {
        if (job.id == id) {
            job.descriere = descriereNoua;
            job.skills.clear();
            stringstream ss(skillsLineNou);
            string skill;
            while (getline(ss, skill, ',')) {
                job.skills.push_back(skill);
            }
            scrieJoburiInFisier();
            jobGasit = true;
            cout << "\nJob modificat cu succes!" << endl;
            break;
        }
    }
    if (!jobGasit) {
        cout << "\nJobul cu ID-ul introdus nu exista." << endl;
    }
}

void GestionareJoburi::stergeJob(const string& id) {
    if (!existaJob(id)) {
        cout << "\nJobul cu ID-ul introdus nu exista." << endl;
        return;
    }
    joburi.erase(remove_if(joburi.begin(), joburi.end(), [&id](const Job& job) {
        return job.id == id;
    }), joburi.end());
    scrieJoburiInFisier();
    cout << "\nJob sters cu succes!" << endl;
}

void GestionareJoburi::vizualizeazaCandidati(const string& idJob) {
    bool aplicariGasite = false;
    for (const auto& aplicare : aplicari) {
        if (aplicare.jobID == idJob) {
            cout << aplicare << endl;
            aplicariGasite = true;
        }
    }
    if (!aplicariGasite) {
        cout << "\nNu exista aplicari pentru jobul cu ID-ul " << idJob << "." << endl;
    }
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void afiseazaMeniu() {
    cout << "- Retea socializare jobs -" << endl;
    cout << "1. Adauga job" << endl;
    cout << "2. Modifica job" << endl;
    cout << "3. Sterge job" << endl;
    cout << "4. Vizualizeaza candidati" << endl;
    cout << "5. Iesire" << endl;
    cout << "Alege o optiune: ";
}

void adaugaJob(GestionareJoburi& gestionare, const string& id, const string& titlu, const string& descriere, const string& skills) {
    gestionare.adaugaJob(id, titlu, descriere, skills);
    cout << "\nApasa Enter pentru a reveni la meniul principal...";
    cin.ignore();
    cin.get();
}

void modificaJob(GestionareJoburi& gestionare, const string& id, const string& descriere, const string& skills) {
    gestionare.modificaJob(id, descriere, skills);
    cout << "\nApasa Enter pentru a reveni la meniul principal...";
    cin.ignore();
    cin.get();
}

void stergeJob(GestionareJoburi& gestionare, const string& id) {
    gestionare.stergeJob(id);
    cout << "\nApasa Enter pentru a reveni la meniul principal...";
    cin.ignore();
    cin.get();
}

void vizualizeazaCandidati(GestionareJoburi& gestionare, const string& id) {
    gestionare.vizualizeazaCandidati(id);
    cout << "\nApasa Enter pentru a reveni la meniul principal...";
    cin.ignore();
    cin.get();
}

int main(int argc, char* argv[]) {
    GestionareJoburi gestionare;
    if (argc > 1) {
        string command = argv[1];
        if (command == "adauga" && argc == 6) {
            adaugaJob(gestionare, argv[2], argv[3], argv[4], argv[5]);
        } else if (command == "modifica" && argc == 5) {
            modificaJob(gestionare, argv[2], argv[3], argv[4]);
        } else if (command == "sterge" && argc == 3) {
            stergeJob(gestionare, argv[2]);
        } else if (command == "vizualizeaza" && argc == 3) {
            vizualizeazaCandidati(gestionare, argv[2]);
        } else {
            cout << "Comanda sau argumente invalide." << endl;
        }
    } else {
        int optiune;
        do {
            afiseazaMeniu();
            cin >> optiune;
            cin.ignore();

            switch (optiune) {
                case 1: {
                    clearScreen();
                    string id, titlu, descriere, skills;
                    cout << "- Adauga Job -";
                    cout << "\nIntrodu ID job: ";
                    getline(cin, id);
                    cout << "Introdu titlu job: ";
                    getline(cin, titlu);
                    cout << "Introdu descriere job: ";
                    getline(cin, descriere);
                    cout << "Introdu skill-uri separate prin virgula: ";
                    getline(cin, skills);
                    adaugaJob(gestionare, id, titlu, descriere, skills);
                    clearScreen();
                    break;
                }
                case 2: {
                    clearScreen();
                    string id, descriere, skills;
                    cout << "- Modifica Job -";
                    cout << "\nIntrodu ID job: ";
                    getline(cin, id);
                    cout << "Introdu noua descriere: ";
                    getline(cin, descriere);
                    cout << "Introdu noi skill-uri separate prin virgula: ";
                    getline(cin, skills);
                    modificaJob(gestionare, id, descriere, skills);
                    clearScreen();
                    break;
                }
                case 3: {
                    clearScreen();
                    string id;
                    cout << "- Sterge Job -";
                    cout << "\nIntrodu ID job: ";
                    getline(cin, id);
                    stergeJob(gestionare, id);
                    clearScreen();
                    break;
                }
                case 4: {
                    clearScreen();
                    string id;
                    cout << "- Vizualizeaza Candidati -";
                    cout << "\nIntrodu ID job: ";
                    getline(cin, id);
                    vizualizeazaCandidati(gestionare, id);
                    clearScreen();
                    break;
                }
                case 5:
                    cout << "\nLa revedere!" << endl;
                    break;
                default:
                    cout << "\nOptiune invalida. Te rog sa incerci din nou." << endl;
                    break;
            }
        } while (optiune != 5);
    }
    return 0;
}
