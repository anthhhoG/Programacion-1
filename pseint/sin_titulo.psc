Algoritmo promediosYnota
	Escribir "Ingrese la primera nota:"
	Leer nota1
	Escribir "Ingrese la segunda nota:"
	Leer nota2
	Escribir "Ingrese la tercera nota:"
	Leer nota3
	Escribir "Ingrese la cuarta nota:"
	Leer nota4
	promedio = (nota1 + nota2 + nota3 + nota4) / 4
	Escribir "El promedio es:", promedio
	Si promedio >= 61 Entonces
		Escribir "Estado: Aprobado"
	Sino
		Escribir "Estado: No aprobado"
	FinSi	
FinAlgoritmo