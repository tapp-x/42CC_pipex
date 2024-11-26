# Pipex

## Description

Le projet `pipex` consiste à recréer le comportement du pipe (`|`) en ligne de commande. Il permet de rediriger la sortie d'une commande vers l'entrée d'une autre, en utilisant des appels système Unix tels que `pipe`, `fork`, `dup2`, et `execve`.

## Utilisation

### Compilation

Pour compiler le projet, utilisez la commande suivante :

```sh
make
```

Pour compiler la version bonus, utilisez la commande suivante :

```sh
make bonus
```

### Exécution

Le programme `pipex` s'utilise de la manière suivante :

```sh
./pipex file1 cmd1 cmd2 file2
```

- `file1` : fichier d'entrée.
- `cmd1` : première commande à exécuter.
- `cmd2` : deuxième commande à exécuter.
- `file2` : fichier de sortie.

Exemple :

```sh
./pipex infile "ls -l" "grep pipex" outfile
```

Pour la version bonus, qui supporte le mode `here_doc`, utilisez la commande suivante :

```sh
./pipex here_doc LIMITER cmd1 cmd2 file
```

- `LIMITER` : délimiteur pour le mode `here_doc`.

Exemple :

```sh
./pipex here_doc END "cat" "wc -l" outfile
```