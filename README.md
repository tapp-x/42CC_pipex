# Pipex

## Description

The `pipex` project involves recreating the behavior of the pipe (`|`)  in the command line. It allows redirecting the output of one command to the input of another, using system calls like `pipe`, `fork`, `dup2`, or `execve`.

## Usage

### Compilation

To compile the project, use the following command:

```sh
make
```

To compile the bonus version, use the following command:

```sh
make bonus
```

### Execution

The `pipex` program is used as follows:

```sh
./pipex file1 cmd1 cmd2 file2
```

- `file1` : input file.
- `cmd1` : first command to execute.
- `cmd2` : second command to execute.
- `file2` : output file.

Exemple :

```sh
./pipex infile "ls -l" "grep pipex" outfile
```

For the bonus version, which supports the `here_doc` mode, use the following command:

```sh
./pipex here_doc LIMITER cmd1 cmd2 file
```

- `LIMITER` : delimiter for `here_doc`mode.

Exemple :

```sh
./pipex here_doc END "cat" "wc -l" outfile
```
