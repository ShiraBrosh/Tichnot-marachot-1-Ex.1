CC = gcc
AR = ar
FLAGS = -Wall -g
CFLAGS = -fPIC
HEADER_NUMCLASS = NumClass.h
OBJECT_MAIN = main.o
OBJECT_BASIC = basicClassification.o
OBJECT_RECURSION = advancedClassificationRecursion.o
OBJECT_LOOP = advancedClassificationLoop.o

all: loops recursives recursived loopd mains maindloop maindrec 

loops: libclassloops.a  

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so
	

libclassloops: $(OBJECT_BASIC) $(OBJECT_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECT_BASIC) $(OBJECT_LOOP)      

libclassrec.a: $(OBJECT_BASIC) $(OBJECT_RECURSION)
	$(AR) -rcs libclassrec.a $(OBJECT_BASIC) $(OBJECT_RECURSION)

libclassrec.so:  $(OBJECT_BASIC) $(OBJECT_RECURSION)
	$(CC) $(FLAGS)-shared  $(CFLAGS) -o libclassrec.so  $(OBJECT_BASIC) $(OBJECT_RECURSION)

libclassloops.so:  $(OBJECT_BASIC) $(OBJECT_LOOP)
	$(CC) $(FLAGS) -shared  $(CFLAGS) -o libclassloops.so $(OBJECT_BASIC) $(OBJECT_LOOP)

mains: $(OBJECT_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECT_MAIN) libclassrec.a

maindloop: $(OBJECT_MAIN) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(OBJECT_MAIN) libclassloops.so

maindrec: $(OBJECT_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECT_MAIN) libclassrec.so


$(OBJECT_MAIN): main.c $(HEADER_NUMCLASS)
	$(CC) $(FLAGS) -c main.c 

$(OBJECT_BASIC): basicClassification.c $(HEADER_NUMCLASS)
	$(CC) $(FLAGS) $(CFLAGS) -c basicClassification.c

$(OBJECT_LOOP): advancedClassificationLoop.c $(HEADER_NUMCLASS)
	$(CC) $(FLAGS) $(CFLAGS) -c advancedClassificationLoop.c

$(OBJECT_RECURSION): advancedClassificationRecursion.c $(HEADER_NUMCLASS)
	$(CC) $(FLAGS) $(CFLAGS) -c advancedClassificationRecursion.c

.PHONY: clean 

clean:
	rm -f mains maindloop maindrec *.o *.a *.so *.gch

