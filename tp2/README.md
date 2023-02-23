# TP1

> TP de Synthèse et Animation d'Image ~ Primitives de remplissage
> Auteur : Valentin _RIEU_

---

## Compilation

2 commandes :

- `make` ou `make all` pour créer l'executable `bin/remplissage`
- `make clean` pour supprimer les `.o` et l'executable.


## Exécution

`bin/remplissage` suivi des coordonnées `x y` de chaque sommet du polygone à remplir, `x` et `y` compris entre les valeurs de `X/YMIN` et `X/YMAX` dans le fichier `inc/all.h` (par défaut : `-2048` et `2048`).

Exemple : 
```bash
bin/remplissage 0 10 1300 300 800 900 700 300 500 200
```


## Structure

```bash
.
├── bin
│   └── remplissage
├── inc
│   ├── all.h
│   ├── bresenham.h
│   ├── cercle.h
│   ├── common.h
│   ├── display.h
│   ├── list.h
│   ├── main.h
│   ├── remplissage.h
│   ├── setup.h
│   └── utils.h
└── src
    ├── bresenham.c
    ├── cercle.c
    ├── display.c
    ├── list.c
    ├── main.c
    ├── remplissage.c
    ├── setup.c
    └── utils.c
```

## Issues
- Certaines coordonnées des sommets en fonction du sommet précédent causent des segfault ; c'est notamment le cas avec des polygones concaves. 

