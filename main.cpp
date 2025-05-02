#include <iostream>
#include "vecteur.h"


using namespace std;

/**
 * \brief Question 4
 */
void additionFloat() {

    cout << "Q4 - Saisir le nombre de dimensions des vecteurs : " << endl;
    int nbDimension;
    cin >> nbDimension;
    Vecteur<float> vecteur1(nbDimension);
    for (int i = 0; i < nbDimension; i++) {
        std::cout << "\nValeur " << i << " : ";
        float val;
        cin >> val;
        vecteur1.set(i, val);

        std::cout << "\n";
    }
    cout << endl;
    afficherVecteur(&vecteur1, cout);

    cout << endl << "Saisir le nombre de dimensions des vecteurs : " << endl;
    int nbDimension2;
    cin >> nbDimension2;
    Vecteur<float> vecteur2(nbDimension2);
    for (int i = 0; i < nbDimension2; i++) {
        std::cout << "\nValeur " << i << " : ";
        float val;
        cin >> val;
        vecteur2.set(i, val);

        std::cout << "\n";
    }

    afficherVecteur(&vecteur2, cout);
    Vecteur<float> vecteur3 = vecteur1 + vecteur2;
    cout << endl << "Somme des vecteurs : " << endl;
    afficherVecteur(&vecteur3, cout);
}

/**
 * \brief Question 5
 */
void additionString() {
    cout << "Q5 - Saisir le nombre de dimensions des vecteurs : " << endl;
    int nbDimension;
    cin >> nbDimension;
    Vecteur<std::string> vecteur1(nbDimension);
    for (int i = 0; i < nbDimension; i++) {
        std::cout << "\nValeur " << i << " : ";
        std::string val;
        cin >> val;
        vecteur1.set(i, val);

        std::cout << "\n";
    }
    cout << endl;
    afficherVecteur(&vecteur1, cout);

    cout << endl << "Saisir le nombre de dimensions des vecteurs : " << endl;
    int nbDimension2;
    cin >> nbDimension2;
    Vecteur<std::string> vecteur2(nbDimension2);
    for (int i = 0; i < nbDimension2; i++) {
        std::cout << "\nValeur " << i << " : ";
        std::string val;
        cin >> val;
        vecteur2.set(i, val);

        std::cout << "\n";
    }

    afficherVecteur(&vecteur2, cout);
    Vecteur<std::string> vecteur3 = vecteur1 + vecteur2;
    cout << endl << "Somme des vecteurs : " << endl;
    afficherVecteur(&vecteur3, cout);
}

/**
 * \brief Question 9
 */
void prodScal() {
    cout << "Q9 - Saisir le nombre de dimensions des vecteurs : " << endl;
    Vecteur<float> vecteur1(3, 2);
    afficherVecteur(&vecteur1, cout);

    Vecteur<float> vecteur2(3, 5);
    afficherVecteur(&vecteur2, cout);

    float prodScal(vecteur1 * vecteur2);
    cout << endl << "Produit scalaire des vecteurs : " << prodScal << endl;
}

int main() {
// question 4
    additionFloat();

//// question 5 -additionner 2 vecteurs de string rend les vecteur concaténé...
    additionString();


//// question 6 - 8
//Vecteur<float> v7( 3, 0);
//cin >> v7;
//cout << v7;


// question 9
    prodScal();


//// question 10
// ça ne marche pas car on ne peut pas faire de multiplication de vecteur de type float et string... ça n'as aucun sens

//// question 11
    Vecteur<int> v10(3, 2);
    Vecteur<float> v11(3, 3.3);
    float v12 = v10 * v11;
    float v13 = v11 * v10;
    std::cout << v12 << std::endl << v13 << std::endl;
// pour la suite, les tests unitaires permettent de vérifier les comportement voulu

    return 0;
}


