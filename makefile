objects = main.o hash.o bloomfilter.o

main : $(objects)
	g++ -o main $(objects)

main.o : hash.h bloomfilter.h
bloomfilter.o : bloomfilter.h
hash.o : hash.h

clean:
	rm *.o main
