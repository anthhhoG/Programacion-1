//revisado por Anthony Suc, 9959-24-389
Algoritmo EjemploFechaHora
	
	fa <- FechaActual() // retorna un solo nro entero en formato AAAAMMDD
	anio <- trunc(fa/10000)
	mes <- trunc(fa/100)%100
	dia <- fa%100
	
	Mientras Verdadero Hacer
		Borrar Pantalla
		Escribir "Fecha actual: ", dia, "/", mes, "/", anio
		
		ha <- HoraActual() // retorna un solo nro entero en formato HHMMSS
		hora <- trunc(ha/10000)
		min <- trunc(ha/100)%100
		seg <- ha%100
		Escribir "Hora Actual: ", hora, ":", min, ":", seg
		
		Esperar 1 Segundo
	FinMientras
	
FinAlgoritmo