# MBAACC Training for Linux

This is an attempt at rewriting [kosunan's training tool](https://github.com/kosunan/MBAACC_Training) in C++, to make it work on Linux.

So far only tested on Wine 10.0, as in running both this training tool and cccaster with pure Wine, no funny proton or anything. Please let me know if something goes wrong on your setup.

Some code was taken from [Fang's training tool](https://github.com/fangdreth/MBAACC-Extended-Training-Mode).

## TODO

- [X] Savestates (FN1 to save, FN2 to load)
- * [X] Way to clear savestate (Hold FN1 for 1 second)
- [ ] Frame indicator bar display thing
- [ ] Hitboxes...?

### Known issues

- [X] ~~Game crashes after going back to css, then back again to training mode, while having a savestate from previous session~~
- [X] ~~Sometimes loading state doesn't work. Probably something to do with `high_precision_sleep`~~

## Compiling

Only dependency is `mingw-w64`. Run `make`, and you should get a binary called `training.exe`.

Doesn't matter whether you run it before or after opening the game.

## Why

1. I want savestates
2. Fang's training tool doesn't work
3. kosunan's training tool doesn't work
4. I'm tired of messing with `winetricks` and waiting for Wine updates just to have nothing work in the end

## License

Do whatever you want with it.
