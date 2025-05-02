# Projet Vecteur - TP C++ à l'ESIR

## Description

Ce projet a été réalisé dans le cadre d'un travail universitaire à l'ESIR (École Supérieure d'Ingénieurs de Rennes). Il s'agit d'une implémentation en C++ permettant de manipuler des vecteurs génériques, avec des fonctionnalités telles que :

- L'addition de vecteurs de types `float` et `string`.
- Le calcul du produit scalaire entre deux vecteurs.
- La gestion de vecteurs de différentes dimensions et types.

Le projet met en œuvre des concepts avancés de programmation en C++, notamment les templates, la surcharge d'opérateurs et les tests unitaires.

## Fonctionnalités principales

1. **Addition de vecteurs** :
   - Addition de vecteurs de type `float`.
   - Concaténation de vecteurs de type `string`.

2. **Produit scalaire** :
   - Calcul du produit scalaire entre deux vecteurs de type `float`.
   - Gestion des incompatibilités de types (exemple : multiplication entre `float` et `string`).

3. **Tests unitaires** :
   - Utilisation de Google Test pour valider les comportements attendus.

## Structure du projet

- `main.cpp` : Contient le code principal pour tester les fonctionnalités du projet.
- `vecteur.h` : Définition de la classe template `Vecteur` et des surcharges d'opérateurs.
- `memory.cxx` : Gestion mémoire (si applicable).
- `tests/` : Contient les tests unitaires pour valider les fonctionnalités.
- `CMakeLists.txt` : Configuration du projet avec CMake.

## Prérequis

- **Compilateur C++** : Supportant la norme C++23.
- **CMake** : Version 3.15 ou supérieure.
- **Google Test** : Inclus automatiquement via `FetchContent`.

## Compilation et exécution

1. **Cloner le dépôt** :
   ```bash
   git clone https://github.com/kiurow590/ESIR1_PROG2_TP1b.git
   cd ESIR1_PROG2_TP1b
   ```

2. **Générer les fichiers de build** :
   ```bash
   cmake -B build
   ```

3. **Compiler le projet** :
   ```bash
   cmake --build build
   ```

4. **Exécuter le programme principal** :
   ```bash
   ./build/Vecteur
   ```

5. **Lancer les tests unitaires** :
   ```bash
   ./build/Vecteur_test
   ```

## Auteurs

Ce projet a été réalisé par **[Votre Nom]**, étudiant à l'ESIR, dans le cadre d'un TP sur la programmation en C++.

## Licence

Ce projet est à usage académique et n'est pas destiné à une utilisation commerciale.
