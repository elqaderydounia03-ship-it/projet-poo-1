#include <iostream>
#include <fstream>
using namespace std;

// Structure Etudiant
struct Etudiant
{
    int id;
    string nom;
    string prenom;
    int age;
    float note;
};

// Tableau des étudiants
Etudiant etudiants[100];
int nombreEtudiants = 0;

// Ajouter étudiant
void ajouterEtudiant()
{
    cout << "\n===== Ajouter un etudiant =====" << endl;

    cout << "ID : ";
    cin >> etudiants[nombreEtudiants].id;

    cout << "Nom : ";
    cin >> etudiants[nombreEtudiants].nom;

    cout << "Prenom : ";
    cin >> etudiants[nombreEtudiants].prenom;

    cout << "Age : ";
    cin >> etudiants[nombreEtudiants].age;

    cout << "Note : ";
    cin >> etudiants[nombreEtudiants].note;

    nombreEtudiants++;

    cout << "Etudiant ajoute avec succes !" << endl;
}

// Afficher étudiants
void afficherEtudiants()
{
    cout << "\n===== Liste des etudiants =====" << endl;

    if(nombreEtudiants == 0)
    {
        cout << "Aucun etudiant." << endl;
    }

    for(int i = 0; i < nombreEtudiants; i++)
    {
        cout << "\nEtudiant " << i + 1 << endl;
        cout << "ID : " << etudiants[i].id << endl;
        cout << "Nom : " << etudiants[i].nom << endl;
        cout << "Prenom : " << etudiants[i].prenom << endl;
        cout << "Age : " << etudiants[i].age << endl;
        cout << "Note : " << etudiants[i].note << endl;
    }
}

// Rechercher étudiant
void rechercherEtudiant()
{
    int id;
    bool trouve = false;

    cout << "\nEntrer ID : ";
    cin >> id;

    for(int i = 0; i < nombreEtudiants; i++)
    {
        if(etudiants[i].id == id)
        {
            cout << "\nEtudiant trouve :" << endl;
            cout << "ID : " << etudiants[i].id << endl;
            cout << "Nom : " << etudiants[i].nom << endl;
            cout << "Prenom : " << etudiants[i].prenom << endl;
            cout << "Age : " << etudiants[i].age << endl;
            cout << "Note : " << etudiants[i].note << endl;

            trouve = true;
        }
    }

    if(!trouve)
        cout << "Etudiant introuvable !" << endl;
}

// Modifier étudiant
void modifierEtudiant()
{
    int id;
    bool trouve = false;

    cout << "\nID a modifier : ";
    cin >> id;

    for(int i = 0; i < nombreEtudiants; i++)
    {
        if(etudiants[i].id == id)
        {
            cout << "Nouveau nom : ";
            cin >> etudiants[i].nom;

            cout << "Nouveau prenom : ";
            cin >> etudiants[i].prenom;

            cout << "Nouvel age : ";
            cin >> etudiants[i].age;

            cout << "Nouvelle note : ";
            cin >> etudiants[i].note;

            cout << "Modifie avec succes !" << endl;
            trouve = true;
        }
    }

    if(!trouve)
        cout << "Etudiant introuvable !" << endl;
}

// Supprimer étudiant
void supprimerEtudiant()
{
    int id;
    bool trouve = false;

    cout << "\nID a supprimer : ";
    cin >> id;

    for(int i = 0; i < nombreEtudiants; i++)
    {
        if(etudiants[i].id == id)
        {
            for(int j = i; j < nombreEtudiants - 1; j++)
            {
                etudiants[j] = etudiants[j + 1];
            }

            nombreEtudiants--;
            cout << "Supprime avec succes !" << endl;

            trouve = true;
        }
    }

    if(!trouve)
        cout << "Etudiant introuvable !" << endl;
}

// Sauvegarde fichier
void sauvegarderEtudiants()
{
    ofstream fichier("etudiants.txt");

    for(int i = 0; i < nombreEtudiants; i++)
    {
        fichier << etudiants[i].id << " "
                << etudiants[i].nom << " "
                << etudiants[i].prenom << " "
                << etudiants[i].age << " "
                << etudiants[i].note << endl;
    }

    fichier.close();

    cout << "Donnees sauvegardees dans fichier !" << endl;
}

// Main
int main()
{
    int choix;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====" << endl;

        cout << "1. Ajouter etudiant" << endl;
        cout << "2. Afficher etudiants" << endl;
        cout << "3. Rechercher etudiant" << endl;
        cout << "4. Modifier etudiant" << endl;
        cout << "5. Supprimer etudiant" << endl;
        cout << "6. Sauvegarder" << endl;
        cout << "7. Quitter" << endl;

        cout << "Choix : ";
        cin >> choix;

        switch(choix)
        {
            case 1: ajouterEtudiant(); break;
            case 2: afficherEtudiants(); break;
            case 3: rechercherEtudiant(); break;
            case 4: modifierEtudiant(); break;
            case 5: supprimerEtudiant(); break;
            case 6: sauvegarderEtudiants(); break;
            case 7: cout << "Fin du programme." << endl; break;
            default: cout << "Choix invalide !" << endl;
        }

    } while(choix != 7);

    return 0;
}
