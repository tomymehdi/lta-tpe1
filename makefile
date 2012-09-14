tp1 : tp
	gcc -g -m32 -o exe target/app.o

tp : clean
	mkdir target
	flex --outfile=src/lex.gen.c src/parser.l
	gcc -g -m32 -o target/app.o -c src/app.c 

clean:
	rm -rf target
	rm -f src/lex.gen.c