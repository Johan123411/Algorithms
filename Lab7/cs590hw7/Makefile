
hw7: main.o graph.o random_generator.o
	g++ -Wall -g -std=c++11 main.o graph.o random_generator.o -o hw7

main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp

graph.o: graph.cpp graph.h
	g++ -c -g -std=c++11 graph.cpp

random_generator.o: random_generator.cpp random_generator.h
	g++ -c -g -std=c++11 random_generator.cpp

clean:
	rm *.o hw7