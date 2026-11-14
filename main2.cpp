
#include <iostream>
#include <string>
using namespace std;

class Personne {
private:
    string nom;
    int age;

public:
    Personne(string n, int a) {
        nom = n;
        age = a;
    }

    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Age : " << age << " ans" << endl;
    }
};

int main() {

    Personne* p = new Personne("Hiba", 20);

    cout << "===== INFORMATIONS PERSONNE =====" << endl;
    p->afficher();

    delete p;
    p = nullptr;

    cout << "Memoire liberee !" << endl;

    return 0;
}
