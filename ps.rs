Crear la ListaAbierta como una lista de nodos vacía
Crear la ListaCerrada como una lista de nodos vacía

Poner el NodoInicial en la ListaAbierta (Asignarle un costo f de 0)

Bucle que corra siempre y cuando la ListaAbierta no este vacía   

    Obtener el NodoActual a partir del nodo con el costo f más bajo de la ListaAbierta
    Borrar el NodoActual de la ListaAbierta
    Poner el NodoActual en la ListaCerrada

    Si NodoActual es igual al NodoFinal:
        Terminamos el bucle (Se ha encontrado la meta, regresar
        por los nodos padres para encontrar ruta mas corta)

    Crear una lista de nodos Vecinos del NodoActual
    
    Por cada Vecino en la lista de Vecinos del NodoActual hacer:    

        Si el Vecino esta en la ListaCerrada o es parte de un obstaculo/muro:
            Terminar esta iteración y continuamos con el siguiente Vecino      
        
        Vecino.g = NodoActual.g + distancia entre Vecino y NodoActual
        Vecino.h = distancia del Vecino al NodoFinal
        Vecino.f = Vecino.g + Vecino.h        

        Si Vecino.posición esta en alguna posición de algun nodo de la ListaAbierta:  
            Si el Vecino.g es mayor que el costo g del que esta en la ListaAbierta:
                Terminar esta iteración y continuamos con el siguiente Vecino        

        Poner el Vecino en la ListaAbierta
