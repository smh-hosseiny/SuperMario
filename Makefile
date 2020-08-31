CC := g++ 
CFLAG= -c
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: mario.out

mario.out: main.o Game.o ObjectsBorders.o InputHandler.o MapDesigner.o Mario.o Gomba.o KoopaTroopa.o Block.o SimpleBlock.o SimpleBrick.o CoinContainer.o RedMushroomContainer.o HealthMushroomContainer.o Screen.o Input.o Pipe.o Flag.o rsdl.o 
	
	$(CC) main.o Game.o ObjectsBorders.o InputHandler.o MapDesigner.o Mario.o Gomba.o KoopaTroopa.o Block.o SimpleBlock.o SimpleBrick.o CoinContainer.o RedMushroomContainer.o HealthMushroomContainer.o Screen.o Input.o Pipe.o Flag.o rsdl.o  $(CCFLAGS) -o mario.out


main.o: main.cpp Game.h Screen.h Input.h InputHandler.h rsdl.hpp
	$(CC) ${CFLAG} main.cpp -o main.o


rsdl.o: rsdl.hpp rsdl.cpp
	$(CC) ${CFLAG} rsdl.cpp -o rsdl.o


InputHandler.o: InputHandler.h InputHandler.cpp MapDesigner.h Game.h
	$(CC) ${CFLAG} InputHandler.cpp -o InputHandler.o
	

Game.o: Game.h Game.cpp ObjectsBorders.h Mario.h Gomba.h KoopaTroopa.h Block.h SimpleBlock.h SimpleBrick.h RedMushroomContainer.h HealthMushroomContainer.h Screen.h Pipe.h Flag.h rsdl.hpp
	$(CC) ${CFLAG} Game.cpp -o Game.o	



ObjectsBorders.o: ObjectsBorders.h ObjectsBorders.cpp Game.h rsdl.hpp
	$(CC) ${CFLAG} ObjectsBorders.cpp -o ObjectsBorders.o	


MapDesigner.o: MapDesigner.h Game.h rsdl.hpp
	$(CC) ${CFLAG} MapDesigner.cpp -o MapDesigner.o	


Mario.o: rsdl.hpp Mario.h Mario.cpp
	$(CC) ${CFLAG} Mario.cpp -o Mario.o


Pipe.o:  Pipe.h  Pipe.cpp
	$(CC) ${CFLAG}  Pipe.cpp -o  Pipe.o


Flag.o:  Flag.h  Flag.cpp 
	$(CC) ${CFLAG}  Flag.cpp -o  Flag.o


Gomba.o: Gomba.h Gomba.cpp
	$(CC) ${CFLAG} Gomba.cpp -o Gomba.o
	

KoopaTroopa.o: KoopaTroopa.h KoopaTroopa.cpp
	$(CC) ${CFLAG} KoopaTroopa.cpp -o KoopaTroopa.o


Block.o: Block.h Block.cpp
	$(CC) ${CFLAG} Block.cpp -o Block.o


SimpleBlock.o: SimpleBlock.h SimpleBlock.cpp
	$(CC) ${CFLAG} SimpleBlock.cpp -o SimpleBlock.o


SimpleBrick.o: SimpleBrick.h SimpleBrick.cpp
	$(CC) ${CFLAG} SimpleBrick.cpp -o SimpleBrick.o


RedMushroomContainer.o: RedMushroomContainer.h RedMushroomContainer.cpp
	$(CC) ${CFLAG} RedMushroomContainer.cpp -o RedMushroomContainer.o


HealthMushroomContainer.o: HealthMushroomContainer.h HealthMushroomContainer.cpp
	$(CC) ${CFLAG} HealthMushroomContainer.cpp -o HealthMushroomContainer.o


CoinContainer.o: CoinContainer.h CoinContainer.cpp
	$(CC) ${CFLAG} CoinContainer.cpp -o CoinContainer.o


Input.o: Input.h Input.cpp
	${CC} ${CFLAG} Input.cpp -o Input.o
	

Screen.o: Screen.h Screen.cpp
	${CC} ${CFLAG} Screen.cpp -o Screen.o

.PHONY: clean
clean:
	rm -r *.o