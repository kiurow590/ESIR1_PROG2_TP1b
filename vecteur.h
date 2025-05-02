/** \brief Ce fichier doit contenir la déclaration de la classe vecteur
    Attention, elle ne doit contenir aucune implémentation de méthode / fonction
*/

#ifndef _VECTEUR_H
#define _VECTEUR_H

#include <cstddef>
#include <iosfwd>
#include <iostream>
#include <cassert>

// Déclaration de la classe vecteur
template<typename T>
class Vecteur {
private :
    // attributs
    T *m_tableau; // tableau de type T
    // dimensions du vecteur
    int m_taille;
protected:

public :

    /**
     * \brief Constructeur par dimensions et valeur initiale
     * \param nbDimension La dimensions du vecteur
     * \param initValue La valeur initiale des éléments du vecteur
     */
    Vecteur(int nbDimension = 3, T initValue = T()) : m_taille(nbDimension), m_tableau(new T[nbDimension]) {
        assert(nbDimension > 0 && "Vecteur::Vecteur : nbDimension must be > 0");
        std::cout << "Vecteur dimensions : " << m_taille << std::endl
                  << "Les papiers sont en regle pour initialiser le vecteur" << std::endl;
        for (int i = 0; i < nbDimension; i++) {
            m_tableau[i] = initValue;
        }
    }

    /**
     * \brief Constructeur par copie de type T1
     * @param v
     */
    template<class T1>
    Vecteur(const Vecteur<T1> &v): m_taille(v.dimensions()), m_tableau(new T[v.dimensions()]) { // probleme ici
        std::cout << "Vecteur dimensions : " << m_taille << std::endl
                  << "Les papiers sont en regle pour initialiser le vecteur" << std::endl;
        for (int i = 0; i < m_taille; i++) {
            m_tableau[i] = v.get(i);
        }
    }

    /**
   * \brief Constructeur par copie de type T
   * @param v
   */
    Vecteur(const Vecteur<T> &v) : m_taille(v.dimensions()), m_tableau(new T[v.dimensions()]) {
        std::cout << "Vecteur dimensions : " << m_taille << std::endl
                  << "Les papiers sont en regle pour initialiser le vecteur" << std::endl;
        for (int i = 0; i < m_taille; i++) {
            m_tableau[i] = v.m_tableau[i];
        }
    }

    /**
    * \brief Destructeur
    */
    ~Vecteur() {
        delete[]  m_tableau;

        std::cout << "Les papiers sont en regle pour detruire le vecteur, le notaire a signer l'acte de deces"
                  << std::endl;

    }

    /**
     * \brief Accesseur en écriture
     * @param index  L'index de l'élément à accéder
     * @return  La valeur de l'élément
     */
    T &operator[](int index) {
        assert(index < m_taille && "Vecteur::operator[] : index out of range");
        return m_tableau[index];
    }

    /**
     * \brief Accesseur en lecture
     * @param index L'index de l'élément à accéder
     * @return La valeur de l'élément
     */
    const T &operator[](int i) const {
        assert(i < m_taille && "Vecteur::operator[] : index out of range");
        return m_tableau[i];
    }

    /**
     * \brief Accesseur en lecture taille du vecteur
     * @param index L'index de l'élément à accéder
     * @return La valeur de l'élément
     */
    T get(int index) const {
        assert(index < m_taille && "Vecteur::get : index out of range");
        return m_tableau[index];
    }

    /**
     * \brief Accesseur en écriture
     * \param index L'index de l'élément à modifier
     * \param value La nouvelle valeur de l'élément
     */
    void set(int index, T value) {
        assert(index < m_taille && "Vecteur::set : index out of range");
        m_tableau[index] = value;
    }

    /**
     * Getter de la dimensions du vecteur
     * @return La dimensions du vecteur
     */
    int dimensions() const {
        return m_taille;
    }

    /**
     * \brief Opérateur d'affectation
     * @param v Le vecteur à affecter
     * @return Le vecteur affecté
     */
    Vecteur &operator=(const Vecteur<T> &v) {
        if (this != &v) {
            delete[] m_tableau;
            m_taille = v.m_taille;
            m_tableau = new T[m_taille];
            for (int i = 0; i < m_taille; i++) {
                m_tableau[i] = v.m_tableau[i];
            }
        }
        return *this;
    }


private :
    // méthodes privées d'implémentation (si besoin)
};

