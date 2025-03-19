flex lex.l
gcc lex.yy.c -o test.exe
test.exe < test.txt