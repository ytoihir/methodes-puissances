# Programmation Parallèle et Distribuée

## Auteurs
* Jihad GHANNOUM
* Yoa TOIHIR

ISTY | IATIC 4 | 2021-2022

## Commandes

### Compiler le programme :
```sh
$ make
```

### Lancer le programme :
```sh
$ ./main > plot.txt
```
### Générer la courbe de performance  :
```sh
$ plot './plot.txt' using 1:2 with linespoints
```

## Avertissement
le fichier "plot.txt" est nécessaire pour le bon fonctionnement du programme, même s'il est vide ou à zéro. Veillez à ne pas le supprimer.
Ce fichier contient (nombre de threads, temps d'exécution, résultat des méthodes puissances).
