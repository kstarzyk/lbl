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
$ mkdir vendor
$ git clone https://github.com/kokke/tiny-regex-c vendor/
$ make # DEBUG=1
```

## Third parties

- [tiny-regex-c](https://github.com/kokke/tiny-regex-c) - regular expressions

## Examples

- [brainfuck interpreter](examples/bf.lbl)