/**
     * \brief Opérateur d'addition
     * @param v  Le vecteur à ajouter
     * @return  Le vecteur résultat
     */
template<class T1, class T2>
Vecteur<T1> operator+(const Vecteur<T1> &v1, const Vecteur<T2> &v2) {
    assert((v1.dimensions() == v2.dimensions()) && "Vecteur::operator+ : les vecteurs n'ont pas la meme dimensions");
    Vecteur<T1> result(v1.dimensions());
    for (size_t i = 0; i < result.dimensions(); i++) {
        result.set(i, v1.get(i) + v2.get(i));
    }
    return result;
}

/**
 * \brief Opérateur de multiplication scalaire
 * @tparam T1  Le type des éléments du premier vecteur
 * @tparam T2  Le type des éléments du second vecteur
 * @param v1  Le premier vecteur
 * @param v2  Le second vecteur
 * @return  Le résultat de la multiplication
 */
template<typename T1, typename T2>
float operator*(const Vecteur<T1> &v1, const Vecteur<T2> &v2) {
    assert((v1.dimensions() == v2.dimensions()) && "Vecteur::operator* : les vecteurs n'ont pas la meme dimensions");
    float res(0);
    for (int i = 0; i < v1.dimensions(); i++) {
        res += v1.get(i) * v2.get(i);
    }
    return res;
}

/**
 * \brief Opérateur d'affichage
 * @tparam T  Le type des éléments du vecteur
 * @param out  Le flux de sortie
 * @param v  Le vecteur à afficher
 * @return  Le flux de sortie
 */
template<typename T>
std::ostream &operator<<(std::ostream &out, const Vecteur<T> &v) {
    afficherVecteur(&v, out);
    return out;
}

/**
 * \brief Opérateur d'entrée
 * @tparam T  Le type des éléments du vecteur
 * @param in  Le flux d'entrée
 * @param v  Le vecteur à remplir
 * @return  Le flux d'entrée
 */
template<typename T>
std::istream &operator>>(std::istream &in, Vecteur<T> &v) {
    for (int i = 0; i < v.dimensions(); ++i) {
        float value;
        in >> value;
        v.set(i, value);
    }

    return in;
}

/**
 * \brief Affiche un vecteur
 * @tparam T  Le type des éléments du vecteur
 * @param v  Le vecteur à afficher
 * @param out  Le flux de sortie
 */
template<typename T>
void afficherVecteur(const Vecteur<T> *v, std::ostream &out) {
    std::cout << "Vecteur : ";
    for (int i = 0; i < v->dimensions(); i++) {
        out << v->get(i) << " ";
    }


}

/**
 * @brief Additionne deux vecteurs
 * @param v1 le premier vecteur
 * @param v2 le second vecteur
 * @return le vecteur résultat
 */
template<typename T1, typename T2>
Vecteur<T1> add(const Vecteur<T1> *v1, const Vecteur<T2> *v2) {

    assert((v1->dimensions() == v2->dimensions()) && "Vecteur::add : les vecteurs n'ont pas la meme dimensions");
    Vecteur v3(v1->dimensions());
    for (int i = 0; i < v1->dimensions(); i++) {
        v3.set(i, v1->get(i) + v2->get(i));
    }
    return v3;
}

/**
 * @brief Lit un vecteur depuis un flux d'entrée
 * @param in le flux d'entrée
 * @return le vecteur lu
 */
template<typename T>
Vecteur<T> *lireVecteur(std::istream &in) {
    std::cout << "Donnez la taille du vecteur : ";
    int dims;
    in >> dims;

    auto *vec_a_remplir = new Vecteur<T>(dims);

    for (int i = 0; i < dims; i++) {
        std::cout << "\nValeur " << i << " : ";
        T val;
        in >> val;
        vec_a_remplir->set(i, val);

        std::cout << "\n";
    }

    return vec_a_remplir;
}

#endif
