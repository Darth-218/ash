# ash

## Idea

A simple shell *(IN C++)* that implements:

- basic file/directory manipulating functions.

## Commands to implement

 1. Move files/directories
 2. Copy files/directories
 3. Delete files/directories
 4. Create files/directories
 5. Show current directory
 6. Show the contents of a file
 7. Show contents of a directory
 8. Navigate files
 9. Move between directories
10. Manual pages

## Additional features

- Text editor
- Prompt customization
- Directory Tree
- Keybinds
- Varibles
- Colored outputs (command dependant)

## Roles

### Main processes

- [ ] Default shell process: Darth
- [ ] Makefile: Zein
- [ ] Create a default path to store all the commands: Afifi
- [ ] Create a history file: Afifi

### Commands

- [ ] Move & delete: Darth

- [ ] Copy & create: Mazen

- [ ] Show directory contents & show current directory: Bullets

- [ ] Navigate files & Show file contents: Afifi

- [ ] Move between directories & manual pages: AlchemistsGestalt
  - NOTE ABOUT cd/change-pos: The command `cd` is not an executable like other
    commands, but a shell built-in.  This is because **processes cannot change
    the working directory of other processes**.  I have changed `change-pos.cpp`
    from having a `main()` function to being a `change-pos` function, which
    should be called from the main shell somehow.  It should also preferably not
    be in its own independent file. --- Fedora Enthusiast

## New Command Names

| Original command | Our command  |
|------------------|--------------|
| `mv`             | `change-loc` |
| `rm`             | `destroy`    |
| `cp`             | `clone`      |
| `touch`          | `punch`      |
| `cat`            | `print-file` |
| `ls`             | `print-dir`  |
| `pwd`            | `where`      |
| `less`           | `view-file`  |
| `cd`             | `change-pos` |
| `man`            | `elder`      |
