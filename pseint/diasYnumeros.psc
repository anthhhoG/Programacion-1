Algoritmo diasYnumeros
	Definir dia Como Caracter
	Definir n Como Entero
	Escribir 'ingresa un numero'
	Leer n
	Si n>=1 Y n<=7 Entonces
		Si n==1 Entonces
			dia <- 'LUNES'
		SiNo
			Si n==2 Entonces
				dia <- 'MARTES'
			SiNo
				Si n==3 Entonces
					dia <- 'MIERCOLES'
				SiNo
					Si n==4 Entonces
						dia <- 'JUEVES'
					SiNo
						Si n==5 Entonces
							dia <- 'VIERNES'
						SiNo
							Si n==6 Entonces
								dia <- 'SABADO'
							SiNo
								dia <- 'DOMINGO'
							FinSi
						FinSi
					FinSi
				FinSi
			FinSi
		FinSi
		Escribir 'Al numero ',n,' Le corresponde el dia ',dia
	SiNo
		Escribir 'NUMERO INCORRECTO'
	FinSi
FinAlgoritmo
