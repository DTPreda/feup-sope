all: main mainWall atExit ex5 ex5b ex6

main : main.c
	gcc main.c -o main

mainWall: main.c
	gcc main.c -Wall -o mainWall

atExit: atExit.c
	gcc atExit.c -Wall -o atExit

ex5: ex5.c
	gcc ex5.c -Wall -o ex5

ex5b: ex5b.c
	gcc ex5b.c -Wall -o ex5b

ex6: ex6.c
	gcc ex6.c -Wall -o ex6

ex6c: ex6c.c
	gcc ex6c.c -Wall -o ex6c

ex10: ex10.c
	gcc ex10.c -Wall -o ex10

ex11: ex11.c
	gcc ex11.c -Wall -o ex11

ex11a: ex11a.c
	gcc ex11a.c -Wall -o ex11a

ex11b: ex11b.c
	gcc ex11b.c -Wall -o ex11b

ex12: ex12.c
	gcc ex12.c -Wall -o ex12

clean:
	rm -f main mainWall atExit ex5 ex5b ex6 ex6c ex10 ex11 ex11a ex11b ex12
