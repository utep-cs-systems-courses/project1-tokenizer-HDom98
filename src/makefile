tokenize: tokenizer.o uimain.o history.o
	cc -o tokenize tokenizer.o uimain.o history.o

clean:
	rm -f *.o tokenize
tokenizer.o: tokenizer.h tokenizer.c

history.o: history.h history.c

uimain.o: uimain.c


