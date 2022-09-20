# LBL Programming Language

```
██      ██████  ██              a small programming language for text processing
██      ██   ██ ██                - compiled
██      ██████  ██                - portable
██      ██   ██ ██                - syntax similar to awk
███████ ██████  ███████.
```

## Dependencies

- `gcc` or `clang`
- (compiler development) `flex`
- (compiler development) `bison`
- (optional) `clang-format`

## Install from source

```
$ git clone https://github.com/kstarzyk/lbl && cd lbl
$ git clone https://github.com/kokke/tiny-regex-c vendors/tiny-regex-c
# outputs lblc binary to root directory
$ make # DEBUG=1
```

## Third parties

- [tiny-regex-c](https://github.com/kokke/tiny-regex-c) - regular expressions

## Examples

- [brainfuck interpreter](examples/bf.lbl)

```
$ ./lblc examples/bf.lbl
$ ./examples/bf ./examples/99_bottles.lbl
```