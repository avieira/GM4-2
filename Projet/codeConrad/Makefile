CC=g++
SOURCE=ElFini
OBJECT=objets
EXEC=test

all: $(EXEC)

$(OBJECT)/carre.o : $(OBJECT)/geometrier2.o $(SOURCE)/carre.h $(SOURCE)/carre.cpp $(SOURCE)/integer_part.c
	$(CC) $(SOURCE)/carre.cpp -c -o $@

$(OBJECT)/elementfini.o : $(OBJECT)/geometrie.o $(OBJECT)/restfctbase.o $(SOURCE)/elementfini.h $(SOURCE)/elementfini.cpp
	$(CC) $(SOURCE)/elementfini.cpp -c -o $@

$(OBJECT)/elementfinir2.o : $(OBJECT)/geometrier2.o $(OBJECT)/elementfini.o $(SOURCE)/elementfinir2.h $(SOURCE)/elementfinir2.cpp
	$(CC) $(SOURCE)/elementfinir2.cpp -c -o $@

$(OBJECT)/fonction.o : $(SOURCE)/fonction.h $(SOURCE)/fonction.cpp
	$(CC) $(SOURCE)/fonction.cpp -c -o $@

$(OBJECT)/fonctionsmath.o : $(SOURCE)/fonctionsmath.h $(SOURCE)/fonctionsmath.cpp
	$(CC) $(SOURCE)/fonctionsmath.cpp -c -o $@

$(OBJECT)/formbilin.o : $(SOURCE)/formbilin.h $(SOURCE)/formbilin.cpp
	$(CC) $(SOURCE)/formbilin.cpp -c -o $@

$(OBJECT)/formbilinr2p1.o : $(SOURCE)/formbilin.o $(SOURCE)/formbilinr2p1.h $(SOURCE)/formbilinr2p1.cpp
	$(CC) $(SOURCE)/formbilinr2p1.cpp -c -o $@

$(OBJECT)/formlinr2p1.o : $(SOURCE)/formlinr2p1.h $(SOURCE)/formlinr2p1.cpp
	$(CC) $(SOURCE)/formlinr2p1.cpp -c -o $@

$(OBJECT)/geometrie.o : $(OBJECT)/sommet.o $(SOURCE)/geometrie.h $(SOURCE)/geometrie.cpp
	$(CC) $(SOURCE)/geometrie.cpp -c -o $@

$(OBJECT)/geometrier2.o : $(OBJECT)/sommetr2.o $(OBJECT)/geometrie.o $(SOURCE)/geometrier2.h $(SOURCE)/geometrier2.cpp
	$(CC) $(SOURCE)/geometrier2.cpp -c -o $@

$(OBJECT)/maillage.o : $(OBJECT)/elementfini.o $(SOURCE)/maillage.h $(SOURCE)/maillage.cpp
	$(CC) $(SOURCE)/maillage.cpp -c -o $@

$(OBJECT)/maillager2.o : $(OBJECT)/maillage.o $(SOURCE)/maillager2.h $(SOURCE)/maillager2.cpp
	$(CC) $(SOURCE)/maillager2.cpp -c -o $@

$(OBJECT)/main.o : $(SOURCE)/main.cpp $(OBJECT)/elementfinir2.o $(OBJECT)/maillager2.o $(OBJECT)/triangle.o $(OBJECT)/carre.o $(OBJECT)/formbilinr2p1.o $(OBJECT)/formlinr2p1.o $(OBJECT)/probleme.o
	$(CC) $(SOURCE)/main.cpp -c -o $@

$(OBJECT)/probleme.o : $(SOURCE)/probleme.h $(SOURCE)/probleme.cpp
	$(CC) $(SOURCE)/probleme.cpp -c -o $@

$(OBJECT)/restfctbase.o : $(OBJECT)/fonction.o $(SOURCE)/restfctbase.h $(SOURCE)/restfctbase.cpp
	$(CC) $(SOURCE)/restfctbase.cpp -c -o $@

$(OBJECT)/restfctbaser2.o : $(OBJECT)/restfctbase.o $(SOURCE)/restfctbaser2.h $(SOURCE)/restfctbaser2.cpp
	$(CC) $(SOURCE)/restfctbaser2.cpp -c -o $@

$(OBJECT)/restfctbaser2p1.o : $(OBJECT)/restfctbaser2.o $(SOURCE)/restfctbaser2p1.h $(SOURCE)/restfctbaser2p1.cpp
	$(CC) $(SOURCE)/restfctbaser2p1.cpp -c -o $@

$(OBJECT)/sommet.o : $(SOURCE)/sommet.cpp $(SOURCE)/sommet.h
	$(CC) $(SOURCE)/sommet.cpp -c -o $@

$(OBJECT)/sommetr2.o : $(OBJECT)/sommet.o $(SOURCE)/sommetr2.cpp $(SOURCE)/sommetr2.h
	$(CC) $(SOURCE)/sommetr2.cpp -c -o $@

$(OBJECT)/triangle.o : $(OBJECT)/geometrier2.o $(SOURCE)/triangle.h $(SOURCE)/triangle.cpp
	$(CC) $(SOURCE)/triangle.cpp -c -o $@


test : $(OBJECT)/main.o $(OBJECT)/carre.o $(OBJECT)/elementfini.o $(OBJECT)/elementfinir2.o $(OBJECT)/fonction.o $(OBJECT)/fonctionsmath.o $(OBJECT)/formbilin.o $(OBJECT)/formbilinr2p1.o $(OBJECT)/formlinr2p1.o $(OBJECT)/geometrie.o $(OBJECT)/geometrier2.o $(OBJECT)/maillage.o $(OBJECT)/maillager2.o $(OBJECT)/probleme.o $(OBJECT)/restfctbase.o $(OBJECT)/restfctbaser2.o $(OBJECT)/restfctbaser2p1.o $(OBJECT)/sommet.o $(OBJECT)/sommetr2.o $(OBJECT)/triangle.o
	$(CC) $(OBJECT)/*.o -o $(EXEC)

clean:
	rm -rf $(OBJECT) && mkdir $(OBJECT)
