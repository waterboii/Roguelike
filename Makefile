CXX = g++
CXXFLAGS = -Wall -MMD -g 
EXEC = cc3k
OBJECTS = cell.o \
	  floor.o \
	  main.o \
	  object.o \
	  PC.o \
	  gold.o \
	  stair.o \
	  tempeffect.o \
	  race.o \
	  vampire.o \
	  drow.o \
	  goblin.o \
	  shade.o \
	  troll.o \
	  treasure.o \
	  enemy.o \
	  interact.o \
	  pcinteract.o \
	  enemyinteract.o \
	  dtreasure.o \
	  dragon.o \
	  potion.o \
	  merchant.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
