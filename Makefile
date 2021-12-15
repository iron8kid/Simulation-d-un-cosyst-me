CPP_FLAGS = -Wall  -std=c++11

main : main.cpp Aquarium.o Bestiole.o Milieu.o Comportement.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o VisiteurDeplacement.o Camouflage.o Carapace.o Nageoire.o Oeil.o Oreille.o
	g++ $(CPP_FLAGS) -o main main.cpp Aquarium.o Bestiole.o Milieu.o Comportement.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o VisiteurDeplacement.o Camouflage.o Carapace.o Nageoire.o  Oeil.o Oreille.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp Milieu.h
	g++ $(CPP_FLAGS) -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp # Capteurs/Oeil.h Capteurs/Oreille.h Accesoires/Carapace.h Accesoires/Nageoire.h Accesoires/Camouflage.h
	g++ $(CPP_FLAGS) -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp Bestiole.h Visiteur.h
	g++ $(CPP_FLAGS) -c Milieu.cpp -I .

Comportement.o : Comportements/Comportement.h Comportements/Comportement.cpp
	g++ $(CPP_FLAGS) -c Comportements/Comportement.cpp -I .	

Gregaire.o : Comportements/Gregaire.h Comportements/Gregaire.cpp Comportements/Comportement.h Visiteur.h
	g++ $(CPP_FLAGS) -c Comportements/Gregaire.cpp -I .	

Kamikaze.o : Comportements/Kamikaze.h Comportements/Kamikaze.cpp Comportements/Comportement.h Visiteur.h
	g++ $(CPP_FLAGS) -c Comportements/Kamikaze.cpp -I .	

Peureuse.o : Comportements/Peureuse.h Comportements/Peureuse.cpp Comportements/Comportement.h Visiteur.h
	g++ $(CPP_FLAGS) -c Comportements/Peureuse.cpp -I .

Prevoyante.o : Comportements/Prevoyante.h Comportements/Prevoyante.cpp Comportements/Comportement.h Visiteur.h
	g++ $(CPP_FLAGS) -c Comportements/Prevoyante.cpp -I .	

VisiteurDeplacement.o : VisiteurDeplacement.cpp VisiteurDeplacement.h
	g++ $(CPP_FLAGS) -c VisiteurDeplacement.cpp -I .

Camouflage.o : Accesoires/Camouflage.h Accesoires/Camouflage.cpp
	g++ $(CPP_FLAGS) -c Accesoires/Camouflage.cpp -I .

Carapace.o : Accesoires/Carapace.h Accesoires/Carapace.cpp
	g++ $(CPP_FLAGS) -c Accesoires/Carapace.cpp -I .

Nageoire.o : Accesoires/Nageoire.h Accesoires/Nageoire.cpp
	g++ $(CPP_FLAGS) -c Accesoires/Nageoire.cpp -I .

Oeil.o : Capteurs/Oeil.cpp Capteurs/Oeil.h
	g++ $(CPP_FLAGS) -c Capteurs/Oeil.cpp -I .

Oreille.o : Capteurs/Oreille.cpp Capteurs/Oreille.h
	g++ $(CPP_FLAGS) -c Capteurs/Oreille.cpp -I .

clean :
	rm *.o main

