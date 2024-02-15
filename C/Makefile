NOM=exercice2

all: release

release: ${NOM}.c
	gcc ${NOM}.c -o ${NOM}
	./${NOM}

debug: ${NOM}.c
	gcc -g ${NOM}.c 

clean: 
	rm ${NOM} a.out

