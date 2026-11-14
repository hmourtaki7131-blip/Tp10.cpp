
#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string telephone;
    string email;

public:
    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    string getNom() const {
        return nom;
    }

    void afficher() const {
        cout << "Nom : " << nom << endl;
        cout << "Telephone : " << telephone << endl;
        cout << "Email : " << email << endl;
        cout << "----------------------" << endl;
    }
};

// Ajouter un contact
void ajouterContact(Contact** carnet, int& nb) {
    string nom, telephone, email;

    cout << "Donner le nom : ";
    cin >> nom;

    cout << "Donner le telephone : ";
    cin >> telephone;

    cout << "Donner l'email : ";
    cin >> email;

    carnet[nb] = new Contact(nom, telephone, email);
    nb++;

    cout << "Contact ajoute !" << endl;
}

// Afficher les contacts
void afficherContacts(Contact** carnet, int nb) {
    if (nb == 0) {
        cout << "Aucun contact !" << endl;
        return;
    }

    for (int i = 0; i < nb; i++) {
        carnet[i]->afficher();
    }
}

// Supprimer un contact par nom
void supprimerContact(Contact** carnet, int& nb, string nom) {
    for (int i = 0; i < nb; i++) {

        if (carnet[i]->getNom() == nom) {

            delete carnet[i];

            for (int j = i; j < nb - 1; j++) {
                carnet[j] = carnet[j + 1];
            }

            nb--;

            carnet[nb] = nullptr;

            cout << "Contact supprime !" << endl;
            return;
        }
    }

    cout << "Contact introuvable !" << endl;
}

int main() {

    const int MAX = 100;
    Contact** carnet = new Contact*[MAX];

    int nb = 0;
    int choix;
    string nom;

    do {
        cout << "\n===== CARNET D'ADRESSES =====" << endl;
        cout << "1. Ajouter un contact" << endl;
        cout << "2. Afficher les contacts" << endl;
        cout << "3. Supprimer un contact" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {

        case 1:
            if (nb < MAX) {
                ajouterContact(carnet, nb);
            } else {
                cout << "Carnet plein !" << endl;
            }
            break;

        case 2:
            afficherContacts(carnet, nb);
            break;

        case 3:
            cout << "Nom du contact a supprimer : ";
            cin >> nom;

            supprimerContact(carnet, nb, nom);
            break;

        case 0:
            cout << "Fin du programme." << endl;
            break;

        default:
            cout << "Choix invalide !" << endl;
        }

    } while (choix != 0);

    // Liberer les contacts restants
    for (int i = 0; i < nb; i++) {
        delete carnet[i];
    }

    // Liberer le tableau de pointeurs
    delete[] carnet;

    carnet = nullptr;

    return 0;
}
