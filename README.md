## 📋 Description

**Pipex** est un projet éducatif visant à recréer le fonctionnement de la commande Unix `pipe`.
Le but est de rediriger la sortie d'une commande vers l'entrée d'une autre, simulant ainsi le comportement de la ligne de commande suivante : 
```bash

< file1 cmd1 | cmd2 > file2
```
Ce projet vous aidera à approfondir votre compréhension des processus, de la gestion des tubes (pipes) et des redirections en C.

## 🔍 Objectif
L'objectif est de développer un programme capable d'exécuter deux commandes shell enchaînées, tout en redirigeant leurs entrées et sorties via des fichiers et des pipes. Les commandes à exécuter seront passées en arguments et devront être traitées dynamiquement.

## 🛠️ Installation
### Prérequis :
- Un compilateur C (cc)
### Cloner le projet :
- Pour obtenir les fichiers nécessaires, clonez le dépôt GitHub :
```bash
git clone https://github.com/agraille/pipex.git
```
### Compilation :
Pour compiler le programme, exécutez :
```bash
cd pipex
make
```
### Exécution :
Pour utiliser votre programme, la syntaxe est la suivante :
```bash
./pipex file1 "cmd1" "cmd2" file2
```
### Par exemple :

```bash
./pipex infile "ls -l" "wc -l" outfile
```
Cela exécutera ls -l sur le contenu de infile et redirigera la sortie de wc -l vers outfile.

### Exemple de Sortie :
Si infile contient une liste de fichiers, la sortie de la commande précédente sera le nombre de fichiers, écrit dans outfile.

## Bonus : Here Doc et Multi Pipe
En plus de la fonctionnalité de base, des bonus peuvent être ajoutés :

```bash
make bonus
```

Here Doc : Permet d'envoyer des données directement à une commande via un fichier temporaire. Cela permet de simuler l'entrée de données dans une commande sans utiliser un fichier externe.

Exemple d'utilisation :

```bash
./pipex here_doc END cat "grep 'hello'" outfile
```
Multi Pipe : Cette fonctionnalité permet de chaîner plusieurs commandes avec plusieurs pipes, pas seulement deux. Cela permet de rediriger la sortie de plusieurs commandes vers l'entrée des suivantes.

Exemple d'utilisation avec trois commandes :

```bash
./pipex infile "cmd1" "cmd2" "cmd3" outfile
```
## 📏 Contraintes

Vous ne pouvez pas utiliser de fonctions non autorisées telles que printf ou scanf.
Le programme doit gérer les erreurs comme l'absence de fichier, les commandes invalides, etc.
Vous devez utiliser uniquement des pipes et des redirections standards.
## 🌟 Fonctionnalités

Gestion dynamique des entrées et sorties.
Manipulation des processus à l'aide de fork et execve.
Validation robuste des erreurs et des entrées.
## 💻 Contribuer

Les contributions sont les bienvenues ! Si vous souhaitez ajouter des fonctionnalités, corriger des bugs ou améliorer l'efficacité, n'hésitez pas à forker le projet et proposer une pull request.

Comment contribuer :

- 1 - Forkez le projet.
- 2 - Créez une branche pour vos modifications : git checkout -b feature/amélioration.
- 3 - Committez vos changements : git commit -am 'Ajout d’une nouvelle fonctionnalité'.
- 4 - Poussez la branche : git push origin feature/amélioration.
- 5 - Ouvrez une Pull Request pour proposer vos changements.
