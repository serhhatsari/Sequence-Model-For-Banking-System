target:	bank

bank_lib:	bank_lib.h bank_lib.c
			gcc -ansi -pedantic-errors -c bank_lib.c -lm

bank_main:	bank_lib.h bank_main.c
			gcc -ansi -pedantic-errors -c bank_main.c -lm

bank:	bank_main bank_lib
		gcc bank_lib.o bank_main.c -o bank -lm

clean:
		rm bank
