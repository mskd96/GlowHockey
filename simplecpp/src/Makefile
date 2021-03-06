OPTIONS=-I`pwd` -I/usr/include/X11 -L/usr/lib/i386-linux-gnu -L/usr/X11R6/lib -lX11  

OBJS = canvas.o polygon.o line.o circle.o sprite.o turtle.o rectangle.o text.o turtleSim.o

HDRS =  pose.h composite.h common_def.h matrix.h sprite.h canvas.h polygon.h turtle.h line.h circle.h rectangle.h text.h turtleSim.h simplecpp

default: $(OBJS) $(HDRS)
	ar rcs libsprite.a $(OBJS)

config: 
	rm -f ..lib/libsprite.a
	rm -f libsprite.a
	rm -f *.o
	make
	cp libsprite.a ../lib/
	cp -v $(HDRS) ../include

canvas.o: canvas.cpp canvas.h sprite.h common_def.h turtle.h
	g++ -g -c canvas.cpp -o canvas.o $(OPTIONS)

polygon.o: polygon.cpp polygon.h sprite.h common_def.h
	g++ -g -c polygon.cpp -o polygon.o $(OPTIONS)

line.o: line.cpp line.h sprite.h common_def.h
	g++ -g -c line.cpp -o line.o $(OPTIONS)

rectangle.o: rectangle.cpp rectangle.h sprite.h common_def.h
	g++ -g -c rectangle.cpp -o rectangle.o $(OPTIONS)

circle.o: circle.cpp circle.h sprite.h common_def.h
	g++ -g -c circle.cpp -o circle.o $(OPTIONS)

text.o: text.cpp text.h sprite.h canvas.h common_def.h
	g++ -g -c text.cpp -o text.o $(OPTIONS)

sprite.o: sprite.h sprite.cpp common_def.h pose.h
	g++ -g -c sprite.cpp -o sprite.o $(OPTIONS)

turtle.o: turtle.h turtle.cpp common_def.h
	g++ -g -c turtle.cpp -o turtle.o $(OPTIONS)

turtleSim.o: turtleSim.h turtleSim.cpp
	g++ -g -c turtleSim.cpp -o turtleSim.o $(OPTIONS)

clean:
	rm *.o *.a

exe: 2turtles.cpp $(OBJS)
	g++ 2turtles.cpp $(OBJS) $(OPTIONS)

exe2: tt.cpp libsprite.a
	g++ tt.cpp libsprite.a $(OPTIONS)

exep: tree.cpp $(OBJS)
	g++ tree.cpp $(OBJS) $(OPTIONS)

exet: transformvectors.cpp $(OBJS)
	g++ transformvectors.cpp $(OBJS) $(OPTIONS)

exerect : transformvectors.cpp $(OBJS)
	g++ rectmain.cpp $(OBJS) $(OPTIONS)

exedraw : drawformula.cpp $(OBJS)
	g++ drawformula.cpp $(OBJS) $(OPTIONS)

texttest: texttest.cpp $(OBJS)
	g++ texttest.cpp $(OBJS) $(OPTIONS)

hilbert: hilbert.cpp $(OBJS)
	g++ hilbert.cpp $(OBJS) $(OPTIONS)

OBJS2 = canvas.o sprite.o polygon.o line.o circle.o turtle.o rectangle.o

trtest: trtest.cpp $(OBJS2) pose.h sprite.h canvas.h polygon.h composite.h
	g++ trtest.cpp canvas.cpp sprite.cpp polygon.cpp $(OPTIONS)

colonytest: colonytest.cpp $(OBJS2) pose.h sprite.h canvas.h polygon.h composite.h
	g++ colonytest.cpp canvas.cpp sprite.cpp polygon.cpp $(OPTIONS)

linetest: linetest.cpp pose.h sprite.h canvas.h polygon.h line.h $(OBJS2)
	g++ linetest.cpp line.cpp canvas.cpp sprite.cpp $(OPTIONS)

circletest: circletest.cpp pose.h sprite.h canvas.h polygon.h circle.h $(OBJS2)
	g++ circletest.cpp circle.cpp canvas.cpp sprite.cpp $(OPTIONS)

turtletest: turtletest.cpp $(HDRS) $(OBJS2)
	g++ turtletest.cpp $(OBJS2) $(OPTIONS)

rectangletest: rectangletest.cpp $(HDRS) $(OBJS2)
	g++ rectangletest.cpp $(OBJS2) $(OPTIONS)