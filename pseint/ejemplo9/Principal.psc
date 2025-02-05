//revisado por Anthony Suc, 9959-24-389
// Calcula el promedio de una lista de N datos utilizando un SubProceso

Funcion prom <- Promedio ( arreglo, cantidad )
	suma <- 0
	Para i<-1 Hasta cantidad Hacer
		suma <- suma + arreglo[i]
	FinPara
	prom <- suma/cantidad
FinFuncion

Algoritmo Principal
	
	Dimension datos[100]
	Escribir "Ingrese la cantidad de datos:"
	Leer n
	
	Para i<-1 Hasta n Hacer
		Escribir "Ingrese el dato ",i,":"
		Leer datos[i]
	FinPara
	
	Escribir "El promedio es: ",Promedio(datos,n)
	
FinAlgoritmo