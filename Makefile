#Para escrever comentários ##
############################# Makefile ##########################

1550: compilar_1550 run_1550

1552: compilar_1552 run_1552

2: main clean run2

3: main clean run3

4: main clean run4

5: main clean run5

all: main clean run1 run2 run3 run4 run5

#Regras de compilação

compilar_1550: 
			gcc -o executavel Lista1/Resgate\ em\ queda\ livre\ -\ URI\ 1552.c

compilar_1552: 
			gcc -o executavel Lista\ 2/Resgate\ em\ queda\ livre\ -\ URI\ 1552.c -lm

#Regras de execução

run_1550: 
			cat Lista\ 1/entradas/entrada\ 1550 | ./executavel
			clear
			cat Lista\ 1/resultados/resultado\1550

run_1552: 
			cat Lista\ 2/entradas/entrada\ 1552 | ./executavel
			rm executavel
			clear
			cat Lista\ 2/resultados/resultado\ 1552

# main: main.o Controle.o Data.o Filas.o HRRN.o Loterry.o 1-Loterry.o Multilevel_Feedback.o Processos.o Round-robins.o
# 			gcc -o main main.o Controle.o Data.o Filas.o HRRN.o Loterry.o 1-Loterry.o Multilevel_Feedback.o Processos.o Round-robins.o
			
#-----> Distancia com o botão TAB ### e não com espaços

# main.o: main.c
# 			gcc -o main.o -c main.c

# Controle.o: Controle.c
# 			gcc -o Controle.o -c Controle.c

# Data.o: Data.c
# 			gcc -o Data.o -c Data.c

# Filas.o:  Filas.c
# 			gcc -o Filas.o -c Filas.c

# HRRN.o:  HRRN.c
# 			gcc -o HRRN.o -c HRRN.c

# Loterry.o:  Loterry.c
# 			gcc -o Loterry.o -c Loterry.c

# 1-Loterry.o:  1-Loterry.c
# 			gcc -o 1-Loterry.o -c 1-Loterry.c

# Multilevel_Feedback.o:  Multilevel_Feedback.c
# 			gcc -o Multilevel_Feedback.o -c Multilevel_Feedback.c

# Processos.o:  Processos.c
# 			gcc -o Processos.o -c Processos.c

# Round-robins.o:  Round-robins.c
# 			gcc -o Round-robins.o -c Round-robins.c

clean:
			rm -rf *.o
			rm executavel

# mrproper: clean
# 			rm -rf main

# run1: 
# 			./main 1

# run2: 
# 			./main 2

# run3: 
# 			./main 3

# run4: 
# 			./main 4

# run5: 
# 			./main 5

# a: main run
			
