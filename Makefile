main : main.cpp Aquarium.o Bestiole.o Milieu.o Comportement.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o VisiteurDeplacement.o Camouflage.o Carapace.o Nageoire.o 
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o Comportement.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o VisiteurDeplacement.o Camouflage.o Carapace.o Nageoire.o  -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp Milieu.h
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp Accesoires/Carapace.h Accesoires/Nageoire.h Accesoires/Camouflage.h 
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp Bestiole.h Visiteur.h # Comportements/Comportement.h Comportements/Gregaire.h Comportements/Kamikaze.h Comportements/Peureuse.h Comportements/Prevoyante.h
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

Comportement.o : Comportements/Comportement.h Comportements/Comportement.cpp
	g++ -Wall -std=c++11  -c Comportements/Comportement.cpp -I .	

Gregaire.o : Comportements/Gregaire.h Comportements/Gregaire.cpp Comportements/Comportement.h Visiteur.h
	g++ -Wall -std=c++11  -c Comportements/Gregaire.cpp -I .	

Kamikaze.o : Comportements/Kamikaze.h Comportements/Kamikaze.cpp Comportements/Comportement.h Visiteur.h
	g++ -Wall -std=c++11  -c Comportements/Kamikaze.cpp -I .	

Peureuse.o : Comportements/Peureuse.h Comportements/Peureuse.cpp Comportements/Comportement.h Visiteur.h
	g++ -Wall -std=c++11  -c Comportements/Peureuse.cpp -I .

Prevoyante.o : Comportements/Prevoyante.h Comportements/Prevoyante.cpp Comportements/Comportement.h Visiteur.h
	g++ -Wall -std=c++11  -c Comportements/Prevoyante.cpp -I .	

VisiteurDeplacement.o : VisiteurDeplacement.cpp VisiteurDeplacement.h #Comportements/Kamikaze.h Comportements/Gregaire.h Comportements/Prevoyante.h Comportements/Peureuse.h Bestiole.h
	g++ -Wall -std=c++11  -c VisiteurDeplacement.cpp -I .

Camouflage.o : Accesoires/Camouflage.h Accesoires/Camouflage.cpp
	g++ -Wall -std=c++11  -c Accesoires/Camouflage.cpp -I .

Carapace.o : Accesoires/Carapace.h Accesoires/Carapace.cpp
	g++ -Wall -std=c++11  -c Accesoires/Carapace.cpp -I .

Nageoire.o : Accesoires/Nageoire.h Accesoires/Nageoire.cpp
	g++ -Wall -std=c++11  -c Accesoires/Nageoire.cpp -I .



clean :
	rm *.o main

