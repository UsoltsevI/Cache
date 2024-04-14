all: LC.c
	gcc -O2 LC.c -o LC.x

separate: LCmain.o cache.o hash.o list.o
	gcc -O2 LCmain.o cache.o hash.o list.o -o LCsep.x

LCmain.o: LCmain.c
	gcc -O2 -c LCmain.c

cache.o: ../source/cache.c
	gcc -O2 -c ../source/cache.c -o cache.o 

hash.o: ../source/hash.c
	gcc -O2 -c ../source/hash.c -o hash.o 

list.o: ../source/list.c
	gcc -O2 -c ../source/list.c -o list.o 

test: LC.x
	for i in $$(seq 1 1 12); do echo -n "Tests/test$${i}.ans:\nright answer: " && cat Tests/test$${i}.ans && echo -n "result:       " && ./LC.x < Tests/test$${i}.dat && echo ""; done

testsep: LCsep.x
	for i in $$(seq 1 1 12); do echo -n "Tests/test$${i}.ans:\nright answer: " && cat Tests/test$${i}.ans && echo -n "result:       " && ./LCsep.x < Tests/test$${i}.dat && echo ""; done

clean:
	rm *.x
	rm -rf *.o
