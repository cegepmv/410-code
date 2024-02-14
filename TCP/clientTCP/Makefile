NOM=client3

all: release

release: ${NOM}.c
	gcc -o ${NOM} ${NOM}.c 

debug: ${NOM}.c
	gcc -g ${NOM}.c 
	
clean:
	rm ${NOM} a.out