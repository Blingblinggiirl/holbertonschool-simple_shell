Our very simple shell is compiled on Ubuntu 20.04 LTS with the following command:
```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

```
## Example of how to launch the shell after compiling:

`./hsh`

- Output: prompt to terminal: `#cisfun$`. 

## Builtins
There are two builtins programmed into the shell. Below is a description and use for each builtin.

- `env` - The env command is a command that tells the shell program to display all of the environment variables with their values. It is a way to access those values through the shell.
- `exit` - If you wish to exit out of the shell the user can use the builtin `exit`.
## Exiting commands

To exit out of a command or process the user can use `ctrl c`. `Control c` stops a process and causes it to abort. The user can also utilize the command `ctrl D` which will just exit. When the command `ctrl D` is used an exit status of 0 is given. Using exit, you can input its exit status or it is defaulted to the status of the last command executed.


## Files
- `README.md`: Current file, contains information about this project.
- [main.h](https://github.com/Blingblinggiirl/holbertonschool-simple_shell/blob/master/main.h): Header file, contains all prototypes for funcitons used, as well as libriaries.
- [simple_shell](https://github.com/Blingblinggiirl/holbertonschool-simple_shell/blob/master/simple_shell.c): The main program.
- [Authors of the project](https://github.com/Blingblinggiirl/holbertonschool-simple_shell/blob/master/AUTHORS)
## Interactive Mode

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```




## Non-interactive mode

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Authors

- [Romina Benitez](https://github.com/Blingblinggiirl)
- [Santiago Alves](https://github.com/santialvesz)
