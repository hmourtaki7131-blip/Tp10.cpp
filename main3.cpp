
#include <iostream>
#include <string>
using namespace std;

class Livre {
private:
    string titre;
    float prix;

public:
    void saisir() {
        cout << "Donner le titre : ";
        cin >> titre;

        cout << "Donner le prix : ";
        cin >> prix;
    }

    void afficher() {
        cout << "Titre : " << titre << endl;
        cout << "Prix : " << prix << " DH" << endl;
        cout << "-------------------" << endl;
    }
};

int main() {

    int n;

    cout << "Combien de livres voulez-vous creer ? ";
    cin >> n;

    if (n <= 0) {
        cout << "Nombre invalide !" << endl;
        return 1;
    }

    Livre* livres = new Livre[n];

    for (int i = 0; i < n; i++) {
        cout << "\nLivre " << i + 1 << endl;
        livres[i].saisir();
    }

    cout << "\n===== LISTE DES LIVRES =====" << endl;

    for (int i = 0; i < n; i++) {
        livres[i].afficher();
    }

    delete[] livres;
    livres = nullptr;

    cout << "Memoire liberee !" << endl;

    return 0;
}
