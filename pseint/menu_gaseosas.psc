Algoritmo 	menu_gaseosas
	definir usuario como entero
	escribir "Menu de Gaseosas"
	escribir "1. Pepsi"
	escribir "2. CocaCola"
	escribir "3. Fanta"
	escribir "4. Grapete"
	escribir "5. Crush"
	escribir "ingrese el numero de la gaseosa que desee"
	leer usuario 
	si usuario==1 Entonces
		escribir "disfruta tu Pepsi fr�a"
	FinSi
	si usuario==2 Entonces
		escribir "disfruta tu CocaCola fr�a"
	FinSi
	si usuario==3 Entonces
		escribir "disfruta tu Fanta fr�a"
	FinSi
	si usuario==4 Entonces
		escribir "disfruta tu Grapete fr�a"
	FinSi
	si usuario==5 Entonces
		escribir "disfruta tu Crush fr�a"
	FinSi
	si usuario<>1 y usuario<>2 y usuario<>3 y usuario<>4 y usuario<>5 Entonces
		escribir "ingreso un numero incorrecto"
	FinSi
FinAlgoritmo
