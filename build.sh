# simple build script

./compile.sh level0/types/_compile.c output/types.o
./compile.sh wrapper/zin.c output/zin.o
./compile.sh wrapper/main.c output/main.o

clang output/*.o -o output/zin -lgc
./output/zin
