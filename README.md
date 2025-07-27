# MBAACC Training for Linux

This is an attempt at rewriting [kosunan's training tool](https://github.com/kosunan/MBAACC_Training) in C++, to make it work on Linux.

So far only tested on Wine 10.0 stable and GEProton9-25. Please let me know if something goes wrong on your setup.

Some code was taken from [Fang's training tool](https://github.com/fangdreth/MBAACC-Extended-Training-Mode).

## TODO

- [X] Savestates (FN1 to save, FN2 to load)
- * [X] Way to clear savestate (Hold FN1 for 1 second)
- [ ] Frame indicator bar display thing

## Compiling

Only dependency is `mingw-w64`. Run `make`, and you should get a binary called `training.exe`.

Doesn't matter whether you run it before or after opening the game.

## License

Do whatever you want with it.
