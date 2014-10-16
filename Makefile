all: lemon parser extension

lemon:
	gcc -w lemon/lemon.c -o lemon/lemon

parser:
	lemon/lemon -s parser/parser.lemon
	cat parser/base.c >> parser/parser.c
	re2c -o scanner/scanner.c scanner/scanner.re

extension:
	cd ext && phpize && ./configure --silent --enable-zephir-parser && make && make test && sudo make install

clean:
	rm -f lemon/lemon
	cd parser && rm -f parser.h parser.c parser.out
	cd scanner && rm -f scanner.c
	cd ext && phpize --clean

.PHONY: all extension parser lemon
