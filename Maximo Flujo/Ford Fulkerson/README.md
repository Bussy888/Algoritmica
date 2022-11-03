El método Ford-Fulkerson o algoritmo Ford-Fulkerson (FFA) es un algoritmo codicioso para calcular el flujo máximo en una red de flujo. A veces se denomina "método" en lugar de "algoritmo" porque el método para encontrar rutas de aumento en el gráfico residual no está completamente especificado o se especifica en varias implementaciones con diferentes tiempos de ejecución.


La idea detrás del algoritmo es la siguiente: siempre que haya una ruta desde el origen (nodo inicial) hasta el sumidero (nodo final), y haya capacidad disponible en todos los bordes de la ruta, enviamos el flujo a lo largo de uno de esos caminos. Luego encontramos otro camino, y así sucesivamente. Las rutas con capacidad disponible se denominan rutas aumentadas.

![FordF](https://cdn.programiz.com/sites/tutorial2program/files/flow-network-example.png)

## Ejercicios Relacionados
[Data Flow UVA - 10594](https://vjudge.net/problem/UVA-10594)

## Referencias
[Wikipedia](https://es.wikipedia.org/wiki/Algoritmo_de_Ford-Fulkerson)


[GeeksForGeeks](https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/)
