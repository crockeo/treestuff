# treestuff

This repository is an exploration of implementing a
[Trie](http://en.wikipedia.org/wiki/Trie)-like structure in a number of
different languages. Implementations at the time of writing are:

* C
* C++
* Python
* Haskell

The C++ version is intended to be used to solve boggle boards for every possible
word. The end result is solving the boggle challenge on the nerdsniping board in
the Hacker School, but the algorithms used should be able to be easily adapted
to any number of applications.

Keep in mind that these Trie's are not "real", in that they don't really store
any data within in them. The data is effectively stored in the fact that each
node corresponds to a character in a specified range.

### Building

Building this project depends on the language used. I'll provide instructions
for every one.

First, for a language agnostic instruction, clone to repo:

```bash
>$ git clone git@github.com:crockeo/treestuff.git
>$ cd treestuff/
```

**C**:

```bash
>$ cd trie_in_c/
>$ make
>$ ./trie
```

**C++**:

```bash
>$ cd boggle_solver/
>$ make
>$ ./boggle_solver
```

**Python**:

I'm not sure on build instructions for Python. I didn't write the Python code
and I'm not very experienced with it. I'll try to get the person who wrote it to
make some build instructions.

**Haskell**:

```bash
>$ cd trie_in_hs/
>$ cabal sandbox init
>$ cabal install --only-dependencies
>$ cabal run
```
