#! /bin/bash

FILES="http://www.lifl.fr/~poteaux/fichiers/teaching/"

echo "Preparing some data"

mkdir computer-science
mkdir computer-science/tp1
cd computer-science/tp1
echo "Unix is easy!" > readme
touch empty-file
for i in $(seq 1 7); do
    mkdir ex$i
done
cd ex2
wget -q $FILES/bigfile.txt
cd ../ex3
wget -q $FILES/Sand.msg
wget -q $FILES/Sand.rep
wget -q $FILES/Musset.rep
cd ../ex4
echo "some data in this file" > file1.txt
echo "more data in the same file" >> file1.txt
touch file2-empty.txt
echo "another file" >> file3.txt
cd ../ex7
touch cmd.txt
echo -e "A=4\necho A\necho \$A\nB=5\nexpr A+B" > cmd.txt

echo "Done"
