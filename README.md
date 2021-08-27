# C - Simple Shell
### Objective 📋
* Coding your own shell
### Requirements 📌
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to

# Task 📄

0. README, man, AUTHORS
1. Betty would be proud
2. Simple shell 0.1
3. Simple shell 0.2
4. Simple shell 0.3
5. Simple shell 0.4
6. Simple shell 1.0
7. What happens when you type `ls -l *.c` in the shell

## How To Install, Compile, and Use
Install and Compile
```
(your_terminal)$ git clone https://github.com/jrichard1909/simple_shell.git
(your_terminal)$ cd simple_shell
(your_terminal)$ gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o simple_shell
```
**Non-Interactive Mode**
```
echo "ls -l" | ./simple_shell
```
**Interactive Mode***
Activate the shell
```
(your_terminal)$ ./simple_shell
$
```
Sample Usage
```
$ ls -al
total 4
-rw-rw-r-- 1 vagrant vagrant   234 Aug 27 09:32 file1.c
-rw-rw-r-- 1 vagrant vagrant    69 Aug 27 09:32 file2.c
$ echo "Hello World!"
Hello World!
$ man ./man_1_simple_shell (opens our manpage for more information)
```
Stop and return to your original shell
```
$ exit
(your_terminal)$
```

### Authors ✒️
* [John Chavez](https://github.com/jrichard1909)
* [Giuliano Flores](https://github.com/mrgiulls)
* [Diego Morey](https://github.com/DAlons27)
