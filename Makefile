CC=g++
KONF=-std=c++11
FLAG=-c
MAIN=TaskGenerator

all: $(MAIN)

debug: KONF+=-g -DDEBUG
debug: $(MAIN)


$(MAIN): GenProperties.o Random.o Task.o TaskGenerator.o main.cpp
	$(CC) $(KONF) GenProperties.o Random.o Task.o TaskGenerator.o main.cpp -o $(MAIN)

GenProperties.o: GenProperties.hpp GenProperties.cpp
	$(CC) $(KONF) $(FLAG) GenProperties.hpp GenProperties.cpp

Random.o: Random.cpp Random.hpp
	$(CC) $(KONF) $(FLAG) Random.hpp Random.cpp

Task.o: Task.cpp Task.hpp
	$(CC) $(KONF) $(FLAG) Task.hpp Task.cpp

TaskGenerator.o: TaskGenerator.cpp TaskGenerator.hpp
	$(CC) $(KONF) $(FLAG) TaskGenerator.hpp TaskGenerator.cpp

clean:
	rm -f $(MAIN) *.o *.gch
