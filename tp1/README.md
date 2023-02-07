# TP1

> TP de Synthèse et Animation d'Image ~ Découverte OpenGL
> Auteur : Valentin _RIEU_

---

## Compilation

2 commandes :

- `make` ou `make all` pour créer l'executable `bin/montre`
- `make clean` pour supprimer les `.o` et l'executable.


## Exécution

`bin/montre` suffit à executer le programme. L'heure du système est utilisé par défaut pour la montre.

Des options sont disponibles :

- `bin/montre s <vitesse>` applique un ratio à la vitesse de déplacement de la trotteuse. Par défaut, la vitesse est de `4`
- `bin/montre <heures> <minutes> <secondes>` applique un temps au lancement de l'application. Possible de ne spécifier aucune de ces valeurs, `<heures>`, `<heures> <minutes>` ou `<heures> <minutes> <secondes>`.

Ces deux options sont combinables, la séléction du ratio de la vitesse doit être en première position.

## Structure

```bash
.
├── bin
│   └── montre
├── inc
│   ├── all.h
│   ├── bresenham.h
│   ├── cercle.h
│   ├── common.h
│   ├── main.h
│   ├── montre.h
│   └── utils.h
├── obj
│   ├── bresenham.o
│   ├── cercle.o
│   ├── main.o
│   ├── montre.o
│   └── utils.o
└──  src
    ├── bresenham.c
    ├── cercle.c
    ├── main.c
    ├── montre.c
    └── utils.c
```