# LIFProjet 2018

## Index

1. [Introduction](#introduction)
      * [Équipe](#equipe)
      * [Encadrant](#encadrant)
      * [Objectif](#objectif)
      * [Code Recap](#Code)

<a name="introduction"></a>
## Introduction


[//]: # "{{{"

<a name="equipe"></a>
### Équipe

Equipe :
- AZOUI Aymen
- SBAAI Abdelaziz (pillowinacoma)


<a name="encadrant"></a>
### Encadrant

- Encadrant :	-Jean-Claude Iehl
		          -Vincent Nivoliers (vincent.nivoliers@univ-lyon1.fr)

<a name="objectif"></a>
### Objectif

Implementation d'un solver de niveau du jeu Rush Hour
- https://forge.univ-lyon1.fr/lifap6/rush-hour-etu


<a name="Code"></a>
### Code Recap

Main    :
    - 1)dans le main on charge la situation initiale du jeu, on affiche la grille (parking)
    - 2)on cherche les déplacements possibles (à un sel coup)
    - 2)on teste la fonction de déplacements
    - 2)on affiche pour montrer que le déplacement est effectué
    - 2)on teste aussi les fonctions qui vérifient qu'une voiture peut avancer ou reculer
    - 2)on teste la fonction qui trouve tous les déplacements possibles (même à plusieurs coups)
    - 2)on lance le solveur
    - 2)on affiche la solution (le chemin)
Classes :
- 1) Parking : la partie objet manipulable, un parking qui contient un ensemble de voitures.
 Cette classe contient tout les fonctions qui permettent de manipuler le parking (bouger les voitures, chercher une voiture, checker si on a une situation gagnante ...)
- 2) Set_Parking : C'est la partie qui s'occupe de la résolution du problème,


[//]: # "}}}"
