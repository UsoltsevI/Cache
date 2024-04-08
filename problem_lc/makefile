all: LC.c
	gcc -O2 LC.c -o LC.x

test: LC.x
	for i in $$(seq 1 1 9); do echo -n "Tests/test$${i}.ans: | " && cat Tests/test$${i}.ans && ./LC.x < Tests/test$${i}.dat; done

clear:
	rm *.x
