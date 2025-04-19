flex lex.l
bison -d synt.y 
gcc lex.yy.c synt.tab.c tableSymbole.c quads.c codegen.c -o test.exe
test.exe < test.txt