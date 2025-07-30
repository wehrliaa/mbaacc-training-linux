# MBAACC Training for Linux

This is an attempt at rewriting [kosunan's training tool](https://github.com/kosunan/MBAACC_Training) in C++, to make it work on Linux.

**Due to a limitation in (or feature of) Wine, this tool and the game need to be run on the same Wine prefix**, otherwise it won't detect the game at all. So if you're running the game through Lutris, Proton, Steam, etc, you might run into issues.

Some code was taken from [Fang's training tool](https://github.com/fangdreth/MBAACC-Extended-Training-Mode).

## TODO

- [X] Savestates (FN1 to save, FN2 to load)
- * [X] Way to clear savestate (Hold FN1 for 1 second)
- [ ] Frame indicator bar display thing

## Installation and usage

Only dependencies are `mingw-w64` and `make`. 

```
git clone https://github.com/wehrliaa/mbaacc-training-linux
cd mbaacc-training-linux
make
```

You should get an executable called `training.exe`. Run it with Wine.

```
wine training.exe
```

Doesn't matter whether you run it before or after opening the game.

## License

Do whatever you want with it.
