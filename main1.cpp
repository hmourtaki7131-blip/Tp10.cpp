
#include <iostream>
using namespace std;

int main() {

    int n;

    cout << "Donner la taille du tableau : ";
    cin >> n;

    if (n <= 0) {
        cout << "Taille invalide !" << endl;
        return 1;
    }

    int* tableau = new int[n];

    cout << "Saisir les elements :" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << " : ";
        cin >> tableau[i];
    }

    cout << "\nLes elements du tableau :" << endl;

    for (int i = 0; i < n; i++) {
        cout << tableau[i] << " ";
    }

    cout << endl;

    delete[] tableau;
    tableau = nullptr;

    cout << "Memoire liberee !" << endl;

    return 0;
}
