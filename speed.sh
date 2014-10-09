#!/bin/bash

cabal build
cp dist/build/treestuff/treestuff .
time ./treestuff
rm ./treestuff
