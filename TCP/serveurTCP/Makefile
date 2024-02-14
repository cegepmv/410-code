NOM=serveur4

all: release

release: ${NOM}.c
	gcc -o ${NOM} ${NOM}.c -lpigpio

debug: ${NOM}.c
	gcc -g ${NOM}.c -lpigpio
	
clean:
	rm ${NOM} a.out