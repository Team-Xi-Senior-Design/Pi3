CPP = g++
CPPOPTS =
LINKER = -lpthread -lbluetooth

main.o : src/main.c src/main.h



all : Bike
Bike : main.o
	$(CPP) $(LINKER) -o Bike Debug/main.o

%.o : %.c
	$(CPP) $(CPPOPTS) -c $<

clean:
	rm -f ../Bike
	rm -f *.o
