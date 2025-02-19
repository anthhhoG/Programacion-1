Algoritmo ControlPartidosPoliticos
    Definir cantidadCandidatos, cantidadAfiliados, cantidadRondas Como Entero
    cantidadCandidatos <- 5
    cantidadAfiliados <- 50
    cantidadRondas <- 5
    
    Dimension nombresCandidatos[cantidadCandidatos]
    Dimension resultadosVotos[cantidadCandidatos, cantidadRondas]
    Dimension totalVotosPorCandidato[cantidadCandidatos]
    
    Para i <- 1 Hasta cantidadCandidatos Hacer
        Escribir "Ingrese el nombre del candidato ", i, ": "
        Leer nombresCandidatos[i]
    FinPara
    
    Repetir
        Para i <- 1 Hasta cantidadCandidatos Hacer
            Para j <- 1 Hasta cantidadRondas Hacer
                resultadosVotos[i, j] <- 0
            FinPara
        FinPara
        
        Para ronda <- 1 Hasta cantidadRondas Hacer
            Para afiliado <- 1 Hasta cantidadAfiliados Hacer
                voto <- Aleatorio(1, cantidadCandidatos)
                resultadosVotos[voto, ronda] <- resultadosVotos[voto, ronda] + 1
            FinPara
        FinPara
        escribir "+----------------------------------------------+"
        Escribir "Resultados de las votaciones:"
        escribir "+----------------------------------------------+"
        Para i <- 1 Hasta cantidadCandidatos Hacer
            Escribir "Candidato: " nombresCandidatos[i], "     ";  
            totalVotosPorCandidato[i] <- 0  
            Escribir "Resultados de cada ronda (1-5): "
            Para ronda <- 1 Hasta cantidadRondas Hacer
                Escribir resultadosVotos[i, ronda], "    ";  
                totalVotosPorCandidato[i] <- totalVotosPorCandidato[i] + resultadosVotos[i, ronda]  
            FinPara
            Escribir "Total de votos: " totalVotosPorCandidato[i] 
			escribir "+----------------------------------------------+"
        FinPara
        
        mayorVoto <- totalVotosPorCandidato[1]
        menorVoto <- totalVotosPorCandidato[1]
        candidatoMayor <- 1
        candidatoMenor <- 1
        
        Para i <- 2 Hasta cantidadCandidatos Hacer
            Si totalVotosPorCandidato[i] > mayorVoto Entonces
                mayorVoto <- totalVotosPorCandidato[i]
                candidatoMayor <- i
            FinSi
            Si totalVotosPorCandidato[i] < menorVoto Entonces
                menorVoto <- totalVotosPorCandidato[i]
                candidatoMenor <- i
            FinSi
        FinPara
        
        Escribir "El candidato a la presidencia ganador es: ", nombresCandidatos[candidatoMayor], " con ", mayorVoto, " votos."
        Escribir "El candidato con menos votos es: ", nombresCandidatos[candidatoMenor], " con ", menorVoto, " votos."
        
        Escribir "¿Desea realizar otra elección? (s/n): "
        Leer opcion
    Hasta Que opcion = 'n' O opcion = 'N'
FinAlgoritmo